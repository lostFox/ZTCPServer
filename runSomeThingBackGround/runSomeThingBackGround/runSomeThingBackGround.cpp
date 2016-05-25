// runSomeThingBackGround.cpp : 定义控制台应用程序的入口点。
//

//#include "stdafx.h"
#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

//void thread_task() { std::cout << "hello thread" << std::endl; }
void f1(int n) 
{ 
	for (int i = 0; i < 5; ++i) 
	{ 
		std::cout << "Thread " << n << " executing\n"; 
		std::this_thread::sleep_for(std::chrono::milliseconds(10)); 
	} 
} 

void f2(int& n) 
{ 
	for (int i = 0; i < 5; ++i) 
	{ 
		std::cout << "Thread 2 executing\n"; 
		++n; 
		std::this_thread::sleep_for(std::chrono::milliseconds(10)); 
	} 
}

void thread_task(int n) 
{ 
	std::this_thread::sleep_for(std::chrono::seconds(n)); 
	std::cout << "hello thread " << std::this_thread::get_id() 
		<< " paused " << n << " seconds" << std::endl; 
}

int main(int argc, char* argv[])
{
	int n = 0; 
	std::thread t1; // t1 is not a thread 
	std::thread t2(f1, n + 1); // pass by value 
	std::thread t3(f2, std::ref(n)); // pass by reference 
	std::thread t4(std::move(t3)); // t4 is now running f2(). t3 is no longer a thread 
	t2.join(); 
	t4.join(); 
	std::cout << "Final value of n is " << n << '\n';

	std::thread threads[5]; 
	std::cout << "Spawning 5 threads...\n"; 
	for (int i = 0; i < 5; i++) 
	{ 
		threads[i] = std::thread(thread_task, i+1);
	} 
	std::cout << "Done spawning threads! Now wait for them to join\n"; 
	for (auto& t : threads) 
	{ 
		t.join(); 
	} 
	std::cout << "All threads joined.\n";
}

