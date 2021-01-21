#include<iostream>
#include<string>
#include<ctime>
#include <iomanip>
#include "TimeUtility.h"
#include "ClassManager.h"
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

/*******************************************/
/*                 F E E D                 */
/*******************************************/
int ClassManager::insert(Feed* feed)
{
	DatabaseConnection dbConn;
	PreparedStatement* ps = dbConn.prepareStatement("INSERT INTO Feed VALUES (?, ?, ?, ?, ?, ?, ?, ?)");

	ps->setString(1, feed->feedID);
	ps->setString(2, feed->feedName);
	ps->setString(3, feed->feedType);
	ps->setDouble(4, feed->calcium);
	ps->setDouble(5, feed->phosphorus);
	ps->setDouble(6, feed->potassium);
	ps->setDouble(7, feed->copper);
	ps->setDouble(8, feed->zinc);

	int status = ps->executeUpdate();
	delete ps;
	return status;
}
ResultSet* ClassManager::search(Feed* feed)
{
	DatabaseConnection dbConn;
	PreparedStatement* ps = dbConn.prepareStatement
	("SELECT * FROM Feed WHERE FeedID = ?");
	ps->setString(1, feed->feedID);

	ResultSet* rs = ps->executeQuery();

	delete ps;
	return rs;
}
ResultSet* ClassManager::searchByType(Feed* feed)
{
	DatabaseConnection dbConn;
	PreparedStatement* ps = dbConn.prepareStatement
	("SELECT * FROM Feed WHERE FeedType = ?");
	ps->setString(1, feed->feedType);

	ResultSet* rs = ps->executeQuery();

	delete ps;
	return rs;
}
ResultSet* ClassManager::searchByName(Feed* feed)
{
	DatabaseConnection dbConn;
	PreparedStatement* ps = dbConn.prepareStatement
	("SELECT * FROM Feed WHERE FeedName LIKE ?");
	ps->setString(1, ("%" + feed->feedName + "%"));

	ResultSet* rs = ps->executeQuery();

	delete ps;
	return rs;
}
ResultSet* ClassManager::listOfFeed()
{
	DatabaseConnection dbConn;
	PreparedStatement* ps = dbConn.prepareStatement
	("SELECT * FROM Feed");
	ResultSet* rs = ps->executeQuery();

	delete ps;
	return rs;
}
int ClassManager::update(Feed* feed)
{
	DatabaseConnection dbConn;
	PreparedStatement* ps = dbConn.prepareStatement
	("UPDATE Feed SET FeedName = ?, FeedType = ?, Calcium = ?, Phosphorus = ?, Potassium = ?, Copper = ?, Zinc = ? WHERE FeedID = ?");
	//Uneditable: FeedID
	ps->setString(1, feed->feedName);
	ps->setString(2, feed->feedType);
	ps->setDouble(3, feed->calcium);
	ps->setDouble(4, feed->phosphorus);
	ps->setDouble(5, feed->potassium);
	ps->setDouble(6, feed->copper);
	ps->setDouble(7, feed->zinc);
	ps->setString(8, feed->feedID);

	int status = ps->executeUpdate();

	delete ps;
	return status;
}
bool ClassManager::delRecord(Feed* feed)
{
	DatabaseConnection dbConn;
	PreparedStatement* ps = dbConn.prepareStatement
	("DELETE FROM Feed WHERE FeedID = ?");
	ps->setString(1, feed->feedID);
	bool status = ps->execute();

	delete ps;
	return status;
}


//------------------------------------------
//       F E E D I N G   R E C O R D
//------------------------------------------
int ClassManager::insert(FeedingRecord* feedingrecord)
{
	DatabaseConnection dbConn;
	PreparedStatement* ps = dbConn.prepareStatement("INSERT INTO FeedingRecord VALUES (?, ?, ?, ?, ?)");

	ps->setString(1, feedingrecord->goatID);
	ps->setString(2, feedingrecord->feedID);
	ps->setString(3, feedingrecord->staffID);
	ps->setDouble(4, feedingrecord->quantity);
	ps->setDateTime(5, timefunc.datetimeToString(feedingrecord->feedingTime));


	int status = ps->executeUpdate();
	delete ps;
	return status;
}
ResultSet* ClassManager::search(FeedingRecord* feedingrecord)
{
	DatabaseConnection dbConn;
	PreparedStatement* ps = dbConn.prepareStatement
	("SELECT * FROM FeedingRecord WHERE GoatID = ? AND FeedingTime = ?");
	ps->setString(1, feedingrecord->goatID);
	ps->setDateTime(2, timefunc.datetimeToString(feedingrecord->feedingTime));

	ResultSet* rs = ps->executeQuery();

	delete ps;
	return rs;
}
ResultSet* ClassManager::searchByGoatID(FeedingRecord* feedingrecord)
{
	DatabaseConnection dbConn;
	PreparedStatement* ps = dbConn.prepareStatement
	("SELECT * FROM FeedingRecord WHERE GoatID = ?");
	ps->setString(1, feedingrecord->goatID);

	ResultSet* rs = ps->executeQuery();

	delete ps;
	return rs;
}
ResultSet* ClassManager::searchByStaffID(FeedingRecord* feedingrecord)
{
	DatabaseConnection dbConn;
	PreparedStatement* ps = dbConn.prepareStatement
	("SELECT * FROM FeedingRecord WHERE StaffID = ?");
	ps->setString(1, feedingrecord->staffID);

	ResultSet* rs = ps->executeQuery();

	delete ps;
	return rs;
}
ResultSet* ClassManager::listOfFeedingRecord()
{
	DatabaseConnection dbConn;
	PreparedStatement* ps = dbConn.prepareStatement
	("SELECT * FROM FeedingRecord");
	ResultSet* rs = ps->executeQuery();

	delete ps;
	return rs;
}
int ClassManager::update(FeedingRecord* feedingrecord)
{
	DatabaseConnection dbConn;
	PreparedStatement* ps = dbConn.prepareStatement
	("UPDATE FeedingRecord SET FeedID = ?, Staff ID = ?, Quantity = ? WHERE GoatID = ? AND FeedingTime = ?");
	//Uneditable: GoatID, FeedingTime
	ps->setString(1, feedingrecord->feedID);
	ps->setString(2, feedingrecord->staffID);
	ps->setDouble(3, feedingrecord->quantity);
	ps->setString(4, feedingrecord->goatID);
	ps->setDateTime(5, timefunc.datetimeToString(feedingrecord->feedingTime));


	int status = ps->executeUpdate();

	delete ps;
	return status;
}
bool ClassManager::delRecord(FeedingRecord* feedingrecord)
{
	DatabaseConnection dbConn;
	PreparedStatement* ps = dbConn.prepareStatement
	("DELETE FROM Feed WHERE GoatID = ? AND FeedingTime = ?");
	ps->setString(1, feedingrecord->goatID);
	ps->setDateTime(2, timefunc.datetimeToString(feedingrecord->feedingTime));
	bool status = ps->execute();

	delete ps;
	return status;
}


//------------------------------------------
//           G O A T  B I R T H
//------------------------------------------
int ClassManager::insert(GoatBirth* goatbirth)
{
	DatabaseConnection dbConn;
	PreparedStatement* ps = dbConn.prepareStatement("INSERT INTO GoatBirth VALUES (?, ?, ?, ?, ?, ?)");

	ps->setString(1, goatbirth->goatID);
	ps->setString(2, goatbirth->goatBreed);
	ps->setString(3, goatbirth->goatGender);
	ps->setString(4, goatbirth->parentGoatID);
	ps->setString(5, goatbirth->healthStatus);
	ps->setDateTime(6, timefunc.dateToString(goatbirth->goatDOB));

	int status = ps->executeUpdate();
	delete ps;
	return status;
}
ResultSet* ClassManager::search(GoatBirth* goatbirth)
{
	DatabaseConnection dbConn;
	PreparedStatement* ps = dbConn.prepareStatement
	("SELECT * FROM GoatBirth WHERE GoatID = ?");
	ps->setString(1, goatbirth->goatID);

	ResultSet* rs = ps->executeQuery();

	delete ps;
	return rs;
}
ResultSet* ClassManager::searchBySickGoat(GoatBirth* goatbirth)
{
	DatabaseConnection dbConn;
	PreparedStatement* ps = dbConn.prepareStatement
	("SELECT * FROM GoatBirth WHERE HealthStatus = 'Sick'");

	ResultSet* rs = ps->executeQuery();

	delete ps;
	return rs;
}
ResultSet* ClassManager::searchByGoatBreed(GoatBirth* goatbirth)
{
	DatabaseConnection dbConn;
	PreparedStatement* ps = dbConn.prepareStatement
	("SELECT * FROM GoatBirth WHERE GoatBreed = ?");
	ps->setString(1, goatbirth->goatBreed);

	ResultSet* rs = ps->executeQuery();

	delete ps;
	return rs;
}
ResultSet* ClassManager::listOfGoatBirth()
{
	DatabaseConnection dbConn;
	PreparedStatement* ps = dbConn.prepareStatement
	("SELECT * FROM GoatBirth");
	ResultSet* rs = ps->executeQuery();

	delete ps;
	return rs;
}
int ClassManager::update(GoatBirth* goatbirth)
{
	DatabaseConnection dbConn;
	PreparedStatement* ps = dbConn.prepareStatement
	("UPDATE MilkCollection SET GoatBreed = ?, GoatGender = ?, HealthStatus = ? WHERE goatID = ?");
	//Uneditable: GoatID, ParentGoatID, GoatDOB
	ps->setString(1, goatbirth->goatBreed);
	ps->setString(2, goatbirth->goatGender);
	ps->setString(3, goatbirth->healthStatus);
	ps->setString(4, goatbirth->goatID);

	int status = ps->executeUpdate();

	delete ps;
	return status;
}
bool ClassManager::delRecord(GoatBirth* goatbirth)
{
	DatabaseConnection dbConn;
	PreparedStatement* ps = dbConn.prepareStatement
	("DELETE FROM GoatBirth WHERE GoatID = ?");
	ps->setString(1, goatbirth->goatID);
	bool status = ps->execute();

	delete ps;
	return status;
}
bool ClassManager::delDeadGoat(GoatBirth* goatbirth)
{
	DatabaseConnection dbConn;
	PreparedStatement* ps = dbConn.prepareStatement
	("DELETE FROM GoatBirth WHERE HealthStatus = 'Die'");
	bool status = ps->execute();

	delete ps;
	return status;
}

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
ResultSet* ClassManager::searchByID(GoatShed* goatshed)
{
	DatabaseConnection dbConn;
	PreparedStatement* ps = dbConn.prepareStatement
	("SELECT * FROM GoatShed WHERE GoatShedID = ?");
	ps->setString(1, goatshed->goatShedID);
	
	ResultSet* rs = ps->executeQuery();

	delete ps;
	return rs;
}
ResultSet* ClassManager::searchByName(GoatShed* goatshed)
{
	DatabaseConnection dbConn;
	PreparedStatement* ps = dbConn.prepareStatement
	("SELECT * FROM GoatShed WHERE Title = ?");
	ps->setString(1, goatshed->title);

	ResultSet* rs = ps->executeQuery();

	delete ps;
	return rs;
}
ResultSet* ClassManager::listOfGoatShed()
{
	DatabaseConnection dbConn;
	PreparedStatement* ps = dbConn.prepareStatement
	("SELECT * FROM GoatShed");
	ResultSet* rs = ps->executeQuery();

	delete ps;
	return rs;
} 
int ClassManager::update(GoatShed* goatshed)
{
	string title;
	cout << "Edit Title: " << endl;
	getline(cin, title);
	DatabaseConnection dbConn;
	PreparedStatement* ps = dbConn.prepareStatement
	("UPDATE HealthHistory SET Title = ?, Description = ? WHERE GoatShedID = ?");
	//Uneditable: GoatShedID
	ps->setString(3, goatshed->goatShedID);
	ps->setString(1, goatshed->title);
	ps->setString(2, goatshed->description);

	int status = ps->executeUpdate();

	delete ps;
	return status;
}
bool ClassManager::delRecord(GoatShed* goatshed) //delByTitle
{
	DatabaseConnection dbConn;
	PreparedStatement* ps = dbConn.prepareStatement
	("DELETE FROM GoatShed WHERE Title = ?");
	ps->setString(1, goatshed->title);

	bool status = ps->execute();

	delete ps;
	return status;
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
	ps->setDateTime(3, timefunc.dateToString(goatshedinout->checkIn));
	ps->setDateTime(4, timefunc.dateToString(goatshedinout->checkOut));

	int status = ps->executeUpdate();
	delete ps;
	return status;
}
ResultSet* ClassManager::search(GoatShedInOut* goatshedinout)
{
	DatabaseConnection dbConn;
	PreparedStatement* ps = dbConn.prepareStatement
	("SELECT * FROM GoatShedInOut WHERE GoatID = ? AND CheckIn = ?");
	ps->setString(1, goatshedinout->goatID);
	ps->setDateTime(2, timefunc.dateToString(goatshedinout->checkIn));

	ResultSet* rs = ps->executeQuery();

	delete ps;
	return rs;
}
ResultSet* ClassManager::listOfGoatShedInOut()
{
	DatabaseConnection dbConn;
	PreparedStatement* ps = dbConn.prepareStatement
	("SELECT * FROM GoatShedInOut");
	ResultSet* rs = ps->executeQuery();

	delete ps;
	return rs;
}
int ClassManager::update(GoatShedInOut* goatshedinout)
{
	DatabaseConnection dbConn;
	PreparedStatement* ps = dbConn.prepareStatement
	("UPDATE GoatShedInOut SET checkOut = ? WHERE GoatID = ? AND checkIn = ?");
	//Uneditable: GoatID, checkIn, GoatShedID
	ps->setDateTime(1, timefunc.dateToString(goatshedinout->checkOut));
	ps->setString(2, goatshedinout->goatID);
	ps->setDateTime(3, timefunc.dateToString(goatshedinout->checkIn));

	int status = ps->executeUpdate();

	delete ps;
	return status;
}
bool ClassManager::delRecord(GoatShedInOut* goatshedinout)
{
	DatabaseConnection dbConn;
	PreparedStatement* ps = dbConn.prepareStatement
	("DELETE FROM Feed WHERE GoatID = ? AND checkIn = ?");
	ps->setString(1, goatshedinout->goatID);
	ps->setDateTime(2, timefunc.dateToString(goatshedinout->checkIn));
	bool status = ps->execute();

	delete ps;
	return status;
}


//------------------------------------------
//       H E A L T H   H I S T O R Y
//------------------------------------------ 
int ClassManager::insert(HealthHistory* healthhistory)
{
	DatabaseConnection dbConn;
	PreparedStatement* ps = dbConn.prepareStatement("INSERT INTO HealthHistory VALUES (?, ?, ?, ?, ?, ?)");

	ps->setString(1, healthhistory->healthHistoryID);
	ps->setString(2, healthhistory->goatID);
	ps->setString(3, healthhistory->sickness);
	ps->setString(4, healthhistory->symptom);
	ps->setString(5, healthhistory->treatment);
	ps->setDateTime(6, timefunc.dateToString(healthhistory->dateOfRecord));


	int status = ps->executeUpdate();

	delete ps;
	return status;
}
ResultSet* ClassManager::listOfHealthHistory()
{
	DatabaseConnection dbConn;
	PreparedStatement* ps = dbConn.prepareStatement
	("SELECT * FROM HealthHistory");
	ResultSet* rs = ps->executeQuery();

	delete ps;
	return rs;
}
ResultSet* ClassManager::search(HealthHistory* healthhistory)
{
	DatabaseConnection dbConn;
	PreparedStatement* ps = dbConn.prepareStatement
	("SELECT * FROM HealthHistory WHERE HealthHistoryID = ?");
	ps->setString(1, healthhistory->healthHistoryID);

	ResultSet* rs = ps->executeQuery();

	delete ps;
	return rs;
}
int ClassManager::update(HealthHistory* healthhistory)
{
	DatabaseConnection dbConn;
	PreparedStatement* ps = dbConn.prepareStatement
	("UPDATE HealthHistory SET Sickness = ?, Symptom = ?,Treatment = ?, DateOfRecord = ? WHERE HealthHistoryID = ?");
	//Uneditable: GoatID, HealthHistoryID
	ps->setString(1, healthhistory->sickness);
	ps->setString(2, healthhistory->symptom);
	ps->setString(3, healthhistory->treatment);
	ps->setDateTime(4, timefunc.dateToString(healthhistory->dateOfRecord));
	ps->setString(5, healthhistory->healthHistoryID);


	int status = ps->executeUpdate();

	delete ps;
	return status;
}
bool ClassManager::delRecord(HealthHistory* healthhistory)
{
	DatabaseConnection dbConn;
	PreparedStatement* ps = dbConn.prepareStatement
	("DELETE FROM HealthHistory WHERE HealthHistoryID = ?");
	ps->setString(1, healthhistory->healthHistoryID);

	bool status = ps->execute();

	delete ps;
	return status;
}


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
	ps->setDateTime(4, timefunc.dateToString(milkcollection->dateCollect));
	ps->setDouble(5, milkcollection->quantity);

	int status = ps->executeUpdate();
	delete ps;
	return status;
}
ResultSet* ClassManager::search(MilkCollection* milkcollection)
{
	DatabaseConnection dbConn;
	PreparedStatement* ps = dbConn.prepareStatement
	("SELECT * FROM MilkCollection WHERE GoatID = ? AND DateCollect = ?");
	ps->setString(1, milkcollection->goatID);
	ps->setDateTime(2, timefunc.dateToString(milkcollection->dateCollect));
	ResultSet* rs = ps->executeQuery();

	delete ps;
	return rs;
}
ResultSet* ClassManager::listOfMilkCollection()
{
	DatabaseConnection dbConn;
	PreparedStatement* ps = dbConn.prepareStatement
	("SELECT * FROM MilkCollection");
	ResultSet* rs = ps->executeQuery();

	delete ps;
	return rs;
}
int ClassManager::update(MilkCollection* milkcollection)
{
	DatabaseConnection dbConn;
	PreparedStatement* ps = dbConn.prepareStatement
	("UPDATE MilkCollection SET Quantity = ? WHERE GoatID = ? AND DateCollect = ?");
	//Uneditable: GoatID, DateCollect, StaffID, GoatShedID
	ps->setString(1, milkcollection->goatID);
	ps->setDateTime(4, timefunc.dateToString(milkcollection->dateCollect));
	ps->setDouble(5, milkcollection->quantity);

	int status = ps->executeUpdate();

	delete ps;
	return status; 
}
bool ClassManager::delRecord(MilkCollection* milkcollection)
{
	DatabaseConnection dbConn;
	PreparedStatement* ps = dbConn.prepareStatement
	("DELETE FROM MilkCollection WHERE GoatID = ?,DateCollect = ?");
	ps->setString(1, milkcollection->goatID);
	ps->setDateTime(2, timefunc.dateToString(milkcollection->dateCollect));
	bool status = ps->execute();

	delete ps;
	return status;
}
ResultSet* ClassManager::totalMilkYield(MilkCollection* milkcollection)
{
	DatabaseConnection dbConn;
	PreparedStatement* ps = dbConn.prepareStatement
	("SELECT goatShedID, SUM(quantity) FROM MilkCollection GROUP BY goatShedID");
	ResultSet* rs = ps->executeQuery();

	delete ps;
	return rs;
}
ResultSet* ClassManager::totalMilkYieldByMonth(MilkCollection* milkcollection)
{
	DatabaseConnection dbConn;
	PreparedStatement* ps = dbConn.prepareStatement
	("SELECT MONTHNAME(dateCollect), SUM(quantity) FROM milkcollection GROUP BY MONTHNAME(dateCollect) ORDER BY dateCollect");
	ResultSet* rs = ps->executeQuery();

	delete ps;
	return rs;
}


//------------------------------------------
//                S T A F F
//------------------------------------------
int ClassManager::insert(Staff* staff)
{
	DatabaseConnection dbConn;
	PreparedStatement* ps = dbConn.prepareStatement("INSERT INTO Staff VALUES (?, ?, ?, ?, ?, ?)");

	ps->setString(1, staff->staffID);
	ps->setString(2, staff->name);
	ps->setString(3, staff->staffType);
	ps->setString(4, staff->password);
	ps->setString(5, staff->telNo);
	ps->setString(6, staff->gender);
	
	int status = ps->executeUpdate();
	delete ps;
	return status;
}
ResultSet* ClassManager::search(Staff* staff)
{
	string staffID;
	DatabaseConnection dbConn;
	PreparedStatement* ps = dbConn.prepareStatement
	("SELECT * FROM Staff WHERE StaffID = ?");
	ps->setString(1, staff->staffID);

	ResultSet* rs = ps->executeQuery();

	delete ps;
	return rs;
}
ResultSet* ClassManager::searchByType(Staff* staff)
{
	DatabaseConnection dbConn;
	PreparedStatement* ps = dbConn.prepareStatement
	("SELECT * FROM Staff WHERE StaffType = ?");
	ps->setString(1, staff->staffType);

	ResultSet* rs = ps->executeQuery();

	delete ps;
	return rs;
}
ResultSet* ClassManager::searchByName(Staff* staff)
{
	DatabaseConnection dbConn;
	PreparedStatement* ps = dbConn.prepareStatement
	("SELECT * FROM Staff WHERE Name LIKE ?");
	ps->setString(1, ("%" + staff->name + "%"));

	ResultSet* rs = ps->executeQuery();

	delete ps;
	return rs;
}
ResultSet* ClassManager::listOfStaff()
{
	DatabaseConnection dbConn;
	PreparedStatement* ps = dbConn.prepareStatement
	("SELECT * FROM Staff");
	ResultSet* rs = ps->executeQuery();

	delete ps;
	return rs;
}
int ClassManager::update(Staff* staff) 
{
	DatabaseConnection dbConn;
	PreparedStatement* ps = dbConn.prepareStatement
	("UPDATE MilkCollection SET Name = ?, StaffType = ?, Password = ?, Gender =?, TelNo = ? WHERE StaffID = ?");
	//Uneditable: StaffID
	ps->setString(1, staff->name);
	ps->setString(2, staff->staffType);
	ps->setString(3, staff->password);
	ps->setString(4, staff->gender);
	ps->setString(6, staff->telNo);
	ps->setString(5, staff->staffID);

	int status = ps->executeUpdate();

	delete ps;
	return status;
}
bool ClassManager::delRecord(Staff* staff)
{
	DatabaseConnection dbConn;
	PreparedStatement* ps = dbConn.prepareStatement
	("DELETE FROM Staff WHERE StaffID = ?");
	ps->setString(1, staff->staffID);
	bool status = ps->execute();

	delete ps;
	return status;
}