#include<iostream>
#include<string>
#include<iomanip>
#include "TimeUtility.h"
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


void ClassManager::InputHealthHistory(string &hID, string &hsick, string &htreat,
    time_t& hdaterec, string &hsymp, string &hgID)
{
    /*Initial load*/
    system("cls");

    cout << "+---------------------------+\n";
    cout << "  ---- HEALTH HISTORY ----\n";
    cout << "+---------------------------+\n\n";

    cout << ">> Enter details to add a new health record" << endl;
    cout << "Health History ID: " << endl;
    getline(cin, hID);
    cout << "Sickness: " << endl;
    getline(cin, hsick);
    cout << "Treatment: " << endl;
    getline(cin, htreat);
    cout << "Date of Record: " << endl;
    cin >> hdaterec;
    cout << "Symptom: " << endl;
    getline(cin, hsymp);
    cout << "Goat ID: " << endl;
    getline(cin, hgID);
    
    cout << ">> Registration success!" << endl;
    cout << ">> Query Execution Problem. Please try again." << endl;

    /*Table Header*/
    cout << setw(11) << "Health History ID" << setw(20) << "Sickness" << setw(20) << "Treatment" << 
        setw(15) << "Date of Record" << setw(20) << "Symptom" << setw(11) << "Goat ID" << endl;

    /*Choose Edit(Update/Del) or Add Diagnosis Info*/

}

void ClassManager::InputGoatShed(string &gsID, string &gstitle, string &gsdesc)
{
    /*Initial load*/
    system("cls");

    cout << "+---------------------+\n";
    cout << "  ---- GOAT SHED ----\n";
    cout << "+---------------------+\n\n";

    cout << ">> Enter details to register a new goat shed" << endl;
    cout << "Goat Shed ID: " << endl;
    getline(cin, gsID);
    cout << "Title: " << endl;
    getline(cin, gstitle);
    cout << "Description" << endl;
    getline(cin, gsdesc);

    cout << ">> Registration success!" << endl;
    cout << ">> Query Execution Problem. Please try again." << endl;

    /*Table Header*/
    cout << setw(11) << "Goat Shed ID" << setw(20) << "Title" 
        << setw(20) << "Description"<< setw(10) <<"Goat Count" <<endl;

    /*Choose Edit(Update/Del) or Add New Goat Shed */

}

void ClassManager::InputMilkCollection(string &mgID, string &msID,
    string &mgsID, int &mqty, time_t &mdatecol)
{
    /*Initial Load*/
    system("cls");
    cout << "+-----------------------------------+\n";
    cout << "  ---- MILK COLLECTION RECORD ----\n";
    cout << "+-----------------------------------+\n\n";

    cout << ">> Enter details to add milk collection record " << endl;
    cout << "Goat ID: " << endl;
    getline(cin, mgID);
    cout << "Record by: " << endl;
    getline(cin, msID);
    cout << "Goat Shed ID: " << endl;
    getline(cin, mgsID);
    cout << "Milk Yield (litres)" << endl;
    cin >> mqty;
    cout << "Date of Collect: " << endl;
    cin >> mdatecol;

    cout << ">> Registration success!" << endl;
    cout << ">> Query Execution Problem. Please try again." << endl;
}

void ClassManager::InputGoatBirth(string &gID, string &gtype, string &gparentgID,
    string &ghealthstatus, string &ggender, time_t &gDOB)
{
    /*Initial Load*/
    system("cls");
    cout << "+----------------------+\n";
    cout << "  ---- GOAT BIRTH ----\n";
    cout << "+----------------------+\n\n";

    cout << ">> Enter details to register new arrival goat " << endl;
    cout << "Goat ID: " << endl;
    getline(cin, gID);
    cout << "Goat Type: " << endl;
    getline(cin, gtype);
    cout << "Parent ID: " << endl;
    getline(cin, gparentgID);
    cout << "Health Status: " << endl;
    getline(cin, ghealthstatus);
    cout << "Date of Birth: " << endl;
    cin >> gDOB;
}

void ClassManager::InputFeed(string &fID, string &ftype, double &fcal, double &fphos,
    double &fpotassium, double &fcu, double &fzinc)
{
    /*Initial Load*/
    system("cls");
    cout << "+---------------------+\n";
    cout << "  ---- FEED LIST ----\n";
    cout << "+---------------------+\n\n";

    cout << ">> Enter details to register new feed " << endl;
    cout << "Feed ID: " << endl;
    getline(cin, fID);
    cout << "Feed Type: " << endl;
    getline(cin, ftype);
    cout << "Calcium(g/kg): " << endl;
    cin >> fcal;
    cout << "Phosphorus(g/kg): " << endl;
    cin >> fphos;
    cout << "Potassium(g/kg): " << endl;
    cin >> fpotassium;
    cout << "Copper(mg/kg): " << endl;
    cin >> fcu;
    cout << "Zinc(mg/kg): " << endl;
    cin >> fzinc;
}

void ClassManager::InputFeedingRecord(string &frgID, string &frfID,
    string &frsID, int &frqty, time_t &frfeedtime)
{
    /*Initial Load*/
    system("cls");
    cout << "+---------------------------+\n";
    cout << "  ---- FEEDING RECORD ----\n";
    cout << "+---------------------------+\n\n";

    cout << ">> Enter details to add new feeding record " << endl;
    cout << "Goat ID: " << endl;
    getline(cin, frgID);
    cout << "Feed Record ID: " << endl;
    getline(cin, frfID);
    cout << "Record by: " << endl;
    getline(cin,frsID);
    cout << "Feed Quantity(kg): " << endl;
    cin >> frqty;
    cout << "Feed Time: " << endl;
    cin >> frfeedtime;
}

void ClassManager::InputGoatShedInOut(string &iogsID, string &iogID, time_t &iodatein, time_t &iodateout)
{
    /*Initial Load*/
    system("cls");
    cout << "+-------------------------------+\n";
    cout << "  ----  GOAT SHED IN OUT  ----\n";
    cout << "+-------------------------------+\n\n";

    cout << ">> Enter details to add new feeding record " << endl;
    cout << "Goat Shed ID: " << endl;
    getline(cin, iogsID);
    cout << "Goat ID: " << endl;
    getline(cin, iogID);
    cout << "Date In: " << endl;
    cin >> iodatein;
    cout << "Date Out: " << endl;
    cin >> iodateout;
}
