#ifndef LOGGER_H
#define LOGGER_H

#include <string>

using namespace std;

public class Logger
{
public:
	Logger();
	Logger(string name);
	void StartLog(double initialBal);
	void WriteLog(string s);
	void CloseLog(string s);
	bool IsLogOpen();
private:
	string filename;
	bool bLogOpen;
	string timeRightNow;
	string dateTimeStamp;
	void Time();
	void FileName();
};

#endif
