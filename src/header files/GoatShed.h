#include <string>
using namespace std;

#ifndef GOATSHED_H
#define GOATSHED_H

class GoatShed
{
public:
	string goatShedID, title, description;

	GoatShed(string gsID, string gstitle, string gsdesc)
	{
		goatShedID = gsID;
		title = gstitle;
		description = gsdesc;
	}

	GoatShed()
	{
		goatShedID = "";
		title = "";
		description = "";
	}
};

#endif