#ifndef MENUDISPLAY_H
#define MENUDISPLAY_H

#include <mysql/jdbc.h>
using namespace sql;

#include "DatabaseConnection.h"

class MenuDisplay
{
public:
	void GoatMenuPage(int staff_type);
	void FeedMenuPage(int staff_type);
	void FeedingRecordMenuPage(int staff_type);
	void HealthHistoryMenuPage(int staff_type);
	void MilkCollectionMenuPage(int staff_type);
	void StaffMenuPage(int staff_type);
	void GoatShedMenuPage(int staff_type);
	void GoatShedInOutMenuPage(int staff_type);

};
#endif