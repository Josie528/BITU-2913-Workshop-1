#include<iostream>
#include<string>
#include<ctime>
#include <iomanip>
#include "TimeUtility.h"
#include "ClassManager.h"
#include "MenuDisplay.h"
#include "Login.h"
#include "StaffTypeMenu.h"
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
#include "FancyText.h"


void StaffTypeMenu::staffTypeMenu(int staff_type)
{
	FancyText fancyheader;
	map<int, int> menu_display;
	MenuDisplay menupage;

	string menu[9] = {"Staff","Goat Birth","Goat Shed","Goat Shed In Out","Milk Collection",
		"Feed","Feeding Record","Health History","Exit"};

	switch (staff_type)
	{
	case 1: // Admin
		menu_display.emplace(1, 0);
		menu_display.emplace(2, 1);
		menu_display.emplace(3, 2);
		menu_display.emplace(4, 3);
		menu_display.emplace(5, 4);
		menu_display.emplace(6, 5);
		menu_display.emplace(7, 6);
		menu_display.emplace(8, 7);
		menu_display.emplace(9, 8);
		break;
	case 2: // Farmer
		menu_display.emplace(1, 1);
		menu_display.emplace(2, 2);
		menu_display.emplace(3, 3);
		menu_display.emplace(4, 4);
		menu_display.emplace(5, 5);
		menu_display.emplace(6, 8);
		break;
	case 3: // Veterinarian ONLY access Health History Menu
		menupage.HealthHistoryMenuPage(staff_type);
		return; //quit func at this point
		break;
	case 4: // Supervisor
		menu_display.emplace(1, 3); 
		menu_display.emplace(2, 4);
		menu_display.emplace(3, 6);
		menu_display.emplace(4, 7);
		menu_display.emplace(5, 8);
		break;
	}

	int input;

	do
	{
		system("cls");
		fancyheader.MainHeader();
		int space_width;
		switch (staff_type)
		{
		case 1:
			space_width = 37;
			cout << "\t\t\t\t  __| |_____________________________________| |__ " << endl;
			cout << "\t\t\t\t (__   _____________________________________   __)" << endl;
			cout << "\t\t\t\t    | |                                     | |   " << endl;
			cout << "\t\t\t\t    | |    A D M I N   M E N U   P A G E    | |   " << endl;
			cout << "\t\t\t\t  __| |_____________________________________| |__ " << endl;
			cout << "\t\t\t\t (__   _____________________________________   __)" << endl;
			cout << "\t\t\t\t    | |                                     | |   " << endl;
			break;
		case 2:
			space_width = 39;
			cout << "\t\t\t\t  __| |_______________________________________| |__ " << endl;
			cout << "\t\t\t\t (__   _______________________________________   __)" << endl;
			cout << "\t\t\t\t    | |                                       | |   " << endl;
			cout << "\t\t\t\t    | |    F A R M E R   M E N U   P A G E    | |   " << endl;
			cout << "\t\t\t\t  __| |_______________________________________| |__ " << endl;
			cout << "\t\t\t\t (__   _______________________________________   __)" << endl;
			cout << "\t\t\t\t    | |                                       | |   " << endl;
			break;
		case 4:
			space_width = 47;
			cout << "\t\t\t\t  __| |_______________________________________________| |__ " << endl;
			cout << "\t\t\t\t (__   _______________________________________________   __)" << endl;
			cout << "\t\t\t\t    | |                                               | |   " << endl;
			cout << "\t\t\t\t    | |    S U P E R V I S O R   M E N U   P A G E    | |   " << endl;
			cout << "\t\t\t\t  __| |_______________________________________________| |__ " << endl;
			cout << "\t\t\t\t (__   _______________________________________________   __)" << endl;
			cout << "\t\t\t\t    | |                                               | |   " << endl;
			break;
		}
		


		for (auto elem : menu_display)
		{
			cout << "\t\t\t\t    | |\t" << elem.first << "-> " << menu[elem.second];
			std::ios oldState(nullptr);
			oldState.copyfmt(std::cout);
			cout << setw(space_width + 6 - (4 + 1 + 3 + menu[elem.second].length())) << "| |" << endl;
			std::cout.copyfmt(oldState);
			
			if (menu[elem.second] == "Exit")
			{
				cout << "\t\t\t\t  __| |" << setw(space_width) <<setfill('_');
				cout << "";
				std::cout.copyfmt(oldState);
				cout << "| |__" << endl;
				cout << "\t\t\t\t (__   " << setw(space_width) << setfill('_');
				cout << "";
				std::cout.copyfmt(oldState);
				cout << "   __)" << endl;
				cout << "\t\t\t\t    | |" << setw(space_width);
				cout << "";
				std::cout.copyfmt(oldState);
				cout << "| |" << endl;
			}
			else
			{
				cout << "\t\t\t\t    | |" << setw(space_width);
				cout << "";
				std::cout.copyfmt(oldState);
				cout << "| |" << endl;
			}
		}

		cout << "\n\t\t\t\t\t  Enter your choice: ";
		cin >> input;

		// Carry out selected action
		switch (menu_display.at(input)) 
		{
		case 0:
			menupage.StaffMenuPage(staff_type);
			break;
		case 1:
			menupage.GoatMenuPage(staff_type);
			break;
		case 2:
			menupage.GoatShedMenuPage(staff_type);
		case 3:
			menupage.GoatShedInOutMenuPage(staff_type);
			break;
		case 4:
			menupage.MilkCollectionMenuPage(staff_type);
			break;
		case 5:
			menupage.FeedMenuPage(staff_type);
			break;
		case 6:
			menupage.FeedingRecordMenuPage(staff_type);
			break;
		case 7:
			menupage.HealthHistoryMenuPage(staff_type);
			break;
		default:
			break;
		}
	} while (menu[menu_display.at(input)] != "Exit");
}