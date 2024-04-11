#ifndef FRAME_H
#define FRAME_H

#include <wx/wx.h>
#include <functional>
#include <string>

#include "Utils.h"

struct wstringInterface {
	std::function<std::wstring()> getString;
	std::function<void(std::wstring)> setString;
};

extern wstringInterface primaryInterface;
extern wstringInterface secondaryInterface;

class CalculatorFrame: public wxFrame {

	public:
		CalculatorFrame();

	private:
		void ConfigSize();
		void ConfigSecondary(wxPanel *panel);
		void ConfigPrimary(wxPanel *panel);
		void ConfigKeyboard(wxPanel *panel);
		void SetupButton(wxWindow *parent, wxSizer *sizer, wxSize buttonSize, gui_utils::ButtonConfiguration configuration);
		void OnOperation(wxCommandEvent &event);
		void OnDestroy(wxWindowDestroyEvent &event);

};

#endif
