#include <string>
#include <time.h>
using namespace std;

#ifndef GOATSHEDINOUT_H
#define GOATSHEDINOUT_H

class GoatShedInOut
{
public:
	string goatShedID,goatID;
	time_t checkIn, checkOut;

	GoatShedInOut(string iogsID, string iogID, time_t iocheckin, time_t iocheckout)
	{
		goatShedID = iogsID;
		goatID = iogID;
		checkIn = iocheckin;
		checkOut = iocheckout;
	}

	GoatShedInOut()
	{
		goatShedID = "";
		goatID = "";
		checkIn = time(0);
		checkOut = time(0);
	}
};

#endif