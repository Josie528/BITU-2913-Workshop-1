#include<iostream>
#include<string>
#include "TimeUtility.h"
#include "TimeUtility.cpp"
using namespace std;

#include <mysql/jdbc.h>
using namespace sql;

#include "DatabaseConnection.h"
#include "HealthHistory.h"
#include "GoatShed.h"
#include "MilkCollection.h"
#include "Staff.h"
#include "GoatBirth.h"
#include "Feed.h"
#include "FeedingRecord.h"
#include "GoatShedInOut.h"
#include "ClassManager.h"


//------------------------------------------
//       H E A L T H   H I S T O R Y
//------------------------------------------
int ClassManager::insert(HealthHistory* healthhistory)
{
	DatabaseConnection dbConn;
	PreparedStatement* ps = dbConn.prepareStatement("INSERT INTO HealthHistory VALUES (?, ?, ?, ?, ?, ?)");

	ps->setString(1, healthhistory->healthHistoryID);
	ps->setString(2, healthhistory->sickness);
	ps->setString(3, healthhistory->treatment);
	ps->setDateTime(4, TimeFunc.dateToString(healthhistory->dateOfRecord));
	ps->setString(5, healthhistory->symptom);
	ps->setString(6, healthhistory->goatID);

	int status = ps->executeUpdate();

	delete ps;
	return status;
}

//int ClassManager::delete(HealthHistory* healthhistory) 
//{

//}

//------------------------------------------
//           G O A T  S H E D
//------------------------------------------
int ClassManager::insert(GoatShed* goatshed)
{
	DatabaseConnection dbConn;
	PreparedStatement* ps = dbConn.prepareStatement("INSERT INTO GoatShed VALUES (?, ?, ?)");

	ps->setString(1, goatshed->goatShedID);
	ps->setString(2, goatshed->title);
	ps->setString(3, goatshed->description);

	int status = ps->executeUpdate();
	delete ps;
	return status;
}
//int ClassManager::update(GoatShed* goatshed)
//{

//}

//------------------------------------------
//       M I L K   C O L L E C T I O N
//------------------------------------------
int ClassManager::insert(MilkCollection* milkcollection)
{
	DatabaseConnection dbConn;
	PreparedStatement* ps = dbConn.prepareStatement("INSERT INTO MilkCollection VALUES (?, ?, ?, ?, ?)");

	ps->setString(1, milkcollection->goatID);
	ps->setString(2, milkcollection->staffID);
	ps->setString(3, milkcollection->goatShedID);
	ps->setDateTime(4, TimeFunc.dateToString(milkcollection->dateCollect));
	ps->setInt(5, milkcollection->quantity);

	int status = ps->executeUpdate();
	delete ps;
	return status;
}
//int ClassManager::update(MilkCollection* milkcollection)
//{

//}

//------------------------------------------
//                S T A F F
//------------------------------------------
int ClassManager::insert(Staff* staff)
{
	DatabaseConnection dbConn;
	PreparedStatement* ps = dbConn.prepareStatement("INSERT INTO Staff VALUES (?, ?, ?, ?, ?, ?, ?)");

	ps->setString(1, staff->staffID);
	ps->setString(2, staff->name);
	ps->setString(3, staff->staffType);
	ps->setString(4, staff->password);
	ps->setString(5, staff->gender);
	ps->setString(6, staff->telNo);

	int status = ps->executeUpdate();
	delete ps;
	return status;
}
int ClassManager::update(Staff* staff) 
{

}

 
//------------------------------------------
//           G O A T  B I R T H
//------------------------------------------
int ClassManager::insert(GoatBirth* goatbirth)
{
	DatabaseConnection dbConn;
	PreparedStatement* ps = dbConn.prepareStatement("INSERT INTO GoatBirth VALUES (?, ?, ?, ?, ?, ?)");

	ps->setString(1, goatbirth->goatID);
	ps->setString(2, goatbirth->goatType);
	ps->setString(3, goatbirth->goatGender);
	ps->setString(4, goatbirth->parentGoatID);
	ps->setString(5, goatbirth->healthStatus);
	ps->setDateTime(6, TimeFunc.dateToString(goatbirth->goatDOB));
	
	int status = ps->executeUpdate();
	delete ps;
	return status;
}
int ClassManager::update(GoatBirth* goatbirth) 
{

}

//------------------------------------------
//                F E E D
//------------------------------------------
int ClassManager::insert(Feed* feed)
{
	DatabaseConnection dbConn;
	PreparedStatement* ps = dbConn.prepareStatement("INSERT INTO Feed VALUES (?, ?, ?, ?, ?, ?, ?)");

	ps->setString(1, feed->feedID);
	ps->setString(2, feed->feedType);
	ps->setDouble(3, feed->calcium);
	ps->setDouble(4, feed->phosphorus);
	ps->setDouble(5, feed->potassium);
	ps->setDouble(6, feed->copper);
	ps->setDouble(7, feed->zinc);

	int status = ps->executeUpdate();
	delete ps;
	return status;
}
int ClassManager::update(Feed* feed)
{

}

//------------------------------------------
//       F E E D I N G   R E C O R D
//------------------------------------------
int ClassManager::insert(FeedingRecord* feedingrecord)
{
	DatabaseConnection dbConn;
	PreparedStatement* ps = dbConn.prepareStatement("INSERT INTO FeedingRecord VALUES (?, ?, ?, ?)");

	ps->setString(1, feedingrecord->goatID);
	ps->setString(2, feedingrecord->feedID);
	ps->setString(3, feedingrecord->staffID);
	ps->setDateTime(4, TimeFunc.datetimeToString(feedingrecord->feedingTime));
	ps->setInt(5, feedingrecord->quantity);
	
	int status = ps->executeUpdate();
	delete ps;
	return status;
}
int ClassManager::update(FeedingRecord* feedingrecord)
{

}

//------------------------------------------
//       G O A T S H E D  I N  O U T
//------------------------------------------
int ClassManager::insert(GoatShedInOut* goatshedinout)
{
	DatabaseConnection dbConn;
	PreparedStatement* ps = dbConn.prepareStatement("INSERT INTO GoatShedInOut VALUES (?, ?, ?, ?)");

	ps->setString(1, goatshedinout->goatShedID);
	ps->setString(2, goatshedinout->goatID);
	ps->setDateTime(3, TimeFunc.dateToString(goatshedinout->dateIn));
	ps->setDateTime(4, TimeFunc.dateToString(goatshedinout->dateOut));

	int status = ps->executeUpdate();
	delete ps;
	return status;
}
int ClassManager::update(GoatShedInOut* goatshedinout)
{

}
