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

struct ADDRESS
{
    string streetName;
    string streetNumber;
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

struct SCHOOL
{
    string name;
    string city;
    ADDRESS address;
    TEACHER teachers[20];
    TEAM teams[20];
    STUDENT students[300];
};


void initStudents(STUDENT* students, int& index)
{
    students[0] = { "Maria", "Georgieva", 10, 'A', role::scrumTrainor, "mariaG@abv.bg" };
    students[1] = { "Veselin", "Atanasov", 9, 'B', role::QAEngineer, "vesel@gmail.com" };
    students[2] = { "Ivan", "Stanimirov", 9, 'V', role::developerBackend, "ivancho@gmail.com" };
    students[3] = { "Georgi", "Petrov", 10, 'G', role::scrumTrainor, "gogo@abv.bg" };
    students[4] = { "Kameliya", "Ivanova", 8, 'B', role::developerFrontend, "kIvanova@codingburgas.bg" };
    students[5] = { "Zhivko", "Vladimirov", 10, 'B', role::developerBackend, "jiwkoV@abv.bg" };
    students[6] = { "Aneliya", "Shishmanova", 10, 'V', role::developerBackend, "aneliq04@gamil.com" };
    students[7] = { "Stoyan", "Dobrev", 8, 'G', role::QAEngineer, "sDobrev@abv.bg" };

    index = 8;
}

void showStudent(STUDENT* students, int index)
{
    cout << "Student ID: " << index + 1<<endl;
    cout << "  Name: "<<students[index].name << " " << students[index].surname<<endl;
    cout << "  Class: " << students[index].schoolYear << " " << students[index].className << endl;
    cout << "  Role: ";
    if (students[index].teamRole==0)
        cout<<"Scrum Trainor"<< endl;
    else if (students[index].teamRole == 1)
        cout << "QA Engineer" << endl;
    else if (students[index].teamRole == 2)
        cout << "Backend Developer" << endl;
    else
        cout << "Frontend Developer" << endl;
    cout << "  E-mail: " << students[index].email << endl;
}

void showStudents(STUDENT* students, int index)
{

    cout << "List of students: " << endl<<endl;
    for (int i = 0; i < index; i++)
    {
        showStudent(students, i);
        cout << endl;
    }
}

int main()
{
    STUDENT students[100];
    int st_index = 0;

    initStudents(students, st_index);
    showStudents(students, st_index);
}
