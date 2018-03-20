#include "VektorStuff.h"
#include <algorithm>

void DoDamage(int& i);

class FunctionClass
{
public:
	void operator()(int& i)
	{
		i -= 100;
		if (i <= 0)
		{
			cout << "Enemy dead." << endl;
			i = 0;
		}
	}
};

void DoStuff()
{
	auto DamageFunc = [](int& i) { 	
		i -= 100;
		if (i <= 0)
		{
			cout << "Enemy dead." << endl;
			i = 0;
		}
	};//DoDamage;
	vector<int> intVektor = { 56, 112, 100, 9 };

	FunctionClass func;

	//for_each(intVektor.begin(), intVektor.end(), [](int& i) {
	//	i -= 100;
	//	if (i <= 0)
	//	{
	//		cout << "Enemy dead." << endl;
	//		i = 0;
	//	}});
	for_each(intVektor.begin(), intVektor.end(), func);
}

void DoDamage(int& i)
{
	i -= 100;
	if (i <= 0)
	{
		cout << "Enemy dead." << endl;
		i = 0;
	}
}