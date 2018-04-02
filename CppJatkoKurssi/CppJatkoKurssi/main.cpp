#pragma once
#include "Big_Data.h"
#include "VektorStuff.h"
//#include "NullPointerTeht.h"
//#include "AutoFor.h"
//#include "Inheritance.h"
//#include "Longaf.h"
//#include "MemoryExplosion.h"
//#include <time.h>
#include "Log_Ptr.cpp"
#include <string>
#include "UniquePtrVector.h"

using namespace std;

struct InfoStuff
{
	public:
		string strInfo;
		int intInfo;
		void printInfo()
		{
			string s = "My info contains \"" + strInfo + "\" and " + to_string(intInfo) + ". \n";
			cout << s;
		}
};

int main()
{
	//Big_Data a(1024);
	//Big_Data b(1024);
	////a = a;
	//a = b;
	////Big_Data c(a);
	//a = Big_Data(1024);

	//Big_Data c(b);
	//Big_Data d(move(Big_Data(1024)));

	//DoStuff();

	try
	{
		Log_Ptr<int> p(new int(2), "myLogFile");
		Log_Ptr<int> o(new int(120), "myOtherLogFile");
		InfoStuff* info = new InfoStuff();
		Log_Ptr<InfoStuff> iptr(info, "infoLogFile");

		iptr->intInfo = *p + *o;
		iptr->strInfo = "My name Jeff.";
		iptr->printInfo();

		p.reset();

		cout << "This is a number " << *p << "." <<endl;
	}
	catch (exception e)
	{
		cout << "Caught an exception of type: " << e.what() << endl;
	}

	//DoVectorStuff();

	//run();
	int x;
	cin >> x;
	return 0;
}