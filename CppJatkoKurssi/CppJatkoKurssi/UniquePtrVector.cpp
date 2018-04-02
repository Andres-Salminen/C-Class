#pragma once
#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>
#include "UniquePtrVector.h"

using namespace std;

void printFunction(unique_ptr<int>& ptr)
{
	cout << "Value of ptr is: " << *ptr << endl;
}

void DoVectorStuff()
{
	vector<unique_ptr<int>> intVektor;
	unique_ptr<int> intPtr(new int(3));
	unique_ptr<int> intPtr2(new int(6));
	unique_ptr<int> intPtr3(new int(9));
	intVektor.push_back(move(intPtr));
	intVektor.push_back(move(intPtr2));
	intVektor.push_back(move(intPtr3));
	
	for_each(intVektor.begin(), intVektor.end(), printFunction);

	intVektor.pop_back();

	for_each(intVektor.begin(), intVektor.end(), printFunction);
}