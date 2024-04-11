#ifndef UTILS_H
#define UTILS_H

#include <string>
#include <wx/wx.h>

namespace logger {

	void log(std::ostream &stream, std::string message, std::string level);

	void log(std::string message, std::string level);

	void info(std::ostream &stream, std::string message);

	void info(std::string message);

	void error(std::ostream &stream, std::string message);

	void error(std::string message);
}

namespace gui_utils {

	class ButtonConfiguration {

		private:
			int id;
			std::wstring text;
			int x, y;

		public:
			ButtonConfiguration(int id, std::wstring text, int x, int y);

			int getId();
			std::wstring getText();
			int getX();
			int getY();

	};

}

#endif
