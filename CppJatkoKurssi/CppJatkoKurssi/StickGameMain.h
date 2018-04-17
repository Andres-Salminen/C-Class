//#pragma once
//#include <mutex>
//#include <thread>
//#include <chrono>
//#include <limits>
//#include <iostream>
//#include <future>
//#include "MinMaxAlgorithm.h"
//#include "Game_Task.h"
//#include "PrimeNumberTask.h"
//#include "CalculateTask.h"
//
//using namespace std;
//
//
//void DoStickGameStuff()
//{
//	mutex resultMapMutex;
//	int resultMap[60];
//
//	for (auto& i : resultMap)
//		i = numeric_limits<int>::min();
//
//	int sticks = 60;
//
//	bool botTurn = false;
//
//	while (sticks > 0)
//	{
//		int lastSticks = sticks;
//
//		int sticksTaken;
//
//		int numberOfThreads = 0;
//
//		if (!botTurn)
//		{
//			cout << "Your turn, current amount of sticks: " << sticks << ". Take 1 - 3 sticks please: ";
//
//			cin >> sticksTaken;
//
//			if (sticksTaken > 0 && sticksTaken < 4 && sticksTaken <= sticks)
//			{
//				sticks -= sticksTaken;
//			}
//			else
//				cout << "Invalid amount of sticks. Try again." << endl;
//
//		}
//		else
//		{
//			chrono::high_resolution_clock::time_point t1 = chrono::high_resolution_clock::now();
//
//			cout << "It's the bots turn to take sticks. Current amount of sticks: " << sticks << ". Please wait while the bot is calculating." << endl;
//
//
//			int result1, result2, result3;
//			result1 = result2 = result3 = numeric_limits<int>::min();
//
//			//if (sticks >= 3)
//			//	result1 = MinMax(sticks - 3, !botTurn);
//			//if (sticks >= 2)
//			//	result2 = MinMax(sticks - 2, !botTurn);
//			//if (sticks >= 1)
//			//	result3 = MinMax(sticks - 1, !botTurn);
//
//
//			future<int> futuResult1, futuResult2, futuResult3;
//			if (sticks >= 3)
//				futuResult1 = async(MinMax, sticks - 3, !botTurn, resultMap, &resultMapMutex);
//			if (sticks >= 2)
//				futuResult2 = async(MinMax, sticks - 2, !botTurn, resultMap, &resultMapMutex);
//			if (sticks >= 1)
//				futuResult3 = async(MinMax, sticks - 1, !botTurn, resultMap, &resultMapMutex);
//
//			if (futuResult1.valid())
//			{
//				result1 = futuResult1.get();
//				//cout << "Result gottered." << endl;
//			}
//			if (futuResult2.valid())
//				result2 = futuResult2.get();
//			if (futuResult3.valid())
//				result3 = futuResult3.get();
//
//			//cout << "Result1: " << result1 << " Result2: " << result2 << " Result3: " << result3 << endl;
//
//			if (result1 > result2 && result1 > result3)
//				sticksTaken = 3;
//			else if (result2 > result1 && result2 > result3)
//				sticksTaken = 2;
//			else
//				sticksTaken = 1;
//			cout << "The bot has choosen to take " << sticksTaken << " sticks." << endl;
//			sticks -= sticksTaken;
//
//
//			chrono::high_resolution_clock::time_point t2 = chrono::high_resolution_clock::now();
//
//			chrono::duration<double> time_span = chrono::duration_cast<chrono::duration<double>>(t2 - t1);
//
//			cout << "It took: " << time_span.count() << " seconds for the bot to calculate board state." << endl;
//		}
//
//		if (sticks <= 0)
//		{
//			if (botTurn)
//			{
//				cout << "Congratulations. Youve won the game." << endl;
//			}
//
//			else
//			{
//				cout << "Shoocks. Seems the bot has beaten you. Better luck next time." << endl;
//			}
//		}
//		else if (lastSticks != sticks)
//			botTurn = !botTurn;
//	}
//}