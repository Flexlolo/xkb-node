#include <iostream>
#include <iterator>
#include <string>
#include <stdio.h>
#include <sstream>
#include <unordered_map> 
#include <vector>

#include "docopt.cpp/docopt.h"

#include "XKeyboard.h"

static const char USAGE[] =
R"(Usage:
  xkb-node [options] [-]

Options:
  -h --help         Show this message.
  --version         Show version.
  -d, --default     Set default layout to all new windows
)";


using namespace std;

vector<string> string_split(string s)
{
	stringstream ss(s);
	istream_iterator<string> begin(ss);
	istream_iterator<string> end;

	return vector<string>(begin, end);
}

int main(int argc, char const *argv[])
{
	map<string, docopt::value> args = docopt::docopt(USAGE, 
													{ argv + 1, argv + argc },
													true,               // show help if requested
													"xkb-node v1.1");  // version string

	XKeyboard xkb;

	unordered_map<string, int> layouts;
	string window_last = "";

	for (string line; getline(cin, line);) 
	{
		vector<string> parts = string_split(line);

		if (parts[0] == "node_focus")
		{
			string window = parts[3];
			int layout = xkb.currentGroupNum();

			if (window_last.length())
			{
				layouts[window_last] = layout;
			}

			if (layouts.find(window) != layouts.end())
			{
				layout = layouts[window];
			}
			else if (args["--default"].asBool())
			{
				layout = 0;
			}

			xkb.setGroupByNum(layout);
			layouts[window] = layout;
			window_last = window;
		}
		else if (parts[0] == "node_remove")
		{
			string window = parts[3];

			if (layouts.find(window) != layouts.end())
			{
				layouts.erase(window);
			}
		}
	}

	return 0;
}