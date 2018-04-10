#pragma once
#include "GameTaskMain.h"
#include <iostream>
#include <string>
#include "Mutex_Guard.h"
#include "StickGameMain.h"

using namespace std;



//struct InfoStuff
//{
//	public:
//		string strInfo;
//		int intInfo;
//		void printInfo()
//		{
//			string s = "My info contains \"" + strInfo + "\" and " + to_string(intInfo) + ". \n";
//			cout << s;
//		}
//};

void loopCout(mutex* in_mutex)
{
	// TEHTÄVÄ 3 ---------------------

	for (int i = 0; i < 10000; ++i)
	{
		Mutex_Guard guard(in_mutex);
		cout << "Current number is " << i << endl;
	}
}

int main()
{
	//TEHTÄVÄ 4 --------------------------------------------------------
	//StickGame();


	// TEHTÄVÄ 1 -------------------------------------------------------
	RunGameTaskStuff();

	//DoVectorStuff();

	//run();
	int x;
	cin >> x;
	return 0;
}


void OldStuff()
{
	////Big_Data a(1024);
	////Big_Data b(1024);
	//////a = a;
	////a = b;
	//////Big_Data c(a);
	////a = Big_Data(1024);

	////Big_Data c(b);
	////Big_Data d(move(Big_Data(1024)));

	////DoStuff();

	////try
	////{
	////	Log_Ptr<int> p(new int(2), "myLogFile");
	////	Log_Ptr<int> o(new int(120), "myOtherLogFile");
	////	InfoStuff* info = new InfoStuff();
	////	Log_Ptr<InfoStuff> iptr(info, "infoLogFile");

	////	iptr->intInfo = *p + *o;
	////	iptr->strInfo = "My name Jeff.";
	////	iptr->printInfo();

	////	p.reset();

	////	cout << "This is a number " << *p << "." <<endl;
	////}
	////catch (exception e)
	////{
	////	cout << "Caught an exception of type: " << e.what() << endl;
	////}
}