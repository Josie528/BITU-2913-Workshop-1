#include<iostream>
#include<string>
#include<ctime>
#include <iomanip>
#include "TimeUtility.h"
#include "ClassManager.h"
#include "MenuDisplay.h"
#include "Login.h"
#include "ScreenClass.h"
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

/*
 * Some option should be hidden from certain staff type
*/

//------------------------------------------
//           G O A T  B I R T H
//------------------------------------------
void MenuDisplay::GoatMenuPage(int staff_type)
{
	FancyText fancyheader;
	ScreenClass screenClass;
	map<int, int> menu_display;

	string menu[6] = { "Register New Goat","Modify Goat Details",
		"Search Goat Detail","View Goats List","Delete Goat Detail","Back to Main Page" };

	switch (staff_type)
	{
	case 1: // Administrator
		menu_display.emplace(1, 0);
		menu_display.emplace(2, 1);
		menu_display.emplace(3, 2);
		menu_display.emplace(4, 3);
		menu_display.emplace(5, 4);
		menu_display.emplace(6, 5);
		break;
	case 2: // Farmer
		menu_display.emplace(1, 2);
		menu_display.emplace(2, 3);
		menu_display.emplace(3, 5);
		break;
	}
	
		

	int input;

	do
	{
		system("cls");
		fancyheader.MainHeader();
		fancyheader.GoatBirthHeader();

		for (auto elem : menu_display)
		{
			cout << "\n";
			cout <<"\t\t\t\t\t\t "<< elem.first << "-> " << menu[elem.second] << endl;
		}
		cout << "\n\t\t\t\t\t\t  Enter your choice: ";
		cin >> input;

		switch (menu_display.at(input)) //carry out selected action
		{
		case 0: 
			screenClass.InsertViewGoatBirth();
			break;
		case 1:
			screenClass.UpdateViewGoatBirth();
			break;
		case 2:
			screenClass.SearchViewGoatBirth();
			break;
		case 3:
			screenClass.ListViewGoatBirth();
			break;
		case 4:
			screenClass.DeleteViewGoatBirth();
			break;
		default:
			break;
		}
	} while (menu[menu_display.at(input)] != "Back to Main Page");
}

//------------------------------------------
//                F E E D
//------------------------------------------
void MenuDisplay::FeedMenuPage(int staff_type)
{
	ScreenClass screenClass;
	FancyText fancyheader;
	map<int, int> menu_display;

	string menu[6] = { "Register New Feed","Modify Feed Nutrient Content",
		"Search Feed","View Goats Feed List","Delete Goat Feed","Back to Main Page" };

	switch (staff_type)
	{
	case 1: // Administrator
		menu_display.emplace(1, 0);
		menu_display.emplace(2, 1);
		menu_display.emplace(3, 2);
		menu_display.emplace(4, 3);
		menu_display.emplace(5, 4);
		menu_display.emplace(6, 5);
		break;
	case 2: // Farmer
		menu_display.emplace(1, 2);
		menu_display.emplace(2, 3);
		menu_display.emplace(3, 5);
		break;
	}

	int input;

	do
	{
		system("cls");
		fancyheader.MainHeader();
		fancyheader.FeedHeader();

		for (auto elem : menu_display)
		{
			cout << "\n\t\t\t\t\t\t " << elem.first << "-> " << menu[elem.second] << endl;
		}
		cout << "\n\t\t\t\t\t\t  Enter your choice: ";
		cin >> input;

		switch (menu_display.at(input)) //carry out selected action
		{
		case 0:
			screenClass.InsertViewFeed();
			break;
		case 1:
			screenClass.UpdateViewFeed();
			break;
		case 2:
			screenClass.SearchViewFeed();
			break;
		case 3:
			screenClass.ListViewFeed();
			break;
		case 4:
			screenClass.DeleteViewFeed();
			break;
		default:
			break;
		}
	} while (menu[menu_display.at(input)] != "Back to Main Page");
}

//------------------------------------------
//       F E E D I N G   R E C O R D
//------------------------------------------
void MenuDisplay::FeedingRecordMenuPage(int staff_type)
{
	FancyText fancyheader;
	ScreenClass screenClass;
	map<int, int> menu_display;

	string menu[6] = { "Add New Feeding Record","Modify Feeding Record",
		"Search Feeding Record","View Feeding Records List","Delete Feeding Record","Back to Main Page" };

	switch (staff_type)
	{
	case 1: // Administrator
		menu_display.emplace(1, 0);
		menu_display.emplace(2, 1);
		menu_display.emplace(3, 2);
		menu_display.emplace(4, 3);
		menu_display.emplace(5, 4);
		menu_display.emplace(6, 5);
		break;
	case 2: // Farmer
		menu_display.emplace(1, 0);
		menu_display.emplace(2, 1);
		menu_display.emplace(3, 2);
		menu_display.emplace(4, 3);
		menu_display.emplace(5, 4);
		menu_display.emplace(6, 5);
		break;
	case 4: // Supervisor
		menu_display.emplace(1, 2);
		menu_display.emplace(2, 3);
		menu_display.emplace(3, 5);
		break;
	}

	int input;

	do
	{
		system("cls");
		fancyheader.MainHeader();
		fancyheader.FeedingRecordHeader();

		for (auto elem : menu_display)
		{
			cout << "\n\t\t\t\t\t\t " << elem.first << ". " << menu[elem.second] << endl;
		}
		cout << "\n\t\t\t\t\t\t  Enter your choice: ";
		cin >> input;

		switch (menu_display.at(input)) //carry out selected action
		{
		case 0:
			screenClass.InsertViewFeedingRecord();
			break;
		case 1:
			screenClass.UpdateViewFeedingRecord();
			break;
		case 2:
			screenClass.SearchViewFeedingRecord();
			break;
		case 3:
			screenClass.ListViewFeedingRecord();
			break;
		case 4:
			screenClass.DeleteViewFeedingRecord();
			break;
		default:
			break;
		}
	} while (menu[menu_display.at(input)] != "Back to Main Page");
}

//------------------------------------------
//       H E A L T H   H I S T O R Y
//------------------------------------------
void MenuDisplay::HealthHistoryMenuPage(int staff_type)
{
	FancyText fancyheader;
	ScreenClass screenClass;
	map<int, int> menu_display;

	string menu[7] = { "Add New Health Record","Modify Health Record Details",
		"Search Health Record","View Health History Record List","Delete Health Record","Back to Main Page" };

	switch (staff_type)
	{
	case 1: // Administrator
		menu_display.emplace(1, 0);
		menu_display.emplace(2, 1);
		menu_display.emplace(3, 2);
		menu_display.emplace(4, 3);
		menu_display.emplace(5, 4);
		menu_display.emplace(6, 5);
		break;
	case 2: // Farmer
		menu_display.emplace(1, 2);
		menu_display.emplace(2, 3);
		menu_display.emplace(3, 5);
		break;
	case 3: // Veterinarian
		menu_display.emplace(1, 0);
		menu_display.emplace(2, 1);
		menu_display.emplace(3, 2);
		menu_display.emplace(4, 3);
		menu_display.emplace(5, 4);
		menu_display.emplace(6, 5);
		break;
	}

	int input;

	do
	{
		system("cls");
		fancyheader.MainHeader();
		fancyheader.HealthHistoryHeader();

		for (auto elem : menu_display)
		{
			cout << "\n\t\t\t\t\t\t " << elem.first << ". " << menu[elem.second] << endl;
		}
		cout << "\n\t\t\t\t\t\t  Enter your choice: ";
		cin >> input;

		switch (menu_display.at(input)) //carry out selected action
		{
		case 0:
			screenClass.InsertViewHealthHistory();
			break;
		case 1:
			screenClass.UpdateViewHealthHistory();
			break;
		case 2:
			screenClass.SearchViewHealthHistory();
			break;
		case 3:
			screenClass.ListViewHealthHistory();
			break;
		case 4:
			screenClass.DeleteViewHealthHistory();
			break;
		default:
			break;
		}
	} while (menu[menu_display.at(input)] != "Back to Main Page");
}

//------------------------------------------
//       M I L K   C O L L E C T I O N
//------------------------------------------
void MenuDisplay::MilkCollectionMenuPage(int staff_type)
{
	FancyText fancyheader;
	ScreenClass screenClass;
	map<int, int> menu_display;

	string menu[8] = 
	{ "Add New Milk Collection Record","Modify Milk Collection Record",
	  "Search Milk Collection Record", "View Milk Collection Records List",
	  "Delete Milk Collection Record", "Back to Main Page",
	  "View Total Milk Yield For Each Goat House", "View Total Milk Yield For Each Month"};

	switch (staff_type)
	{
	case 1: // Administrator
		menu_display.emplace(1, 0);
		menu_display.emplace(2, 1);
		menu_display.emplace(3, 2);
		menu_display.emplace(4, 3);
		menu_display.emplace(5, 4);
		menu_display.emplace(8, 5);
		menu_display.emplace(6, 6);
		menu_display.emplace(7, 7);
		break;
	case 2: // Farmer
		menu_display.emplace(1, 0);
		menu_display.emplace(2, 1);
		menu_display.emplace(3, 2);
		menu_display.emplace(4, 3);
		menu_display.emplace(5, 4);
		menu_display.emplace(6, 5);
		break;
	case 4: // Supervisor
		menu_display.emplace(1, 2);
		menu_display.emplace(2, 3);
		menu_display.emplace(3, 6);
		menu_display.emplace(4, 7);
		menu_display.emplace(5, 5);
		break;
	}

	int input;

	do
	{
		system("cls");
		fancyheader.MainHeader();
		fancyheader.MilkCollectionHeader();

		for (auto elem : menu_display)
		{
			cout << "\n\t\t\t\t " << elem.first << "-> " << menu[elem.second] << endl;
		}
		cout << "\n\t\t\t\t  Enter your choice: ";
		cin >> input;

		switch (menu_display.at(input)) //carry out selected action
		{
		case 0:
			screenClass.InsertViewMilkCollection();
			break;
		case 1:
			screenClass.UpdateViewMilkCollection();
			break;
		case 2:
			screenClass.SearchViewMilkCollection();
			break;
		case 3:
			screenClass.ListViewMilkCollection();
			break;
		case 4:
			screenClass.DeleteViewMilkCollection();
			break;
		case 6:
			screenClass.ViewTotalMilkYield();
			break;
		case 7:
			screenClass.ViewTotalMilkYieldByMonth();
			break;
		default:
			break;
		}
	} while (menu[menu_display.at(input)] != "Back to Main Page");
}

//------------------------------------------
//                S T A F F
//------------------------------------------
void MenuDisplay::StaffMenuPage(int staff_type)
{
	FancyText fancyheader;
	ScreenClass screenClass;
	map<int, int> menu_display;

	string menu[6] = { "Register New Staff","Modify Staff Detail","Search Staff Detail",
		"View Staff Details List","Delete Staff Detail","Back to Main Page" };

	switch (staff_type)
	{
	case 1: // Administrator
		menu_display.emplace(1, 0);
		menu_display.emplace(2, 1);
		menu_display.emplace(3, 2);
		menu_display.emplace(4, 3);
		menu_display.emplace(5, 4);
		menu_display.emplace(6, 5);
		break;
	}

	int input;

	do
	{
		system("cls");
		fancyheader.MainHeader();
		fancyheader.StaffHeader();

		for (auto elem : menu_display)
		{
			cout << "\n\t\t\t\t\t\t " << elem.first << "-> " << menu[elem.second] << endl;
		}
		cout << "\n\t\t\t\t\t\t  Enter your choice: ";
		cin >> input;

		switch (menu_display.at(input)) //carry out selected action
		{
		case 0:
			screenClass.InsertViewStaff();
			break;
		case 1:
			screenClass.UpdateViewStaff();
			break;
		case 2:
			screenClass.SearchViewStaff();
			break;
		case 3:
			screenClass.ListViewStaff();
			break;
		case 4:
			screenClass.DeleteViewStaff();
			break;
		default:
			break;
		}
	} while (menu[menu_display.at(input)] != "Back to Main Page");
}

//------------------------------------------
//           G O A T  S H E D
//------------------------------------------
void MenuDisplay::GoatShedMenuPage(int staff_type)
{
	FancyText fancyheader;
	ScreenClass screenClass;
	map<int, int> menu_display;

	string menu[6] = { "Register New Goat Shed","Modify Goat Shed Detail",
		"Search Goat Shed","View Goat Sheds List","Delete Goat Shed","Back to Main Page" };

	switch (staff_type)
	{
	case 1: // Administrator
		menu_display.emplace(1, 0);
		menu_display.emplace(2, 1);
		menu_display.emplace(3, 2);
		menu_display.emplace(4, 3);
		menu_display.emplace(5, 4);
		menu_display.emplace(6, 5);
		break;
	case 2: // Farmer
		menu_display.emplace(1, 2);
		menu_display.emplace(2, 3);
		menu_display.emplace(3, 5);
		break;
	}

	int input;

	do
	{
		system("cls");
		fancyheader.MainHeader();
		fancyheader.GoatShedHeader();

		for (auto elem : menu_display)
		{
			cout << "\n\t\t\t\t\t\t " << elem.first << "-> " << menu[elem.second] << endl;
		}
		cout << "\n\t\t\t\t\t\t  Enter your choice: ";
		cin >> input;

		switch (menu_display.at(input)) //carry out selected action
		{
		case 0:
			screenClass.InsertViewGoatShed();
			break;
		case 1:
			screenClass.UpdateViewGoatShed();
			break;
		case 2:
			screenClass.SearchViewGoatShed();
			break;
		case 3:
			screenClass.ListViewGoatShed();
			break;
		case 4:
			screenClass.DeleteViewGoatShed();
			break;
		default:
			break;
		}
	} while (menu[menu_display.at(input)] != "Back to Main Page");
}

//------------------------------------------
//       G O A T S H E D  I N  O U T
//------------------------------------------
void MenuDisplay::GoatShedInOutMenuPage(int staff_type)
{
	FancyText fancyheader;
	ScreenClass screenClass;
	map<int, int> menu_display;

	string menu[6] = { "Add Goat Shed In Out Record","Modify Goat Shed In Out Record","Search Goat Shed In Out Record",
		"View Goat Shed In Out Records List","Delete Goat Shed In Out Record","Back to Main Page" };

	switch (staff_type)
	{
	case 1: // Administrator
		menu_display.emplace(1, 0);
		menu_display.emplace(2, 1);
		menu_display.emplace(3, 2);
		menu_display.emplace(4, 3);
		menu_display.emplace(5, 4);
		menu_display.emplace(6, 5);
		break;
	case 2: // Farmer
		menu_display.emplace(1, 0);
		menu_display.emplace(2, 1);
		menu_display.emplace(3, 2);
		menu_display.emplace(4, 3);
		menu_display.emplace(5, 4);
		menu_display.emplace(6, 5);
		break;
	case 4: // Supervisor
		menu_display.emplace(1, 2);
		menu_display.emplace(2, 3);
		menu_display.emplace(3, 5);
		break;
	}

	int input;

	do
	{
		system("cls");
		fancyheader.MainHeader();
		fancyheader.GoatShedInOutHeader();

		for (auto elem : menu_display)
		{
			cout << "\n\t\t\t\t\t\t " << elem.first << "-> " << menu[elem.second] << endl;
		}
		cout << "\n\t\t\t\t\t\t  Enter your choice: ";
		cin >> input;

		switch (menu_display.at(input)) //carry out selected action
		{
		case 0:
			screenClass.InsertViewGoatShedInOut();
			break;
		case 1:
			screenClass.UpdateViewGoatShedInOut();
			break;
		case 2:
			screenClass.SearchViewGoatShedInOut();
			break;
		case 3:
			screenClass.ListViewGoatShedInOut();
			break;
		case 4:
			screenClass.DeleteViewGoatShedInOut();
			break;
		default:
			break;
		}
	} while (menu[menu_display.at(input)] != "Back to Main Page");

}