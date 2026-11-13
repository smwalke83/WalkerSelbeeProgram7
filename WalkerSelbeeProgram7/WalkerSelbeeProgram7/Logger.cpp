/*
	Scott Walker / Rikki Selbee
	swalker62@student.cnm.edu / RSelbee@student.cnm.edu
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


// Overloaded constructor (the default constructor delegates here with "")
Logger::Logger(string name)
{
	// TODO: Call FileName() to build the log filename

	// TODO: Open the file with ios::out (creates a new file)
	//       ofstream output(filename.c_str(), ios::out);

	// TODO: Set bLogOpen based on whether the file opened

	// TODO: Call Time(), then write timeRightNow as the first line

	// TODO: Close the stream
}


// Writes the opening lines of the log, including the starting balance
void Logger::StartLog(double initialBal)
{
	// TODO: Open with ios::app, write the starting info, close
}

// Writes an entry each time a game is completed
void Logger::WriteLog(string s)
{
	// TODO: Open with ios::app, call Time(), write timestamp + s, close
}

// Writes the end-of-session summary from Game::EndGame() and closes the file
void Logger::CloseLog(string s)
{
	// TODO: Open with ios::app, write s, close
}

// Returns whether the log file was opened successfully
bool Logger::IsLogOpen()
{
	return bLogOpen;
}

// ---------------------------------------------------------------
// Private Methods
// ---------------------------------------------------------------

// Gets the current date/time as a string and stores it in timeRightNow
void Logger::Time()
{
	// TODO: time_t now = time(nullptr);
	// TODO: tm localTime;  localtime_s(&localTime, &now);
	// TODO: stringstream + put_time(&localTime, "format") -> timeRightNow
}

// Builds the log filename: Log_<date/time>.txt
void Logger::FileName()
{
	// TODO: Same time steps as Time(), but use a format with no / or :
	//       Store the date/time part in dateTimeStamp
	//       filename = "Log_" + dateTimeStamp + ".txt";
}