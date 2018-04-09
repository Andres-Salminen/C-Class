#pragma once
#include <iostream>
#include <mutex>
#include <thread>

using namespace std;

class Mutex_Guard
{
public:
	Mutex_Guard(mutex* input)
	{
		_myMutex = input;
		_myMutex->lock();
	}
	~Mutex_Guard()
	{
		_myMutex->unlock();
	}
private:
	mutex* _myMutex;
};