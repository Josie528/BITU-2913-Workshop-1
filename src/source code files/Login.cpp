#include<iostream>
#include<string>
#include "Login.h"

using namespace std;

#include <mysql/jdbc.h>
using namespace sql;

#include "DatabaseConnection.h"

void Login::welcome()
{
	cout << "  __| |____________________________________________| |__ " << endl;
	cout << " (__   ____________________________________________   __)" << endl;
	cout << "    | |                                            | |   " << endl;
	cout << "    | |                 WELCOME TO                 | |   " << endl;
	cout << "    | |         GOAT FARM MANAGEMENT SYSTEM        | |   " << endl;
	cout << "    | |         ===========================        | |   " << endl;
	cout << "    | |         Author    : PANG JIA MEI           | |   " << endl;
	cout << "    | |         Matric No : B031910436		        | |   " << endl;
	cout << "  __| |____________________________________________| |__ " << endl;
	cout << " (__   ____________________________________________   __)" << endl;
	cout << "    | |                                            | |   " << endl;
}

void Login::InputName(string &Name,string &Password)
{
	//Prompt user enter name and password
	cout << "Enter your full name " << endl;
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	getline(cin, Name);

	cout << "Enter your password" << endl;
	getline(cin, Password);

}

/* 1 -> Admin
* 2 -> Farmer
* 3 -> Vets
* 4 -> Supervisor*/
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
	int answ =  -1;
	if (rs->next())
	{
		cout << "Login successful, redirecting to main menu..." << endl;
		// extract staff information from RS (make staff.h)
		staff.staffID = rs->getString(1);
		staff.name = rs->getString(2);
		staff.staffType = rs->getString(3);
		staff.password = rs->getString(4);
		staff.telNo = rs->getString(5);
		staff.gender = rs->getString(6);

		if (staff.staffType == "Administrator")
			answ = 1;
		else if (staff.staffType == "Farmer")
			answ = 2;
		else if (staff.staffType == "Veterinarian")
			answ = 3;
		else 
			answ = 4;
	}
	else
	{
		cout << "Wrong username or password, redirecting to homepage..." << endl;
	}

	delete rs;
	delete ps;

	return answ;
}

//return an int indicating staff type, or return 0 to exit program
int Login::LoginPage(Staff &staff) // pass by ref a staff 
{
	

	//Display menu
	welcome();
	
	string Input;
	int Control = -1;
	while (Control == -1)
	{
		cout << "Select an action" << endl;
		cout << "----------------" << endl;
		cout << "1. Login" << endl;
		cout << "2. Exit" << endl;
		cin >> Input;

		if (Input == "1")
		{
			Login login;
			Control = login.tryLogin(staff);
		}
		else if (Input == "2")
		{
			Control = 0;
		}
		else
		{
			cout << "Invalid Input. Please try again." << endl;
		}


	}
	

	return Control;
}