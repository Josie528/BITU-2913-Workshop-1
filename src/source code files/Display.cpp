#include<iostream>
#include<string>
#include "timeSQL.h"
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

/**
 * List of Full Health History
 */
void ClassManager::displayHealthHistory()
{
    system("cls");
    cout << "+---------------------------+\n";
    cout << "  ---- HEALTH HISTORY ----\n";
    cout << "+---------------------------+";

    /*Table Header*/
    cout << setw(11) << "Health History ID" << setw(20) << "Sickness" << setw(20) << "Treatment" << 
        setw(15) << "Date of Record" << setw(20) << "Symptom" << setw(11) << "Goat ID" << endl;

    /*Choose Edit(Update/Del) or Add Diagnosis Info*/
}

void ClassManager::displayGoatShed()
{
    system("cls");
    cout << "+---------------------+\n";
    cout << "  ---- GOAT SHED ----\n";
    cout << "+---------------------+";

    /*Table Header*/
    cout << setw(11) << "Goat Shed ID" << setw(20) << "Title" 
        << setw(20) << "Description"<< setw(10) <<"Goat Count" <<endl;

    /*Choose Edit(Update/Del) or Add New Goat Shed */

}

void ClassManager::displayMilkCollection()
{
    system("cls");
    cout << "+-----------------------------------+\n";
    cout << "  ---- MILK COLLECTION RECORD ----\n";
    cout << "+-----------------------------------+";
}

void ClassManager::displayStaff()
{
    system("cls");
    cout << "+------------------+\n";
    cout << "  ---- STAFF ----\n";
    cout << "+------------------+";
}

void ClassManager::displayGoatBirth()
{
    system("cls");
    cout << "+----------------------+\n";
    cout << "  ---- GOAT BIRTH ----\n";
    cout << "+----------------------+";
}

void ClassManager::displayFeed()
{
    system("cls");
    cout << "+---------------------+\n";
    cout << "  ---- FEED LIST ----\n";
    cout << "+---------------------+";
}

void ClassManager::displayFeedingRecord()
{
    system("cls");
    cout << "+---------------------------+\n";
    cout << "  ---- FEEDING RECORD ----\n";
    cout << "+---------------------------+";
}

void ClassManager::displayGoatShedInOut()
{
    cout << "+-------------------------------- +";
    cout << "   ----  GOAT SHED IN OUT  ----   ";
    cout << "+ -------------------------------- +";
}
