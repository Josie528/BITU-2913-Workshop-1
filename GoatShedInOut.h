#include <string>
#include <time.h>
using namespace std;

#ifndef GOATSHEDINOUT_H
#define GOATSHEDINOUT_H

class GoatShedInOut
{
public:
	string goatShedID,goatID;
	time_t dateIn, dateOut;

	GoatShedInOut(string iogsID, string iogID, time_t iodatein, time_t iodateout)
	{
		goatShedID = iogsID;
		goatID = iogID;
		dateIn = iodatein;
		dateOut = iodateout;
	}

	GoatShedInOut()
	{
		goatShedID = "";
		goatID = "";
		dateIn = time(0);
		dateOut = time(0);
	}
};

#endif