#include <iostream>
#include <string>
using namespace std;

enum role
{
    scrumTrainer,
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
    role teamRole = role::scrumTrainer;
    string email;
};

struct TEAM
{
    string name;
    string description;
    DATE dateOfSetUp;
    STUDENT teammates[4];
    status teamStatus = status::notArchived;
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
    students[0] = { "Maria", "Georgieva", 10, 'A', role::scrumTrainer, "mariaG@abv.bg" };
    students[1] = { "Veselin", "Atanasov", 9, 'B', role::QAEngineer, "vesel@gmail.com" };
    students[2] = { "Ivan", "Stanimirov", 9, 'V', role::developerBackend, "ivancho420@gmail.com" };
    students[3] = { "Georgi", "Ognyanov", 10, 'G', role::scrumTrainer, "gogo@abv.bg" };
    students[4] = { "Kameliya", "Ivanova", 8, 'B', role::developerFrontend, "kIvanova@codingburgas.bg" };
    students[5] = { "Zhivko", "Vladimirov", 10, 'B', role::developerBackend, "jiwkoV@abv.bg" };
    students[6] = { "Aneliya", "Shishmanova", 10, 'V', role::developerBackend, "aneliq04@gamil.com" };
    students[7] = { "Stoyan", "Dobrev", 8, 'G', role::QAEngineer, "sDobrev@abv.bg" };
    students[8] = { "Galin", "Georgiev", 8, 'G', role::scrumTrainer, "gggeorgiev@yahoo.org" };
    students[9] = { "Galena", "Hadzhieva", 9, 'V', role::developerBackend, "geymarkata@gmail.com"};
    students[10] = { "Didi", "Popova", 10, 'A', role::QAEngineer, "Dida_D@abv.bg" };
    students[11] = { "Radomir", "Liliev", 9, 'B', role::scrumTrainer, "RadoGashtite@gmail.com" };


    index = 12;
}

void showStudent(STUDENT* students, int index)
{
    cout << "Student ID: " << index + 1<<endl;
    cout << "  Name: "<<students[index].name << " " << students[index].surname<<endl;
    cout << "  Class: " << students[index].schoolYear << " " << students[index].className << endl;
    cout << "  Role: ";
    if (students[index].teamRole==0)
        cout<<"Scrum Trainer"<< endl;
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

void enterStudent(STUDENT* students, int& index)
{
    int choice;

    cout << "Enter info about student:" << endl;

    cout << " First and last name: ";
    cin >> students[index].name >> students[index].surname;

    cout << " Class (number and letter): ";
    cin >> students[index].schoolYear >> students[index].className;

    cout << " Role in team: "<<endl;
    cout << "  1. Scrum Trainer" << endl;
    cout << "  2. QA Engineer" << endl;
    cout << "  3. Backend Developer" << endl;
    cout << "  4. Frontend Developer" << endl;
    cout << "Enter choice: ";
    cin >> choice;
    students[index].teamRole = role(choice-1);

    cout << "E-mail: ";
    cin >> students[index].email;

    index++;
}

void deleteStudent(STUDENT* students, int& index, int position)
{
    for (int i = position; i < index-1; i++)
    {
        students[i] = students[i + 1];
    }

    index--;
}


void initTeams(STUDENT* students, int& index, TEAM* teams, int& t_index)
{
    teams[0] = { "Vikings", "We are here to win!", {10,2,2021}, {students[2], students[4], students[10]}, status::notActive };
    teams[1] = { "We Showed Up", "Hoping for the best with minimum effort!", {13,2,2021}, {students[7], students[9], students[11]}, status::inUse };
    teams[2] = { "Cereal Killers", "Trying our best", {20, 2, 2021},  {students[0], students[1], students[5]}, status::notArchived };

    t_index = 3;
}

void showTeam(STUDENT* students, TEAM* teams, int& t_index, int teamMembers)
{
    cout << "Name: " << teams[t_index].name<<endl;
    cout << "Description: " << teams[t_index].description << endl;
    cout << "Date of set-up: " << teams[t_index].dateOfSetUp.day << "/" 
        << teams[t_index].dateOfSetUp.month << "/" << teams[t_index].dateOfSetUp.year << endl;
    cout << "Teammates: " << endl;
    for (int i = 0; i < teamMembers; i++)
    {
        cout << " " << i + 1 << ". " << teams[t_index].teammates[i].name << " " << teams[t_index].teammates[i].surname << " - ";
       
        if (teams[t_index].teammates[i].teamRole == 0)
            cout << "Scrum Traner" << endl;
        else if (teams[t_index].teammates[i].teamRole == 1)
            cout << "QA Engineer" << endl;
        else if (teams[t_index].teammates[i].teamRole == 2)
            cout << "Backend Developer" << endl;
        else
            cout << "Frontend Developer" << endl;
    }

        cout << "Status: ";
    if (teams[t_index].teamStatus == 0)
        cout << "In use";
    else if (teams[t_index].teamStatus == 1)
        cout << "Not active";
    else
        cout << "Not archived";
}

void showTeams(STUDENT* students, TEAM* teams, int& t_index, int teamMembers)
{
    cout << "List of teams: " << endl << endl;
    for (int i = 0; i < t_index; i++)
    {
        showTeam(students, teams, i, teamMembers);
        cout << endl << endl;
    }
}

void enterTeam(STUDENT* students,  TEAM* teams, int& t_index)
{
    int number,id;

    cout << "Enter info about a new team:" << endl;

    cout << "Name of the team: ";
    getline (cin, teams[t_index].name);
    

    cout << "Description: ";
    getline (cin,teams[t_index].description);

    cout << "Date of set up: "<<endl;
    cout << " Day: ";
    cin >> teams[t_index].dateOfSetUp.day;
    cout << " Month: ";
    cin >> teams[t_index].dateOfSetUp.month;
    cout << " Year: ";
    cin >> teams[t_index].dateOfSetUp.year;

    cout << "Number of members: ";
    cin >> number;

    cout << "Enter the ID numbers of the members of the team: "<<endl;
    for (int i = 0; i < number; i++)
    {
        cout << " " << i + 1 << ". ";
        cin >> id;
        teams[t_index].teammates[i] = students[id-1];
    }

    t_index++;
}

void deleteTeam(TEAM* teams, int& t_index, int position)
{
    for (int i = position; i < t_index - 1; i++)
    {
        teams[i] = teams[i + 1];
    }

    t_index--;
}


void initTeachers(TEAM* teams, TEACHER* teachers, int& tch_index)
{
    teachers[0] = { "Ivelina", "Staykova", {teams[0], teams[1]}, "iStaikova@abv.bg" };
    teachers[1] = { "Yordan", "Kamenov", {teams[2]}, "yordanKA@gmail.com" };

    tch_index = 2;
}

void showTeacher(TEAM* teams, TEACHER* teachers, int& tch_index, int numberTeams)
{
    cout << "First and last name: "<<teachers[tch_index].name<<" "<< teachers[tch_index].surname<<endl;
    cout << "Teams they assist: "<<endl;
    for (int i = 0; i < numberTeams; i++)
    {
        cout << " " << i + 1 << ". " << teachers[tch_index].teams[i].name << endl;
    }
    cout << "E-mail: " << teachers[tch_index].email << endl;
}

void showTeachers(TEAM* teams, TEACHER* teachers, int& tch_index, int numberTeams)
{
    cout << "List of teachers: " << endl << endl;
    for (int i = 0; i < tch_index; i++)
    {
        showTeacher(teams, teachers, i, numberTeams);
        cout << endl << endl;
    }
}

void enterTeacher(TEAM* teams, TEACHER* teachers, int& tch_index)
{
    int number,id; 

    cout << "Enter info about teacher:" << endl;

    cout << "First name: ";
    cin >> teachers[tch_index].name;

    cout << "Last name: ";
    cin >> teachers[tch_index].surname;

    cout << "E-mail: ";
    cin >> teachers[tch_index].email;

    cout << "Number of teams they assist: ";
    cin >> number;

    cout << "Enter the IDs of the teams they assist:" << endl;
    for (int i = 0; i < number; i++)
    {
        cout << " " << i + 1 << ". ";
        cin >> id;
        teachers[tch_index].teams[i] = teams[id - 1];
    }

    tch_index++;
}

void deleteTeacher(TEACHER* teachers, int& tch_index, int position)
{
    for (int i = position; i < tch_index - 1; i++)
    {
        teachers[i] = teachers[i + 1];
    }

    tch_index--;
}



void greetings()
{
    cout << "Hello from us, the codebenders and welcome to out program!"<<endl<<endl;
}

int searchByStatus()
{
    cout << "1. In use" << endl;
    cout << "2. Not active" << endl;
    cout << "3. Not archived" << endl;

    char userChoice;
    cout << "Enter your choice: ";
    cin >> userChoice;
    switch (userChoice)
    {
    case '1':
        return true;
        break;
    case '2':
        return true;
        break;
    case '3':
        return true;
        break;
    default:
        cout << "Try entering a valid option" << endl;
        break;
    }
    return false;
}

int changeStatus()
{
    cout << "1. In use" << endl;
    cout << "2. Not active" << endl;
    cout << "3. Not archived" << endl;

    char userChoice;
    cout << "Enter your choice: ";
    cin >> userChoice;
    switch (userChoice)
    {
    case '1':
        return true;
        break;
    case '2':
        return true;
        break;
    case '3':
        return true;
        break;
    default:
        cout << "Try entering a valid option" << endl;
        break;
    }
    return false;
}

int searchStudentByCriteria()
{
    cout << "1. Name" << endl;
    cout << "2. Class" << endl;
    cout << "3. Role" << endl;
    cout << "4. Without a team" << endl;

    char userChoice;
    cout << "Enter your choice: ";
    cin >> userChoice;
    switch (userChoice)
    {
    case '1':
        return true;
        break;
    case '2':
        return true;
        break;
    case '3':
        return true;
        break;
    case '4':
        return true;
        break;
    default:
        cout << "Try entering a valid option" << endl;
        break;
    }
    return false;
}

int updateStudentInfo() {
    cout << "1. Name" << endl;
    cout << "2. Class" << endl;
    cout << "3. Email" << endl;
    cout << "4. Team role" << endl;

    char userChoice;
    cout << "Enter your choice: ";
    cin >> userChoice;
    switch (userChoice)
    {
    case '1':
        return true;
        break;
    case '2':
        return true;
        break;
    case '3':
        return true;
        break;
    case '4':
        return true;
        break;
    default:
        cout << "Try entering a valid option" << endl;
        break;
    }
    return false;
}

int searchTeamByCriteria()
{
    cout << "1. Name" << endl;
    cout << "2. Number of members" << endl;
    cout << "3. Status" << endl;


    char userChoice;
    cout << "Enter your choice: ";
    cin >> userChoice;
    switch (userChoice)
    {
    case '1':
        return true;
        break;
    case '2':
        return true;
        break;
    case '3':
        searchByStatus();
        return true;
        break;
    default:
        cout << "Try entering a valid option" << endl;
        break;
    }
    return false;
}

int updateTeamInfo()
{
    cout << "1. Name"<<endl;
    cout << "2. Description" << endl;
    cout << "3. Status" << endl;

    char userChoice;
    cout << "Enter your choice: ";
    cin >> userChoice;
    switch (userChoice)
    {
    case '1':
        return true;
        break;
    case '2':
        return true;
        break;
    case '3':
        changeStatus();
        return true;
        break;
    default:
        cout << "Try entering a valid option" << endl;
        break;
    }
    return false;
}

int searchTeacherByCriteria() 
{
    cout << "1. Name"<<endl;
    cout << "2. Team"<<endl;

    char userChoice;
    cout << "Enter your choice: ";
    cin >> userChoice;
    switch (userChoice)
    {
    case '1':
        return true;
        break;
    case '2':
        return true;
        break;
    default:
        cout << "Try entering a valid option" << endl;
        break;
    }
    return false;
}

int updateTeacherInfo()
{
    cout << "1. Name" << endl;
    cout << "2. Email" << endl;

    char userChoice;
    cout << "Enter your choice: ";
    cin >> userChoice;
    switch (userChoice)
    {
    case '1':
        return true;
        break;
    case '2':
        return true;
        break;
    default:
        cout << "Try entering a valid option" << endl;
        break;
    }
    return false;
}



int teamSearchMenu()
{
    cout << endl;
    cout << "1. Show a list of all the teams"<<endl;
    cout << "2. Add a new team"<<endl;
    cout << "3. Delete a team"<<endl;
    cout << "4. Search a team by criteria"<<endl;
    cout << "5. Update info about a team"<<endl;

    char userChoice;
    cout << "Enter your choice: ";
    cin >> userChoice;
    switch (userChoice)
    {
    case '1':
        return true;
        break;
    case '2':
        return true;
        break;
    case '3':
        return true;
        break;
    case '4':
        searchTeamByCriteria();
        return true;
        break;
    case '5':
        updateTeamInfo();
        return true;
        break;
    default:
        cout << "Try entering a valid option" << endl;
        break;
    }
    return false;
}

int teacherSearchMenu()
{
    cout << endl;
    cout << "1. Show a list of all the teachers"<<endl;
    cout << "2. Add a new teacher"<<endl;
    cout << "3. Delete a teacher"<<endl;
    cout << "4. Search a teacher by criteria"<<endl;
    cout << "5. Update info about a teacher"<<endl;

    char userChoice;
    cout << "Enter your choice: ";
    cin >> userChoice;
    switch (userChoice)
    {
    case '1':
        return true;
        break;
    case '2':
        return true;
        break;
    case '3':
        return true;
        break;
    case '4':
        searchTeacherByCriteria();
        return true;
        break;
    case '5':
        updateTeacherInfo();
        return true;
        break;
    default:
        cout << "Try entering a valid option" << endl;
        break;
    }
    return false;
}

int studentSearchMenu()
{
    cout << endl;
    cout << "1. Show a list of all the students"<<endl;
    cout << "2. Add a new student"<<endl;
    cout << "3. Delete a student"<<endl;
    cout << "4. Search a student by criteria"<<endl;
    cout << "5. Update info about a student"<<endl;

    char userChoice;
    cout << "Enter your choice: ";
    cin >> userChoice;
    switch (userChoice)
    {
    case '1':
        return true;
        break;
    case '2':
        return true;
        break;
    case '3':
        return true;
        break;
    case '4':
        searchStudentByCriteria();
        return true;
        break;
    case '5':
        updateStudentInfo();
        return true;
        break;
    default:
        cout << "Try entering a valid option" << endl;
        break;
    }
    return false;
}

bool mainMenu()
{
    cout << "1. Students" << endl;
    cout << "2. Teams" << endl;
    cout << "3. Teachers" << endl;
    cout << "4. School" << endl; //add

    char userChoice;
    cout << "Enter your choice: ";
    cin >> userChoice;
    switch (userChoice)
    {
    case '1':
        studentSearchMenu();
        return true;
        break;
    case '2':
        teamSearchMenu();
        return true;
        break;
    case '3':
        teacherSearchMenu();
        return true;
        break;
    case '4':
        return true;
        break;
    default:
        cout << "Try entering a valid option" << endl;
        break;
    }
    return false;

}


int main()
{
    STUDENT students[100];
    TEAM teams[30];
    TEACHER teachers[30];

    int st_index = 0;
    int t_index = 0;
    int tch_index = 0;

    /*greetings();
    cout << mainMenu();
    initStudents(students, st_index);
    showStudents(students, st_index);
    enterStudent(students, st_index);
    deleteStudent(students, st_index, 4);
    showStudents(students, st_index);
    */

    initStudents(students, st_index);
    initTeams(students, st_index, teams, t_index);

    /*showTeams(students, teams, t_index, 3);
    deleteTeam(teams, t_index, 0);
    showTeams(students, teams, t_index, 3);*/

    initTeachers(teams, teachers, tch_index);
    showTeachers(teams, teachers, tch_index, 2);
    enterTeacher(teams, teachers, tch_index);
    deleteTeacher(teachers, tch_index, 0);
    showTeachers(teams, teachers, tch_index, 2);
}
