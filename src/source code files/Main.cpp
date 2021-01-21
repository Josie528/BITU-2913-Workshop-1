#include<iostream>
#include<string>
#include<limits>
#include "ClassManager.h"
#include "Login.h"
#include "TimeUtility.h"
#include "MenuDisplay.h"
#include "StaffTypeMenu.h"

using namespace std;

#include <mysql/jdbc.h>
using namespace sql;

#include "DatabaseConnection.h"

/*
* Display menu based on user's staff type,
* Call appropriate action menu based on user's choice.
*/
int main()
{
	Staff staff;
	Login login;
	int staffType;
	

	do
	{
		staffType = login.LoginPage(staff);

		if (staffType == 0)
			continue; //break if occur, cont nxt iteration

		StaffTypeMenu stafmenu;
		stafmenu.staffTypeMenu(staffType);

	} while (staffType != 0);
	
	return 0;
}

