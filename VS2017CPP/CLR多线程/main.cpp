using namespace System;
using namespace System::Threading;
ref class Slot
{
private:
	static Random^ randomGenerator;
	static LocalDataStoreSlot^ localSlot;
	static Slot()
	{
		randomGenerator = gcnew Random;
		localSlot = Thread::AllocateDataSlot();
	}

public:
	static void SlotTest()
	{
		// Set different data in each thread's data slot.
		Thread::SetData(localSlot, randomGenerator->Next(1, 200));

		// Write the data from each thread's data slot.
		Console::WriteLine("Data in thread_{0}'s data slot: {1,3}", AppDomain::GetCurrentThreadId().ToString(), Thread::GetData(localSlot)->ToString());

		// Allow other threads time to execute SetData to show
		// that a thread's data slot is unique to the thread.
		Thread::Sleep(1000);
		Console::WriteLine("Data in thread_{0}'s data slot: {1,3}", AppDomain::GetCurrentThreadId().ToString(), Thread::GetData(localSlot)->ToString());
	}
};

ref class ThreadData
{
private:
	[ThreadStaticAttribute]
	static int threadSpecificData;

public:
	static void ThreadStaticDemo()
	{
		// Store the managed thread id for each thread in the static
		// variable.
		threadSpecificData = Thread::CurrentThread->ManagedThreadId;

		// Allow other threads time to execute the same code, to show
		// that the static data is unique to each thread.
		Thread::Sleep(1000);

		// Display the static data.
		Console::WriteLine("Data for managed thread {0}: {1}", Thread::CurrentThread->ManagedThreadId, threadSpecificData);
	}
};

void test01()
{
	for (int i = 0; i < 20; i++)
	{
		Thread^ newThread = gcnew Thread(gcnew ThreadStart(ThreadData::ThreadStaticDemo));
		newThread->Start();
	}
}

void test02()
{
	array<Thread^>^newThreads = gcnew array<Thread^>(20);
	for (int i = 0; i < newThreads->Length; i++)
	{
		newThreads[i] = gcnew Thread(gcnew ThreadStart(&Slot::SlotTest));
		newThreads[i]->Start();
	}
}
int main()
{
	test01();
	test02();
	Console::ReadKey();
}