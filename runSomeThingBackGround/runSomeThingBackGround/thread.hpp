#pragma once
#include <iostream>
#include <thread>


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