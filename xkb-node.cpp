#include <iostream>
#include <iterator>
#include <string>
#include <stdio.h>
#include <sstream>
#include <unordered_map> 
#include <vector>

#include "XKeyboard.h"

using namespace std;

vector<string> string_split(string s)
{
	stringstream ss(s);
	istream_iterator<string> begin(ss);
	istream_iterator<string> end;

	return vector<string>(begin, end);
}

unordered_map<string, int> layouts;

int layout_window(string window)
{
	if (layouts.find(window) != layouts.end())
	{
		return layouts[window];
	}
	
	return 0;
}

void layout_window_erase(string window)
{
	if (layouts.find(window) != layouts.end())
	{
		layouts.erase(window);
	}
}

int main(int argc, char const *argv[])
{
	XKeyboard xkb;
	string window_last = "";

	for (string line; getline(cin, line);) 
	{
		vector<string> args = string_split(line);

		if (args[0] == "node_focus")
		{
			string window = args[3];
			if (window_last.length())
			{
				layouts[window_last] = xkb.currentGroupNum();
			}

			xkb.setGroupByNum(layout_window(window));
			window_last = window;
		}
		else if (args[0] == "node_remove")
		{
			string window = args[3];

			layout_window_erase(window);
		}
	}

	return 0;
}