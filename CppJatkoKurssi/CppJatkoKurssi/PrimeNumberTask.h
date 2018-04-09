#pragma once
#include "Game_Task.h"
#include <iostream>

class PrimeNumberTask : public Game_Task {
public:
	int numberToCalculate;

	PrimeNumberTask(int number) : numberToCalculate {number} {}

	void perform() override {
		if (is_prime(numberToCalculate))
		{
			coutLock->lock();
			std::cout << "Number is prime." << std::endl;
			coutLock->unlock();
		}
		else
		{
			coutLock->lock();
			std::cout << "Number isnt prime." << std::endl;
			coutLock->unlock();
		}

		callBack();
	}

	bool is_prime(int x) {
		coutLock->lock();
		std::cout << "Calculating. Please, wait...\n";
		coutLock->unlock();
		for (int i = 2; i<x; ++i) if (x%i == 0) return false;
		return true;
	}
};