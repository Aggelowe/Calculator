#include <iostream>
#include <string>

using namespace std;

namespace info {

	string NAME = "Calculator";
	string VERSION = "v0.0.1";
	string AUTHOR = "Aggelowe";

}

namespace logger_config {

	string DATE_TIME_FORMAT = "%Y-%m-%d %H:%M:%S";
	string LOGGER_DEFAULT_LEVEL = "INFO";

	ostream& getLoggerDefaultStream() {
		return cout;
	}

}

#include "Utils.h"

using namespace gui_utils;

namespace gui_settings {

	float DISPLAY_PERCENT = 0.5;
	float ASPECT_RATIO = 0.8;
	bool RESIZABLE = false;
	float KEYBOARD_PERCENT = 0.5;
	int KEYBOARD_GRID_ROWS = 4;
	int KEYBOARD_GRID_COLS = 4;
	int KEYBOARD_MARGIN = 4;
	bool BUTTON_FONT_BOLD = true;
	float BUTTON_FONT_SCALE_FACTOR = 1.6;
	float SECONDARY_FONT_SCALE_FACTOR = 1.8;
	float PRIMARY_FONT_SCALE_FACTOR = 2.4;
	int MAIN_MARGIN = 8;

	namespace button_configuration {

		ButtonConfiguration BUTTON_ZERO_CONFIGURATION(0, L"0", 0, 3);
		ButtonConfiguration BUTTON_ONE_CONFIGURATION(1, L"1", 0, 2);
		ButtonConfiguration BUTTON_TWO_CONFIGURATION(2, L"2", 1, 2);
		ButtonConfiguration BUTTON_THREE_CONFIGURATION(3, L"3", 2, 2);
		ButtonConfiguration BUTTON_FOUR_CONFIGURATION(4, L"4", 0, 1);
		ButtonConfiguration BUTTON_FIVE_CONFIGURATION(5, L"5", 1, 1);
		ButtonConfiguration BUTTON_SIX_CONFIGURATION(6, L"6", 1, 2);
		ButtonConfiguration BUTTON_SEVEN_CONFIGURATION(7, L"7", 0, 0);
		ButtonConfiguration BUTTON_EIGHT_CONFIGURATION(8, L"8", 0, 1);
		ButtonConfiguration BUTTON_NINE_CONFIGURATION(9, L"9", 0, 2);
		ButtonConfiguration BUTTON_POINT_CONFIGURATION(10, L".", 1, 3);
		ButtonConfiguration BUTTON_ADD_CONFIGURATION(11, L"+", 3, 3);
		ButtonConfiguration BUTTON_SUBTRACT_CONFIGURATION(12, L"-", 3, 2);
		ButtonConfiguration BUTTON_MULTIPLY_CONFIGURATION(13, L"×", 3, 1);
		ButtonConfiguration BUTTON_DIVIDE_CONFIGURATION(14, L"÷", 3, 0);
		ButtonConfiguration BUTTON_EQUALS_CONFIGURATION(15, L"=", 2, 3);

	}

}

