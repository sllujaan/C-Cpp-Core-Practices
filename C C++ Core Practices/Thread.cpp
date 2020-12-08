#include "Thread.h"

void c_thread::Thread::PrintMsg()
{
	for (size_t i = 0; i < 10; i++)
	{
		this_thread::sleep_for(chrono::milliseconds(1000));
		
		cout << "child thread printMsg" << endl;

		this->CURRENT_THREAD_TIME++;

		if (this->CURRENT_THREAD_TIME > MAX_THREAD_TIME) return;
	}
	
}

c_thread::Thread::~Thread()
{
	this->t1->join();
	cout << "Thread Destructor Called." << endl;
}

void c_thread::Thread::init()
{
	//std::thread* t1 = nullptr;// = new std::thread();
	this->t1 = new std::thread(&c_thread::Thread::PrintMsg, this);
	//std::thread t1(&c_thread::Thread::PrintMsg, this);

	
	for (size_t i = 0; i < 10; i++)
	{
		this_thread::sleep_for(chrono::milliseconds(1000));
		cout << "main thread" << i << endl;
	}


	cout << "done" << endl;
}
