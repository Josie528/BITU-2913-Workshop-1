#include<iostream>
#include "HealthHistory.h"
#include "ClassManager.h"
#include "TimeUtility.h"

using namespace std;



int main()
{
	/*Staff staff;
	Login login;
	int staffType = login.LoginPage(staff);

	cout << "The function returns " << staffType << endl;
	cout << "Staff information:" << endl;
	cout << "ID         : " << staff.staffID << endl;
	cout << "Name       : " << staff.name << endl;
	cout << "Type       : " << staff.staffType << endl;
	cout << "Gender     : " << staff.gender << endl;
	cout << "Contact No.: " << staff.telNo << endl;*/

	HealthHistory goatHist;

	goatHist.goatID = "B03202";
	goatHist.dateOfRecord = time(0);
	goatHist.healthHistoryID = "ABC";
	goatHist.sickness = "Stomach irritation";
	goatHist.symptom = "Vomiting";
	goatHist.treatment = "Capsule";

	cout << "Done initialisation" << endl;

	ClassManager healthManage;

	cout<<healthManage.insert(&goatHist);

	return 0;
}