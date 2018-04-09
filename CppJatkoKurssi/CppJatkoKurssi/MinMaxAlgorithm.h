#pragma once
#include <iostream>

using namespace std;

int MinMax(int sticks, bool isMyTurn)
{

	if (sticks == 0)
	{
		if (!isMyTurn)
			return -1;
		else
			return 1;
	}

	int result1, result2, result3;

	result1 = result2 = result3 = 0;

	if (sticks >= 3)
		result1 = MinMax(sticks - 3, !isMyTurn);

	if (sticks >= 2)
		result2 = MinMax(sticks - 2, !isMyTurn);

	if (sticks >= 1)
		result3 = MinMax(sticks - 1, !isMyTurn);

	int result = result1 + result2 + result3;

	//cout << ".";//"Result1: " << result1 << " Result2: " << result2 << " Result3: " << result3 << endl;

	return result;
}