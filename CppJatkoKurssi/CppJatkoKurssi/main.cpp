#pragma once
#include "GameTaskMain.h"
#include <iostream>
#include <string>
#include "Mutex_Guard.h"
#include "StickGameMain.h"
#include <fstream>
#include "CharmanderStates.h"
#include "PeliJutska.h"

using namespace std;

void Holyshitcopypastepls();
void CharmanderJutut();
void LetsdoTikkupeli();




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
	//RunGameTaskStuff();

	//DoVectorStuff();

	//Holyshitcopypastepls();
	//CharmanderJutut();
	LetsdoTikkupeli();

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

void Holyshitcopypastepls()
{
	fstream fileToCopyFrom;

	fileToCopyFrom.open("hallelujahICanCopy.txt", ios::out | ios::app);

	for (int i = 1; i < 25; ++i)
	{
		for (int k = 0; k < 40; ++k)
		{
			fileToCopyFrom << "screen_mem[" << i - 1 << "][" << k << "] = screen_mem[" << i << "][" << k << "];" << endl;
		}
	}
}

void CharmanderJutut()
{
	float position[] = { 0, 0, 0 };
	PokemonState* charmanderState = new Charmander();
	PokemonState* charmeleonState = new Charmeleon();
	PokemonState* charizardState = new Charizard();
	Pokemon charmander(charmanderState);
	charmander.Greet();
	charmander.Move(position);
	cout << "My position is now x: " << position[0] << " y: " << position[1] << " z: " << position[2] << "." << endl;
	charmander.Attack();
	charmander.ChangeState(charmeleonState);
	charmander.Greet();
	charmander.Move(position);
	cout << "My position is now x: " << position[0] << " y: " << position[1] << " z: " << position[2] << "." << endl;
	charmander.Attack();
	charmander.ChangeState(charizardState);
	charmander.Greet();
	charmander.Move(position);
	cout << "My position is now x: " << position[0] << " y: " << position[1] << " z: " << position[2] << "." << endl;
	charmander.Attack();

}

void LetsdoTikkupeli()
{
	Game* tikkuPeli = new TikkuPeli();
	tikkuPeli->playOneGame(2);
}