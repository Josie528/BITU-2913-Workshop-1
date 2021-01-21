#ifndef SCREENCLASS_H
#define SCREENCLASS_H

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
class ScreenClass
{
public: 
	// Health History
	void InsertViewHealthHistory();
	void SearchViewHealthHistory();
	void UpdateViewHealthHistory();
	void DeleteViewHealthHistory();
	void ListViewHealthHistory();

	// Feed
	void InsertViewFeed();
	void SearchViewFeed(); 
	void UpdateViewFeed();
	void DeleteViewFeed();
	void ListViewFeed();

	// Goat Birth
	void InsertViewGoatBirth();
	void SearchViewGoatBirth();
	void UpdateViewGoatBirth();
	void DeleteViewGoatBirth();
	void ListViewGoatBirth();

	// Goat Shed
	void InsertViewGoatShed();
	void SearchViewGoatShed();
	void UpdateViewGoatShed();
	void DeleteViewGoatShed();
	void ListViewGoatShed();

	// Staff
	void InsertViewStaff();
	void SearchViewStaff();
	void UpdateViewStaff();
	void DeleteViewStaff();
	void ListViewStaff();

	// Milk Collection
	void InsertViewMilkCollection();
	void SearchViewMilkCollection(); 
	void UpdateViewMilkCollection(); 
	void DeleteViewMilkCollection(); 
	void ListViewMilkCollection();
	void ViewTotalMilkYield();
	void ViewTotalMilkYieldByMonth();

	// Goat Shed In Out
	void InsertViewGoatShedInOut();
	void SearchViewGoatShedInOut();
	void UpdateViewGoatShedInOut();
	void DeleteViewGoatShedInOut();
	void ListViewGoatShedInOut();

	// Feeding Record
	void InsertViewFeedingRecord();
	void SearchViewFeedingRecord();
	void UpdateViewFeedingRecord();
	void DeleteViewFeedingRecord();
	void ListViewFeedingRecord();
};
#endif
