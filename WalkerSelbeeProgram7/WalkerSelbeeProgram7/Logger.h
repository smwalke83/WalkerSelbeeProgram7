/*
	Scott Walker / Rikki Selbee
	swalker62@student.cnm.edu / RSelbee@student.cnm.edu
	CIST2275_72999
	WalkerSelbeeP7
	Logger.h
*/

// Guard
#ifndef LOGGER_H
#define LOGGER_H

// Libraries
#include <string>

// Namespaces
using namespace std;

// Class
class Logger
{
	public:
		// Constructors
		Logger() : Logger("") {}
		explicit Logger(string name);
	
		// Methods
		void StartLog(double initialBal);
		void WriteLog(string s);
		void CloseLog(string s);
		bool IsLogOpen();

	private:
		// Members
		bool bLogOpen { false };
		string filename;
		string timeRightNow;
		string dateTimeStamp;
		void Time();
		void FileName();
};

#endif
