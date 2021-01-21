#ifndef FANCYTEXT_H
#define FANCYTEXT_H

#include "TimeUtility.h"
#include "HealthHistory.h"
#include "GoatShed.h"
#include "MilkCollection.h"
#include "Staff.h"
#include "GoatBirth.h"
#include "Feed.h"
#include "FeedingRecord.h"
#include "GoatShedInOut.h"

#include <mysql/jdbc.h>
using namespace sql;

#include "DatabaseConnection.h"
class FancyText
{
public:
	void MainHeader();
	void GoatBirthHeader();
	void FeedHeader();
	void StaffHeader();
	void MilkCollectionHeader();
	void FeedingRecordHeader();
	void GoatShedHeader();
	void GoatShedInOutHeader();
	void HealthHistoryHeader();
};
#endif
