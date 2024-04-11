#include <string>
#include <wx/wx.h>

#include "Calculator.h"
#include "Utils.h"
#include "Reference.h"
#include "Frame.h"

using namespace std;

wxIMPLEMENT_APP(Calculator);

bool Calculator::OnInit() {
	logger::info("Welcome to " + info::NAME + " " + info::VERSION + " by " + info::AUTHOR + "!");
	logger::info("Application starting up...");
	CalculatorFrame *frame = new CalculatorFrame();
	frame->Show(true);
	return true;
}
