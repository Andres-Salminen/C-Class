#pragma once
#include <iostream>

using namespace std;

int MinMax(int sticks, bool isMyTurn, int* resultMap, mutex* mapMutex)
{

	if (sticks == 0)
	{
		if (!isMyTurn)
			return numeric_limits<int>::min();
		else
			return 1;
	}

	int result, result1, result2, result3;

	//cout << "Minmax called." << endl;

	result1 = result2 = result3 = 0;
	if (resultMap[sticks - 1] == numeric_limits<int>::min())
	{
		if (sticks >= 3)
		{
			mapMutex->lock();
			if (resultMap[sticks - 1 - 3] != numeric_limits<int>::min())
			{
				result1 = resultMap[sticks - 1 - 3];
				mapMutex->unlock();
			}
			else
			{
				mapMutex->unlock();
				result1 = MinMax(sticks - 3, !isMyTurn, resultMap, mapMutex);
				mapMutex->lock();
				resultMap[sticks - 1 - 3] = result1;
				mapMutex->unlock();
			}
		}

		if (sticks >= 2)
		{
			mapMutex->lock();
			if (resultMap[sticks - 1 - 2] != numeric_limits<int>::min())
			{
				result2 = resultMap[sticks - 1 - 2];
				mapMutex->unlock();
			}
			else
			{
				mapMutex->unlock();
				result2 = MinMax(sticks - 2, !isMyTurn, resultMap, mapMutex);
				mapMutex->lock();
				resultMap[sticks - 1 - 2] = result2;
				mapMutex->unlock();
			}
		}

		if (sticks >= 1)
		{
			mapMutex->lock();
			if (resultMap[sticks - 1 - 1] != numeric_limits<int>::min())
			{
				result3 = resultMap[sticks - 1 - 1];
				mapMutex->unlock();
			}
			else
			{
				mapMutex->unlock();
				result3 = MinMax(sticks - 1, !isMyTurn, resultMap, mapMutex);
				mapMutex->lock();
				resultMap[sticks - 1 - 1] = result3;
				mapMutex->unlock();
			}
		}

		result = result1 + result2 + result3;
		mapMutex->lock();
		resultMap[sticks - 1] = result;
		mapMutex->unlock();
	}
	else
	{
		mapMutex->lock();
		result = resultMap[sticks - 1];
		mapMutex->unlock();

		//cout << "Value was not min?" << endl;
	}

	//cout << "Result1: " << result1 << " Result2: " << result2 << " Result3: " << result3 << endl;

	return result;
}