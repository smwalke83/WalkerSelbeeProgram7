/*
	Scott Walker / Rikki Selbee
	CIST2275_72999
	WalkerSelbeeP7
	Logger.cpp
*/

// Libraries
#include "Logger.h"
#include <fstream>
#include <sstream>
#include <iomanip>
#include <ctime>

// Namespaces
using namespace std;

// Constructors
Logger::Logger(string name)
{
	// I have no idea what the name attr is used for...
	(void)name;	// Silence the "unused parameter" warning

	FileName();

	// Create a new file
	ofstream output(filename.c_str(), ios::out);
	bLogOpen = output.is_open();

	// If the file opened, write the timestamp as the first line
	if (bLogOpen)
	{
		Time();
		output << "BlackJack Log - Created " << timeRightNow << endl;
		output.close();
	}
}

// Writes the opening lines of the log, including the starting balance
void Logger::StartLog(double initialBal)
{
	if (!bLogOpen) { return; }

	ofstream output(filename.c_str(), ios::app);
	Time();
	output << "Session started: " << timeRightNow << endl;
	output << "Starting balance: $" << fixed << setprecision(2) << initialBal << endl;
	output << "----------------------------------------" << endl;
	output.close();
}

// Writes an entry each time a hand is completed
void Logger::WriteLog(string s)
{
	if (!bLogOpen) { return; }

	ofstream output(filename.c_str(), ios::app);
	Time();
	output << timeRightNow << " - " << s << endl;
	output.close();
}

// Writes the end-of-session summary from Game::EndGame() and ends the log
void Logger::CloseLog(string s)
{
	if (!bLogOpen) { return; }

	ofstream output(filename.c_str(), ios::app);
	Time();
	output << "----------------------------------------" << endl;
	output << s << endl;
	output << "Session ended: " << timeRightNow << endl;
	output.close();

	bLogOpen = false;
}

// Returns whether the log file was opened successfully
bool Logger::IsLogOpen() { return bLogOpen; }

void Logger::Time()
{
	time_t now = time(nullptr);		// current time
	tm localTime;
	localtime_s(&localTime, &now);

	stringstream ss;
	ss << put_time(&localTime, "%m/%d/%Y %I:%M:%S %p");
	timeRightNow = ss.str();
}

// Build filename:
// Log_11_12_2026_173045.txt
void Logger::FileName()
{
	time_t now = time(nullptr); // https://en.cppreference.com/cpp/chrono/c/time_t
	tm localTime; // https://en.cppreference.com/cpp/chrono/c/tm
	localtime_s(&localTime, &now); // https://learn.microsoft.com/en-us/cpp/c-runtime-library/reference/localtime-s-localtime32-s-localtime64-s?view=msvc-170

	stringstream ss; // init stringstream
	ss << put_time(&localTime, "%m_%d_%Y_%H%M%S"); // https://en.cppreference.com/cpp/io/manip/put_time
	dateTimeStamp = ss.str(); 

	filename = "Log_" + dateTimeStamp + ".txt";
}