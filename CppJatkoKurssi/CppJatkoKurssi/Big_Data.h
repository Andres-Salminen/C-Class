#pragma once
#include <iostream>

class Big_Data
{
public:
	Big_Data(size_t size);
	Big_Data(const Big_Data& in);
	Big_Data(Big_Data&& in);
	~Big_Data();
	Big_Data& operator= (const Big_Data& rhs);
	Big_Data& operator= (Big_Data&& rhs);
private:
	void* allocatedMemory = nullptr;
	size_t sizeOfMemory = 0;
};