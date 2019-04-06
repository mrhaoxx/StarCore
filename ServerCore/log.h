#ifndef COLOR_PRInt_H
#define COLOR_PRInt_H
#include <iostream>
#include <String>
class log {
public:
	enum log_level
	{
		Debug,
		Info,
		Success,
		Warning,
		Error
	};
	/*
	Print logs with level
	Debug
	Info
	Success
	Warning
	Error
	*/
	static void print(log_level, const std::string &info, bool t = true);
	static bool iscolored;
};

#endif
