#pragma once
#include "Game_Task.h"
#include <iostream>


class CalculateTask : public Game_Task {
public:
	void perform() override {
		for (int i = 0; i < 1000000; i++)
		{
			float k = i + i * i / 2 * i;
			float p = k * k / i * i * i + i - 6102;
		}

		callBack();
	}
};
