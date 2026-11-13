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
	// STUB: name is not used yet. The spec passes it in but never says what it's for.
	// One option: if name is not empty, use it in the filename instead of "Log_".
	(void)name;	// Silences the "unused parameter" warning

	// Build the filename from the current date and time
	FileName();

	// Create a new file (ios::out starts a fresh file)
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

// Public Methods

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

	// Nothing else should be written after the summary
	bLogOpen = false;
}

// Returns whether the log file was opened successfully
bool Logger::IsLogOpen()
{
	return bLogOpen;
}

// ---------------------------------------------------------------
// Private Methods
// ---------------------------------------------------------------

// Gets the current date/time as a readable string and stores it in timeRightNow
// Example: 11/12/2026 05:30:45 PM
void Logger::Time()
{
	time_t now = time(nullptr);		// Raw current time
	tm localTime;
	localtime_s(&localTime, &now);	// Break it into fields (Microsoft version: tm first)

	stringstream ss;
	ss << put_time(&localTime, "%m/%d/%Y %I:%M:%S %p");
	timeRightNow = ss.str();
}

// Builds the log filename: Log_month_day_year_hhmmss.txt
// Example: Log_11_12_2026_173045.txt
// The time is included so two sessions on the same day don't overwrite each other.
// No / or : allowed, since Windows doesn't allow them in file names.
void Logger::FileName()
{
	time_t now = time(nullptr);
	tm localTime;
	localtime_s(&localTime, &now);

	stringstream ss;
	ss << put_time(&localTime, "%m_%d_%Y_%H%M%S");
	dateTimeStamp = ss.str();

	filename = "Log_" + dateTimeStamp + ".txt";
}