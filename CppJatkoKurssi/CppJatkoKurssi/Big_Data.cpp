#pragma once
#include "Big_Data.h"
#include <iostream>

using namespace std;

Big_Data::Big_Data(size_t size)
{
	allocatedMemory = malloc(size);
	sizeOfMemory = size;
	cout << "Allocated memory of size " << size << " bytes." << endl;
}

Big_Data::Big_Data(const Big_Data& in)
{
	allocatedMemory = malloc(in.sizeOfMemory);
	sizeOfMemory = in.sizeOfMemory;
	memcpy(allocatedMemory, in.allocatedMemory, in.sizeOfMemory);
	cout << "Copied from existing big data." << endl;
}

Big_Data::Big_Data(Big_Data&& in)
{
	allocatedMemory = in.allocatedMemory;
	sizeOfMemory = in.sizeOfMemory;
	in.allocatedMemory = nullptr;
	in.sizeOfMemory = 0;
	cout << "Stole rvalues stuff." << endl;
}

Big_Data::~Big_Data()
{
	cout << "Freeing memory of size " << sizeOfMemory << " bytes." << endl;
	free(allocatedMemory);
}

Big_Data& Big_Data::operator=(const Big_Data& rhs)
{
	free(allocatedMemory);
	allocatedMemory = malloc(rhs.sizeOfMemory);
	sizeOfMemory = rhs.sizeOfMemory;

	memcpy(allocatedMemory, rhs.allocatedMemory, sizeOfMemory);

	cout << "Sijoitusoperaattori.\n";

	return *this;
}

Big_Data& Big_Data::operator=(Big_Data&& rhs)
{
	cout << "Move sijoitusoperaattori\n";
	free(allocatedMemory);
	allocatedMemory = rhs.allocatedMemory;
	sizeOfMemory = rhs.sizeOfMemory;
	rhs.allocatedMemory = nullptr;

	return *this;
}