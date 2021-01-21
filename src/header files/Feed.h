#include <string>
using namespace std;

#ifndef FEED_H
#define FEED_H

class Feed
{
public:
	string feedID, feedName, feedType;
	double calcium, phosphorus, potassium, copper, zinc;

	Feed(string fID, string fname, string ftype, double fcal, double fphos,
		double fpotassium, double fcu,double fzinc)
	{
		feedID = fID;
		feedName = fname;
		feedType = ftype;
		calcium = fcal;
		phosphorus = fphos;
		potassium = fpotassium;
		copper = fcu;
		zinc = fzinc;
	}

	Feed()
	{
		feedID = "";
		feedType = "";
		calcium = 0.0;
		phosphorus = 0.0;
		potassium = 0.0;
		copper = 0.0;
		zinc = 0.0;
	}
};

#endif