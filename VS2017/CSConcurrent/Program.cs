﻿using System;
using System.Collections.Concurrent;
using System.Collections.Generic;
using System.Linq;
using System.Threading;
using System.Threading.Tasks;

namespace CSConcurrent
{
    public class Person
    {
        public string Name { get; set; }
    }

    internal class Program
    {
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

        private static void Main(string[] args)
        {
            Demo1();
            Demo2();
            Demo3();
            Demo4();
            Console.ReadKey();
        }
    }
}