#pragma once
#include <iostream> // std::cout 
#include <thread> // std::thread 
#include <mutex> // std::mutex 
/*volatile int counter(0); // non-atomic counter 
std::mutex mtx; // locks access to counter 

void attempt_10k_increases() 
{ 
	for (int i=0; i<10000; ++i) 
	{ 
		if (mtx.try_lock()) 
		{ // only increase if currently not locked: 
			++counter; 
			mtx.unlock(); 
		} 
	} 
}*/

#include <chrono> // std::chrono::milliseconds
namespace yellow
{
	std::timed_mutex mtx;
	void fireworks()
	{ // waiting to get a lock: each thread prints "-" every 200ms: 
		while (!mtx.try_lock_for(std::chrono::milliseconds(200)))
		{
			std::cout << "-";
		}

		// got a lock! - wait for 1s, then this thread prints "*" 
		std::this_thread::sleep_for(std::chrono::milliseconds(1000));
		std::cout << "*\n";
		mtx.unlock();
	}
}