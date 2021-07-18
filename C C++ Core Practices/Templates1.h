#pragma once
#include<iostream>
#include<string>
#include<thread>

#define APP_NAMESPACE_BEGIN namespace Template1 {
#define APP_NAMESPACE_END }

APP_NAMESPACE_BEGIN


struct APP_THREADS {
    int MAIN_THREAD_SHOULD_CLOSE = 0;
    int CHILD_THREADS_SHOULD_CLOSE = 0;
};

APP_THREADS _appThreads = { };

void testit() {
    std::cout << "testit empty" << std::endl;
    std::cout << _threadid << std::endl;
    for (size_t i = 0; i < 10; i++)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        std::cout << "child thread is still running...." << std::endl;
        if (_appThreads.CHILD_THREADS_SHOULD_CLOSE) return;
        //return;
    }

}



template<class fn, class... args>
struct ShaderAnimateStruct {
    void printSize() {
        int size = sizeof...(args);
        std::cout << "size: " << size << std::endl;
    }
};


template<class type, class... args>
void testit(type _type, args... _args)
{

    std::cout << _type << std::endl;

    //recursive fun. call it at the end 
    testit(_args...);
    //std::cout << _args... << std::endl;
    std::cout << "testit para" << std::endl;
}

template<class T, class... args>
void sample(T first, args... _args) {
    std::cout << first << std::endl;
}

//define call type of the overloaded function
template<class type, class... args>
using call_type = void(*)(type _type, args... _args);


void init()
{

    //std::this_thread::sleep_for(std::chrono::milliseconds(1000));

    std::cout << _threadid << std::endl;

    ShaderAnimateStruct<int, int> a;
    a.printSize();

    // Start thread t1
    std::thread t1(testit<int, int, int>, 10, 20, 30);
    //t1.detach();

    std::this_thread::sleep_for(std::chrono::milliseconds(4000));
    _appThreads.CHILD_THREADS_SHOULD_CLOSE = 1;

    // Wait for t1 to finish
    t1.join();
    std::cout << "child thread detached!" << std::endl;

    std::cout << "end" << std::endl;

    // t1 has finished do other stuff

    //testit("char*", 10, 10, 10);

    //
}

APP_NAMESPACE_END