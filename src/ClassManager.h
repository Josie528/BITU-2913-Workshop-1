#ifndef CLASSMANAGER_H
#define CLASSMANAGER_H

#include"TimeUtility.h"
#include"TimeUtility.cpp"
#include"GoatShed.h"
#include "MilkCollection.h"
#include "Staff.h"
#include "GoatBirth.h"
#include "Feed.h"
#include "FeedingRecord.h"
#include "GoatShedInOut.h"

//---- NOTE -----
// UPDATE int, time_t -> convert to string first
// DELETE -> primary key
// Create public variable for update func, and switch

class ClassManager
{
	private:
		TimeUtility TimeFunc;

	public:
		//Health History
		int insert(HealthHistory* healthhistory);
		void displayHealthHistory();

		//Goat Shed
		int insert(GoatShed*);
		//int delete(GoatShed*)
		void displayGoatShed();

		//Milk Collection
		int insert(MilkCollection*);
		void displayMilkCollection();

		//Staff
		int insert(Staff*);
		int update(Staff*);
		void displayStaff();

		//Goat Birth
		int insert(GoatBirth*);
		int update(GoatBirth*);
		void displayGoatBirth();

		//Feed
		int insert(Feed*);
		int update(Feed*);
		void displayFeed();

		//Feeding Record
		int insert(FeedingRecord*);
		int update(FeedingRecord*);
		void displayFeedingRecord();

		//Goat Shed In Out
		int insert(GoatShedInOut*);
		int update(GoatShedInOut*);
		void displayGoatShedInOut();
};
#endif