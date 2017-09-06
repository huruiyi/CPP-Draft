using System;
using System.Threading;

namespace CSLock
{
    #region Mutex

    internal class shareRes
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
            shareRes.mutex.WaitOne();
            Console.WriteLine(thrd.Name + "申请到 the mutex");
            do
            {
                Thread.Sleep(1000);
                shareRes.count++;
                Console.WriteLine("In " + thrd.Name + "ShareRes.count is " + shareRes.count);
                number--;
            } while (number > 0);
            Console.WriteLine(thrd.Name + "释放 the nmutex");
            // 释放
            shareRes.mutex.ReleaseMutex();
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
            shareRes.mutex.WaitOne();
            Console.WriteLine(thrd.Name + "申请到 the mutex");
            do
            {
                Thread.Sleep(1000);
                shareRes.count--;
                Console.WriteLine("In " + thrd.Name + "ShareRes.count is " + shareRes.count);
                number--;
            } while (number > 0);
            Console.WriteLine(thrd.Name + "释放 the nmutex");
            // 释放
            shareRes.mutex.ReleaseMutex();
        }
    }

    #endregion Mutex

    internal class Program
    {
        private static void Main(string[] args)
        {
            DateTime now = new DateTime(DateTime.Now.Ticks);
        }

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
    }
}