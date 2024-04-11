#include <string>
#include <functional>
#include <wx/wx.h>
#include <wx/statline.h>

#include "Frame.h"
#include "Reference.h"
#include "Utils.h"
#include "Operations.h"

using namespace std;
using namespace gui_settings;

wstringInterface primaryInterface;
wstringInterface secondaryInterface;

CalculatorFrame::CalculatorFrame() :
		wxFrame(nullptr, wxID_ANY, info::NAME) {
	ConfigSize();
	wxPanel *keyboardPanel = new wxPanel(this, wxID_ANY);
	wxBoxSizer *panelSizer = new wxBoxSizer(wxVERTICAL);
	wxPanel *secondaryPanel = new wxPanel(this, wxID_ANY);
	ConfigSecondary(secondaryPanel);
	wxPanel *primaryPanel = new wxPanel(this, wxID_ANY);
	ConfigPrimary(primaryPanel);
	int spacerHeight = GetClientSize().GetHeight() * (1.0 - gui_settings::KEYBOARD_PERCENT) - 7 * gui_settings::KEYBOARD_MARGIN;
	spacerHeight -= gui_settings::MAIN_MARGIN + secondaryPanel->GetSize().GetHeight();
	spacerHeight -= gui_settings::MAIN_MARGIN + primaryPanel->GetSize().GetHeight() + 2;
	panelSizer->AddSpacer(spacerHeight);
	panelSizer->Add(secondaryPanel, 0, wxEXPAND);
	panelSizer->AddSpacer(gui_settings::MAIN_MARGIN);
	panelSizer->Add(primaryPanel, 0, wxEXPAND);
	panelSizer->AddSpacer(gui_settings::MAIN_MARGIN);
	wxStaticLine *separator = new wxStaticLine(this, wxID_ANY);
	panelSizer->Add(separator, 0, wxEXPAND | wxTOP);
	panelSizer->AddSpacer(gui_settings::KEYBOARD_MARGIN);
	panelSizer->Add(keyboardPanel, 0, wxSHRINK);
	SetSizer(panelSizer);
	ConfigKeyboard(keyboardPanel);
	Connect(wxEVT_DESTROY, wxWindowDestroyEventHandler(CalculatorFrame::OnDestroy), nullptr, this);
	Center();
}

void CalculatorFrame::ConfigSecondary(wxPanel *panel) {
	wxBoxSizer *secondarySizer = new wxBoxSizer(wxHORIZONTAL);
	panel->SetSizer(secondarySizer);
	wxStaticText *secondaryLabel = new wxStaticText(panel, wxID_ANY, "");
	secondaryLabel->SetFont(secondaryLabel->GetFont().Scaled(gui_settings::SECONDARY_FONT_SCALE_FACTOR));
	secondarySizer->AddSpacer(gui_settings::MAIN_MARGIN);
	secondarySizer->Add(secondaryLabel);
	secondaryInterface.setString = [secondaryLabel](wstring string) {
		secondaryLabel->SetLabelText(string);
	};
	secondaryInterface.getString = [secondaryLabel]() -> wstring {
		return secondaryLabel->GetLabelText().ToStdWstring();
	};
}

void CalculatorFrame::ConfigPrimary(wxPanel *panel) {
	wxBoxSizer *primarySizer = new wxBoxSizer(wxHORIZONTAL);
	panel->SetSizer(primarySizer);
	wxStaticText *primaryLabel = new wxStaticText(panel, wxID_ANY, "");
	primaryLabel->SetFont(primaryLabel->GetFont().Scaled(gui_settings::PRIMARY_FONT_SCALE_FACTOR));
	primarySizer->AddSpacer(gui_settings::MAIN_MARGIN);
	primarySizer->Add(primaryLabel);
	primaryInterface.setString = [primaryLabel](wstring string) {
		primaryLabel->SetLabelText(string);
	};
	primaryInterface.getString = [primaryLabel]() -> wstring {
		return primaryLabel->GetLabelText().ToStdWstring();
	};
}

void CalculatorFrame::ConfigKeyboard(wxPanel *panel) {
	wxGridSizer *keyboardSizer = new wxGridSizer(gui_settings::KEYBOARD_GRID_ROWS, gui_settings::KEYBOARD_GRID_COLS, gui_settings::KEYBOARD_MARGIN, gui_settings::KEYBOARD_MARGIN);
	panel->SetSizer(keyboardSizer);
	int keyboardXSize = GetClientSize().GetWidth();
	int keyboardYSize = GetClientSize().GetHeight() * gui_settings::KEYBOARD_PERCENT;
	wxSize keyboardSize(keyboardXSize, keyboardYSize);
	int buttonXSize = keyboardXSize / gui_settings::KEYBOARD_GRID_COLS;
	int buttonXSizeLast = keyboardXSize - ((gui_settings::KEYBOARD_GRID_COLS - 1) * buttonXSize);
	int buttonYSize = keyboardYSize / gui_settings::KEYBOARD_GRID_ROWS;
	int buttonYSizeLast = keyboardYSize - ((gui_settings::KEYBOARD_GRID_ROWS - 1) * buttonYSize);
	wxSize buttonSize(buttonXSize, buttonYSize);
	wxSize buttonSizeRightEdge(buttonXSizeLast, buttonYSize);
	wxSize buttonSizeBottomEdge(buttonXSize, buttonYSizeLast);
	wxSize buttonSizeBottomRightCorner(buttonXSizeLast, buttonYSizeLast);
	SetupButton(panel, keyboardSizer, buttonSize, button_configuration::BUTTON_SEVEN_CONFIGURATION);
	SetupButton(panel, keyboardSizer, buttonSize, button_configuration::BUTTON_EIGHT_CONFIGURATION);
	SetupButton(panel, keyboardSizer, buttonSize, button_configuration::BUTTON_NINE_CONFIGURATION);
	SetupButton(panel, keyboardSizer, buttonSizeRightEdge, button_configuration::BUTTON_DIVIDE_CONFIGURATION);
	SetupButton(panel, keyboardSizer, buttonSize, button_configuration::BUTTON_FOUR_CONFIGURATION);
	SetupButton(panel, keyboardSizer, buttonSize, button_configuration::BUTTON_FIVE_CONFIGURATION);
	SetupButton(panel, keyboardSizer, buttonSize, button_configuration::BUTTON_SIX_CONFIGURATION);
	SetupButton(panel, keyboardSizer, buttonSizeRightEdge, button_configuration::BUTTON_MULTIPLY_CONFIGURATION);
	SetupButton(panel, keyboardSizer, buttonSize, button_configuration::BUTTON_ONE_CONFIGURATION);
	SetupButton(panel, keyboardSizer, buttonSize, button_configuration::BUTTON_TWO_CONFIGURATION);
	SetupButton(panel, keyboardSizer, buttonSize, button_configuration::BUTTON_THREE_CONFIGURATION);
	SetupButton(panel, keyboardSizer, buttonSizeRightEdge, button_configuration::BUTTON_SUBTRACT_CONFIGURATION);
	SetupButton(panel, keyboardSizer, buttonSizeBottomEdge, button_configuration::BUTTON_ZERO_CONFIGURATION);
	SetupButton(panel, keyboardSizer, buttonSizeBottomEdge, button_configuration::BUTTON_POINT_CONFIGURATION);
	SetupButton(panel, keyboardSizer, buttonSizeBottomEdge, button_configuration::BUTTON_EQUALS_CONFIGURATION);
	SetupButton(panel, keyboardSizer, buttonSizeBottomRightCorner, button_configuration::BUTTON_ADD_CONFIGURATION);
}

void CalculatorFrame::ConfigSize() {
	wxSize size = wxGetDisplaySize();
	size *= DISPLAY_PERCENT;
	size.SetWidth(size.GetHeight() * ASPECT_RATIO);
	SetClientSize(size);
	if (!RESIZABLE) {
		SetMinSize(size);
		SetMaxSize(size);
	}
}

void CalculatorFrame::SetupButton(wxWindow *parent, wxSizer *sizer, wxSize buttonSize, gui_utils::ButtonConfiguration configuration) {
	int buttonId = configuration.getId();
	wstring buttonText = configuration.getText();
	wxButton *button = new wxButton(parent, buttonId, buttonText);
	sizer->Add(button);
	button->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(CalculatorFrame::OnOperation), nullptr, this);
	wxSize size = buttonSize;
	size.DecBy((3.0 / 4.0) * gui_settings::KEYBOARD_MARGIN);
	button->SetMinSize(size);
	if (gui_settings::BUTTON_FONT_BOLD) {
		button->SetFont(button->GetFont().Bold());
	}
	button->SetFont(button->GetFont().Scaled(gui_settings::BUTTON_FONT_SCALE_FACTOR));
}

void CalculatorFrame::OnOperation(wxCommandEvent &event) {
	operations::onOperation(event.GetId());
}

void CalculatorFrame::OnDestroy(wxWindowDestroyEvent &event) {
	logger::info("Stopping Application...");
}
