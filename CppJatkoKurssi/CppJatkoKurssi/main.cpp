#pragma once
#include "Big_Data.h"
#include "VektorStuff.h"
//#include "NullPointerTeht.h"
//#include "AutoFor.h"
//#include "Inheritance.h"
//#include "Longaf.h"
//#include "MemoryExplosion.h"
//#include <time.h>
#include "Log_Ptr.cpp"
#include <string>
#include "UniquePtrVector.h"
#include "Game_Task.h"
#include "CalculateTask.h"
#include "PrimeNumberTask.h"
#include <vector>
#include <condition_variable>
#include <mutex>
#include <ctime>
#include <ratio>
#include <chrono>
#include <thread>
#include "Mutex_Guard.h"
#include "MinMaxAlgorithm.h"
#include <limits>

using namespace std;

void TicTacToe()
{
	int sticks = 40;

	bool botTurn = false;
	
	while (sticks > 0)
	{
		int lastSticks = sticks;

		int sticksTaken;

		if (!botTurn)
		{
			cout << "Your turn, current amount of sticks: " << sticks << ". Take 1 - 3 sticks please: ";
			
			cin >> sticksTaken;

			if (sticksTaken > 0 && sticksTaken < 4 && sticksTaken <= sticks)
			{
				sticks -= sticksTaken;
			}
			else
				cout << "Invalid amount of sticks. Try again." << endl;
		}
		else
		{
			chrono::high_resolution_clock::time_point t1 = chrono::high_resolution_clock::now();

			cout << "It's the bots turn to take sticks. Current amount of sticks: " << sticks << ". Please wait while the bot is calculating." << endl;
			int result1, result2, result3;
			result1 = result2 = result3 = numeric_limits<int>::min();

			if (sticks >= 3)
				result1 = MinMax(sticks - 3, !botTurn);
			if (sticks >= 2)
				result2 = MinMax(sticks - 2, !botTurn);
			if (sticks >= 1)
				result3 = MinMax(sticks - 1, !botTurn);

			if (result1 > result2 && result1 > result3)
				sticksTaken = 3;
			else if (result2 > result1 && result2 > result3)
				sticksTaken = 2;
			else
				sticksTaken = 1;
			cout << "The bot has choosen to take " << sticksTaken << " sticks." << endl;
			sticks -= sticksTaken;


			chrono::high_resolution_clock::time_point t2 = chrono::high_resolution_clock::now();

			chrono::duration<double> time_span = chrono::duration_cast<chrono::duration<double>>(t2 - t1);

			cout << "It took: " << time_span.count() << " seconds for the bot to calculate board state." << endl;
		}

		if (sticks <= 0)
		{
			if (botTurn)
			{
				cout << "Congratulations. Youve won the game." << endl;
			}

			else
			{
				cout << "Shoocks. Seems the bot has beaten you. Better luck next time." << endl;
			}
		}
		else if (lastSticks != sticks)
			botTurn = !botTurn;
	}
}

struct InfoStuff
{
	public:
		string strInfo;
		int intInfo;
		void printInfo()
		{
			string s = "My info contains \"" + strInfo + "\" and " + to_string(intInfo) + ". \n";
			cout << s;
		}
};

void loopCout(mutex* in_mutex)
{
	for (int i = 0; i < 10000; ++i)
	{
		Mutex_Guard guard(in_mutex);
		cout << "Current number is " << i << endl;
	}
}

int main()
{
	TicTacToe();
	//mutex mtx;
	//condition_variable cv;
	//unique_lock<mutex> lck(mtx);
	//mutex intMutex;
	//mutex coutLock;



	//int i = 0;
	//int numberOfTasksRunning = 0;

	//auto alambda = [&]()
	//{
	//	intMutex.lock();
	//	if (numberOfTasksRunning >= 8)
	//	{
	//		unique_lock<mutex> lck(mtx);
	//		--numberOfTasksRunning;
	//		intMutex.unlock();
	//		cv.notify_all();
	//	}
	//	else
	//	{
	//		--numberOfTasksRunning;
	//		intMutex.unlock();
	//	}

	//	coutLock.lock();
	//	cout << "Callback called. Value is: " << numberOfTasksRunning << endl;
	//	coutLock.unlock();
	//};

	//vector<Game_Task*> taskVektor;
	//for (int p = 0; p < 30; ++p)
	//{
	//	taskVektor.push_back(new CalculateTask());
	//}


	//for (auto gt : taskVektor)
	//{
	//	gt->callBack = alambda;
	//	gt->coutLock = &coutLock;
	//}


	//chrono::high_resolution_clock::time_point t1 = chrono::high_resolution_clock::now();

	////vector<thread> taskThreads;

	//mutex coutMutex;

	//thread first(loopCout, &coutMutex);
	//thread second(loopCout, &coutMutex);

	//first.join();
	//second.join();

	//while (true)
	//{
	//	if (i >= taskVektor.size())
	//		break;
	//	else if (numberOfTasksRunning >= 8)
	//	{
	//		coutLock.lock();
	//		cout << "number of tasks to many, waiting." << endl;
	//		coutLock.unlock();
	//		cv.wait(lck);
	//	}
	//	
	//	coutLock.lock();
	//	cout << "Continuing tasks." << endl;
	//	coutLock.unlock();
	//	taskThreads.push_back(thread(&Game_Task::perform, taskVektor[i]));
	//	//if (i >= taskVektor.size())
	//	//	break;
	//	//else
	//	//	taskThreads.push_back(thread(&Game_Task::perform, taskVektor[i]));
	//	intMutex.lock();
	//	++numberOfTasksRunning;
	//	intMutex.unlock();
	//	//taskVektor[i]->perform();
	//	++i;
	//	//coutLock.lock();
	//	//cout << numberOfTasksRunning << endl;
	//	//coutLock.unlock();

	//}

	//coutLock.lock();
	//cout << "Waiting for threads." << endl;
	//coutLock.unlock();
	//for (int k = 0; k < taskThreads.size(); ++k)
	//	taskThreads[k].join();

	////chrono::high_resolution_clock::time_point t2 = chrono::high_resolution_clock::now();

	////chrono::duration<double> time_span = chrono::duration_cast<chrono::duration<double>>(t2 - t1);

	//cout << "It took: " << time_span.count() << " seconds to complete all tasks." << endl;
	//DoVectorStuff();

	//run();
	int x;
	cin >> x;
	return 0;
}


void OldStuff()
{
	////Big_Data a(1024);
	////Big_Data b(1024);
	//////a = a;
	////a = b;
	//////Big_Data c(a);
	////a = Big_Data(1024);

	////Big_Data c(b);
	////Big_Data d(move(Big_Data(1024)));

	////DoStuff();

	////try
	////{
	////	Log_Ptr<int> p(new int(2), "myLogFile");
	////	Log_Ptr<int> o(new int(120), "myOtherLogFile");
	////	InfoStuff* info = new InfoStuff();
	////	Log_Ptr<InfoStuff> iptr(info, "infoLogFile");

	////	iptr->intInfo = *p + *o;
	////	iptr->strInfo = "My name Jeff.";
	////	iptr->printInfo();

	////	p.reset();

	////	cout << "This is a number " << *p << "." <<endl;
	////}
	////catch (exception e)
	////{
	////	cout << "Caught an exception of type: " << e.what() << endl;
	////}
}