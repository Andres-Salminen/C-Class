#pragma once
#include "stdafx.h"
#include "NullPointerTeht.h"

int run()
{
	foo();
	int* i = new int;
	*i = 2;
	foo(i);
	return 0;
}

void foo(int* i)
{
	if (i == nullptr)
		printf("No value given. \n");
	else
		printf("Value given: %i \n", *i);
	int x;
	cin >> x;
}