#include <iostream>
#include <fstream>
#include <time.h>


using namespace std;

template < typename T > class Log_Ptr
{
private:
	T * pointerToData;
	fstream logFileStream;

public:
	Log_Ptr()
	{
		pointerToData = nullptr;
		logFileStream.open("asdNoName.txt", ios::out | ios::app);

		if (logFileStream.is_open())
		{
			time_t timeNow;

			time(&timeNow);
			char timeStr[100];
			ctime_s(timeStr, sizeof(timeStr), &timeNow);
			logFileStream << timeStr << "->    " << "Empty pointer class created. \n";
		}
		else
			throw std::invalid_argument("File could not be opened. Check the file name.");
	}

	Log_Ptr(const Log_Ptr& other) = delete;

	Log_Ptr(T** data, string fileName)
	{
		pointerToData = *data;
		data = 0;
		logFileStream.open(fileName + ".txt", ios::out | ios::app);

		if (logFileStream.is_open())
		{
			time_t timeNow;

			time(&timeNow);
			char timeStr[100];
			ctime_s(timeStr, sizeof(timeStr), &timeNow);
			logFileStream << timeStr << "->    " << "Object ownership transferred. \n";
		}
		else
			throw std::invalid_argument("File could not be opened. Check the file name.");
	}

	Log_Ptr(T* data, string fileName)
	{
		pointerToData = data;
		logFileStream.open(fileName + ".txt", ios::out | ios::app);

		if (logFileStream.is_open())
		{
			time_t timeNow;

			time(&timeNow);
			char timeStr[100];
			ctime_s(timeStr, sizeof(timeStr), &timeNow);
			logFileStream << timeStr << "->    " << "Object ownership transferred. \n";
		}
		else
			throw std::invalid_argument("File could not be opened. Check the file name.");
	}

	~Log_Ptr()
	{
		delete(pointerToData);
		time_t timeNow;

		time(&timeNow);
		char timeStr[100];
		ctime_s(timeStr, sizeof(timeStr), &timeNow);
		logFileStream << timeStr << "->    " << "Object destroyed. \n";
		logFileStream.close();
	}

	Log_Ptr<T>& operator= (const Log_Ptr<T>& other) = delete;

	T& operator* ()
	{
		time_t timeNow;

		time(&timeNow);
		char timeStr[100];
		ctime_s(timeStr, sizeof(timeStr), &timeNow);
		logFileStream << timeStr << "->    " << "Operator* used. \n";

		if (pointerToData == nullptr)
			throw std::invalid_argument("Pointer is a nullptr.");

		return *pointerToData;
	}

	T* operator-> ()
	{
		time_t timeNow;

		time(&timeNow);
		char timeStr[100];
		ctime_s(timeStr, sizeof(timeStr), &timeNow);
		logFileStream << timeStr << "->    " << "Operator-> used. \n";

		if (pointerToData == nullptr)
			throw std::invalid_argument("Pointer is a nullptr.");

		return pointerToData;
	}

	void reset(T* data)
	{
		if (pointerToData != nullptr)
		{
			delete(pointerToData);
			pointerToData = nullptr;
		}

		pointerToData = data;

		time_t timeNow;

		time(&timeNow);
		char timeStr[100];
		ctime_s(timeStr, sizeof(timeStr), &timeNow);
		logFileStream << timeStr << "->    " << "Object that we pointed to was destroyed. \n";
	}

	void reset()
	{
		if (pointerToData != nullptr)
		{
			delete(pointerToData);
			pointerToData = nullptr;
		}

		time_t timeNow;

		time(&timeNow);
		char timeStr[100];
		ctime_s(timeStr, sizeof(timeStr), &timeNow);
		logFileStream << timeStr << "->    " << "Object that we pointed to was destroyed. \n";
	}

};