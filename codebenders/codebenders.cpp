#include <iostream>
#include <string>
using namespace std;

enum role
{
    scrumTrainor,
    QAEngineer,
    developerBackend,
    developerFrontend
};

enum status
{
    inUse,
    notActive,
    notArchived
};

struct DATE
{
    int day;
    int month;
    int year;
};

struct STUDENT
{
    string name;
    string surname;
    int schoolYear;
    char className;
    role teamRole;
    string email;
};

struct TEAM
{
    string name;
    string description;
    DATE dateOfSetUp;
    STUDENT teammates[4];
    status teamStatus;
};

struct TEACHER
{
    string name;
    string surname;
    TEAM teams[5];
    string email;
};

int main()
{
   

}
