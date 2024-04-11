#ifndef REFERENCE_H
#define REFERENCE_H

#include <iostream>
#include <string>

namespace info {

	extern const std::string NAME;
	extern const std::string VERSION;
	extern const std::string AUTHOR;

}

namespace logger_config {

	extern const std::string DATE_TIME_FORMAT;
	extern const std::string LOGGER_DEFAULT_LEVEL;

	std::ostream& getLoggerDefaultStream();

}

#include "Utils.h"

namespace gui_settings {

	extern const float DISPLAY_PERCENT;
	extern const float ASPECT_RATIO;
	extern const bool RESIZABLE;
	extern const float KEYBOARD_PERCENT;
	extern const int KEYBOARD_GRID_ROWS;
	extern const int KEYBOARD_GRID_COLS;
	extern const int KEYBOARD_MARGIN;
	extern const float BUTTON_FONT_SCALE_FACTOR;
	extern const bool BUTTON_FONT_BOLD;
	extern const float SECONDARY_FONT_SCALE_FACTOR;
	extern const float PRIMARY_FONT_SCALE_FACTOR;
	extern const int MAIN_MARGIN;

	namespace button_configuration {

		extern gui_utils::ButtonConfiguration BUTTON_ZERO_CONFIGURATION;
		extern gui_utils::ButtonConfiguration BUTTON_ONE_CONFIGURATION;
		extern gui_utils::ButtonConfiguration BUTTON_TWO_CONFIGURATION;
		extern gui_utils::ButtonConfiguration BUTTON_THREE_CONFIGURATION;
		extern gui_utils::ButtonConfiguration BUTTON_FOUR_CONFIGURATION;
		extern gui_utils::ButtonConfiguration BUTTON_FIVE_CONFIGURATION;
		extern gui_utils::ButtonConfiguration BUTTON_SIX_CONFIGURATION;
		extern gui_utils::ButtonConfiguration BUTTON_SEVEN_CONFIGURATION;
		extern gui_utils::ButtonConfiguration BUTTON_EIGHT_CONFIGURATION;
		extern gui_utils::ButtonConfiguration BUTTON_NINE_CONFIGURATION;
		extern gui_utils::ButtonConfiguration BUTTON_POINT_CONFIGURATION;
		extern gui_utils::ButtonConfiguration BUTTON_ADD_CONFIGURATION;
		extern gui_utils::ButtonConfiguration BUTTON_SUBTRACT_CONFIGURATION;
		extern gui_utils::ButtonConfiguration BUTTON_MULTIPLY_CONFIGURATION;
		extern gui_utils::ButtonConfiguration BUTTON_DIVIDE_CONFIGURATION;
		extern gui_utils::ButtonConfiguration BUTTON_EQUALS_CONFIGURATION;

	}
}

#endif
