#include <iostream>
#include <string>
#include <ctime>
#include <iomanip>
#include "TimeUtility.h"
#include "ClassManager.h"
#include "ScreenClass.h"
#include "MenuDisplay.h"
#include "StaffTypeMenu.h"
#include "FancyText.h"
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

//------------------------------------------
//                F E E D
//------------------------------------------
void ScreenClass::InsertViewFeed()
{
	system("cls");
	FancyText fancyheader;
	fancyheader.MainHeader();
	fancyheader.FeedHeader();
	ClassManager FeedManager;
	Feed goat_feed;
	
	cout << "\n\t\t\t\t\t\t<<<<< Register New Feed >>>>>\n\n";
	cout << "\n\t\t\t\t\t\tFeed ID: ";
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	getline(cin, goat_feed.feedID);
	
	ResultSet* rs = FeedManager.search(&goat_feed);
	
	if (rs->next())
	{
		cout << "\n\n\t\t\t\tDuplicated entry. " << endl;
		system("pause");
	}
	else
	{
		cout << "\n\t\t\t\t\t\tFeedName: ";
		getline(cin, goat_feed.feedName);
		cout << "\n\t\t\t\t\t\tFeed Type: ";
		getline(cin, goat_feed.feedType);
		cout << "\n\t\t\t\t\t\tCalcium(g/kg): ";
		cin >> goat_feed.calcium;
		cout << "\n\t\t\t\t\t\tPhosphorus(g/kg): ";
		cin >> goat_feed.phosphorus;
		cout << "\n\t\t\t\t\t\tPotassium(g/kg): ";
		cin >> goat_feed.potassium;
		cout << "\n\t\t\t\t\t\tCopper(mg/kg): ";
		cin >> goat_feed.copper;
		cout << "\n\t\t\t\t\t\tZinc(mg/kg): ";
		cin >> goat_feed.zinc;

		FeedManager.insert(&goat_feed);

		cout << "\n\n\t\t\t\tRegistration Successful. ";
		system("pause");

		char choice;
		do
		{
			cout << "\n\t\t\t\t\t\tDo you want register another new goat feed? (y/n): ";
			cin >> choice;
			if (choice == 'y' || choice == 'Y')
			{
				InsertViewFeed();
			}
			else if (choice == 'n' || choice == 'N')
			{
				break;
			}
		} while (choice != 'y' && choice != 'Y' && choice != 'n' && choice != 'N');
	}
}
void ScreenClass::SearchViewFeed()
{
	system("cls");
	FancyText fancyheader;
	fancyheader.MainHeader();
	fancyheader.FeedHeader();
	ClassManager FeedManager;
	Feed goat_feed;

	char searchOption;

	cout << "\n\t\t\t\t\t\t>>>>> Search Goat Feed <<<<<" << endl;
	cout << "\n\t\t\t\tSelect a search option." << endl;
	cout << "\n\t\t\t\t(A) By Feed ID" << endl;
	cout << "\n\t\t\t\t(B) By Feed Type" << endl;
	cout << "\n\t\t\t\t(C) By Name" << endl;
	cout << "\n\n\t\t\t\tOption:";
	cin >> searchOption;

	if (searchOption == 'A')
	{
		cout << "\n\t\t\t\t\t\tFeed ID: ";
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		getline(cin, goat_feed.feedID);
		ResultSet* rs = FeedManager.search(&goat_feed);
		if (rs->next())
		{
			cout << "\n\t\t\t\t\t\tRecord is found." << endl;
			cout << "\t\t\t\t\t\t";
			system("pause");
			cout << "\n\t\t\t\t++++++++++++++++ List of Searched Goat Feed ++++++++++++++++\n\n";
			cout << "\t\t\t\tFeed ID            : " << rs->getString(1) << endl;
			cout << "\t\t\t\tFeed Name          : " << rs->getString(2) << endl;
			cout << "\t\t\t\tFeed Type          : " << rs->getString(3) << endl;
			cout << "\t\t\t\tCalcium (g/kg)     : " << rs->getDouble(4) << endl;
			cout << "\t\t\t\tPhosphorus (g/kg)  : " << rs->getDouble(5) << endl;
			cout << "\t\t\t\tPotassium (g/kg)   : " << rs->getDouble(6) << endl;
			cout << "\t\t\t\tCopper (mg/kg)     : " << rs->getDouble(7) << endl;
			cout << "\t\t\t\tZinc (mg/kg)       : " << rs->getDouble(8) << endl;
			cout << "\n\t\t\t\t^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^" << endl;

			system("pause");
		}
		else
		{
			cout << "\n\n\t\t\t\t\t\tRecord Not Found. Please Try Again..." << endl;
			system("pause");
		}

		delete rs;
	}
	else if (searchOption == 'B')
	{
		cout << "\n\t\t\t\t\t\tFeed Type: ";
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		getline(cin, goat_feed.feedType);
		ResultSet* rs = FeedManager.searchByType(&goat_feed);
		cout << "\n\t\t\t\t\t\tRecord is found." << endl;
		cout << "\t\t\t\t\t\t";
		system("pause");
		cout << "\n\t\t\t\t++++++++++++++++ List of Searched Goat Feed ++++++++++++++++\n\n";
		while (rs->next())
		{
			cout << "\t\t\t\tFeed ID            : " << rs->getString(1) << endl;
			cout << "\t\t\t\tFeed Name          : " << rs->getString(2) << endl;
			cout << "\t\t\t\tFeed Type          : " << rs->getString(3) << endl;
			cout << "\t\t\t\tCalcium (g/kg)     : " << rs->getDouble(4) << endl;
			cout << "\t\t\t\tPhosphorus (g/kg)  : " << rs->getDouble(5) << endl;
			cout << "\t\t\t\tPotassium (g/kg)   : " << rs->getDouble(6) << endl;
			cout << "\t\t\t\tCopper (mg/kg)     : " << rs->getDouble(7) << endl;
			cout << "\t\t\t\tZinc (mg/kg)       : " << rs->getDouble(8) << endl;
			cout << "\n\t\t\t\t^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^" << endl;
		}

		delete rs;
		system("pause");
	}
	else if (searchOption == 'C')
	{
		string letter;
		cout << "\n\t\t\t\t\t\tEnter the keyword: ";
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		getline(cin,goat_feed.feedName);
		ResultSet* rs = FeedManager.searchByName(&goat_feed);
		cout << "\n\t\t\t\t\t\tRecord is found." << endl;
		cout << "\t\t\t\t\t\t";
		system("pause");
		cout << "\n\t\t\t\t++++++++++++++++ List of Searched Goat Feed ++++++++++++++++\n\n";
		while (rs->next())
		{
			cout << "\t\t\t\tFeed ID            : " << rs->getString(1) << endl;
			cout << "\t\t\t\tFeed Name          : " << rs->getString(2) << endl;
			cout << "\t\t\t\tFeed Type          : " << rs->getString(3) << endl;
			cout << "\t\t\t\tCalcium (g/kg)     : " << rs->getDouble(4) << endl;
			cout << "\t\t\t\tPhosphorus (g/kg)  : " << rs->getDouble(5) << endl;
			cout << "\t\t\t\tPotassium (g/kg)   : " << rs->getDouble(6) << endl;
			cout << "\t\t\t\tCopper (mg/kg)     : " << rs->getDouble(7) << endl;
			cout << "\t\t\t\tZinc (mg/kg)       : " << rs->getDouble(8) << endl;
			cout << "\n\t\t\t\t^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^" << endl;
		}

		delete rs;
		system("pause");
	}
	else
	{
		cout << "\n\t\t\t\t\t\tUnrecognized input. You can only choose A-C.";
	}	
}
void ScreenClass::UpdateViewFeed()
{
	system("cls");
	FancyText fancyheader;
	fancyheader.MainHeader();
	fancyheader.FeedHeader();
	ClassManager FeedManager;
	Feed goat_feed;

	cout << "\n\t\t\t\t\t>>>>>> Modify Feed Nutrient Content <<<<<" << endl;
	cout << "\n\t\t\t\t\tFeed ID: ";
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	getline(cin, goat_feed.feedID);
	ResultSet* rs = FeedManager.search(&goat_feed);

	if (rs->next())
	{
		goat_feed.feedID = rs->getString(1);
		goat_feed.feedName = rs->getString(2);
		goat_feed.feedType = rs->getString(3);
		goat_feed.calcium = rs->getDouble(4);
		goat_feed.phosphorus = rs->getDouble(5);
		goat_feed.potassium = rs->getDouble(6);
		goat_feed.copper = rs->getDouble(7);
		goat_feed.zinc = rs->getDouble(8);
	}
	else
	{
		cout << "\n\t\t\t\t\t\tRecord not found. You've entered wrong feed ID." << endl;
		system("pause");
		return; //simply return for termination
	}
	delete rs;

	int control = 0;

	while (control != -1)
	{
		system("cls");
		FancyText fancyheader;
		fancyheader.MainHeader();
		fancyheader.FeedHeader();
		cout << "\n\t\t\t\t\t>>>>>> Modify Feed Nutrient Content <<<<<" << endl;
		cout << "\n\t\t\t\t   Feed ID          : " << goat_feed.feedID << endl;
		cout << "\t\t\t\t-----------------------------------------------------------" << endl;
		cout << "\t\t\t\t1. Feed Name        : " << goat_feed.feedName << endl;
		cout << "\t\t\t\t2. Feed Type        : " << goat_feed.feedType << endl;
		cout << "\t\t\t\t3. Calcium (g/kg)   : " << goat_feed.calcium << endl;
		cout << "\t\t\t\t4. Phosphorus (g/kg): " << goat_feed.phosphorus << endl;
		cout << "\t\t\t\t5. Potassium (g/kg) : " << goat_feed.potassium << endl;
		cout << "\t\t\t\t6. Copper (mg/kg)   : " << goat_feed.copper << endl;
		cout << "\t\t\t\t7. Zinc (mg/kg)     : " << goat_feed.zinc << "\n\n";
		cout << "\t\tEnter the corresponding number of item you wish to edit, or enter 'S' to save the record. - ";

		string input;

		cin >> input;
		if (input == "S" || input == "s")
		{
			FeedManager.update(&goat_feed);
			control = -1;
			cout << "\n\t\tData saved! ";
			system("pause");
		}
		else
		{
			control = stoi(input);

			switch (control)
			{
			case 1:
				cout << "\n\t\t\t\tInput the new feed name: ";
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				getline(cin, goat_feed.feedName);
				break;
			case 2:
				cout << "\n\t\t\t\tInput the new feed type: ";
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				getline(cin, goat_feed.feedType);
				break;
			case 3:
				cout << "\n\t\t\t\tInput the new calcium (g/kg):" << endl;
				cin >> goat_feed.calcium;
				break;
			case 4:
				cout << "\n\t\t\t\tInput the new phosphorus (g/kg):" << endl;
				cin >> goat_feed.phosphorus;
				break;
			case 5:
				cout << "\n\t\t\t\tInput the new potassium (g/kg):" << endl;
				cin >> goat_feed.potassium;
				break;
			case 6:
				cout << "\n\t\t\t\tInput the new copper (mg/kg):" << endl;
				cin >> goat_feed.copper;
				break;
			case 7:
				cout << "\n\t\t\t\tInput the new zinc (mg/kg):" << endl;
				cin >> goat_feed.zinc;
				break;
			default:
				cout << "\n\t\t\t\tUnrecognized input" << endl;
				system("pause");
				break;
			}
		}

	}
}
void ScreenClass::DeleteViewFeed()
{
	system("cls");
	FancyText fancyheader;
	fancyheader.MainHeader();
	fancyheader.FeedHeader();
	ClassManager FeedManager;
	Feed goatFeed;

	cout << "\n\t\t\t\t\t\t<<<<< Delete Goat Feed >>>>>\n\n";
	cout << "\n\t\t\t\tWhich goat feed do you want to delete?\n";
	cout << "\n\t\t\t\tGoat Feed ID: ";
	cin >> goatFeed.feedID;
	FeedManager.search(&goatFeed);
	char choice;
	do
	{
		cout << "\n\t\t\t\tAre you sure you want to delete this? This will delete (Y/N) - ";
		cin >> choice;

		if (choice == 'Y' || choice == 'y')
		{
			FeedManager.delRecord(&goatFeed);

				cout << "\n\t\t\t\tRecord has been successfully deleted." << endl;
				system("pause");

				char chooseview;
				cout << "\n\t\t\t\tPress 'V' to view goat feeds list or press enter to back to menu.";
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				cin.get(chooseview);
				if (chooseview == 'V' || chooseview == 'v')
				{
					ListViewFeed();
				}
		}
		else
		{
			cout << "\n\t\t\t\tFailed To Delete." << endl;
		}
	} while (choice != 'Y' && choice != 'y' && choice != 'N' && choice != 'n');
}
void ScreenClass::ListViewFeed()
{
	system("cls");
	FancyText fancyheader;
	fancyheader.MainHeader();
	fancyheader.FeedHeader();
	ClassManager FeedManager;
	Feed goat_feed;

	ResultSet* rs = FeedManager.listOfFeed();
	TimeFunc timefunc;
	cout << "\n\t\t\t\t\t\t<<<<< View Goat Feed List >>>>>\n\n";
	while (rs->next())
	{
		cout << "\t\t\t\tFeed ID           : " << rs->getString(1) << endl;
		cout << "\t\t\t\tFeed Name         : " << rs->getString(2) << endl;
		cout << "\t\t\t\tFeed Type         : " << rs->getString(3) << endl;
		cout << "\t\t\t\tCalcium (g/kg)    : " << rs->getString(4) << endl;
		cout << "\t\t\t\tPhosphorus (g/kg) : " << rs->getString(5) << endl;
		cout << "\t\t\t\tPotassium (g/kg)  : " << rs->getString(6) << endl;
		cout << "\t\t\t\tCopper (mg/kg)    : " << rs->getString(7) << endl;
		cout << "\t\t\t\tZinc (mg/kg)      : " << rs->getString(8) << endl;
		cout << "\n\t\t\t\t^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^" << endl;
	}

	delete rs;

	system("pause");
}


//------------------------------------------
//       F E E D I N G   R E C O R D
//------------------------------------------
void ScreenClass::InsertViewFeedingRecord()
{
	system("cls");
	FancyText fancyheader;
	fancyheader.MainHeader();
	fancyheader.FeedingRecordHeader();
	ClassManager FeedRecordManager;
	FeedingRecord feed_record;
	TimeFunc timefunc;

	cout << "\n\t\t\t\t\t\t<<<<< Add New Feeding Record >>>>>\n\n";
	cout << "\n\t\t\t\t\t\tGoat ID: ";
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	getline(cin, feed_record.goatID);
	cout << "\n\t\t\t\t\t\tFeed ID: ";
	getline(cin, feed_record.feedID);
	cout << "\n\t\t\t\t\t\tStaff ID: ";
	getline(cin, feed_record.staffID);
	cout << "\n\t\t\t\t\t\tQuantity(kg): ";
	cin >> feed_record.quantity;
	cout << "\n\t\t\t\t\t\tEnter the details of the feeding time:" << endl;
	int day, month, year, hour_24, minute, seconds;
	cout << "\t\t\t\t\t\tYear: ";
	cin >> year;
	cout << "\t\t\t\t\t\tMonth: ";
	cin >> month;
	cout << "\t\t\t\t\t\tDay: ";
	cin >> day;
	cout << "\t\t\t\t\t\tHour: ";
	cin >> hour_24;
	cout << "\t\t\t\t\t\tMinute: ";
	cin >> minute;
	cout << "\t\t\t\t\t\tSecond: ";
	cin >> seconds;
	feed_record.feedingTime = timefunc.userInputToTime_t(year, month, day, hour_24, minute, seconds);

	FeedRecordManager.insert(&feed_record);

	cout << "\n\t\t\t\tRegistration Successful." << endl;
	system("pause");

	char choice;
	do
	{
		cout << "\n\t\t\t\tDo you want register another feeding record? (y/n): ";
		cin >> choice;
		if (choice == 'y' || choice == 'Y')
		{
			InsertViewGoatShedInOut();
		}
		else if (choice == 'n' || choice == 'N')
		{
			break;
		}
	} while (choice != 'y' && choice != 'Y' && choice != 'n' && choice != 'N');
}
void ScreenClass::SearchViewFeedingRecord()
{
	system("cls");
	FancyText fancyheader;
	fancyheader.MainHeader();
	fancyheader.FeedingRecordHeader();
	ClassManager FeedRecordManager;
	FeedingRecord feed_record;
	TimeFunc timefunc;

	char searchOption;
	cout << "\n\t\t\t\t\t\t>>>>>> Search Feeding Record <<<<<" << endl;
	cout << "\n\t\t\t\tSelect a search option." << endl;
	cout << "\n\t\t\t\t(A) By Goat ID with DateTime" << endl;
	cout << "\n\t\t\t\t(B) By Goat ID" << endl;
	cout << "\n\t\t\t\t(C) By Staff ID" << endl;
	cout << "\n\n\t\t\t\tOption:";
	cin >> searchOption;
	
	if (searchOption == 'A')
	{
		cout << "\n\t\t\t\t\t\tGoat ID: ";
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		getline(cin, feed_record.goatID);
		cout << "\n\t\t\t\t\t\tEnter the details of feeding time: " << endl;
		int day, month, year, hour_24, minute, seconds;
		cout << "\t\t\t\t\t\tYear: ";
		cin >> year;
		cout << "\t\t\t\t\t\tMonth: ";
		cin >> month;
		cout << "\t\t\t\t\t\tDay: ";
		cin >> day;
		cout << "\t\t\t\t\t\tHour: ";
		cin >> hour_24;
		cout << "\t\t\t\t\t\tMinute: ";
		cin >> minute;
		cout << "\t\t\t\t\t\tSecond: ";
		cin >> seconds;
		feed_record.feedingTime = timefunc.userInputToTime_t(year, month, day, hour_24, minute, seconds);

		ResultSet* rs = FeedRecordManager.search(&feed_record);
		if (rs->next())
		{
			cout << "\n\t\t\t\t\t\tRecord is found." << endl;
			cout << "\t\t\t\t\t\t";
			system("pause");
			cout << "\n\t\t\t\t++++++++++++++++ List of Searched Feeding Record ++++++++++++++++\n\n";
			
			cout << "\t\t\t\t\t\tGoat ID        :" << rs->getString(1) << endl;
			cout << "\t\t\t\t\t\tFeed ID        :" << rs->getString(2) << endl;
			cout << "\t\t\t\t\t\tStaff ID       :" << rs->getString(3) << endl;
			cout << "\t\t\t\t\t\tQuantity (kg)  :" << rs->getDouble(4) << endl;
			cout << "\t\t\t\t\t\tFeeding Time   :" << rs->getString(5) << endl;

			system("pause");
		}
		else
		{
			cout << "\n\n\t\t\t\t\t\tRecord Not Found. Please Try Again..." << endl;
			system("pause");
		}

		delete rs;
	}
	else if (searchOption == 'B')
	{
		cout << "\n\t\t\t\t\t\tGoat ID: ";
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		getline(cin, feed_record.goatID);

		ResultSet* rs = FeedRecordManager.searchByGoatID(&feed_record);
		cout << "\n\t\t\t\t\t\tRecord is found." << endl;
		cout << "\t\t\t\t\t\t";
		system("pause");
		cout << "\n\t\t\t\t++++++++++++++++ List of Searched Feeding Record ++++++++++++++++\n\n";
		while (rs->next())
		{
			cout << "Goat ID        :" << rs->getString(1) << endl;
			cout << "Feed ID        :" << rs->getString(2) << endl;
			cout << "Staff ID       :" << rs->getString(3) << endl;
			cout << "Quantity (kg)  :" << rs->getDouble(4) << endl;
			cout << "Feeding Time   :" << rs->getString(5) << endl;

			system("pause");
		}

		delete rs;
	}
	else if (searchOption == 'C')
	{
		cout << "\n\t\t\t\t\t\tStaff ID: ";
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		getline(cin, feed_record.staffID);

		ResultSet* rs = FeedRecordManager.searchByStaffID(&feed_record);
		cout << "\n\t\t\t\t\t\tRecord is found." << endl;
		cout << "\t\t\t\t\t\t";
		system("pause");
		cout << "\n\t\t\t\t++++++++++++++++ List of Searched Feeding Record ++++++++++++++++\n\n";
		while (rs->next())
		{
			cout << "Goat ID        :" << rs->getString(1) << endl;
			cout << "Feed ID        :" << rs->getString(2) << endl;
			cout << "Staff ID       :" << rs->getString(3) << endl;
			cout << "Quantity (kg)  :" << rs->getDouble(4) << endl;
			cout << "Feeding Time   :" << rs->getString(5) << endl;

			system("pause");
		}
	}
	else
	{
		cout << "\n\t\t\t\t\t\tUnrecognized input. You can only choose A-C.";
	}
}
void ScreenClass::UpdateViewFeedingRecord()
{
	system("cls");
	FancyText fancyheader;
	fancyheader.MainHeader();
	fancyheader.FeedingRecordHeader();
	ClassManager FeedRecordManager;
	FeedingRecord feed_record;
	TimeFunc timefunc;

	cout << "\n\t\t\t\t\t\t>>>>>> Modify Feeding Record <<<<<" << endl;
	cout << "\n\t\t\t\t\t\tGoat ID: ";
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	getline(cin, feed_record.goatID);
	cout << "\n\t\t\t\t\t\tFeeding Time: ";
	int day, month, year, hour_24, minute, seconds;
	cout << "\n\t\t\t\t\t\tYear: ";
	cin >> year;
	cout << "\t\t\t\t\t\tMonth: ";
	cin >> month;
	cout << "\t\t\t\t\t\tDay: ";
	cin >> day;
	cout << "\t\t\t\t\t\tHour: ";
	cin >> hour_24;
	cout << "\t\t\t\t\t\tMinute: ";
	cin >> minute;
	cout << "\t\t\t\t\t\tSecond: ";
	cin >> seconds;
	feed_record.feedingTime = timefunc.userInputToTime_t(year, month, day, hour_24, minute, seconds);

	ResultSet* rs = FeedRecordManager.search(&feed_record);
	if (rs->next())
	{
		feed_record.goatID = rs->getString(1);
		feed_record.feedID = rs->getString(2);
		feed_record.staffID = rs->getString(3);
		feed_record.quantity = rs->getDouble(4);
		feed_record.feedingTime = timefunc.datetimeToTime_t(rs->getString(5));

	}
	else
	{
		cout << "\n\t\t\t\t\t\tRecord not found." << endl;
		system("pause");
		return; //simply return for termination
	}

	delete rs;

	int control = 0;

	while (control != -1)
	{
		system("cls");
		FancyText fancyheader;
		fancyheader.MainHeader();
		fancyheader.FeedingRecordHeader();
		cout << "\t\t\t\t   Goat ID        : " << feed_record.goatID << endl;
		cout << "\t\t\t\t   Feeding Time   : " << timefunc.datetimeToString(feed_record.feedingTime) << endl;
		cout << "\t\t\t\t-----------------------------------------------------------" << endl;
		cout << "\t\t\t\t1. Feed ID        : " << feed_record.feedID << endl;
		cout << "\t\t\t\t2. Staff ID       : " << feed_record.staffID << endl;
		cout << "\t\t\t\t3. Quantity(kg)   : " << feed_record.quantity << endl;
		cout << "\n\t\tEnter the corresponding number of item you wish to edit, or enter 'S' to save the record. - ";

		string input;

		cin >> input;
		if (input == "S" || input == "s")
		{
			FeedRecordManager.update(&feed_record);
			control = -1;
			cout << "Data saved" << endl;
		}
		else
		{
			control = stoi(input);

			switch (control)
			{
			case 1:
				cout << "\t\t\t\tInput the new feed ID: ";
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				getline(cin, feed_record.feedID);
				break;
			case 2:
				cout << "\t\t\t\tInput the new staff ID: ";
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				getline(cin, feed_record.staffID);
				break;
			case 3:
				cout << "\t\t\t\tInput the new quantity(kg): ";
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cin >> feed_record.quantity;
				break;
			default:
				cout << "\t\t\t\tUnrecognized input" << endl;
				system("pause");
				break;
			}
		}

	}
}
void ScreenClass::DeleteViewFeedingRecord()
{
	system("cls");
	FancyText fancyheader;
	fancyheader.MainHeader();
	fancyheader.FeedingRecordHeader();
	ClassManager FeedRecordManager;
	FeedingRecord feed_record;
	TimeFunc timefunc;

	cout << "\n\t\t\t\t\t\t<<<<< Delete Feeding Record >>>>>\n\n";
	cout << "\n\t\t\t\tWhich record do you want to delete?\n";
	cout << "\n\t\t\t\tGoat ID: ";
	cin >> feed_record.goatID;
	cout << "\n\t\t\t\tEnter the details of the feeding time:" << endl;
	int day, month, year, hour_24, minute, seconds;
	cout << "\t\t\t\tYear: ";
	cin >> year;
	cout << "\t\t\t\tMonth: ";
	cin >> month;
	cout << "\t\t\t\tDay: ";
	cin >> day;
	cout << "\t\t\t\tHour: ";
	cin >> hour_24;
	cout << "\t\t\t\tMinute: ";
	cin >> minute;
	cout << "\t\t\t\tSecond: ";
	cin >> seconds;
	feed_record.feedingTime = timefunc.userInputToTime_t(year, month, day, hour_24, minute, seconds);

	char choice;
	do
	{
		cout << "\n\t\tYou are about to Delete a Feeding Record completely from the system." << endl;
		cout << "\n\t\tDo you want to proceed? This action cannot be altered. (Y/N) - ";
		cin >> choice;

		if (choice == 'Y' || choice == 'y')
		{
			FeedRecordManager.delRecord(&feed_record);
			cout << "\n\t\t\t\tRecord has been successfully deleted.";
			system("pause");

			char chooseview;
			cout << "\n\t\t\t\tPress 'V' to view feeding records list or press enter to back to menu.";
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cin.get(chooseview);
			if (chooseview == 'V' || chooseview == 'v')
			{
				ListViewFeedingRecord();
			}
		}
		else
		{
			cout << "\n\t\t\t\t\t\tFailed To Delete." << endl;
		}
	} while (choice != 'Y' && choice != 'y' && choice != 'N' && choice != 'n');
}
void ScreenClass::ListViewFeedingRecord()
{
	system("cls");
	FancyText fancyheader;
	fancyheader.MainHeader();
	fancyheader.FeedingRecordHeader();
	ClassManager FeedRecordManager;
	FeedingRecord feed_record;
	TimeFunc timefunc;

	ResultSet* rs = FeedRecordManager.listOfFeedingRecord();
	cout << "\n\t\t\t\t\t\t<<<<< View Feeding Records List >>>>>\n\n";
	while (rs->next())
	{
		cout << "\t\t\t\tGoat ID       : " << rs->getString(1) << endl;
		cout << "\t\t\t\tFeed ID       : " << rs->getString(2) << endl;
		cout << "\t\t\t\tStaff ID      : " << rs->getString(3) << endl;
		cout << "\t\t\t\tQuantity(kg)  : " << rs->getDouble(4) << endl;
		cout << "\t\t\t\tFeeding Time  : " << rs->getString(4) << endl;
		cout << "\n\t\t\t\t^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^" << endl;
	}

	delete rs;

	system("pause");
}


//------------------------------------------
//           G O A T  B I R T H
//------------------------------------------
void ScreenClass::InsertViewGoatBirth()
{
	system("cls");
	FancyText fancyheader;
	fancyheader.MainHeader();
	fancyheader.GoatBirthHeader();
	ClassManager GoatManager;
	GoatBirth goat_birth;
	TimeFunc timefunc;

	cout << "\n\t\t\t\t\t\t<<<<< Register New Goat >>>>>\n\n";
	cout << "\n\t\t\t\t\t\tGoat ID: ";
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	getline(cin,goat_birth.goatID);

	ResultSet* rs = GoatManager.search(&goat_birth);

	if (rs->next())
	{
		cout << "\n\n\t\t\t\tDuplicated entry. " << endl;
		system("pause");
	}
	{
		cout << "\n\t\t\t\t\t\tGoat Breed: ";
		getline(cin, goat_birth.goatBreed);
		cout << "\n\t\t\t\t\t\tGoat Gender: ";
		getline(cin, goat_birth.goatGender);
		cout << "\n\t\t\t\t\t\tParent ID: ";
		getline(cin, goat_birth.parentGoatID);
		cout << "\n\t\t\t\t\t\tHealth Status: ";
		getline(cin, goat_birth.healthStatus);
		cout << "\n\t\t\t\t\t\tEnter the details of the date of birth:" << endl;
		int day, month, year;
		cout << "\t\t\t\t\t\tYear: ";
		cin >> year;
		cout << "\t\t\t\t\t\tMonth: ";
		cin >> month;
		cout << "\t\t\t\t\t\tDay: ";
		cin >> day;
		goat_birth.goatDOB = timefunc.userInputToTime_t(year, month, day);

		GoatManager.insert(&goat_birth);

		cout << "\t\t\t\t\t\tRegistration Successful." << endl;
		system("pause");

		char choice;
		do
		{
			cout << "\t\t\t\t\t\tDo you want register another new goat? (y/n): ";
			cin >> choice;
			if (choice == 'y' || choice == 'Y')
			{
				InsertViewGoatBirth();
			}
			else if (choice == 'n' || choice == 'N')
			{
				break;
			}
		} while (choice != 'y' && choice != 'Y' && choice != 'n' && choice != 'N');
	}
}
void ScreenClass::SearchViewGoatBirth() 
{
	system("cls");
	FancyText fancyheader;
	fancyheader.MainHeader();
	fancyheader.GoatBirthHeader();
	ClassManager GoatManager;
	GoatBirth goat_birth;

	TimeFunc timefunc;

	char searchOption;
	cout << "\n\t\t\t\t\t\t>>>>>> Search Goat Record <<<<<" << endl;
	cout << "\n\t\t\t\tSelect a search option." << endl;
	cout << "\n\t\t\t\t(A) By Goat ID" << endl;
	cout << "\n\t\t\t\t(B) By Sick Goat" << endl;
	cout << "\n\t\t\t\t(C) By Goat Breed" << endl;
	cout << "\n\n\t\t\t\tOption:";
	cin >> searchOption;

	if (searchOption == 'A')
	{
		cout << "\n\t\t\t\t\t\tGoat ID: ";
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		getline(cin, goat_birth.goatID);

		ResultSet* rs = GoatManager.search(&goat_birth);
		if (rs->next())
		{
			cout << "\n\t\t\t\t\t\tRecord is found." << endl;
			cout << "\t\t\t\t\t\t";
			system("pause");
			cout << "\n\t\t\t\t++++++++++++++++ List of Searched Goat Details ++++++++++++++++\n\n";
			cout << "\t\t\t\tGoat ID          : " << rs->getString(1) << endl;
			cout << "\t\t\t\tGoat Breed        : " << rs->getString(2) << endl;
			cout << "\t\t\t\tGender           : " << rs->getString(3) << endl;
			cout << "\t\t\t\tParent Goat ID   : " << rs->getString(4) << endl;
			cout << "\t\t\t\tHealth Status    : " << rs->getString(5) << endl;
			cout << "\t\t\t\tDate of Birth    : " << rs->getString(6) << endl;
			cout << "\n\t\t\t\t^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^" << endl;

			system("pause");

		}
		else
		{
			cout << "\n\n\t\t\t\t\t\tRecord Not Found. Please Try Again..." << endl;
			system("pause");
		}

		delete rs;
	}
	else if (searchOption == 'B')
	{
		ResultSet* rs = GoatManager.searchBySickGoat(&goat_birth);
		cout << "\n\t\t\t\t++++++++++++++++ List of Searched Sick Goat Details ++++++++++++++++\n\n";
		while (rs->next())
		{
			cout << "\t\t\t\tGoat ID          : " << rs->getString(1) << endl;
			cout << "\t\t\t\tGoat Breed       : " << rs->getString(2) << endl;
			cout << "\t\t\t\tGender           : " << rs->getString(3) << endl;
			cout << "\t\t\t\tParent Goat ID   : " << rs->getString(4) << endl;
			cout << "\t\t\t\tHealth Status    : " << rs->getString(5) << endl;
			cout << "\t\t\t\tDate of Birth    : " << rs->getString(6) << endl;
			cout << "\n\t\t\t\t^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^" << endl;
		}

		delete rs;

		system("pause");
	}
	else if (searchOption == 'C')
	{
		cout << "\n\t\t\t\t\t\tGoat Type: ";
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		getline(cin, goat_birth.goatBreed);

		ResultSet* rs = GoatManager.searchByGoatBreed(&goat_birth);
		cout << "\n\t\t\t\t++++++++++++++++ List of Searched Goat Details ++++++++++++++++\n\n";
		while (rs->next())
		{
			cout << "\t\t\t\tGoat ID          : " << rs->getString(1) << endl;
			cout << "\t\t\t\tGoat Breed       : " << rs->getString(2) << endl;
			cout << "\t\t\t\tGender           : " << rs->getString(3) << endl;
			cout << "\t\t\t\tParent Goat ID   : " << rs->getString(4) << endl;
			cout << "\t\t\t\tHealth Status    : " << rs->getString(5) << endl;
			cout << "\t\t\t\tDate of Birth    : " << rs->getString(6) << endl;
			cout << "\n\t\t\t\t^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^" << endl;
		}

		delete rs;

		system("pause");
	}
	else
	{
		cout << "\n\t\t\t\t\t\tUnrecognized input. You can only choose A-C.";
		system("pause");
	}
}
void ScreenClass::UpdateViewGoatBirth() 
{
	system("cls");
	FancyText fancyheader;
	fancyheader.MainHeader();
	fancyheader.GoatBirthHeader();
	ClassManager GoatManager;
	GoatBirth goat_birth;
	TimeFunc timefunc;

	cout << "\n\t\t\t\t\t\t>>>>>> Modify Goat Details <<<<<" << endl;
	cout << "\n\t\t\t\t\t\tGoat ID: ";
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	getline(cin, goat_birth.goatID);
	ResultSet* rs = GoatManager.search(&goat_birth);
	if (rs->next())
	{
		system("cls");
		FancyText fancyheader;
		fancyheader.MainHeader();
		fancyheader.GoatBirthHeader();
		cout << "\n\t\t\t\t\t\t>>>>>> Modify Goat Details <<<<<" << endl;
		goat_birth.goatID = rs->getString(1);
		goat_birth.goatBreed = rs->getString(2);
		goat_birth.goatGender = rs->getString(3);
		goat_birth.parentGoatID = rs->getString(4);
		goat_birth.healthStatus = rs->getString(5);
		goat_birth.goatDOB = timefunc.dateToTime_t(rs->getString(6));
	}
	else
	{
		cout << "\n\t\t\t\t\t\tRecord not found." << endl;
		system("pause");
		return; //simply return for termination
	}

	delete rs;

	int control = 0;

	while (control != -1)
	{
		cout << "\t\tGoat ID         : " << goat_birth.goatID << endl;
		cout << "\t\tParent Goat ID  : " << goat_birth.parentGoatID << endl;
		cout << "\t\tDate of Birth   : " << timefunc.dateToString(goat_birth.goatDOB) << endl;
		cout << "\t\t-----------------------------------------------------------" << endl;
		cout << "\t\t1. Breed         : " << goat_birth.goatBreed << endl;
		cout << "\t\t2. Gender       : " << goat_birth.goatGender << endl;
		cout << "\t\t3. Health Status: " << goat_birth.healthStatus << "\n\n"; 
		cout << "\t\tEnter the corresponding number of item you wish to edit, or enter 'S' to save the record." << endl;

		string input;

		cin >> input;
		if (input == "S" || input == "s")
		{
			GoatManager.update(&goat_birth);
			control = -1;
			cout << "Data saved" << endl;
		}
		else
		{
			control = stoi(input);

			switch (control)
			{
			case 1:
				cout << "Input the new breed: ";
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				getline(cin, goat_birth.goatBreed);
				break;
			case 2:
				cout << "Input the new gender: ";
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				getline(cin, goat_birth.goatGender);
				break;
			case 3:
				cout << "Input the new health status: ";
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				getline(cin, goat_birth.healthStatus);
				break;
			default:
				cout << "Unrecognized input" << endl;
				system("pause");
				break;
			}
		}

	}
}
void ScreenClass::DeleteViewGoatBirth()
{
	system("cls");
	FancyText fancyheader;
	fancyheader.MainHeader();
	fancyheader.GoatBirthHeader();
	ClassManager GoatManager;
	GoatBirth goat_birth;

	char delOption;
	cout << "\n\t\t\t\t\t\t<<<<< Delete Goat Detail >>>>>\n\n";
	cout << "\n\t\t\t\tSelect a delete option." << endl;
	cout << "\n\t\t\t\t(A) By Goat ID" << endl;
	cout << "\n\t\t\t\t(B) By Dead Goat" << endl;
	cout << "\n\n\t\t\t\tOption:";
	cin >> delOption;

	if (delOption == 'A')
	{
		cout << "\n\t\t\t\t\t\tWhich goat do you want to delete?\n";
		cout << "\n\t\t\t\t\t\tGoat ID: ";
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		getline(cin, goat_birth.goatID);
		char choice;
		do
		{
			cout << "\n\t\t\t\tAre you sure you want to delete this? (Y/N) - ";
			cin >> choice;

			if (choice == 'Y' || choice == 'y')
			{
				GoatManager.delRecord(&goat_birth);
				cout << "\n\t\tRecord has been successfully deleted.";
				system("pause");

				char chooseview;
				cout << "\n\t\tPress 'V' to view goat detail records list or press enter to back to menu.";
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				cin.get(chooseview);
				if (chooseview == 'V' || chooseview == 'v')
				{
					ListViewGoatBirth();
				}
			}
			else
			{
				cout << "\n\t\t\t\t\t\tFailed To Delete." << endl;
			}

		} while (choice != 'Y' && choice != 'y' && choice != 'N' && choice != 'n');
	}
	else if (delOption == 'B')
	{
		char choice;
		do
		{
			cout << "\n\t\t\t\tAre you sure you want to delete dead goat records? (Y/N) - ";
			cin >> choice;

			if (choice == 'Y' || choice == 'y')
			{
				GoatManager.delDeadGoat(&goat_birth);
				cout << "\n\t\t\t\tDead goat records has been successfully deleted.";
				system("pause");

				char chooseview;
				cout << "\n\t\t\t\tPress 'V' to view goat detail records list or press enter to back to menu.";
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				cin.get(chooseview);
				if (chooseview == 'V' || chooseview == 'v')
				{
					ListViewGoatBirth();
				}
			}
			else
			{
				cout << "\n\t\t\t\t\t\tFailed To Delete." << endl;
			}
		} while (choice != 'Y' && choice != 'y' && choice != 'N' && choice != 'n');
	}
	else
	{
		cout << "\n\t\t\t\t\t\tUnrecognized input. You can only choose A or B.";
		system("pause");
	}
}
void ScreenClass::ListViewGoatBirth()
{
	system("cls");
	FancyText fancyheader;
	fancyheader.MainHeader();
	fancyheader.GoatBirthHeader();
	ClassManager GoatManager;
	GoatBirth goat_birth;
	TimeFunc timefunc;

	ResultSet* rs = GoatManager.listOfGoatBirth();
	cout << "\n\t\t\t\t\t\t<<<<< View Goats List >>>>>\n\n";
	while (rs->next())
	{
		cout << "\t\t\t\tGoat ID          : " << rs->getString(1) << endl;
		cout << "\t\t\t\tGoat Breed       : " << rs->getString(2) << endl;
		cout << "\t\t\t\tGender           : " << rs->getString(3) << endl;
		cout << "\t\t\t\tParent Goat ID   : " << rs->getString(4) << endl;
		cout << "\t\t\t\tHealth Status    : " << rs->getString(5) << endl;
		cout << "\t\t\t\tDate of Birth    : " << rs->getString(6) << endl;
		cout << "\n\t\t\t\t^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^" << endl;
	}

	delete rs;

	system("pause");
}


//------------------------------------------
//           G O A T  S H E D
//------------------------------------------
void ScreenClass::InsertViewGoatShed()
{
	system("cls");
	FancyText fancyheader;
	fancyheader.MainHeader();
	fancyheader.GoatShedHeader();
	ClassManager GoatShedManager;
	GoatShed goat_shed;

	string goatShedID, title, description;

	cout << "\n\t\t\t\t\t\t<<<<< Register New Goat Shed >>>>>\n\n";
	cout << "\n\t\t\t\t\t\tGoat Shed ID: ";
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	getline(cin, goat_shed.goatShedID);
	cout << "\n\t\t\t\t\t\tTitle: ";
	getline(cin, goat_shed.title);
	cout << "\n\t\t\t\t\t\tDescription: ";
	getline(cin, goat_shed.description);

	GoatShedManager.insert(&goat_shed);

	cout << "\n\t\t\t\t\t\tRegistration Successful." << endl;
	system("pause");

	char choice;
	do
	{
		cout << "\n\t\t\t\t\t\tDo you want register another new goat shed? (y/n): ";
		cin >> choice;
		if (choice == 'y' || choice == 'Y')
		{
			InsertViewGoatShed();
		}
		else if (choice == 'n' || choice == 'N')
		{
			break;
		}
	} while (choice != 'y' && choice != 'Y' && choice != 'n' && choice != 'N');
}
void ScreenClass::SearchViewGoatShed() 
{
	system("cls");
	FancyText fancyheader;
	fancyheader.MainHeader();
	fancyheader.GoatShedHeader();
	ClassManager GoatShedManager;
	GoatShed goat_shed;

	cout << "\n\t\t\t\t\t\t>>>>>> Search Goat Shed <<<<<" << endl;
	cout << "\n\t\t\t\t\t\tTitle: ";
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	getline(cin, goat_shed.title);

	ResultSet* rs = GoatShedManager.searchByName(&goat_shed);
	if (rs->next())
	{
		cout << "\n\t\t\t\t\t\tRecord is found." << endl;
		cout << "\t\t\t\t\t\t";
		system("pause");
		cout << "\n\t\t\t\t++++++++++++++++ List of Searched Goat Shed ++++++++++++++++\n\n";
		cout << "\t\t\t\t\t\tGoat Shed ID" << rs->getString(1) << endl;
		cout << "\t\t\t\t\t\tTitle" << rs->getString(2) << endl;
		cout << "\t\t\t\t\t\tDescription" << rs->getString(3) << endl;

		system("pause");

	}
	else
	{
		cout << "\n\n\t\t\t\t\t\tRecord Not Found. Please Try Again..." << endl;
		system("pause");
	}

	delete rs;
}
void ScreenClass::UpdateViewGoatShed() 
{
	system("cls");
	FancyText fancyheader;
	fancyheader.MainHeader();
	fancyheader.GoatShedHeader();
	ClassManager GoatShedManager;
	GoatShed goat_shed;

	string goatShedID, title, description;

	cout << "\n\t\t\t\t\t\t>>>>>> Modify Goat Shed Detail <<<<<" << endl;
	cout << "\n\t\t\t\t\t\tGoat Shed ID: ";
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	getline(cin, goat_shed.goatShedID);
	ResultSet* rs = GoatShedManager.searchByID(&goat_shed);

	if (rs->next())
	{
		goat_shed.goatShedID = rs->getString(1);
		goat_shed.title = rs->getString(2);
		goat_shed.description = rs->getString(3);
	}
	delete rs;

	int control = 0;

	while (control != -1)
	{
		system("cls");
		FancyText fancyheader;
		fancyheader.MainHeader();
		fancyheader.GoatShedHeader();
		cout << "\n\t\t\t\t\t\t>>>>>> Modify Goat Shed Detail <<<<<" << endl;
		cout << "\t\t\t\tGoat Shed ID    : " << goat_shed.goatShedID << endl;
		cout << "\t\t\t\t-----------------------------------------------------------" << endl;
		cout << "\t\t\t\t1. Title        : " << goat_shed.title << endl;
		cout << "\t\t\t\t2. Description  : " << goat_shed.description << "\n\n";
		cout << "\t\tEnter the corresponding number of item you wish to edit, or enter 'S' to save the record." << endl;

		string input;

		cin >> input;
		if (input == "S" || input == "s")
		{
			GoatShedManager.update(&goat_shed);
			control = -1;
			cout << "Data saved" << endl;
		}
		else
		{
			control = stoi(input);

			switch (control)
			{
			case 1:
				cout << "Input the new title: ";
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				getline(cin, goat_shed.title);
				break;
			case 2:
				cout << "Input the new description: ";
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				getline(cin, goat_shed.description);
				break;
			default:
				cout << "Unrecognized input" << endl;
				system("pause");
				break;
			}
		}

	}

}
void ScreenClass::DeleteViewGoatShed() 
{
	system("cls");
	FancyText fancyheader;
	fancyheader.MainHeader();
	fancyheader.GoatShedHeader();
	ClassManager GoatShedManager;
	GoatShed goat_shed;

	cout << "\n\t\t\t\t\t\t<<<<< Delete Goat Shed >>>>>\n\n";
	cout << "\n\t\t\t\t\t\tWhich record do you want to delete?\n\n";
	cout << "\n\t\t\t\t\t\tGoat Shed Title: ";
	getline(cin,goat_shed.title);
	GoatShedManager.searchByName(&goat_shed);
	char choice;
	do
	{
		cout << "\n\t\tYou are about to Delete a Goat Shed Detail completely from the system." << endl;
		cout << "\n\t\tDo you want to proceed? This action cannot be altered. (Y/N) - ";
		cin >> choice;

		if (choice == 'Y' || choice == 'y')
		{
			GoatShedManager.delRecord(&goat_shed); 
			cout << "\n\t\t\t\tRecord has been successfully deleted.";
			system("pause");

			char chooseview;
			cout << "\n\t\t\t\tPress 'V' to view goat sheds list or press enter to back to menu.";
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cin.get(chooseview);
			if (chooseview == 'V' || chooseview == 'v')
			{
				ListViewGoatShed();
			}
		}
		else
		{
			cout << "\n\t\t\t\t\t\tFailed To Delete." << endl;
		}
	} while (choice != 'Y' && choice != 'y' && choice != 'N' && choice != 'n');
}
void ScreenClass::ListViewGoatShed()
{
	system("cls");
	FancyText fancyheader;
	fancyheader.MainHeader();
	fancyheader.GoatShedHeader();
	ClassManager GoatShedManager;
	GoatShed goat_shed;

	ResultSet* rs = GoatShedManager.listOfGoatShed();
	cout << "\n\t\t\t\t\t\t<<<<< View Goat Sheds List >>>>>\n\n";
	while (rs->next())
	{
		cout << "\t\t\t\tGoat Shed ID    : " << rs->getString(1) << endl;
		cout << "\t\t\t\tTitle           : " << rs->getString(2) << endl;
		cout << "\t\t\t\tDescription     : " << rs->getString(3) << endl;
		cout << "\n\t\t\t\t^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^" << endl;
	}

	delete rs;

	system("pause");
}


//------------------------------------------
//       G O A T S H E D  I N  O U T
//------------------------------------------
void ScreenClass::InsertViewGoatShedInOut() 
{
	system("cls");
	FancyText fancyheader;
	fancyheader.MainHeader();
	fancyheader.GoatShedInOutHeader();
	ClassManager GoatShedInOutManager;
	GoatShedInOut goat_inout;
	TimeFunc timefunc;

	cout << "\n\t\t\t\t\t\t<<<<< Add Goat Shed In Out Record >>>>>\n\n";
	cout << "\n\t\t\t\t\t\tGoat Shed ID: ";
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	getline(cin, goat_inout.goatShedID);
	cout << "\n\t\t\t\t\t\tGoat ID: ";
	getline(cin, goat_inout.goatID);
	cout << "\n\t\t\t\t\t\tEnter the details of the checked in time:" << endl;
	int day, month, year, hour_24, minute, seconds;
	cout << "\t\t\t\t\t\tYear: ";
	cin >> year;
	cout << "\t\t\t\t\t\tMonth: ";
	cin >> month;
	cout << "\t\t\t\t\t\tDay: ";
	cin >> day;
	cout << "\t\t\t\t\t\tHour: ";
	cin >> hour_24;
	cout << "\t\t\t\t\t\tMinute: ";
	cin >> minute;
	cout << "\t\t\t\t\t\tSecond: ";
	cin >> seconds;
	goat_inout.checkIn = timefunc.userInputToTime_t(year, month, day, hour_24, minute, seconds);

	GoatShedInOutManager.insert(&goat_inout);

	cout << "\n\t\t\t\t\t\tRegistration Successful." << endl;
	system("pause");

	char choice;
	do
	{
		cout << "\n\t\t\t\t\t\tDo you want register another goat shed in out record? (y/n): ";
		cin >> choice;
		if (choice == 'y' || choice == 'Y')
		{
			InsertViewGoatShedInOut();
		}
		else if (choice == 'n' || choice == 'N')
		{
			break;
		}
	} while (choice != 'y' && choice != 'Y' && choice != 'n' && choice != 'N');
}
void ScreenClass::SearchViewGoatShedInOut()
{
	system("cls");
	FancyText fancyheader;
	fancyheader.MainHeader();
	fancyheader.GoatShedInOutHeader();
	ClassManager GoatShedInOutManager;
	GoatShedInOut goat_inout;
	TimeFunc timefunc;

	cout << "\n\t\t\t\t\t\t>>>>>> Search Goat Shed In Out Record <<<<<" << endl;
	cout << "\n\t\t\t\t\t\tGoat ID: ";
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	getline(cin, goat_inout.goatID);
	cout << "\n\t\t\t\t\t\tEnter the details of checked in time: ";
	int day, month, year, hour_24, minute, seconds;
	cout << "\t\t\t\t\t\tYear: ";
	cin >> year;
	cout << "\t\t\t\t\t\tMonth: ";
	cin >> month;
	cout << "\t\t\t\t\t\tDay: ";
	cin >> day;
	cout << "\t\t\t\t\t\tHour: ";
	cin >> hour_24;
	cout << "\t\t\t\t\t\tMinute: ";
	cin >> minute;
	cout << "\t\t\t\t\t\tSecond: ";
	cin >> seconds;
	goat_inout.checkIn = timefunc.userInputToTime_t(year, month, day, hour_24, minute, seconds);
	
	ResultSet*rs =GoatShedInOutManager.search(&goat_inout);
	if (rs->next())
	{
		cout << "\n\t\t\t\t\t\tRecord is found." << endl;
		cout << "\t\t\t\t\t\t";
		system("pause");
		cout << "\n\t\t\t\t++++++++++++++++ List of Searched Goat Shed In Out Record ++++++++++++++++\n\n";

		cout << "\n\t\t\t\t\tGoat Shed ID   : " << rs->getString(1) << endl;
		cout << "\n\t\t\t\t\tGoat ID        : " << rs->getString(2) << endl;
		cout << "\n\t\t\t\t\tCheck In       : " << rs->getString(3) << endl;
		cout << "\n\t\t\t\t\tCheck Out      : " << rs->getString(4) << endl;

		system("pause");
	}
	else
	{
		cout << "\n\n\t\t\t\t\t\tRecord Not Found. Please Try Again..." << endl;
		system("pause");
	}

	delete rs;

}
void ScreenClass::UpdateViewGoatShedInOut()
{
	system("cls");
	FancyText fancyheader;
	fancyheader.MainHeader();
	fancyheader.GoatShedInOutHeader();
	ClassManager GoatShedInOutManager;
	GoatShedInOut goat_inout;
	TimeFunc timefunc;

	string goatShedID, goatID;
	time_t checkIn;

	cout << "\n\t\t\t\t\t\t>>>>>> Modify Goat Shed In Out Record <<<<<" << endl;
	cout << "\n\t\t\t\t\t\tGoat ID: ";
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	getline(cin, goat_inout.goatID);
	cout << "\n\t\t\t\t\t\tChecked In Time: ";
	int day, month, year, hour_24, minute, seconds;
	cout << "\t\t\t\t\t\tYear: ";
	cin >> year;
	cout << "\t\t\t\t\t\tMonth: ";
	cin >> month;
	cout << "\t\t\t\t\t\tDay: ";
	cin >> day;
	cout << "\t\t\t\t\t\tHour: ";
	cin >> hour_24;
	cout << "\t\t\t\t\t\tMinute: ";
	cin >> minute;
	cout << "\t\t\t\t\t\tSecond: ";
	cin >> seconds;
	goat_inout.checkIn = timefunc.userInputToTime_t(year, month, day, hour_24, minute, seconds);

	ResultSet* rs = GoatShedInOutManager.search(&goat_inout);

	if (rs->next())
	{
		goat_inout.goatShedID = rs->getString(1);
		goat_inout.goatID = rs->getString(2);
		goat_inout.checkIn = timefunc.datetimeToTime_t(rs->getString(3));
		goat_inout.checkOut = timefunc.datetimeToTime_t(rs->getString(4));

	}
	else
	{
		cout << "\n\t\t\t\t\t\tRecord not found.";
		system("pause");
		return; //simply return for termination
	}

	delete rs;

	int control = 0;

	while (control != -1)
	{
		cout << "\t\t   Goat ID           : " << goat_inout.goatID << endl;
		cout << "\t\t   Checked In Time   : " << timefunc.datetimeToString(goat_inout.checkIn) << endl;
		cout << "\t\t   Goat Shed ID      : " << goat_inout.goatShedID << endl;
		cout << "\t\t-----------------------------------------------------------" << endl;
		cout << "\t\t1. Checked Out Time  : " << timefunc.datetimeToString(goat_inout.checkOut) << endl;
		cout << "\t\tEnter the corresponding number of item you wish to edit, or enter 'S' to save the record." << endl;

		string input;

		cin >> input;
		if (input == "S" || input == "s")
		{
			GoatShedInOutManager.update(&goat_inout);
			control = -1;
			cout << "Data saved" << endl;
		}
		else
		{
			control = stoi(input);

			switch (control)
			{
			case 1:
				cout << "Input the checked out time: ";
				int day, month, year, hour_24, minute, seconds;
				cout << "\t\t\t\t\t\tYear: ";
				cin >> year;
				cout << "\t\t\t\t\t\tMonth: ";
				cin >> month;
				cout << "\t\t\t\t\t\tDay: ";
				cin >> day;
				cout << "\t\t\t\t\t\tHour: ";
				cin >> hour_24;
				cout << "\t\t\t\t\t\tMinute: ";
				cin >> minute;
				cout << "\t\t\t\t\t\tSecond: ";
				cin >> seconds;
				goat_inout.checkOut = timefunc.userInputToTime_t(year, month, day, hour_24, minute, seconds);
				break;
			default:
				cout << "Unrecognized input" << endl;
				system("pause");
				break;
			}
		}

	}
}
void ScreenClass::DeleteViewGoatShedInOut()
{
	system("cls");
	FancyText fancyheader;
	fancyheader.MainHeader();
	fancyheader.GoatShedInOutHeader();
	ClassManager GoatShedInOutManager;
	GoatShedInOut goat_inout;
	TimeFunc timefunc;

	cout << "\n\t\t\t\t\t\t<<<<< Delete Goat Shed In Out Record >>>>>\n\n";
	cout << "\n\t\t\t\tWhich record do you want to delete?\n\n";
	cout << "\n\t\t\t\tGoat ID: ";
	cin >> goat_inout.goatID;
	cout << "\n\t\t\t\tEnter the details of the checked in time:" << endl;
	int day, month, year, hour_24, minute, seconds;
	cout << "\n\t\t\t\tYear: ";
	cin >> year;
	cout << "\n\t\t\t\tMonth: ";
	cin >> month;
	cout << "\n\t\t\t\tDay: ";
	cin >> day;
	cout << "\n\t\t\t\tHour: ";
	cin >> hour_24;
	cout << "\n\t\t\t\tMinute: ";
	cin >> minute;
	cout << "\n\t\t\t\tSecond: ";
	cin >> seconds;
	goat_inout.checkIn = timefunc.userInputToTime_t(year, month, day, hour_24, minute, seconds);

	char choice;
	do
	{
		cout << "\n\t\tYou are about to Delete a Goat Shed In Out Record completely from the system." << endl;
		cout << "\n\t\tDo you want to proceed? This action cannot be altered. (Y/N) - ";
		cin >> choice;

		if (choice == 'Y' || choice == 'y')
		{
			GoatShedInOutManager.delRecord(&goat_inout);
			cout << "\n\t\t\t\tRecord has been successfully deleted.";
			system("pause");

			char chooseview;
			cout << "\n\t\t\t\tPress 'V' to view goat shed in out records list or press enter to back to menu.";
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cin.get(chooseview);
			if (chooseview == 'V' || chooseview == 'v')
			{
				ListViewGoatShedInOut();
			}
		}
		else
		{
			cout << "\n\t\t\t\t\t\tFailed To Delete." << endl;
		}
	} while (choice != 'Y' && choice != 'y' && choice != 'N' && choice != 'n');
}
void ScreenClass::ListViewGoatShedInOut()
{
	system("cls");
	FancyText fancyheader;
	fancyheader.MainHeader();
	fancyheader.GoatShedInOutHeader();
	ClassManager GoatShedInOutManager;
	GoatShedInOut goat_inout;
	TimeFunc timefunc;

	ResultSet* rs = GoatShedInOutManager.listOfGoatShedInOut();
	cout << "\n\t\t\t\t\t\t<<<<< View Goat Shed In Out Records List >>>>>\n\n";
	while (rs->next())
	{
		cout << "\t\t\t\tGoat Shed ID  : " << rs->getString(1) << endl;
		cout << "\t\t\t\tGoat ID       : " << rs->getString(2) << endl;
		cout << "\t\t\t\tChecked In    : " << rs->getString(3) << endl;
		cout << "\t\t\t\tChecked Out   : " << rs->getString(4) << endl;
		cout << "\n\t\t\t\t^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^" << endl;
	}

	delete rs;

	system("pause");

}


//------------------------------------------
//       H E A L T H   H I S T O R Y
//------------------------------------------
void ScreenClass::InsertViewHealthHistory()
{
	system("cls");
	FancyText fancyheader;
	fancyheader.MainHeader();
	fancyheader.HealthHistoryHeader();
	ClassManager HealthManager;
	HealthHistory health_history;
	TimeFunc timefunc;

	cout << "\n\t\t\t\t\t\t>>>>>> Add New Health Record <<<<<" << endl;
	cout << "\n\t\t\t\t\t\tHealth History ID: ";
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	getline(cin, health_history.healthHistoryID);
	cout << "\n\t\t\t\t\t\tGoat ID: ";
	getline(cin, health_history.goatID);
	ResultSet* rs = HealthManager.search(&health_history);

	if (rs->next())
	{
		cout << "\n\n\t\t\t\tDuplicated entry. " << endl;
		system("pause");
	}
	else
	{
		cout << "\n\t\t\t\t\t\tSickness: ";
		getline(cin, health_history.sickness);
		cout << "\n\t\t\t\t\t\tSymptom: ";
		getline(cin, health_history.symptom);
		cout << "\n\t\t\t\t\t\tTreatment: ";
		getline(cin, health_history.treatment);
		cout << "\n\t\t\t\t\t\tEnter the details of the date of record:" << endl;
		int day, month, year;
		cout << "\t\t\t\t\t\tYear: ";
		cin >> year;
		cout << "\t\t\t\t\t\tMonth: ";
		cin >> month;
		cout << "\t\t\t\t\t\tDay: ";
		cin >> day;
		health_history.dateOfRecord = timefunc.userInputToTime_t(year, month, day);

		HealthManager.insert(&health_history);

		cout << "\n\t\t\t\t\t\tRegistration Successful.";
		system("pause");

		char choice;
		do
		{
			cout << "\n\t\t\t\t\t\tDo you want register another new health record? (y/n): ";
			cin >> choice;
			if (choice == 'y' || choice == 'Y')
			{
				InsertViewHealthHistory();
			}
			else if (choice == 'n' || choice == 'N')
			{
				break;
			}
		} while (choice != 'y' && choice != 'Y' && choice != 'n' && choice != 'N');
	}
}
void ScreenClass::SearchViewHealthHistory()
{
	std::system("cls");
	FancyText fancyheader;
	fancyheader.MainHeader();
	fancyheader.HealthHistoryHeader();
	ClassManager HealthManager;
	HealthHistory health_history;
	TimeFunc timefunc;

	cout << "\n\t\t\t\t\t\t>>>>>> Search Health Record <<<<<" << endl;
	cout << "\n\t\t\t\t\t\tHealth History ID: ";
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	getline(cin, health_history.healthHistoryID);
	ResultSet* rs = HealthManager.search(&health_history);
	if (rs->next())
	{
		cout << "\n\t\t\t\t\t\tRecord is found." << endl;
		cout << "\t\t\t\t\t\t";
		system("pause");
		cout << "\n\t\t\t\t++++++++++++++++ List of Searched Health Record ++++++++++++++++\n\n";
		cout << "\t\t\tHealth History ID : " << health_history.healthHistoryID << endl;
		cout << "\t\t\tGoat ID           : " << rs->getString(2) << endl;
		cout << "\t\t\tSickness          : " << rs->getString(3) << endl;
		cout << "\t\t\tSymptom           : " << rs->getString(4) << endl;
		cout << "\t\t\tTreatment         : " << rs->getString(5) << endl;
		cout << "\t\t\tDate              : " << rs->getString(6) << endl;
		cout << "\n\t\t\t^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^" << endl;

		system("pause");
	}
	else
	{
		cout << "\n\n\t\t\t\t\t\tRecord Not Found. Please Try Again..." << endl;
		system("pause");
	}

	delete rs;
}
void ScreenClass::UpdateViewHealthHistory()
{
	system("cls");
	FancyText fancyheader;
	fancyheader.MainHeader();
	fancyheader.HealthHistoryHeader();
	ClassManager HealthManager;
	HealthHistory health_history;
	TimeFunc timefunc;

	std::cout << "\n\t\t\t\t\t\t>>>>>> Modify Health Record <<<<<" << endl;
	std::cout << "\n\t\t\t\t\t\tHealth History ID: ";
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	getline(cin, health_history.healthHistoryID);
	ResultSet* rs = HealthManager.search(&health_history);

	// store rs result in health history
	if (rs->next())
	{
		health_history.healthHistoryID = rs->getString(1);
		health_history.goatID = rs->getString(2);
		health_history.sickness = rs->getString(3);
		health_history.symptom = rs->getString(4);
		health_history.treatment = rs->getString(5);
		health_history.dateOfRecord = timefunc.dateToTime_t(rs->getString(6));
	}
	else
	{
		cout << "\n\t\t\t\t\t\tRecord not found." << endl;
		system("pause");
		return; //simply return for termination
	}

	delete rs;
	int control = 0;

	while (control != -1)
	{
		system("cls");
		FancyText fancyheader;
		fancyheader.MainHeader();
		fancyheader.HealthHistoryHeader();
		cout << "\t\tHealth History ID: " << health_history.healthHistoryID << endl;
		cout << "\t\tGoat ID: " << health_history.goatID << endl;
		cout << "\t\t-----------------------------------------------------------" << endl;
		cout << "\t\t1. Sickness: " << health_history.sickness << endl;
		cout << "\t\t2. Treatment: " << health_history.treatment << endl;
		cout << "\t\t3. Date: " << timefunc.dateToString(health_history.dateOfRecord) << endl;
		cout << "\t\t4. Symptom: " << health_history.symptom << "\n\n";
		cout << "\t\tEnter the corresponding number of item you wish to edit, or enter 'S' to save the record." << endl;

		string input;

		cin >> input;
		if (input == "S" || input == "s")
		{
			HealthManager.update(&health_history);
			control = -1;
			cout << "Data saved" << endl;
			system("pause");
		}
		else
		{
			control = stoi(input);

			switch (control)
			{
			case 1:
				cout << "Input the new sickness: ";
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				getline(cin, health_history.sickness);
				break;
			case 2:
				cout << "Input the new treatment: ";
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				getline(cin, health_history.treatment);
				break;
			case 3:
				cout << "Enter the details of the new date:" << endl;
				int day, month, year;
				cout << "Year: ";
				cin >> year;
				cout << "Month: ";
				cin >> month;
				cout << "Day: ";
				cin >> day;
				health_history.dateOfRecord = timefunc.userInputToTime_t(year, month, day);
				break;
			case 4:
				cout << "Input the new symptom: ";
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				getline(cin, health_history.symptom);
				break;
			default:
				cout << "Unrecognized input" << endl;
				system("pause");
				break;
			}
		}

	}
}
void ScreenClass::DeleteViewHealthHistory()
{
	system("cls");
	FancyText fancyheader;
	fancyheader.MainHeader();
	fancyheader.HealthHistoryHeader();
	ClassManager HealthManager;
	HealthHistory health_history;

	cout << "\n\t\t\t\t\t\t<<<<< Delete Health History Record >>>>>\n\n";
	cout << "\n\t\t\t\t\t\tWhich record do you want to delete?\n";
	cout << "\n\t\t\t\t\t\tHealth Record ID: ";
	cin >> health_history.healthHistoryID;
	char choice;
	do
	{
		cout << "\n\t\tYou are about to Delete a Health Record completely from the system." << endl;
		cout << "\n\t\tDo you want to proceed? This action cannot be altered. (Y/N) - ";
		cin >> choice;

		if (choice == 'Y' || choice == 'y')
		{
			HealthManager.delRecord(&health_history);
			cout << "\n\t\t\t\tRecord has been successfully deleted." << endl;
			system("pause");

			char chooseview;
			cout << "\n\t\t\t\tPress 'V' to view health history record or press enter to back to menu.";
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cin.get(chooseview);
			if (chooseview == 'V' || chooseview == 'v')
			{
				ListViewHealthHistory();
			}
		}
		else
		{
			cout << "\n\t\t\t\t\tFailed To Delete.";
			system("pause");
		}
	} while (choice != 'Y' && choice != 'y' && choice != 'N' && choice != 'n');

}
void ScreenClass::ListViewHealthHistory()
{
	system("cls");
	FancyText fancyheader;
	fancyheader.MainHeader();
	fancyheader.HealthHistoryHeader();
	ClassManager HealthManager;
	HealthHistory health_history;

	ResultSet* rs = HealthManager.listOfHealthHistory();
	TimeFunc timefunc;
	cout << "\n\t\t\t\t\t<<<<< View Health History Record List >>>>>\n\n";
	while (rs->next())
	{
		cout << "\t\t\tHealth History ID : " << rs->getString(1) << endl;
		cout << "\t\t\tGoat ID           : " << rs->getString(2) << endl;
		cout << "\t\t\tSickness          : " << rs->getString(3) << endl;
		cout << "\t\t\tSymptom           : " << rs->getString(4) << endl;
		cout << "\t\t\tTreatment         : " << rs->getString(5) << endl;
		cout << "\t\t\tDate              : " << rs->getString(6) << endl;
		cout << "\n\t\t\t^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^" << endl;
	}

	delete rs;

	system("pause");
}


//------------------------------------------
//       M I L K   C O L L E C T I O N
//------------------------------------------
void ScreenClass::InsertViewMilkCollection()
{
	system("cls");
	FancyText fancyheader;
	fancyheader.MainHeader();
	fancyheader.MilkCollectionHeader();
	ClassManager MilkCollectionManager;
	MilkCollection milk_collect;
	TimeFunc timefunc;

	cout << "\n\t\t\t\t\t\t<<<<< Add Milk Collection Record >>>>>\n\n";
	cout << "\n\t\t\t\t\t\tGoat ID: ";
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	getline(cin, milk_collect.goatID);

	ResultSet* rs = MilkCollectionManager.search(&milk_collect);

	if (rs->next())
	{
		cout << "\n\n\t\t\t\tDuplicated entry. " << endl;
		system("pause");
	}
	else
	{
		cout << "\n\t\t\t\t\t\tRecorded by: ";
		getline(cin, milk_collect.staffID);
		cout << "\n\t\t\t\t\t\tGoat Shed ID: ";
		getline(cin, milk_collect.goatShedID);
		cout << "\n\t\t\t\t\t\tEnter the details of the date collected:" << endl;
		int day, month, year;
		cout << "\t\t\t\t\t\tYear: ";
		cin >> year;
		cout << "\t\t\t\t\t\tMonth: ";
		cin >> month;
		cout << "\t\t\t\t\t\tDay: ";
		cin >> day;
		milk_collect.dateCollect = timefunc.userInputToTime_t(year, month, day);
		cout << "\n\t\t\t\t\t\tQuantity(litres): ";
		cin >> milk_collect.quantity;

		MilkCollectionManager.insert(&milk_collect);

		cout << "\n\t\t\t\t\t\tRegistration Successful." << endl;
		system("pause");

		char choice;
		do
		{
			cout << "\n\t\t\t\t\t\tDo you want register another new milk collection record? (y/n): ";
			cin >> choice;
			if (choice == 'y' || choice == 'Y')
			{
				InsertViewMilkCollection();
			}
			else if (choice == 'n' || choice == 'N')
			{
				break;
			}
		} while (choice != 'y' && choice != 'Y' && choice != 'n' && choice != 'N');
	}
}
void ScreenClass::SearchViewMilkCollection()
{
	system("cls");
	FancyText fancyheader;
	fancyheader.MainHeader();
	fancyheader.MilkCollectionHeader();
	ClassManager MilkCollectionManager;
	MilkCollection milk_collect;
	TimeFunc timefunc;

	cout << "\n\t\t\t\t\t\t>>>>>> Search Milk Collection Record <<<<<" << endl;
	cout << "\n\t\t\t\t\t\tGoat ID: ";
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	getline(cin, milk_collect.goatID);
	cout << "\n\t\t\t\t\t\tDate Collected: ";
	int day, month, year;
	cout << "\t\t\t\t\t\tYear: ";
	cin >> year;
	cout << "\t\t\t\t\t\tMonth: ";
	cin >> month;
	cout << "\t\t\t\t\t\tDay: ";
	cin >> day;
	milk_collect.dateCollect = timefunc.userInputToTime_t(year, month, day);

	ResultSet* rs = MilkCollectionManager.search(&milk_collect);
	if (rs->next())
	{
		cout << "\n\t\t\t\t\t\tRecord is found." << endl;
		cout << "\t\t\t\t\t\t";
		system("pause");
		cout << "\n\t\t\t\t++++++++++++++++ List of Searched Milk Collection Record ++++++++++++++++\n\n";
		cout << setw(20) << "Goat ID" << setw(20) << "Staff ID" << setw(30) << "Goat Shed ID"
			<< setw(20) << "Date Collect" << setw(20) << "Quantity(litres)" << endl;

		cout << setw(20) << rs->getString(1) << setw(20) << rs->getString(2) << setw(30) << rs->getString(3)
			<< setw(20) << rs->getString(4) << setw(20) << rs->getDouble(5) << endl;

		system("pause");
	}
	else
	{
		cout << "\n\n\t\t\t\t\t\tRecord Not Found. Please Try Again..." << endl;
		system("pause");
	}

	delete rs;
}
void ScreenClass::UpdateViewMilkCollection()
{
	system("cls");
	FancyText fancyheader;
	fancyheader.MainHeader();
	fancyheader.MilkCollectionHeader();
	ClassManager MilkCollectionManager;
	MilkCollection milk_collect;
	TimeFunc timefunc;

	cout << "\n\t\t\t\t\t\t>>>>>> Modify Milk Collection Record <<<<<" << endl;
	cout << "\n\t\t\t\t\t\tGoat ID: ";
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	getline(cin, milk_collect.goatID);
	std::cout << "\n\t\t\t\t\t\tDate Collected: ";
	int day, month, year;
	cout << "\t\t\t\t\t\tYear: ";
	cin >> year;
	cout << "\t\t\t\t\t\tMonth: ";
	cin >> month;
	cout << "\t\t\t\t\t\tDay: ";
	cin >> day;
	milk_collect.dateCollect = timefunc.userInputToTime_t(year, month, day);
	ResultSet* rs = MilkCollectionManager.search(&milk_collect);

	if (rs->next())
	{
		milk_collect.goatID = rs->getString(1);
		milk_collect.staffID = rs->getString(2);
		milk_collect.goatShedID = rs->getString(3);
		milk_collect.dateCollect = timefunc.dateToTime_t(rs->getString(4));
		milk_collect.quantity = rs->getDouble(5);
	}
	else
	{
		cout << "\n\t\t\t\t\t\tRecord not found." << endl;
		system("pause");
		return; //simply return for termination
	}

	delete rs;
	int control = 0;

	while (control != -1)
	{
		system("cls");
		FancyText fancyheader;
		fancyheader.MainHeader();
		fancyheader.MilkCollectionHeader();
		cout << "\n\t\t\t\t\t\t>>>>>> Modify Milk Collection Record <<<<<" << endl;
		cout << "\t\t   Goat ID             : " << milk_collect.goatID << endl;
		cout << "\t\t   Date Collect        : " << timefunc.datetimeToString(milk_collect.dateCollect) << endl;
		cout << "\t\t   Staff ID            : " << milk_collect.staffID << endl;
		cout << "\t\t   Goat Shed ID        : " << milk_collect.goatShedID << endl;
		cout << "\t\t-----------------------------------------------------------" << endl;
		cout << "\t\t1. Quantity(litres)    : " << milk_collect.quantity << endl;
		cout << "\t\tEnter the corresponding number of item you wish to edit, or enter 'S' to save the record." << endl;

		string input;

		cin >> input;
		if (input == "S" || input == "s")
		{
			MilkCollectionManager.update(&milk_collect);
			control = -1;
			cout << "Data saved" << endl;
		}
		else
		{
			control = stoi(input);

			switch (control)
			{
			case 1:
				cout << "Input the new quantity(litres): ";
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cin >> milk_collect.quantity;
				break;
			default:
				cout << "Unrecognized input" << endl;
				system("pause");
				break;
			}
		}

	}
}
void ScreenClass::DeleteViewMilkCollection()
{
	system("cls");
	FancyText fancyheader;
	fancyheader.MainHeader();
	fancyheader.MilkCollectionHeader();
	ClassManager MilkCollectionManager;
	MilkCollection milk_collect;
	TimeFunc timefunc;

	cout << "\n\t\t\t\t\t\t<<<<< Delete Milk Collection Record >>>>>\n\n";
	cout << "\n\t\t\t\tWhich record do you want to delete?\n\n";
	cout << "\n\t\t\t\tGoat ID: ";
	cin >> milk_collect.goatID;
	cout << "\n\t\t\t\tEnter the details of the date collected:" << endl;
	int day, month, year;
	cout << "\t\t\t\tYear: ";
	cin >> year;
	cout << "\t\t\t\tMonth: ";
	cin >> month;
	cout << "\t\t\t\tDay: ";
	cin >> day;
	milk_collect.dateCollect = timefunc.userInputToTime_t(year, month, day);

	char choice;
	do
	{
		cout << "\n\t\tYou are about to Delete a Milk Collection Record completely from the system." << endl;
		cout << "\n\t\tDo you want to proceed? This action cannot be altered. (Y/N) - ";
		cin >> choice;

		if (choice == 'Y' || choice == 'y')
		{
			MilkCollectionManager.delRecord(&milk_collect);
			cout << "\n\t\t\t\tRecord has been successfully deleted.";
			system("pause");

			char chooseview;
			cout << "\n\t\t\t\tPress 'V' to view milk collection records list or press enter to back to menu.";
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cin.get(chooseview);
			if (chooseview == 'V' || chooseview == 'v')
			{
				ListViewMilkCollection();
			}
		}
		else
		{
			cout << "\n\t\t\t\t\t\tFailed To Delete." << endl;
			system("pause");
		}
	} while (choice != 'Y' && choice != 'y' && choice != 'N' && choice != 'n');
}
void ScreenClass::ListViewMilkCollection()
{
	system("cls");
	FancyText fancyheader;
	fancyheader.MainHeader();
	fancyheader.MilkCollectionHeader();
	ClassManager MilkCollectionManager;
	MilkCollection milk_collect;
	TimeFunc timefunc;

	ResultSet* rs = MilkCollectionManager.listOfMilkCollection();
	cout << "\n\t\t\t\t\t\t<<<<< View Milk Collection Records List >>>>>\n\n";
	while (rs->next())
	{
		cout << "\t\t\t\tGoat ID           : " << rs->getString(1) << endl;
		cout << "\t\t\t\tStaff ID          : " << rs->getString(2) << endl;
		cout << "\t\t\t\tGoat Shed ID      : " << rs->getString(3) << endl;
		cout << "\t\t\t\tDate Collect      : " << rs->getString(4) << endl;
		cout << "\t\t\t\tQuantity(litres)  : " << rs->getDouble(5) << endl;
		cout << "\n\t\t\t\t^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^" << endl;
	}

	delete rs;

	system("pause");
}
void ScreenClass::ViewTotalMilkYield()
{
	system("cls");
	FancyText fancyheader;
	fancyheader.MainHeader();
	fancyheader.MilkCollectionHeader();
	ClassManager MilkCollectionManager;
	MilkCollection milk_collect;
	TimeFunc timefunc;

	ResultSet* rs = MilkCollectionManager.totalMilkYield(&milk_collect);
	cout << "\n\t\t\t\t\t>>>>>> Total Milk Yield For Each Goat House <<<<<" << endl;
	cout << "\n\t\t\t\t" << setw(15) << "Goat Shed" << setw(30) << "Total Milk Yield(litres)" << endl;
	while (rs->next())
	{
		cout << "\t\t\t\t" << setw(15) << rs->getString(1) << setw(25) << rs->getDouble(2) << endl;
		
	}
	cout << "\n\t\t\t\t^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^" << endl;
	delete rs;

	system("pause");

}
void ScreenClass::ViewTotalMilkYieldByMonth()
{
	system("cls");
	FancyText fancyheader;
	fancyheader.MainHeader();
	fancyheader.MilkCollectionHeader();
	ClassManager MilkCollectionManager;
	MilkCollection milk_collect;
	TimeFunc timefunc;

	ResultSet* rs = MilkCollectionManager.totalMilkYieldByMonth(&milk_collect);
	cout << "\n\t\t\t\t\t>>>>>> Total Milk Yield For Each Month <<<<<" << endl;
	cout << "\n\t\t\t\t" << setw(15) << "Month" << setw(30) << "Total Milk Yield(litres)" << endl;
	while (rs->next())
	{
		cout << "\t\t\t\t" << setw(15) << rs->getString(1) << setw(25) << rs->getDouble(2) << endl;

	}
	cout << "\n\t\t\t\t^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^" << endl;
	delete rs;

	system("pause");
}

//------------------------------------------
//                S T A F F
//------------------------------------------
void ScreenClass::InsertViewStaff()
{
	system("cls");
	FancyText fancyheader;
	fancyheader.MainHeader();
	fancyheader.StaffHeader();
	ClassManager StaffManager;
	Staff staff;

	string staffID, name, staffType, password, gender, telNo;

	cout << "\n\t\t\t\t\t\t<<<<< Register New Staff >>>>>\n\n";
	cout << "\n\t\t\t\t\t\tStaff ID: ";
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	getline(cin, staff.staffID);

	ResultSet* rs = StaffManager.search(&staff);

	if (rs->next())
	{
		cout << "\n\n\t\t\t\tDuplicated entry. " << endl;
		system("pause");
	}
	else
	{
		cout << "\n\t\t\t\t\t\tName: ";
		getline(cin, staff.name);
		cout << "\n\t\t\t\t\t\tStaff Type: ";
		getline(cin, staff.staffType);
		cout << "\n\t\t\t\t\t\tPassword: ";
		getline(cin, staff.password);
		cout << "\n\t\t\t\t\t\tTel No: ";
		getline(cin, staff.telNo);
		cout << "\n\t\t\t\t\t\tGender: ";
		getline(cin, staff.gender);

		StaffManager.insert(&staff);

		cout << "\n\t\t\t\t\t\tRegistration Successful." << endl;
		system("pause");

		char choice;
		do
		{
			cout << "\n\t\t\t\t\t\tDo you want register another new staff? (y/n): ";
			cin >> choice;
			if (choice == 'y' || choice == 'Y')
			{
				InsertViewStaff();
			}
			else if (choice == 'n' || choice == 'N')
			{
				break;
			}
		} while (choice != 'y' && choice != 'Y' && choice != 'n' && choice != 'N');
	}
}
void ScreenClass::SearchViewStaff()
{
	system("cls");
	FancyText fancyheader;
	fancyheader.MainHeader();
	fancyheader.StaffHeader();
	ClassManager StaffManager;
	Staff staff;

	char searchOption;
	cout << "\n\t\t\t\t\t\t>>>>>> Search Staff Detail <<<<<" << endl;
	cout << "\n\t\t\t\tSelect a search option." << endl;
	cout << "\n\t\t\t\t(A) By Staff ID" << endl;
	cout << "\n\t\t\t\t(B) By Staff Name" << endl;
	cout << "\n\n\t\t\t\tOption:";
	cin >> searchOption;

	if (searchOption == 'A')
	{
		cout << "\n\t\t\t\t\t\tStaff ID: ";
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		getline(cin, staff.staffID);

		ResultSet* rs = StaffManager.search(&staff);
		if (rs->next())
		{
			cout << "\n\t\t\t\t\t\tRecord is found." << endl;
			cout << "\t\t\t\t\t\t";
			system("pause");
			cout << "\n\t\t\t\t++++++++++++++++ List of Searched Staff Detail ++++++++++++++++\n\n";
			cout << "\n\t\t\t\t\t\tStaff ID   : " << rs->getString(1) << endl;
			cout << "\n\t\t\t\t\t\tName       : " << rs->getString(2) << endl;
			cout << "\n\t\t\t\t\t\tStaff Type : " << rs->getString(3) << endl;
			cout << "\n\t\t\t\t\t\tPassword   : " << rs->getString(4) << endl;
			cout << "\n\t\t\t\t\t\tGender     : " << rs->getString(5) << endl;
			cout << "\n\t\t\t\t\t\tTel No     : " << rs->getString(6) << endl;

			system("pause");

		}
		else
		{
			cout << "\n\n\t\t\t\t\t\tRecord Not Found. Please Try Again..." << endl;
			system("pause");
		}

		delete rs;
	}
	else if(searchOption == 'B')
	{
		string letter;
		cout << "\n\t\t\t\t\t\tEnter the keyword: ";
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		getline(cin, staff.name);
		ResultSet* rs = StaffManager.searchByName(&staff);
		cout << "\n\t\t\t\t\t\tRecord is found." << endl;
		cout << "\t\t\t\t\t\t";
		system("pause");

		cout << "\n\t\t\t\t++++++++++++++++ List of Searched Staff Detail ++++++++++++++++\n\n";
		while (rs->next())
		{
			cout << "\n\t\t\t\t\t\tStaff ID   : " << rs->getString(1) << endl;
			cout << "\n\t\t\t\t\t\tName       : " << rs->getString(2) << endl;
			cout << "\n\t\t\t\t\t\tStaff Type : " << rs->getString(3) << endl;
			cout << "\n\t\t\t\t\t\tPassword   : " << rs->getString(4) << endl;
			cout << "\n\t\t\t\t\t\tGender     : " << rs->getString(5) << endl;
			cout << "\n\t\t\t\t\t\tTel No     : " << rs->getString(6) << endl;
		}
		system("pause");

	}
	else
	{
		cout << "\n\t\t\t\t\t\tUnrecognized input. You can only choose A and B.";
		system("pause");
	}	
}
void ScreenClass::UpdateViewStaff()
{
	system("cls");
	FancyText fancyheader;
	fancyheader.MainHeader();
	fancyheader.StaffHeader();
	ClassManager StaffManager;
	Staff staff;

	cout << "\n\t\t\t\t\t\t>>>>>> Modify Staff Detail <<<<<" << endl;
	cout << "\n\t\t\t\t\t\tStaff ID: ";
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	getline(cin, staff.staffID);
	ResultSet* rs = StaffManager.search(&staff);

	if (rs->next())
	{
		staff.staffID = rs->getString(1);
		staff.name = rs->getString(2);
		staff.staffType = rs->getString(3);
		staff.password = rs->getString(4);
		staff.telNo = rs->getString(5);
		staff.gender = rs->getString(6);
	}

	delete rs;

	int control = 0;

	while (control != -1)
	{
		system("cls");
		FancyText fancyheader;
		fancyheader.MainHeader();
		fancyheader.StaffHeader();
		cout << "\n\t\t\t\t\t\t>>>>>> Modify Staff Detail <<<<<" << endl;
		cout << "\t\t\t\t   Staff ID    : " << staff.staffID << endl;
		cout << "\t\t\t\t-----------------------------------------------------------" << endl;
		cout << "\t\t\t\t1. Name        : " << staff.name << endl;
		cout << "\t\t\t\t2. Staff Type  : " << staff.staffType << endl;
		cout << "\t\t\t\t3. Password    : " << staff.password << endl;
		cout << "\t\t\t\t4. Contact No  : " << staff.telNo << endl;
		cout << "\t\t\t\t5. Gender      : " << staff.gender << "\n\n";
		cout << "\t\tEnter the corresponding number of item you wish to edit, or enter 'S' to save the record." << endl;

		string input;

		cin >> input;
		if (input == "S" || input == "s")
		{
			StaffManager.update(&staff);
			control = -1;
			cout << "Data saved" << endl;
		}
		else
		{
			control = stoi(input);

			switch (control)
			{
			case 1:
				cout << "Input the new name: ";
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				getline(cin, staff.name);
				break;
			case 2:
				cout << "Input the new type: ";
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				getline(cin, staff.staffType);
				break;
			case 3:
				cout << "Input the new password: ";
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				getline(cin, staff.password);
				break;
			case 4:
				cout << "Input the new contact no: ";
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				getline(cin, staff.telNo);
				break;
			case 5:
				cout << "Input the new gender: ";
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				getline(cin, staff.gender);
				break;
			default:
				cout << "Unrecognized input" << endl;
				system("pause");
				break;
			}
		}

	}
}
void ScreenClass::DeleteViewStaff()
{
	system("cls");
	FancyText fancyheader;
	fancyheader.MainHeader();
	fancyheader.StaffHeader();
	ClassManager StaffManager;
	Staff staff;

	cout << "\n<<<<< Delete Staff Detail >>>>>\n\n";
	cout << "Which staff's detail do you want to delete?\n\n";
	cout << "Staff ID: ";
	cin >> staff.staffID;

	char choice;
	do
	{
		cout << "\n\t\tYou are about to Delete a Staff completely from the system." << endl;
		cout << "\n\t\tDo you want to proceed? This action cannot be altered. (Y/N) - ";
		cin >> choice;

		if (choice == 'Y' || choice == 'y')
		{
			StaffManager.delRecord(&staff);
			cout << "\n\t\t\t\tRecord has been successfully deleted.";
			system("pause");

			char chooseview;
			cout << "\n\t\t\t\tPress 'V' to view [staff details list] or press enter to back to menu.";
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cin.get(chooseview);
			if (chooseview == 'V' || chooseview == 'v')
			{
				ListViewStaff();
			}
		}
		else
		{
			cout << "\n\t\t\t\t\t\tFailed To Delete." << endl;
		}
	} while (choice != 'Y' && choice != 'y' && choice != 'N' && choice != 'n');
}
void ScreenClass::ListViewStaff()
{
	system("cls");
	FancyText fancyheader;
	fancyheader.MainHeader();
	fancyheader.StaffHeader();
	ClassManager StaffManager;
	Staff staff;

	ResultSet* rs = StaffManager.listOfStaff();
	cout << "\n\t\t\t\t\t\t<<<<< View Staff Details List >>>>>\n\n";
	while (rs->next())
	{
		cout << "\t\t\t\tStaff ID    : " << rs->getString(1) << endl;
		cout << "\t\t\t\tName        : " << rs->getString(2) << endl;
		cout << "\t\t\t\tType        : " << rs->getString(3) << endl;
		cout << "\t\t\t\tPassword    :" << rs->getString(4) << endl;
		cout << "\t\t\t\tContact No  :" << rs->getString(5) << endl;
		cout << "\t\t\t\tGender      :" << rs->getString(6) << endl;
		cout << "\n\t\t\t\t^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^" << endl;
	}

	delete rs;

	system("pause");
}