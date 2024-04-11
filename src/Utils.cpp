#include <ctime>
#include <iomanip>
#include <iostream>
#include <string>
#include <sstream>
#include <wx/wx.h>

#include "Reference.h"

using namespace std;
using namespace logger_config;

string currentTime() {
	time_t now = time(0);
	tm *time = localtime(&now);
	stringstream timeStream;
	timeStream << put_time(time, DATE_TIME_FORMAT.c_str());
	return timeStream.str();
}

namespace logger {

	void log(ostream &stream, string message, string level) {
		stringstream messageStream;
		messageStream << "[" << currentTime() << "] [" << level << "]: " << message << "\n";
		stream << messageStream.str();
	}

	void log(string message, string level) {
		ostream &stream = getLoggerDefaultStream();
		log(stream, message, level);
	}

	void info(ostream &stream, string message) {
		log(stream, message, "INFO");
	}

	void info(string message) {
		log(cout, message, "INFO");
	}

	void error(ostream &stream, string message) {
		log(stream, message, "ERROR");
	}

	void error(string message) {
		log(cerr, message, "ERROR");
	}

}

#include "Utils.h"

gui_utils::ButtonConfiguration::ButtonConfiguration(int id, wstring text, int x, int y) {
	this->id = id;
	this->text = text;
	this->x = x;
	this->y = y;
}

int gui_utils::ButtonConfiguration::getId() {
	return id;
}

wstring gui_utils::ButtonConfiguration::getText() {
	return text;
}

int gui_utils::ButtonConfiguration::getX() {
	return x;
}

int gui_utils::ButtonConfiguration::getY() {
	return y;
}

