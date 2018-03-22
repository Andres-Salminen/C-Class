#include "MemoryExplosion.h"
#include <exception>

void run()
{
	std::vector<int*>* intVektor = new std::vector<int*>();

	int howMany = 0;
	long int memory = 0;
	while (true)
	{
		try
		{
			new long long int(0);
			++howMany;
		}
		catch (std::exception& e)
		{
			std::cout << "Exception: " << e.what() << ".\n";
			break;
		}
	}
	memory = sizeof(long long int) * howMany;
	std::cout << "Amount of memory needed to go boom: " << memory << " bytes." << std::endl;

	int x;
	std::cin >> x;
}