#pragma once

#include<iostream>
#include<thread>
#include<chrono>
using namespace std;

namespace c_thread {
	class Thread {
	private:
		size_t MAX_THREAD_TIME = 5;
		size_t CURRENT_THREAD_TIME = 0;
		std::thread* t1 = nullptr;

		void PrintMsg();

	public:
		Thread() {};
		~Thread();
		void init();
	};
}
