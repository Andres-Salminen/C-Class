//#pragma once
//#include "Game_Task.h"
//#include "CalculateTask.h"
//#include "PrimeNumberTask.h"
//#include <thread>
//#include <condition_variable>
//#include <mutex>
//#include <chrono>
//#include <ratio>
//#include <vector>
//
//using namespace std;
//
//void RunGameTaskStuff();
//
//
//void RunGameTaskStuff()
//{
//	mutex mtx;
//	condition_variable cv;
//	unique_lock<mutex> lck(mtx);
//	mutex intMutex;
//	mutex coutLock;
//
//
//
//	int i = 0;
//	int numberOfTasksRunning = 0;
//
//	auto alambda = [&]()
//	{
//		intMutex.lock();
//		if (numberOfTasksRunning >= 8)
//		{
//			unique_lock<mutex> lck(mtx);
//			--numberOfTasksRunning;
//			cv.notify_all();
//		}
//		else
//		{
//			--numberOfTasksRunning;
//		}
//		intMutex.unlock();
//		coutLock.lock();
//		cout << "Callback called. Value is: " << numberOfTasksRunning << endl;
//		coutLock.unlock();
//	};
//
//	vector<Game_Task*> taskVektor;
//
//	for (int p = 0; p < 30; ++p)
//	{
//		taskVektor.push_back(new CalculateTask());
//	}
//
//
//	for (auto gt : taskVektor)
//	{
//		gt->callBack = alambda;
//		gt->coutLock = &coutLock;
//	}
//
//
//	chrono::high_resolution_clock::time_point t1 = chrono::high_resolution_clock::now();
//
//	vector<thread> taskThreads;
//
//	while (true)
//	{
//		if (i >= taskVektor.size())
//			break;
//		else if (numberOfTasksRunning >= 8)
//		{
//			coutLock.lock();
//			cout << "number of tasks to many, waiting." << endl;
//			coutLock.unlock();
//			cv.wait(lck);
//		}
//		
//		coutLock.lock();
//		cout << "Continuing tasks." << endl;
//		coutLock.unlock();
//		taskThreads.push_back(thread(&Game_Task::perform, taskVektor[i]));
//
//
//		//if (i >= taskVektor.size())
//		//	break;
//		//else
//		//	taskThreads.push_back(thread(&Game_Task::perform, taskVektor[i]));
//
//		intMutex.lock();
//		++numberOfTasksRunning;
//		intMutex.unlock();
//
//		//taskVektor[i]->perform();
//
//		++i;
//		coutLock.lock();
//		cout << numberOfTasksRunning << endl;
//		coutLock.unlock();
//
//	}
//
//	coutLock.lock();
//	cout << "Waiting for threads." << endl;
//	coutLock.unlock();
//	for (int k = 0; k < taskThreads.size(); ++k)
//		taskThreads[k].join();
//
//	chrono::high_resolution_clock::time_point t2 = chrono::high_resolution_clock::now();
//
//	chrono::duration<double> time_span = chrono::duration_cast<chrono::duration<double>>(t2 - t1);
//
//	cout << "It took: " << time_span.count() << " seconds to complete all tasks." << endl;
//}