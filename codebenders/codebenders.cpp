#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;

#define RESET   "\033[0m"

#define RED     "\033[1;91m" 
#define YELLOW  "\033[1;93m"  
#define GREEN   "\033[1;92m"
#define CYAN    "\033[0;36m"
#define BLUE    "\033[1;96m"
#define PURPLE  "\033[1;95m"

#define WHITE   "\033[4;37m"
#define BWhite  "\033[1;37m"  
#define UWhite  "\033[4;37m"  


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
    char className = ' ';
    role teamRole;
    string email;
    bool hasATeam = false;
};

struct TEAM
{
    string name;
    string description;
    DATE dateOfSetUp;
    STUDENT teammates[4];
    status teamStatus = status::notArchived;
    int numOfStudents;
    bool hasATeacher = false;
};

struct TEACHER
{
    string name;
    string surname;
    TEAM teams[5];
    string email;
    int numOfTeams;
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


int readInt() 
{
    int number;

    //while loop until the value entered is an integer
    while (!(cin >> number)) {

        cin.clear();
        cin.ignore(INT_MAX, '\n');
        cout << endl;
        cout << "You have to enter a number. Please, try again: ";
    }

    return number;
}

void displayMainMenu(STUDENT* students, int& st_index, TEAM* teams, int& t_index, TEACHER* teachers, int& tch_index);
void displayTeachersMenu(STUDENT* students, int& st_index, TEAM* teams, int& t_index, TEACHER* teachers, int& tch_index);
void displayTeamsMenu(STUDENT* students, int& st_index, TEAM* teams, int& t_index, TEACHER* teachers, int& tch_index);
void displayStudentsMenu(STUDENT* students, int& st_index, TEAM* teams, int& t_index, TEACHER* teachers, int& tch_index);


/*=============================================================================*/

void initStudents(STUDENT* students, int& index)
{
    students[0] = { "Maria", "Georgieva", 10, 'A', role::scrumTrainer, "mariaG@abv.bg", 1 };
    students[1] = { "Veselin", "Atanasov", 9, 'B', role::QAEngineer, "vesel@gmail.com",1 };
    students[2] = { "Ivan", "Stanimirov", 9, 'V', role::developerBackend, "ivancho420@gmail.com", 1 };
    students[3] = { "Georgi", "Ognyanov", 10, 'G', role::scrumTrainer, "gogo@abv.bg", 0 };
    students[4] = { "Kameliya", "Ivanova", 8, 'B', role::developerFrontend, "kIvanova@codingburgas.bg", 1 };
    students[5] = { "Zhivko", "Vladimirov", 10, 'B', role::developerBackend, "jiwkoV@abv.bg", 1 };
    students[6] = { "Aneliya", "Shishmanova", 10, 'V', role::developerBackend, "aneliq04@gamil.com", 0 };
    students[7] = { "Stoyan", "Dobrev", 8, 'G', role::QAEngineer, "sDobrev@abv.bg", 1 };
    students[8] = { "Galin", "Georgiev", 8, 'G', role::scrumTrainer, "gggeorgiev@yahoo.org", 0 };
    students[9] = { "Galena", "Hadzhieva", 9, 'V', role::developerBackend, "geymarkata@gmail.com",1 };
    students[10] = { "Didi", "Popova", 10, 'A', role::QAEngineer, "Dida_D@abv.bg", 1 };
    students[11] = { "Radomir", "Liliev", 9, 'B', role::scrumTrainer, "RadoGashtite@gmail.com", 1 };


    index = 12;
}

void showStudent(STUDENT* students, int index)
{
    cout << "  Student ID: " << index + 1 << endl;
    cout << "  Name: " << students[index].name << " " << students[index].surname << endl;
    cout << "  Class: " << students[index].schoolYear << " " << students[index].className << endl;
    cout << "  Role: ";
    if (students[index].teamRole == 0)
        cout << "Scrum Trainer" << endl;
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

    cout << "List of students: " << endl << endl;
    for (int i = 0; i < index; i++)
    {
        showStudent(students, i);
        cout << endl<<endl;
    }
}

void enterStudent(STUDENT* students, int& index)
{
    int choice;

    cout << "Enter info about student:" << endl;

    cout << " First name: ";
    cin >> students[index].name;
    cout << " Last name: ";
    cin >> students[index].surname;

    cout << " Class: " << endl;
    cout << "School year: ";
    students[index].schoolYear = readInt();
    cout << "Class name: ";
    cin >> students[index].className;

    cout << " Role in team: " << endl;
    cout << "  1. Scrum Trainer" << endl;
    cout << "  2. QA Engineer" << endl;
    cout << "  3. Backend Developer" << endl;
    cout << "  4. Frontend Developer" << endl;
    cout << "Enter your choice: ";
    choice = readInt();

    while (choice > 4 or choice < 1)
    {
        cout << endl;
        cout << "The number you enter has to be between 1 and 4! Please, try again: ";
        choice = readInt();
    }

    students[index].teamRole = role(choice - 1);

    cout << "E-mail: ";
    cin >> students[index].email;

    index++;
}

void deleteStudent(STUDENT* students, int& index)
{
    int position;

    cout << "Enter the ID of the student you would like to remove from the list: ";
    position = readInt();
    position -= 1;

    for (int i = position; i < index - 1; i++)
    {
        students[i] = students[i + 1];
    }

    index--;
}

void updateStudentName(STUDENT* students)
{
    int position;

    cout << "Enter the ID of the student you would like to edit: ";
    position = readInt();
    position -= 1;

    cout << "Edit the name of the selected student:" << endl;
    cout << " First name: ";
    cin >> students[position].name;
    cout << " Last name: ";
    cin >> students[position].surname;
}

void updateStudentClass(STUDENT* students)
{
    int position;

    cout << "Enter the ID of the student you would like to edit: ";
    position = readInt();
    position -= 1;

    cout << "Edit the class of the selected student:" << endl;
    cout << " School year: ";
    students[position].schoolYear = readInt();
    cout << " Class name (capital letter): ";
    cin >> students[position].className;
}

void updateStudentRole(STUDENT* students)
{
    int position;

    cout << "Enter the ID of the student you would like to edit: ";
    position = readInt();
    position -= 1;

    int choice;
    cout << "Edit the role of the selected student (choose from the options listed below): " << endl << endl;

    cout << " 1. Scrum Trainer" << endl;
    cout << " 2. QA Engineer" << endl;
    cout << " 3. Backend Developer" << endl;
    cout << " 4. Frontend Developer" << endl << endl;

    cout << "Enter your choice: ";
    choice = readInt();

    while (choice > 4 or choice < 1)
    {
        cout << endl;
        cout << "The number you enter has to be between 1 and 4! Please, try again: ";
        choice = readInt();
    }

    if (choice == 1)
        students[position].teamRole = role::scrumTrainer;
    else if (choice == 2)
        students[position].teamRole = role::QAEngineer;
    else if (choice == 3)
        students[position].teamRole = role::developerBackend;
    else
        students[position].teamRole = role::developerFrontend;
}

void updateStudentEmail(STUDENT* students)
{
    int position;

    cout << "Enter the ID of the student you would like to edit: ";
    position = readInt();
    position -= 1;

    cout << " New E-mail: ";
    cin >> students[position].email;
}

void searchStudentByName(STUDENT* students, int& index)
{
    string name, surname;
    cout << "Enter the first and last name of the student you are looking for: "<<endl;
    cout << " First name: ";
    cin >> name;
    cout << " Last name: ";
    cin >> surname;

    cout << endl;

    for (int i = 0; i < index; i++)
    {
        if (students[i].name == name and students[i].surname == surname)
        {
            showStudent(students, i);
        }
    }
}

void seacrhStudentsByClass(STUDENT* students, int& index)
{
    int schoolYear;
    char className;
    cout << "Show all the students from this class: "<<endl;
    cout << " School year: ";
    schoolYear = readInt();
    cout << " Class name: ";
    cin >> className;

    cout << endl;

    for (int i = 0; i < index; i++)
    {
        if (students[i].schoolYear == schoolYear and students[i].className == className)
        {
            showStudent(students, i);
            cout << endl;
        }
    }
}

void searchStudentsByRole(STUDENT* students, int& index)
{
    int choice;
    role option;

    cout << "Students in which role would you like to see?" << endl;
    cout << "1. Scrum Trainer" << endl;
    cout << "2. QA Engineer" << endl;
    cout << "3. Backend Developer" << endl;
    cout << "4. Frontend Developer" << endl<<endl;
    cout << "Enter your choice: ";
    choice = readInt();

    while (choice > 4 or choice < 1)
    {
        cout << endl;
        cout << "The number you enter has to be between 1 and 4! Please, try again: ";
        choice = readInt();
    }

    cout << endl;

    if (choice == 1)
        option = role::scrumTrainer;
    else if (choice == 2)
        option = role::QAEngineer;
    else if (choice == 3)
        option = role::developerBackend;
    else
        option = role::developerFrontend;

    for (int i = 0; i < index; i++)
    {
        if (students[i].teamRole == option)
        {
            showStudent(students, i);
            cout << endl << endl;
        }
    }
}

void searchStudentsWithoutATeam(STUDENT* students, int& index)
{
    cout << "Students that haven't joined any team yet: " << endl << endl;

    for (int i = 0; i < index; i++)
    {
        if (students[i].hasATeam == false)
        {
            showStudent(students, i);
            cout << endl << endl;
        }
    }
}

/*===========================================================================*/

void initTeams(STUDENT* students, int& index, TEAM* teams, int& t_index)
{
    teams[0] = { "Vikings", "We are here to win!", {10,2,2021}, {students[2], students[4], students[10]}, status::notActive, 3, 1 };
    teams[1] = { "We Showed Up", "Hoping for the best with minimum effort!", {13,2,2021}, {students[7], students[9], students[11]}, status::inUse, 3, 1 };
    teams[2] = { "Cereal Killers", "Trying our best", {20, 2, 2021},  {students[0], students[1], students[5]}, status::notArchived, 3, 1 };

    t_index = 3;
}

void showTeam(STUDENT* students, TEAM* teams, int& t_index)
{
    cout << "ID: " << t_index + 1<<endl;
    cout << "Name: " << teams[t_index].name << endl;
    cout << "Description: " << teams[t_index].description << endl;
    cout << "Date of set-up: " << teams[t_index].dateOfSetUp.day << "/"
        << teams[t_index].dateOfSetUp.month << "/" << teams[t_index].dateOfSetUp.year << endl;
    cout << "Teammates: " << endl;

    for (int i = 0; i < teams[t_index].numOfStudents; i++)
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

void showTeams(STUDENT* students, TEAM* teams, int& t_index)
{
    cout << "List of teams: " << endl << endl;
    for (int i = 0; i < t_index; i++)
    {
        showTeam(students, teams, i);
        cout << endl << endl;
    }
}

void enterTeam(STUDENT* students, TEAM* teams, int& t_index)
{
    int number, id;

    cout << "Enter info about a new team:" << endl;

    cin.ignore();

    cout << "Name of the team: ";
    getline(cin, teams[t_index].name);
    
    cout << "Description: ";
    getline(cin, teams[t_index].description);
    
    cout << "Date of set up: " << endl;
    cout << " Day: ";
    teams[t_index].dateOfSetUp.day = readInt();
    cout << " Month: ";
    teams[t_index].dateOfSetUp.month = readInt();
    cout << " Year: ";
    teams[t_index].dateOfSetUp.year = readInt();

    cout << "Number of members: ";
    number = readInt();

    teams[t_index].numOfStudents = number;

    cout << "Enter the ID numbers of the members of the team: " << endl;
    for (int i = 0; i < number; i++)
    {
        cout << " " << i + 1 << ". ";
        id = readInt();
        teams[t_index].teammates[i] = students[id - 1];
    }

    t_index++;
}

void deleteTeam(TEAM* teams, int& t_index)
{
    int position;

    cout << "Enter the ID of the team you would like to remove from the list: ";
    position = readInt();
    position -= 1;

    for (int i = position; i < t_index - 1; i++)
    {
        teams[i] = teams[i + 1];
    }

    t_index--;
}

void updateTeamName(TEAM* teams)
{
    int position;

    cout << "Enter the ID of the team you would like to edit: ";
    position = readInt();;
    position -= 1;

    cin.ignore();
    cout << " New team name: ";
    getline(cin, teams[position].name);
}

void updateTeamDescription(TEAM* teams)
{
    int position;

    cout << "Enter the ID of the team you would like to edit: ";
    position = readInt();
    position -= 1;

    cin.ignore();

    cout << " New team description: ";
    getline(cin, teams[position].description);
}

void updateTeamStatus(TEAM* teams)
{
    int position;

    cout << "Enter the ID of the team you would like to edit: ";
    position = readInt();
    position -= 1;

    int choice;
    cout << "Edit the status of the selected team (choose from the options listed below): " << endl;
    cout << "1. In use" << endl;
    cout << "2. Not active" << endl;
    cout << "3. Not archived" << endl << endl;

    cout << "Enter your choice: ";
    choice = readInt();

    while (choice > 3 or choice < 1)
    {
        cout << endl;
        cout << "The number you enter has to be between 1 and 3! Please, try again: ";
        choice = readInt();
    }

    if (choice == 1)
        teams[position].teamStatus = status::inUse;
    else if (choice == 2)
        teams[position].teamStatus = status::notActive;
    else
        teams[position].teamStatus = status::notArchived;
}

void addStudentToTeam(STUDENT* students, TEAM* teams)
{
    int position;

    cout << "Enter the ID of the team you would like to edit: ";
    position = readInt();
    position -= 1;
    cout << endl;

    int id;
    cout << "Enter the ID number of the student you want to be added to the selected team: ";
    id = readInt();

    teams[position].teammates[teams[position].numOfStudents] = students[id - 1];
    teams[position].numOfStudents++;
    students[id - 1].hasATeam = true;
}

void removeStudentFromTeam(STUDENT* students, TEAM* teams)
{
    int position;
    cout << "Enter the ID of the team you would like to edit: ";
    position = readInt();;
    position -= 1;
    cout << endl;

    int id;
    cout << "Enter the ID number of the student you want to be removed from the selected team: ";
    id = readInt();
    id -= 1;

    int numberOfMembers = teams[position].numOfStudents;
    int posInTeam;

    for (int i = 0; i < numberOfMembers; i++)
    {
        if (teams[position].teammates[i].email == students[id].email)
            posInTeam = i;
    }

    for (int i = posInTeam; i < numberOfMembers - 1; i++)
    {
        teams[position].teammates[i] = teams[position].teammates[i + 1];
    }

    teams[position].numOfStudents--;
    students[id].hasATeam = false;
}

void searchTeamByName(STUDENT* students, TEAM* teams, int& t_index)
{
    string name;
    cout << "Enter the name of the team you are looking for: ";
    cin >> name;

    cout << endl;

    for (int i = 0; i < t_index; i++)
    {
        if (teams[i].name == name)
        {
            showTeam(students, teams, i);
            cout << endl << endl;;
        }
    }

    cout << endl;
}

void searchTeamByStatus(STUDENT* students, TEAM* teams, int& t_index)
{
    int choice;
    status option;

    cout << "Teams with what status would you like to see?" << endl;
    cout << "1. In use" << endl;
    cout << "2. Not active" << endl;
    cout << "3. Not archived" << endl<<endl;
    cout << "Enter your choice: ";
    choice = readInt();

    while (choice > 3 or choice < 1)
    {
        cout << endl;
        cout << "The number you enter has to be between 1 and 3! Please, try again: ";
        choice = readInt();
    }

    cout << endl;

    if (choice == 1)
        option = status::inUse;
    else if (choice == 2)
        option = status::notActive;
    else
        option = status::notArchived;


    for (int i = 0; i < t_index; i++)
    {
        if (teams[i].teamStatus == option)
        {
            showTeam(students, teams,  i);
            cout << endl << endl;
        }
    }

}

void searchTeamByNumberOfMembers(STUDENT* students, TEAM* teams, int& t_index)
{
    int number;
    cout << "Enter teams with how many teammates you want to see (2-4): ";
    number = readInt();

    while (number > 4 or number < 2)
    {
        cout << endl;
        cout << "The number you enter has to be between 2 and 4! Please, try again: ";
        number = readInt();
    }

    cout << endl;

    for (int i = 0; i < t_index; i++)
    {
        if (teams[i].numOfStudents == number)
        {
            showTeam(students, teams, i);
            cout << endl << endl;
        }
    }
}

void searchTeamsWithoutATeacher(STUDENT* students, TEAM* teams, int& t_index)
{
    cout << "Teams that haven't got any teacher yet: " << endl << endl;

    for (int i = 0; i < t_index; i++)
    {
        if (teams[i].hasATeacher == false)
        {
            showTeam(students, teams, i);
            cout << endl << endl;
        }
    }
}


/*==========================================================================*/

void initTeachers(TEAM* teams, TEACHER* teachers, int& tch_index)
{
    teachers[0] = { "Ivelina", "Staykova", {teams[0], teams[1]}, "iStaikova@abv.bg", 2 };
    teachers[1] = { "Yordan", "Kamenov", {teams[2]}, "yordanKA@gmail.com", 1 };

    tch_index = 2;
}

void showTeacher(TEAM* teams, TEACHER* teachers, int& tch_index)
{
    int numOfTeams = teachers[tch_index].numOfTeams;
    cout << "ID: " << tch_index + 1<< endl;
    cout << "First and last name: " << teachers[tch_index].name << " " << teachers[tch_index].surname << endl;
    cout << "Teams they assist: " << endl;
    for (int i = 0; i < numOfTeams; i++)
    {
        cout << " " << i + 1 << ". " << teachers[tch_index].teams[i].name << endl;
    }
    cout << "E-mail: " << teachers[tch_index].email << endl;
}

void showTeachers(TEAM* teams, TEACHER* teachers, int& tch_index)
{
    cout << "List of teachers: " << endl << endl;
    for (int i = 0; i < tch_index; i++)
    {
        showTeacher(teams, teachers, i);
        cout << endl << endl;
    }
}

void enterTeacher(TEAM* teams, TEACHER* teachers, int& tch_index)
{
    int number, id;

    cout << "Enter info about teacher:" << endl;

    cout << "First name: ";
    cin >> teachers[tch_index].name;

    cout << "Last name: ";
    cin >> teachers[tch_index].surname;

    cout << "E-mail: ";
    cin >> teachers[tch_index].email;

    cout << "Number of teams they assist: ";
    number = readInt();

    teachers[tch_index].numOfTeams = number;

    cout << "Enter the IDs of the teams they assist:" << endl;
    for (int i = 0; i < number; i++)
    {
        cout << " " << i + 1 << ". ";
        id = readInt();
        teachers[tch_index].teams[i] = teams[id - 1];
    }

    tch_index++;
}

void deleteTeacher(TEACHER* teachers, int& tch_index)
{
    int position;

    cout << "Enter the ID of the teacher you would like to remove from the list: ";
    position = readInt();
    position -= 1;

    for (int i = position; i < tch_index - 1; i++)
    {
        teachers[i] = teachers[i + 1];
    }

    tch_index--;
}

void updateTeacherName(TEACHER* teachers)
{
    int position;

    cout << "Enter the ID of the teacher you would like to edit: ";
    position = readInt();
    position -= 1;

    cout << "Edit the name of the selected teacher:" << endl;
    cout << " First name: ";
    cin >> teachers[position].name;
    cout << " Last name: ";
    cin >> teachers[position].surname;
}

void updateTeacherEmail(TEACHER* teachers)
{
    int position;

    cout << "Enter the ID of the teacher you would like to edit: ";
    position = readInt();
    position -= 1;

    cout << " New E-mail: ";
    cin >> teachers[position].email;
}

void addTeamToTeacher(TEAM* teams, TEACHER* teachers)
{
    int position;

    cout << "Enter the ID of the teacher you would like to edit: ";
    position = readInt();
    position -= 1;

    cout << endl;

    int id;
    cout << "Enter the ID of the team you want to be assisted by the selected teacher: ";
    id = readInt();

    teachers[position].teams[teachers[position].numOfTeams] = teams[id - 1];
    teachers[position].numOfTeams++;
    teams[id - 1].hasATeacher = true;
}

void removeTeamFromTeacher(TEAM* teams, TEACHER* teachers)
{
    int position;

    cout << "Enter the ID of the teacher you would like to edit: ";
    position = readInt();
    position -= 1;

    cout << endl;

    int id;
    cout << "Enter the ID of the team you want to not be assisted by the selected teacher anymore: ";
    id = readInt();
    id -= 1;

    int numberOfTeams = teachers[position].numOfTeams;
    int posInTeacher;

    for (int i = 0; i < numberOfTeams; i++)
    {
        if (teachers[position].teams[i].name == teams[id].name)
            posInTeacher = i;
    }

    for (int i = posInTeacher; i < numberOfTeams - 1; i++)
    {
        teachers[position].teams[i] = teachers[position].teams[i + 1];
    }

    teachers[position].numOfTeams--;
    teams[id].hasATeacher = false;
}

void searchTeacherByName(TEAM* teams, TEACHER* teachers, int& tch_index)
{
    string name, surname;
    cout << "Enter the first and last name of the teacher you are looking for: " << endl;
    cout << "First name: ";
    cin >> name;
    cout << "Last name: ";
    cin >> surname;

    cout << endl;

    for (int i = 0; i < tch_index; i++)
    {
        if (teachers[i].name == name and teachers[i].surname == surname)
        {
            showTeacher(teams, teachers, i);
            cout << endl << endl;
        }
    }
}


/*==========================================================================*/

void spaces(int count)
{
    for (int i = 0; i < count; i++)
    {
        cout << " ";
    }
}

void greetings()
{
    cout << "Hello from us, the codebenders, and welcome to our program!" << endl;
}

bool returnBack()
{
    int choice;

    cout << endl;
    cout << "What would you like to do now?" << endl << endl;
    cout << "1) Stay here" << endl;
    cout << "2) Go one menu back" << endl << endl;
    cout << "Enter your choice: ";

    choice = readInt();

    while (choice > 2 or choice < 1)
    {
        cout << endl;
        cout << "The number you enter has to be either 1 or 2! Please, try again: ";
        choice = readInt();
    }

    cout << endl;

    system("cls");

    if (choice == 1)
        return true;
    
    return false;
}


void searchStudentMenu(STUDENT* students, int& st_index, TEAM* teams, int& t_index, TEACHER* teachers, int& tch_index)
{
    bool cont = true;
    while (cont == true)
    {
        int userChoice;

        cout << "By what criteria do you want to search for a student/-s?" << endl << endl;
        cout << "1) Name" << endl;
        cout << "2) Class" << endl;
        cout << "3) Role" << endl;
        cout << "4) Without a team" << endl;
        cout << "5) Return back to Students Menu" << endl << endl;


        cout << "Enter your choice: ";
        userChoice = readInt();

        while (userChoice > 5 or userChoice < 1)
        {
            cout << endl;
            cout << "The number you enter has to be between 1 and 5! Please, try again: ";
            userChoice = readInt();
        }

        system("cls");

        switch (userChoice)
        {
        case 1:
            searchStudentByName(students, st_index);
            cont = returnBack();
            break;
        case 2:
            seacrhStudentsByClass(students, st_index);
            cont = returnBack();
            break;
        case 3:
            searchStudentsByRole(students, st_index);
            cont = returnBack();
            break;
        case 4:
            searchStudentsWithoutATeam(students, st_index);
            cont = returnBack();
            break;
        case 5:
            displayStudentsMenu(students, st_index, teams, t_index, teachers, tch_index);
            cont = false;
            break;
        }
    }
}

void  updateStudentInfoMenu(STUDENT* students, int& st_index, TEAM* teams, int& t_index, TEACHER* teachers, int& tch_index)
{
    bool cont = true;
    while (cont == true)
    {
        int userChoice;

        cout << "What would you like to update?" << endl << endl;
        cout << "1) Name" << endl;
        cout << "2) Class" << endl;
        cout << "3) Email" << endl;
        cout << "4) Team role" << endl;
        cout << "5) Return back to Students Menu" << endl << endl;

        cout << "Enter your choice: ";
        userChoice = readInt();

        while (userChoice > 5 or userChoice < 1)
        {
            cout << endl;
            cout << "The number you enter has to be between 1 and 5! Please, try again: ";
            userChoice = readInt();
        }

        system("cls");

        switch (userChoice)
        {
        case 1:
            updateStudentName(students);
            cont = returnBack();
            break;
        case 2:
            updateStudentClass(students);
            cont = returnBack();
            break;
        case 3:
            updateStudentEmail(students);
            cont = returnBack();
            break;
        case 4:
            updateStudentRole(students);
            cont = returnBack();
            break;
        case 5:
            displayStudentsMenu(students, st_index, teams, t_index, teachers, tch_index);
            cont = false;
            break;
        }
    }
}

void searchTeamMenu(STUDENT* students, int& st_index, TEAM* teams, int& t_index, TEACHER* teachers, int& tch_index)
{
    bool cont = true;
    while (cont == true)
    {
        int userChoice;

        cout << "By what criteria do you want to search for a team/-s?" << endl << endl;
        cout << "1) Name" << endl;
        cout << "2) Number of members" << endl;
        cout << "3) Status" << endl;
        cout << "4) Teams which don't have a teacher" << endl;
        cout << "5) Return back to Teams Menu" << endl << endl;

        cout << "Enter your choice: ";
        userChoice = readInt();

        while (userChoice > 5 or userChoice < 1)
        {
            cout << endl;
            cout << "The number you enter has to be between 1 and 5! Please, try again: ";
            userChoice = readInt();
        }

        system("cls");

        switch (userChoice)
        {
        case 1:
            searchTeamByName(students, teams, t_index);
            cont = returnBack();
            break;
        case 2:
            searchTeamByNumberOfMembers(students, teams, t_index);
            cont = returnBack();
            break;
        case 3:
            searchTeamByStatus(students, teams, t_index);
            cont = returnBack();
        case 4:
            searchTeamsWithoutATeacher(students, teams, t_index);
            cont = returnBack();
            break;
        case 5:
            displayTeamsMenu(students, st_index, teams, t_index, teachers, tch_index);
            cont = false;
            break;
        }
    }
}

void updateTeamInfoMenu(STUDENT* students, int& st_index, TEAM* teams, int& t_index, TEACHER* teachers, int& tch_index)
{
    bool cont = true;
    while (cont == true)
    {
        int userChoice;

        cout << "What would you like to update?" << endl << endl;
        cout << "1) Name" << endl;
        cout << "2) Description" << endl;
        cout << "3) Status" << endl;
        cout << "4) Add a new member to a team" << endl;
        cout << "5) Remove a student from a team" << endl;
        cout << "6) Return back to Teams Menu" << endl << endl;

        cout << "Enter your choice: ";
        userChoice = readInt();

        while (userChoice > 6 or userChoice < 1)
        {
            cout << endl;
            cout << "The number you enter has to be between 1 and 6! Please, try again: ";
            userChoice = readInt();
        }

        system("cls");

        switch (userChoice)
        {
        case 1:
            updateTeamName(teams);
            cont = returnBack();
            break;
        case 2:
            updateTeamDescription(teams);
            cont = returnBack();
            break;
        case 3:
            updateTeamStatus(teams);
            cont = returnBack();
            break;
        case 4:
            addStudentToTeam(students, teams);
            cont = returnBack();
            break;
        case 5:
            removeStudentFromTeam(students, teams);
            cont = returnBack();
            break;
        case 6:
            displayTeamsMenu(students, st_index, teams, t_index, teachers, tch_index);
            cont = false;
            break;
        }
    }
}

void searchTeacherMenu(STUDENT* students, int& st_index, TEAM* teams, int& t_index, TEACHER* teachers, int& tch_index)
{
    bool cont = true;
    while (cont == true)
    {
        int userChoice;

        cout << "By what criteria do you want to search for a teacher/-s?" << endl << endl;
        cout << "1) Name" << endl;
        cout << "2) Team" << endl;
        cout << "3) Return back to Teachers Menu" << endl << endl;

        cout << "Enter your choice: ";
        userChoice = readInt();

        while (userChoice > 3 or userChoice < 1)
        {
            cout << endl;
            cout << "The number you enter has to be between 1 and 3! Please, try again: ";
            userChoice = readInt();
        }

        system("cls");

        switch (userChoice)
        {
        case 1:
            searchTeacherByName(teams, teachers, tch_index);
            cont = returnBack();
            break;
        case 2:

            break;
        case 3:
            displayTeachersMenu(students, st_index, teams, t_index, teachers, tch_index);
            cont = false;
            break;
        }
    }
}

void updateTeacherInfoMenu(STUDENT* students, int& st_index, TEAM* teams, int& t_index, TEACHER* teachers, int& tch_index)
{
    bool cont = true;
    while (cont == true)
    {
        int userChoice;

        cout << "What would you like to update?" << endl << endl;
        cout << "1) Name" << endl;
        cout << "2) Email" << endl;
        cout << "3) Assign a team to a teacher" << endl;
        cout << "4) Remove a team from a teacher" << endl;
        cout << "5) Return back to Teachers Menu" << endl << endl;

        cout << "Enter your choice: ";
        userChoice = readInt();

        while (userChoice > 5 or userChoice < 1)
        {
            cout << endl;
            cout << "The number you enter has to be between 1 and 5! Please, try again: ";
            userChoice = readInt();;
        }

        system("cls");

        switch (userChoice)
        {
        case 1:
            updateTeacherName(teachers);
            cont = returnBack();
            break;
        case 2:
            updateTeacherEmail(teachers);
            cont = returnBack();
            break;
        case 3:
            addTeamToTeacher(teams, teachers);
            cont = returnBack();
            break;
        case 4:
            removeTeamFromTeacher(teams, teachers);
            cont = returnBack();
            break;
        case 5:
            displayTeachersMenu(students, st_index, teams, t_index, teachers, tch_index);
            cont = false;
            break;
        }
    }
}




void displayStudentsMenu(STUDENT* students, int& st_index, TEAM* teams, int& t_index, TEACHER* teachers, int& tch_index)
{
    int userChoice = 0;

    cout << endl;
    cout << "STUDENTS" << endl<<endl;
    cout << "1) Show a list of all the students" << endl;
    cout << "2) Add a new student" << endl;
    cout << "3) Delete a student" << endl;
    cout << "4) Search a student by criteria" << endl;
    cout << "5) Update info about a student" << endl;
    cout << "6) Return back to the Main Menu" << endl << endl;
    
    cout << "Enter your choice: ";
    userChoice = readInt();

    while (userChoice > 6 or userChoice < 1)
    {
        cout << endl;
        cout << "The number you enter has to be between 1 and 6! Please, try again: ";
        userChoice = readInt();
    }

    system("cls");

    switch (userChoice)
    {
    case 1:
        showStudents(students, st_index);
        break;
    case 2:
        enterStudent(students,  st_index);
        break;
    case 3:
        deleteStudent(students, st_index);
        break;
    case 4:
        searchStudentMenu(students, st_index, teams, t_index, teachers, tch_index);
        break;
    case 5:
        updateStudentInfoMenu(students, st_index, teams, t_index, teachers, tch_index);
        break;
    case 6:
        displayMainMenu(students, st_index, teams, t_index, teachers, tch_index);
        break;
    }
   
}

void displayTeamsMenu(STUDENT* students, int& st_index, TEAM* teams, int& t_index, TEACHER* teachers, int& tch_index)
{
    int userChoice = 0;
    
    cout << endl;
    cout << "TEAMS" << endl<<endl;
    cout << "1) Show a list of all the teams" << endl;
    cout << "2) Add a new team" << endl;
    cout << "3) Delete a team" << endl;
    cout << "4) Search a team by criteria" << endl;
    cout << "5) Update info about a team" << endl;
    cout << "6) Return back to the Main Menu" << endl << endl;

    cout << "Enter your choice: ";
    userChoice = readInt();

    while (userChoice > 6 or userChoice < 1)
    {
        cout << endl;
        cout << "The number you enter has to be between 1 and 6! Please, try again: ";
        userChoice = readInt();
    }

    system("cls");

    switch (userChoice)
    {
    case 1:
        showTeams(students, teams, t_index);
        break;
    case 2:
        enterTeam(students, teams, t_index);
        break;
    case 3:
        deleteTeam(teams, t_index);
        break;
    case 4:
        searchTeamMenu(students, st_index, teams, t_index, teachers, tch_index);
        break;
    case 5:
        updateTeamInfoMenu(students, st_index, teams, t_index, teachers, tch_index);
        break;
    case 6:
        displayMainMenu(students, st_index, teams, t_index, teachers, tch_index);
        break;
    }

}

void displayTeachersMenu(STUDENT* students, int& st_index, TEAM* teams, int& t_index, TEACHER* teachers, int& tch_index)
{
    int  userChoice = 0; 

        cout << endl;
        cout << "TEACHERS" << endl<<endl;
        cout << "1) Show a list of all the teachers" << endl;
        cout << "2) Add a new teacher" << endl;
        cout << "3) Delete a teacher" << endl;
        cout << "4) Search a teacher by criteria" << endl;
        cout << "5) Update info about a teacher" << endl;
        cout << "6) Return back to the Main Menu" << endl << endl;

        cout << "Enter your choice: ";
        userChoice = readInt();

        while (userChoice > 6 or userChoice < 1)
        {
            cout << endl;
            cout << "The number you enter has to be between 1 and 6! Please, try again: ";
            userChoice = readInt();
        }

        system("cls");

        switch (userChoice)
        {
        case 1:
            showTeachers(teams, teachers, tch_index);
            break;
        case 2:
            enterTeacher(teams, teachers, tch_index);
            break;
        case 3:
            deleteTeacher(teachers, tch_index);
            break;
        case 4:
            searchTeacherMenu(students, st_index, teams, t_index, teachers, tch_index);
            break;
        case 5:
            updateTeacherInfoMenu(students, st_index, teams, t_index, teachers, tch_index);
            break;
        case 6:
            displayMainMenu(students, st_index, teams, t_index, teachers, tch_index);
            break;
        }
    
   
}


void displayMainMenu(STUDENT* students, int& st_index, TEAM* teams,  int& t_index, TEACHER* teachers, int& tch_index)
{
    int userChoice = 0;

    while (userChoice != 5)
    {
        cout << endl;
        cout << "MAIN MENU" << endl << endl;
        cout << "Which sets of data would you like to work with?" << endl << endl;
        cout << "1) Students" << endl;
        cout << "2) Teams" << endl;
        cout << "3) Teachers" << endl;
        cout << "4) School" << endl;
        cout << "5) Exit" << endl << endl;

        cout << "Enter your choice: ";
        userChoice = readInt();

        while (userChoice > 5 or userChoice < 1)
        {
            cout << endl;
            cout << "The number you enter has to be between 1 and 5! Please, try again: ";
            userChoice = readInt();
        }

        system("cls");

        switch (userChoice)
        {
        case 1:
            displayStudentsMenu(students, st_index, teams, t_index, teachers, tch_index);
            break;
        case 2:
            displayTeamsMenu(students, st_index, teams, t_index, teachers, tch_index);
            break;
        case 3:
            displayTeachersMenu(students, st_index, teams, t_index, teachers, tch_index);
            break;
        case 4:
            break;
        case 5:
            exit(0);
            break;
        }
    }

}


int main()
{
    STUDENT students[100];
    TEAM teams[30];
    TEACHER teachers[30];

    int st_index = 0, t_index = 0, tch_index = 0;

    initStudents(students, st_index);
    initTeams(students, st_index, teams, t_index);
    initTeachers(teams, teachers, tch_index);

    greetings();
    displayMainMenu(students, st_index, teams, t_index, teachers, tch_index);
}
