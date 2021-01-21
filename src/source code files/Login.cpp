#include<iostream>
#include<limits>
#include<string>
#include<cstdio>
#include<ctime>
#include "Login.h"
#include "TimeUtility.h"
#include "FancyText.h"

using namespace std;

#include <mysql/jdbc.h>
using namespace sql;

#include "DatabaseConnection.h"

void Login::InputName(string &Name,string &Password)
{
	//Prompt user enter name and password
	cout << "\n\t\t\t\t\tEnter your full name - ";
	cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
	getline(cin, Name);

	cout << "\n\t\t\t\t\tEnter your password - ";
	getline(cin, Password);
}

/* 
 * 1 -> Admin
 * 2 -> Farmer
 * 3 -> Vets
 * 4 -> Supervisor
*/
//try to login -> if successful return an int indicating staff type, else return -1
int Login::tryLogin(Staff &staff) // get pass by reference of a staff
{
	string Name, Password;
	InputName(Name,Password);
	DatabaseConnection Conn;
	PreparedStatement* ps = Conn.prepareStatement("SELECT * FROM Staff WHERE Name = ? AND Password = ? ");
	ps->setString(1, Name);
	ps->setString(2, Password);

	ResultSet* rs = ps->executeQuery();
	int staff_type =  -1;
	if (rs->next())
	{
		cout << "\n\t\t\t\t    [ Login successful, redirecting to main menu... ]" << endl;
		
		// extract staff information from RS (make staff.h)
		staff.staffID = rs->getString(1);
		staff.name = rs->getString(2);
		staff.staffType = rs->getString(3);
		staff.password = rs->getString(4);
		staff.telNo = rs->getString(5);
		staff.gender = rs->getString(6);

		if (staff.staffType == "Administrator")
			staff_type = 1;
		else if (staff.staffType == "Farmer")
			staff_type = 2;
		else if (staff.staffType == "Veterinarian")
			staff_type = 3;
		else
			staff_type = 4;
	}
	else
	{
		//will return -1
		cout << "\n\t\t\t\t    [ Wrong username or password, redirecting to homepage... ]" << endl;
	}

	system("Pause");

	delete rs;
	delete ps;

	return staff_type;
}

//return an int indicating staff type, or return 0 to exit program
int Login::LoginPage(Staff &staff) // pass by ref a staff 
{	
	FancyText fancyheader;
	string Input;
	int Control = -1;
	while (Control == -1)
	{
		system("cls");
		//Display menu
		fancyheader.MainHeader();

		cout << "\t\t\t\t  __| |____________________________________________| |__ " << endl;
		cout << "\t\t\t\t (__   ____________________________________________   __)" << endl;
		cout << "\t\t\t\t    | |                                            | |   " << endl;
		cout << "\t\t\t\t    | |            HI, WELCOME BACK TO             | |   " << endl;
		cout << "\t\t\t\t    | |         GOAT FARM MANAGEMENT SYSTEM        | |   " << endl;
		cout << "\t\t\t\t    | |         +++++++++++++++++++++++++++        | |   " << endl;
		cout << "\t\t\t\t    | |               (1) LOGIN                    | |   " << endl;
		cout << "\t\t\t\t    | |               (2) EXIT                     | |   " << endl;
		cout << "\t\t\t\t  __| |____________________________________________| |__ " << endl;
		cout << "\t\t\t\t (__   ____________________________________________   __)" << endl;
		cout << "\t\t\t\t    | |                                            | |   " << endl;

		cout << "\t\t\t\t\tEnter your choice : ";
		cin >> Input;

		if (Input == "1")
		{
			Login login;
			Control = login.tryLogin(staff);
		}
		else if (Input == "2")
		{
			Control = 0;
			cout << "\n\n\t\t\t\t [ Thank you for using our services. Have a nice day. ]" << endl;
		}
		else
		{
			cout << "\n\n\t\t\t\t\t[ Invalid Input. Please try again. ]" << endl;
			system("pause");
		}
	}
	

	return Control; //Quit
}