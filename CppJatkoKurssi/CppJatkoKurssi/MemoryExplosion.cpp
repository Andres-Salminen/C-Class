#include "stdafx.h"
#include "MemoryExplosion.h"
#include <exception>

void run()
{
	std::vector<int*>* intVektor = new std::vector<int*>();

	while (true)
	{
		try
		{
			new int(0);
		}
		catch (std::exception& e)
		{
			std::cout << "Exception: " << e.what() << ".\n";
			break;
		}
	}

	int x;
	std::cin >> x;
}