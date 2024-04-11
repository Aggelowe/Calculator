#include <string>
#include <sstream>

#include "Operations.h"
#include "Reference.h"
#include "Frame.h"
#include "Utils.h"

double prevOperator = 0;
int stage = 0;
std::function<double(double, double)> operation;

using namespace gui_settings::button_configuration;
using namespace std;

bool testNumber(int id, gui_utils::ButtonConfiguration configuration);
bool testOperation(int id, gui_utils::ButtonConfiguration configuration);
bool testEquals(int id, gui_utils::ButtonConfiguration configuration);

namespace operations {

	void onOperation(int id) {
		if (testNumber(id, BUTTON_NINE_CONFIGURATION)) {
		} else if (testNumber(id, BUTTON_EIGHT_CONFIGURATION)) {
		} else if (testNumber(id, BUTTON_SEVEN_CONFIGURATION)) {
		} else if (testNumber(id, BUTTON_SIX_CONFIGURATION)) {
		} else if (testNumber(id, BUTTON_FIVE_CONFIGURATION)) {
		} else if (testNumber(id, BUTTON_FOUR_CONFIGURATION)) {
		} else if (testNumber(id, BUTTON_THREE_CONFIGURATION)) {
		} else if (testNumber(id, BUTTON_TWO_CONFIGURATION)) {
		} else if (testNumber(id, BUTTON_ONE_CONFIGURATION)) {
		} else if (testNumber(id, BUTTON_ZERO_CONFIGURATION)) {
		} else if (testNumber(id, BUTTON_POINT_CONFIGURATION)) {
		} else if (testOperation(id, BUTTON_ADD_CONFIGURATION)) {
			operation = [](double operandA, double operandB) -> double {
				return operandA + operandB;
			};
		} else if (testOperation(id, BUTTON_SUBTRACT_CONFIGURATION)) {
			operation = [](double operandA, double operandB) -> double {
				return operandA - operandB;
			};
		} else if (testOperation(id, BUTTON_MULTIPLY_CONFIGURATION)) {
			operation = [](double operandA, double operandB) -> double {
				return operandA * operandB;
			};
		} else if (testOperation(id, BUTTON_DIVIDE_CONFIGURATION)) {
			operation = [](double operandA, double operandB) -> double {
				return operandA / operandB;
			};
		} else if (testEquals(id, BUTTON_EQUALS_CONFIGURATION)) {
		}
	}

}

bool testNumber(int id, gui_utils::ButtonConfiguration configuration) {
	if (id == configuration.getId()) {
		if (stage == 2) {
			stage = 0;
			primaryInterface.setString(L"");
		}
		wstring prev = primaryInterface.getString();
		wstringstream stream;
		stream << prev;
		stream << configuration.getText();
		wstring string = stream.str();
		primaryInterface.setString(string);
		return true;
	}
	return false;
}

bool testOperation(int id, gui_utils::ButtonConfiguration configuration) {
	if (id == configuration.getId()) {
		if (stage == 0) {
			wstringstream stream;
			wstring prev = primaryInterface.getString();
			stream << prev;
			double operand;
			stream >> operand;
			if (!stream.eof() || stream.fail()) {
				operand = 0;
			}
			prevOperator = operand;
			stream = wstringstream();
			stream << operand;
			stream << " ";
			stream << configuration.getText();
			stream << " ";
			secondaryInterface.setString(stream.str());
			primaryInterface.setString(L"");
			stage = 1;
		}
		return true;
	}
	return false;
}

bool testEquals(int id, gui_utils::ButtonConfiguration configuration) {
	if (id == configuration.getId()) {
		if (stage == 1) {
			wstringstream stream;
			wstring prev = primaryInterface.getString();
			stream << prev;
			double operand;
			stream >> operand;
			if (!stream.eof() || stream.fail()) {
				operand = 0;
			}
			double result = operation(prevOperator, operand);
			secondaryInterface.setString(L"");
			stream = wstringstream();
			stream << result;
			primaryInterface.setString(stream.str());
			stage = 2;
		}
		return true;
	}
	return false;
}
