#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;

//defining colors to use in the output
#define RESET   "\033[0m"

#define RED     "\033[1;91m" 
#define YELLOW  "\033[1;93m"  
#define GREEN   "\033[1;92m"
#define BLUE    "\033[0;36m"
#define CYAN    "\033[1;96m"
#define PURPLE  "\033[1;95m"
#define GRAY    "\033[1;90m" 
#define MINT    "\033[1;96m"

#define WHITE   "\033[4;37m"
#define BWhite  "\033[1;37m"  
#define UWhite  "\033[4;37m"  

#define BBlack  "\033[1;30m"    
#define BRed    "\033[1;31m"         
#define BGreen  "\033[1;32m"       
#define BYellow "\033[1;33m"      
#define BBlue   "\033[1;34m"       
#define BPurple "\033[1;35m"      
#define BCyan   "\033[1;36m"       
#define BWhite  "\033[1;37m"       


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
    int streetNumber;
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


//Asks the user to input an integer and outputs an error message if they enter something else
int readInt() 
{
    int number;

    //while loop until the value entered is an integer
    while (!(cin >> number)) {

        cin.clear();
        cin.ignore(INT_MAX, '\n');
        cout << endl;
        cout << RED << "You have to enter a number. Please, try again: "<<RESET;
    }

    return number;
}

void displayMainMenu(STUDENT* students, int& st_index, TEAM* teams, int& t_index, TEACHER* teachers, int& tch_index, SCHOOL* school);
void displayTeachersMenu(STUDENT* students, int& st_index, TEAM* teams, int& t_index, TEACHER* teachers, int& tch_index, SCHOOL* school);
void displayTeamsMenu(STUDENT* students, int& st_index, TEAM* teams, int& t_index, TEACHER* teachers, int& tch_index, SCHOOL* school);
void displayStudentsMenu(STUDENT* students, int& st_index, TEAM* teams, int& t_index, TEACHER* teachers, int& tch_index, SCHOOL* school);
void displaySchoolMenu(STUDENT* students, int& st_index, TEAM* teams, int& t_index, TEACHER* teachers, int& tch_index, SCHOOL* school);


/*=============================================================================*/

//Statically fills up an array of students
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

//Outputs a single student from the students array
void showStudent(STUDENT* students, int index)
{
    cout << YELLOW << "  Student ID: " << RESET << index + 1 << endl;
    cout <<PURPLE<< "  Name: " <<RESET<< students[index].name << " " << students[index].surname << endl;
    cout << CYAN << "  Class: " << RESET << students[index].schoolYear << " " << students[index].className << endl;
    cout << BLUE "  Role: " << RESET;
    if (students[index].teamRole == 0)
        cout << "Scrum Trainer" << endl;
    else if (students[index].teamRole == 1)
        cout << "QA Engineer" << endl;
    else if (students[index].teamRole == 2)
        cout << "Backend Developer" << endl;
    else
        cout << "Frontend Developer" << endl;
    cout << GREEN << "  E-mail: " << RESET << UWhite << students[index].email << RESET << endl;
}

//Outputs a list of all of the students in the students array
void showStudents(STUDENT* students, int index)
{

    cout << YELLOW << "List of students: " << RESET << endl << endl;
    for (int i = 0; i < index; i++)
    {
        showStudent(students, i);
        cout << endl<<endl;
    }
}

//Inputs data for a new student in the students array
void enterStudent(STUDENT* students, int& index)
{
    int choice;
  
    cout << YELLOW << "Enter info about student:" << RESET << endl;

    cout <<PURPLE " First name: "<<RESET;
    cin >> students[index].name;
    cout << CYAN " Last name: " << RESET;
    cin >> students[index].surname;

    cout << endl;
    cout <<GRAY<< " Class: " <<RESET<< endl;
    
    cout << BLUE << "  School year: " << RESET;
    students[index].schoolYear = readInt();
    cout << GREEN << "  Class name (capital letter): " << RESET;
    cin >> students[index].className;

    while (students[index].className != 'A' and students[index].className != 'B' and students[index].className != 'V' and students[index].className != 'G')
    {
        cout << endl;
        cout << RED << "The name of the class should be A, B, V or G. Please, try again: " << RESET;
        cin >> students[index].className;
    }

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
        cout << RED << "The number you enter has to be between 1 and 4! Please, try again: "<<RESET;
        choice = readInt();
    }

    students[index].teamRole = role(choice - 1);

    cout << "E-mail: ";
    cin >> students[index].email;

    index++;
}

//Deletes a particular student from the students array
void deleteStudent(STUDENT* students, int& index)
{
    int position;

    cout << YELLOW << "Enter the ID of the student you would like to remove from the list: " << RESET;
    position = readInt();
    position -= 1;

    for (int i = position; i < index - 1; i++)
    {
        students[i] = students[i + 1];
    }

    index--;
}

//Edits the name of a student
void updateStudentName(STUDENT* students)
{
    int position;

    cout << YELLOW << "Enter the ID of the student you would like to edit: " << RESET;
    position = readInt();
    position -= 1;

    cout << GRAY << "Edit the name of the selected student:" << RESET << endl;
    cout << PURPLE << " First name: " << RESET;
    cin >> students[position].name;
    cout << CYAN << " Last name: " <<RESET<< endl;
    cin >> students[position].surname;
}

//Edits the class of a student
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

    while (students[position].className != 'A' and students[position].className != 'B' and students[position].className != 'V' and students[position].className != 'G')
    {
        cout << endl;
        cout << RED << "The name of the class should be A, B, V or G. Please, try again: " << RESET;
        cin >> students[position].className;
    }
}

//Edits the team role of a student
void updateStudentRole(STUDENT* students)
{
    int position;

    cout << YELLOW << "Enter the ID of the student you would like to edit: " << RESET;
    position = readInt();
    position -= 1;

    int choice;
    cout <<GRAY<< "Edit the role of the selected student (choose from the options listed below): " <<RESET<< endl << endl;

    cout << " 1. Scrum Trainer" << endl;
    cout << " 2. QA Engineer" << endl;
    cout << " 3. Backend Developer" << endl;
    cout << " 4. Frontend Developer" << endl << endl;

    cout << "Enter your choice: ";
    choice = readInt();

    while (choice > 4 or choice < 1)
    {
        cout << endl;
        cout << RED << "The number you enter has to be between 1 and 4! Please, try again: " << RESET;
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

//Edits the e-mail of a student
void updateStudentEmail(STUDENT* students)
{
    int position;

    cout << YELLOW << "Enter the ID of the student you would like to edit: " << RESET;;
    position = readInt();
    position -= 1;

    cout << " New E-mail: ";
    cin >> students[position].email;
}

//Searches for students by their first and last name
void searchStudentByName(STUDENT* students, int& index)
{
    int result = 0;
    string name, surname;
    cout << YELLOW << "Enter the first and last name of the student you are looking for: " << RESET << endl;
    cout << PURPLE << " First name: " << RESET;
    cin >> name;
    cout << CYAN << " Last name: " << RESET;
    cin >> surname;

    cout << endl;

    for (int i = 0; i < index; i++)
    {
        if (students[i].name == name and students[i].surname == surname)
        {
            showStudent(students, i);
            cout << endl << endl;
            result++;
        }
    }

    if (result == 0)
        cout << GRAY << "Nothing was found!" << RESET << endl;
}

//Searches for students by their class (year and class name)
void searchStudentsByClass(STUDENT* students, int& index)
{
    int result = 0;
    int schoolYear;
    char className;
    cout << YELLOW << "Show all the students from this class: " << RESET << endl;
    cout << " School year: ";
    schoolYear = readInt();
    cout << " Class name: ";
    cin >> className;

    while (className != 'A' and className != 'B' and className != 'V' and className != 'G')
    {
        cout << endl;
        cout << RED << "The name of the class should be A, B, V or G. Please, try again: " << RESET;
        cin >> className;
    }

    cout << endl;

    for (int i = 0; i < index; i++)
    {
        if (students[i].schoolYear == schoolYear and students[i].className == className)
        {
            showStudent(students, i);
            cout << endl;
            result++;
        }
    }

    if (result == 0)
        cout << GRAY << "Nothing was found!" << RESET << endl;
}

//Searches for students by their role in their team
void searchStudentsByRole(STUDENT* students, int& index)
{
    int result = 0;
    int choice;
    role option;

    cout << YELLOW << "Students in which role would you like to see?" << RESET << endl;
    cout << GREEN << "1." << RESET << " Scrum Trainer" << endl;
    cout << BLUE << "2." << RESET << " QA Engineer" << endl;
    cout << CYAN << "3." << RESET << " Backend Developer" << endl;
    cout << PURPLE << "4." << RESET << "Frontend Developer" << endl << endl;
    cout << "Enter your choice: ";
    choice = readInt();

    while (choice > 4 or choice < 1)
    {
        cout << endl;
        cout << RED << "The number you enter has to be between 1 and 4! Please, try again: " << RESET;
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
            result++;
        }
    }

    if (result == 0)
        cout << GRAY << "Nothing was found!" << RESET << endl;
}

//Searches for students who don't have a team yet
void searchStudentsWithoutATeam(STUDENT* students, int& index)
{
    int result = 0;

    cout << YELLOW << "Students that haven't joined any team yet: " << RESET << endl << endl;

    for (int i = 0; i < index; i++)
    {
        if (students[i].hasATeam == false)
        {
            showStudent(students, i);
            cout << endl << endl;
            result++;
        }
    }

    if (result == 0)
        cout << GRAY << "Nothing was found!" << RESET << endl;
}

/*===========================================================================*/

//Statically fills up an array of teams
void initTeams(STUDENT* students, int& index, TEAM* teams, int& t_index)
{
    teams[0] = { "Vikings", "We are here to win!", {10,2,2021}, {students[2], students[4], students[10]}, status::notActive, 3, 1 };
    teams[1] = { "We Showed Up", "Hoping for the best with minimum effort!", {13,2,2021}, {students[7], students[9], students[11]}, status::inUse, 3, 1 };
    teams[2] = { "Cereal Killers", "Trying our best", {20, 2, 2021},  {students[0], students[1], students[5]}, status::notArchived, 3, 1 };

    t_index = 3;
}

//Outputs a single team from the teams array
void showTeam(STUDENT* students, TEAM* teams, int& t_index)
{
    cout << CYAN << "ID: " << RESET << t_index + 1 << endl;
    cout << BLUE << "Name: " << RESET << teams[t_index].name << endl;
    cout << PURPLE << "Description: " << RESET << teams[t_index].description << endl;
    cout << YELLOW << "Date of set-up: " << RESET << UWhite << teams[t_index].dateOfSetUp.day << "/"
        << teams[t_index].dateOfSetUp.month << "/" << teams[t_index].dateOfSetUp.year<<RESET << endl;
    cout << GREEN << "Teammates: " << RESET << endl;

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

    cout << GRAY << "Status: " << RESET;
    if (teams[t_index].teamStatus == 0)
        cout << GREEN << "In use" << RESET;
    else if (teams[t_index].teamStatus == 1)
        cout << RED << "Not active" << RESET;
    else
        cout << GRAY << "Not archived" << RESET;
}

//Outputs a list of all of the teams in the teams array
void showTeams(STUDENT* students, TEAM* teams, int& t_index)
{
    cout << GREEN << "List of teams: " << RESET << endl << endl;
    for (int i = 0; i < t_index; i++)
    {
        showTeam(students, teams, i);
        cout << endl << endl;
    }
}

//Inputs data for a new team in the teams array
void enterTeam(STUDENT* students, TEAM* teams, int& t_index)
{
    int number, id;

    cout <<GREEN<< "Enter info about a new team:" <<RESET<< endl;

    cin.ignore();

    cout << YELLOW << "Name of the team: " << RESET;
    getline(cin, teams[t_index].name);
    
    cout << GREEN << "Description: " << RESET;
    getline(cin, teams[t_index].description);
    
    cout << BLUE << "Date of set up: " << RESET << endl;
    cout << CYAN << " Day: " << RESET;
    teams[t_index].dateOfSetUp.day = readInt();
    cout << " Month: ";
    teams[t_index].dateOfSetUp.month = readInt();
    cout << " Year: ";
    teams[t_index].dateOfSetUp.year = readInt();

    cout << "Number of members: ";
    number = readInt();

    teams[t_index].numOfStudents = number;

    cout << GREEN << "Enter the ID numbers of the members of the team: " << RESET << endl;
    for (int i = 0; i < number; i++)
    {
        cout << " " << i + 1 << ". ";
        id = readInt();
        teams[t_index].teammates[i] = students[id - 1];
    }

    t_index++;
}

//Deletes a particular team from the teams array
void deleteTeam(TEAM* teams, int& t_index)
{
    int position;

    cout << GREEN << "Enter the ID of the team you would like to remove from the list: " << RESET;
    position = readInt();
    position -= 1;

    for (int i = position; i < t_index - 1; i++)
    {
        teams[i] = teams[i + 1];
    }

    t_index--;
}

//Edits the name of a team
void updateTeamName(TEAM* teams)
{
    int position;

    cout << GREEN << "Enter the ID of the team you would like to edit: " << RESET;
    position = readInt();;
    position -= 1;

    cin.ignore();
    cout << GREEN << " New team name: " << RESET;
    getline(cin, teams[position].name);
}

//Edits the description of a team
void updateTeamDescription(TEAM* teams)
{
    int position;

    cout << GREEN << "Enter the ID of the team you would like to edit: " << RESET;
    position = readInt();
    position -= 1;

    cin.ignore();

    cout << GREEN << " New team description: " << RESET;;
    getline(cin, teams[position].description);
}

//Edits the status of a team
void updateTeamStatus(TEAM* teams)
{
    int position;

    cout << GREEN << "Enter the ID of the team you would like to edit: " << RESET;
    position = readInt();
    position -= 1;

    int choice;
    cout << GRAY<<"Edit the status of the selected team (choose from the options listed below): "<<RESET << endl;
    cout << GREEN << "1." << RESET << " In use" << endl;
    cout << RED << "2." << RESET << " Not active" << endl;
    cout << GRAY << "3." << RESET << " Not archived" << endl << endl;

    cout << "Enter your choice: ";
    choice = readInt();

    while (choice > 3 or choice < 1)
    {
        cout << endl;
        cout << RED << "The number you enter has to be between 1 and 3! Please, try again: " << RESET;
        choice = readInt();
    }

    if (choice == 1)
        teams[position].teamStatus = status::inUse;
    else if (choice == 2)
        teams[position].teamStatus = status::notActive;
    else
        teams[position].teamStatus = status::notArchived;
}

//Adds a new member to a particular team
void addStudentToTeam(STUDENT* students, TEAM* teams)
{
    int position;

    cout << GREEN << "Enter the ID of the team you would like to edit: " << RESET;
    position = readInt();
    position -= 1;
    cout << endl;

    int id;
    cout << GREEN << "Enter the ID number of the student you want to be added to the selected team: " << RESET;
    id = readInt();

    teams[position].teammates[teams[position].numOfStudents] = students[id - 1];
    teams[position].numOfStudents++;
    students[id - 1].hasATeam = true;
}

//Removes a member from a particular team
void removeStudentFromTeam(STUDENT* students, TEAM* teams)
{
    int position;
    cout << GREEN << "Enter the ID of the team you would like to edit: " << RESET;
    position = readInt();;
    position -= 1;
    cout << endl;

    int id;
    cout << GREEN << "Enter the ID number of the student you want to be removed from the selected team: " << RESET;
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

//Searches for teams by their name 
void searchTeamByName(STUDENT* students, TEAM* teams, int& t_index)
{
    int result = 0;
    string name;
    cout << GREEN << "Enter the name of the team you are looking for: " << RESET;
    cin >> name;

    cout << endl;

    for (int i = 0; i < t_index; i++)
    {
        if (teams[i].name == name)
        {
            showTeam(students, teams, i);
            cout << endl << endl;
            result++;
        }
    }

    cout << endl;

    if (result == 0)
        cout << GRAY << "Nothing was found!" << RESET << endl;
}

//Searches for teams by their status
void searchTeamByStatus(STUDENT* students, TEAM* teams, int& t_index)
{
    int result = 0;
    int choice;
    status option;

    cout << GREEN << "Teams with what status would you like to see?" << RESET << endl;
    cout << GREEN << "1." << RESET << " In use" << endl;
    cout << RED << "2." << RESET << " Not active" << endl;
    cout << GRAY << "3." << RESET << " Not archived" << endl << endl;

    cout << "Enter your choice: ";
    choice = readInt();

    while (choice > 3 or choice < 1)
    {
        cout << endl;
        cout << RED << "The number you enter has to be between 1 and 3! Please, try again: " << RESET;
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
            result++;
        }
    }

    if (result == 0)
        cout << GRAY << "Nothing was found!" << RESET << endl;
}

//Searches for teams by the number of their members
void searchTeamByNumberOfMembers(STUDENT* students, TEAM* teams, int& t_index)
{
    int result = 0;
    int number;
    cout << GREEN << "Enter teams with how many teammates you want to see (2-4): " << RESET;
    number = readInt();

    while (number > 4 or number < 2)
    {
        cout << endl;
        cout << RED << "The number you enter has to be between 2 and 4! Please, try again: " << RESET;
        number = readInt();
    }

    cout << endl;

    for (int i = 0; i < t_index; i++)
    {
        if (teams[i].numOfStudents == number)
        {
            showTeam(students, teams, i);
            cout << endl << endl;
            result++;
        }
    }

    if (result == 0)
        cout << GRAY << "Nothing was found!" << RESET << endl;
}

//Searches for teams which haven't been assigned a teacher yet
void searchTeamsWithoutATeacher(STUDENT* students, TEAM* teams, int& t_index)
{
    int result = 0;

    cout << GREEN << "Teams that haven't got any teacher yet: " << RESET << endl << endl;

    for (int i = 0; i < t_index; i++)
    {
        if (teams[i].hasATeacher == false)
        {
            showTeam(students, teams, i);
            cout << endl << endl;
            result++;
        }
    }

    if (result == 0)
        cout << GRAY << "Nothing was found!" << RESET << endl;
}


/*==========================================================================*/

//Statically fills up an array of teachers
void initTeachers(TEAM* teams, TEACHER* teachers, int& tch_index)
{
    teachers[0] = { "Ivelina", "Staykova", {teams[0], teams[1]}, "iStaikova@abv.bg", 2 };
    teachers[1] = { "Yordan", "Kamenov", {teams[2]}, "yordanKA@gmail.com", 1 };

    tch_index = 2;
}

//Outputs a single teacher from the teachers array
void showTeacher(TEAM* teams, TEACHER* teachers, int& tch_index)
{
    int numOfTeams = teachers[tch_index].numOfTeams;
    cout << BLUE<<"ID: " << RESET << tch_index + 1<< endl;
    cout << CYAN << "First and last name: " << RESET << teachers[tch_index].name << " " << teachers[tch_index].surname << endl;
    cout << PURPLE << "Teams they assist: " << RESET << endl;
    for (int i = 0; i < numOfTeams; i++)
    {
        cout << " " << i + 1 << ". " << teachers[tch_index].teams[i].name << endl;
    }
    cout << YELLOW<<"E-mail: "<<RESET <<UWhite<< teachers[tch_index].email <<RESET<< endl;
}

//Outputs a list of all of the teachers in the teachers array
void showTeachers(TEAM* teams, TEACHER* teachers, int& tch_index)
{
    cout <<CYAN<< "List of teachers: " << RESET<<endl << endl;
    for (int i = 0; i < tch_index; i++)
    {
        showTeacher(teams, teachers, i);
        cout << endl << endl;
    }
}

//Inputs data for a new teacher in the teachers array
void enterTeacher(TEAM* teams, TEACHER* teachers, int& tch_index)
{
    int number, id;

    cout << CYAN << "Enter info about teacher:" << RESET << endl;

    cout << PURPLE << " First name: " << RESET;;
    cin >> teachers[tch_index].name;

    cout << YELLOW << " Last name: " << RESET;
    cin >> teachers[tch_index].surname;

    cout << BLUE << " E-mail: " << RESET;
    cin >> teachers[tch_index].email;

    cout << GREEN << " Number of teams they assist: " << RESET;
    number = readInt();

    teachers[tch_index].numOfTeams = number;

    cout << GREEN << "Enter the IDs of the teams they assist:" << RESET << endl;
    for (int i = 0; i < number; i++)
    {
        cout << " " << i + 1 << ". ";
        id = readInt();
        teachers[tch_index].teams[i] = teams[id - 1];
    }

    tch_index++;
}

//Deletes a particular teacher from the teachers array
void deleteTeacher(TEACHER* teachers, int& tch_index)
{
    int position;

    cout << CYAN << "Enter the ID of the teacher you would like to remove from the list: " << RESET;
    position = readInt();
    position -= 1;

    for (int i = position; i < tch_index - 1; i++)
    {
        teachers[i] = teachers[i + 1];
    }

    tch_index--;
}

//Edits the name of a teacher
void updateTeacherName(TEACHER* teachers)
{
    int position;

    cout << CYAN << "Enter the ID of the teacher you would like to edit: " << RESET;
    position = readInt();
    position -= 1;

    cout << GRAY << "Edit the name of the selected teacher:" << RESET << endl;
    cout << PURPLE << " First name: " << RESET;
    cin >> teachers[position].name;
    cout << YELLOW << " Last name: " << RESET;
    cin >> teachers[position].surname;
}

//Edits the email of a teacher
void updateTeacherEmail(TEACHER* teachers)
{
    int position;

    cout << CYAN << "Enter the ID of the teacher you would like to edit: " << RESET;
    position = readInt();
    position -= 1;

    cout << " New E-mail: ";
    cin >> teachers[position].email;
}

//Assigns a new team to a particular teacher
void addTeamToTeacher(TEAM* teams, TEACHER* teachers)
{
    int position;

    cout <<CYAN<< "Enter the ID of the teacher you would like to edit: "<<RESET;
    position = readInt();
    position -= 1;

    cout << endl;

    int id;
    cout << CYAN << "Enter the ID of the team you want to be assisted by the selected teacher: " << RESET;
    id = readInt();

    teachers[position].teams[teachers[position].numOfTeams] = teams[id - 1];
    teachers[position].numOfTeams++;
    teams[id - 1].hasATeacher = true;
}

//Removes a team from a particular teacher
void removeTeamFromTeacher(TEAM* teams, TEACHER* teachers)
{
    int position;

    cout << CYAN << "Enter the ID of the teacher you would like to edit: " << RESET;
    position = readInt();
    position -= 1;

    cout << endl;

    int id;
    cout << CYAN << "Enter the ID of the team you want to not be assisted by the selected teacher anymore: " << RESET;
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

//Searches for teachers by their first and last names
void searchTeacherByName(TEAM* teams, TEACHER* teachers, int& tch_index)
{
    int result = 0;
    string name, surname;
    cout << CYAN << "Enter the first and last name of the teacher you are looking for: " << RESET << endl;
    cout << PURPLE << "First name: " << RESET;
    cin >> name;
    cout << YELLOW << "Last name: " << RESET;
    cin >> surname;

    cout << endl;

    for (int i = 0; i < tch_index; i++)
    {
        if (teachers[i].name == name and teachers[i].surname == surname)
        {
            showTeacher(teams, teachers, i);
            cout << endl << endl;
            result++;
        }
    }

    if (result == 0)
        cout << GRAY << "Nothing was found!" << RESET << endl;
}

//Searches for teachers by their emails
void searchTeacherByEmail(TEAM* teams, TEACHER* teachers, int& tch_index)
{
    int result = 0;
    string email;
    cout << "Enter the e-mail of the teacher you would like to see: ";
    cin >> email;

    cout << endl;

    for (int i = 0; i < tch_index; i++)
    {
        if (teachers[i].email == email)
        {
            showTeacher(teams, teachers, i);
            cout << endl << endl;
            result++;
        }
   }

    if (result == 0)
    {
        cout << endl;
        cout << GRAY << "Nothing was found!" << RESET << endl;
    }
}

/*==========================================================================*/

//Initializes a variable of type SCHOOL
void initSchool(STUDENT* students, int& st_index, TEAM* teams, int& t_index, TEACHER* teachers, int& tch_index, SCHOOL& school)
{
    school.name = "Vocational School for Programming and Innovation";
    school.city = "Burgas";
    school.address.streetName = "Zahari Stoyanov";
    school.address.streetNumber = 5;

    for (int i = 0; i < st_index; i++)
    {
        school.students[i] = students[i];
    }

    for (int i = 0; i < t_index; i++)
    {
        school.teams[i] = teams[i];
    }

    for (int i = 0; i < tch_index; i++)
    {
        school.teachers[i] = teachers[i];
    }
}

//Outputs information about the school
void showSchoolAddress(STUDENT* students, int& st_index, TEAM* teams, int& t_index, TEACHER* teachers, int& tch_index, SCHOOL* school)
{
    cout << "Name: " << school->name << endl;
    cout << "City: " << school->city << endl;
    cout << "Address: " << endl;
    cout << "  Street name: " << school->address.streetName << endl;
    cout << "  Street number: " << school->address.streetNumber << endl<<endl;
}

/*==========================================================================*/

//print spaces
void spaces(int count)
{
    for (int i = 0; i < count; i++)
    {
        cout << " ";
    }
}

//Displays a greeting for the user in the beginning when the program is started
void greetings()
{
    cout << "Hello from us, the codebenders, and welcome to our program!" << endl;
}

//Asks the user if they want to stay in the same menu or to return one menu back 
bool returnBack()
{
    int choice;

    cout << endl;
    cout << "What would you like to do now?" << endl << endl;
    cout << GREEN << "1)" << RESET << " Stay here" << endl;
    cout << GRAY << "2)" << RESET << " Go one menu back" << endl << endl;
    cout << "Enter your choice: ";

    choice = readInt();

    while (choice > 2 or choice < 1)
    {
        cout << endl;
        cout << RED << "The number you enter has to be either 1 or 2! Please, try again: " RESET;
        choice = readInt();
    }

    cout << endl;

    system("cls");

    if (choice == 1)
        return true;
    
    return false;
}


//Shows options for searching for students by different criteria
void searchStudentMenu(STUDENT* students, int& st_index, TEAM* teams, int& t_index, TEACHER* teachers, int& tch_index, SCHOOL* school)
{
    bool cont = true;
    while (cont == true)
    {
        int userChoice;

        cout << YELLOW <<"By what criteria do you want to search for a student/-s?" << RESET <<endl << endl;

        cout << GREEN << "1)" << RESET << " Name" << endl;
        cout << CYAN << "2)" << RESET << " Class" << endl;
        cout << PURPLE << "3)" << RESET << " Role" << endl;
        cout << RED << "4)" << RESET << " Without a team" << endl;
        cout << GRAY << "5)" << RESET << " Return back to Students Menu" << endl << endl;


        cout << "Enter your choice: ";
        userChoice = readInt();

        while (userChoice > 5 or userChoice < 1)
        {
            cout << endl;
            cout << RED << "The number you enter has to be between 1 and 5! Please, try again: " << RESET;
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
            searchStudentsByClass(students, st_index);
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
            displayStudentsMenu(students, st_index, teams, t_index, teachers, tch_index, school);
            cont = false;
            break;
        }
    }
    displayStudentsMenu(students, st_index, teams, t_index, teachers, tch_index, school);
}

//Shows options for editing different information about a particular student
void  updateStudentInfoMenu(STUDENT* students, int& st_index, TEAM* teams, int& t_index, TEACHER* teachers, int& tch_index, SCHOOL* school)
{
    bool cont = true;
    while (cont == true)
    {
        int userChoice;

        cout <<YELLOW<< "What would you like to update?" <<RESET<< endl << endl;
        cout <<GREEN<< "1)"<<RESET<<" Name" << endl;
        cout <<BLUE<< "2)"<<RESET<<" Class" << endl;
        cout <<CYAN<< "3)"<<RESET<<" Email" << endl;
        cout <<PURPLE<< "4)"<<RESET<<" Team role" << endl;
        cout << GRAY << "5)" << RESET << " Return back to Students Menu" << endl << endl;

        cout << "Enter your choice: ";
        userChoice = readInt();

        while (userChoice > 5 or userChoice < 1)
        {
            cout << endl;
            cout << RED << "The number you enter has to be between 1 and 5! Please, try again: " << RESET;
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
            displayStudentsMenu(students, st_index, teams, t_index, teachers, tch_index, school);
            cont = false;
            break;
        }
    }
    displayStudentsMenu(students, st_index, teams, t_index, teachers, tch_index, school);
}

//Shows options for searching for teams by different criteria
void searchTeamMenu(STUDENT* students, int& st_index, TEAM* teams, int& t_index, TEACHER* teachers, int& tch_index, SCHOOL* school)
{
    bool cont = true;
    while (cont == true)
    {
        int userChoice;

        cout << GREEN << "By what criteria do you want to search for a team/-s?" << RESET << endl << endl;
        cout << YELLOW << "1)" << RESET << " Name" << endl;
        cout << CYAN << "2)" << RESET << " Number of members" << endl;
        cout << BLUE << "3)" << RESET << " Status" << endl;
        cout << PURPLE << "4)" << RESET << " Teams which don't have a teacher" << endl;
        cout << GRAY << "5)" << RESET << " Return back to Teams Menu" << endl << endl;
        cout << "Enter your choice: ";
        userChoice = readInt();

        while (userChoice > 5 or userChoice < 1)
        {
            cout << endl;
            cout << RED << "The number you enter has to be between 1 and 5! Please, try again: " RESET;
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
            displayTeamsMenu(students, st_index, teams, t_index, teachers, tch_index, school);
            cont = false;
            break;
        }
    }
    displayTeamsMenu(students, st_index, teams, t_index, teachers, tch_index, school);
}

//Shows options for editing different information about a particular team
void updateTeamInfoMenu(STUDENT* students, int& st_index, TEAM* teams, int& t_index, TEACHER* teachers, int& tch_index, SCHOOL* school)
{
    bool cont = true;
    while (cont == true)
    {
        int userChoice;

        cout << GREEN << "What would you like to update?" << RESET << endl << endl;
        cout <<YELLOW<< "1)"<<RESET<<" Name" << endl;
        cout << CYAN << "2)" << RESET << " Description" << endl;
        cout << BLUE << "3)" << RESET << " Status" << endl;
        cout << PURPLE << "4)" << RESET << " Add a new member to a team" << endl;
        cout << RED << "5)" << RESET << " Remove a student from a team" << endl;
        cout << GRAY << "6)" << RESET << " Return back to Teams Menu" << endl << endl;

        cout << "Enter your choice: ";
        userChoice = readInt();

        while (userChoice > 6 or userChoice < 1)
        {
            cout << endl;
            cout << RED << "The number you enter has to be between 1 and 6! Please, try again: " << RESET;
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
            displayTeamsMenu(students, st_index, teams, t_index, teachers, tch_index, school);
            cont = false;
            break;
        }
    }
    displayTeamsMenu(students, st_index, teams, t_index, teachers, tch_index, school);
}

//Shows options for searching for teachers by different criteria
void searchTeacherMenu(STUDENT* students, int& st_index, TEAM* teams, int& t_index, TEACHER* teachers, int& tch_index, SCHOOL* school)
{
    bool cont = true;
    while (cont == true)
    {
        int userChoice;

        cout <<CYAN<< "By what criteria do you want to search for a teacher/-s?" <<RESET<< endl << endl;
        cout <<BLUE<< "1)"<<RESET<<" Name" << endl;
        cout <<GREEN<< "2)"<<RESET<<" E-mail" << endl;
        cout <<GRAY<< "3)"<<RESET<<" Return back to Teachers Menu" << endl << endl;

        cout << "Enter your choice: ";
        userChoice = readInt();

        while (userChoice > 3 or userChoice < 1)
        {
            cout << endl;
            cout << RED << "The number you enter has to be between 1 and 3! Please, try again: " << RESET;
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
            searchTeacherByEmail(teams, teachers, tch_index);
            cont = returnBack();
            break;
        case 3:
            displayTeachersMenu(students, st_index, teams, t_index, teachers, tch_index, school);
            cont = false;
            break;
        }
    }
    displayTeachersMenu(students, st_index, teams, t_index, teachers, tch_index, school);
}

//Shows options for editing different information about a particular teacher
void updateTeacherInfoMenu(STUDENT* students, int& st_index, TEAM* teams, int& t_index, TEACHER* teachers, int& tch_index, SCHOOL* school)

{
    bool cont = true;
    while (cont == true)
    {
        int userChoice;

        cout <<GRAY<< "What would you like to update?" << RESET << endl << endl;
        cout <<YELLOW<< "1)"<<RESET<<" Name" << endl;
        cout <<PURPLE<< "2)"<<RESET<<" Email" << endl;
        cout <<BLUE<< "3)"<<RESET<<" Assign a team to a teacher" << endl;
        cout <<CYAN<< "4)"<<RESET<<" Remove a team from a teacher" << endl;
        cout <<GRAY<< "5)"<<RESET<<" Return back to Teachers Menu" << endl << endl;

        cout << "Enter your choice: ";
        userChoice = readInt();

        while (userChoice > 5 or userChoice < 1)
        {
            cout << endl;
            cout << RED << "The number you enter has to be between 1 and 5! Please, try again: " RESET;
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
            displayTeachersMenu(students, st_index, teams, t_index, teachers, tch_index, school);
            cont = false;
            break;
        }
    }
    displayTeachersMenu(students, st_index, teams, t_index, teachers, tch_index, school);
}



//Shows a sub menu with options connected with students
void displayStudentsMenu(STUDENT* students, int& st_index, TEAM* teams, int& t_index, TEACHER* teachers, int& tch_index, SCHOOL* school)
{
    bool cont = true;
    while (cont == true)
    {
        int userChoice = 0;

        cout << endl;
    
        cout << YELLOW "  ____ _____ _   _ ____  _____ _   _ _____ ____  " << endl;
        cout << " / ___|_   _| | | |  _ \\| ____| \\ | |_   _/ ___| " << endl;
        cout << " \\___ \\ | | | | | | | | |  _| |  \\| | | | \\___ \\ " << endl;
        cout << "  ___) || | | |_| | |_| | |___| |\\  | | |  ___) |" << endl;
        cout << " |____/ |_|  \\___/|____/|_____|_| \\_| |_| |____/ " << RESET << endl << endl;
        cout << "  ======================================" << endl;
        cout << "||" << CYAN << "1)" << RESET << " Show a list of all the students    " << "||" << endl;
        cout << "||" << BLUE << "2)" << RESET << " Add a new student         " << "         ||" << endl;
        cout << "||" << RED << "3)" << RESET << " Delete a student        " << "           ||" << endl;
        cout << "||" << GREEN << "4)" << RESET << " Search a student by criteria    " << "   ||" << endl;
        cout << "||" << PURPLE << "5)" << RESET << " Update info about a student     " << "   ||" << endl;
        cout << "||" << GRAY << "6)" << RESET << " Return back to the Main Menu    " << "   ||" << endl;
        cout << "  ======================================" << endl << endl;

        cout << "Enter your choice: ";
        userChoice = readInt();

        while (userChoice > 6 or userChoice < 1)
        {
            cout << endl;
            cout << RED << "The number you enter has to be between 1 and 6! Please, try again: " << RESET;
            userChoice = readInt();
        }

        system("cls");

        switch (userChoice)
        {
        case 1:
            showStudents(students, st_index);
            cont = returnBack();
            break;
        case 2:
            enterStudent(students, st_index);
            cont = returnBack();
            break;
        case 3:
            deleteStudent(students, st_index);
            cont = returnBack();
            break;
        case 4:
            searchStudentMenu(students, st_index, teams, t_index, teachers, tch_index, school);
            cont = returnBack();
            break;
        case 5:
            updateStudentInfoMenu(students, st_index, teams, t_index, teachers, tch_index, school);
            cont = returnBack();
            break;
        case 6:
            displayMainMenu(students, st_index, teams, t_index, teachers, tch_index, school);
            cont = false;
            break;
        }
    }
}

//Shows a sub menu with options connected with teams
void displayTeamsMenu(STUDENT* students, int& st_index, TEAM* teams, int& t_index, TEACHER* teachers, int& tch_index, SCHOOL* school)
{
    bool cont = true;
    while (cont == true)
    {
        int userChoice = 0;
        
        cout <<GREEN<< "  _____         " << endl;
        cout << " |_   _|__  __ _ _ __ ___  ___" << endl;
        cout << "   | |/ _ \\/ _` | '_ ` _ \\/ __|" << endl;
        cout << "   | |  __/ (_| | | | | | \\__ \\" << endl;
        cout << "   |_|\\___|\\__,_|_| |_| |_|___/" << RESET << endl << endl;
        cout << "  ======================================" << endl;
        cout <<"||"<< YELLOW<< "1)"<<RESET<<" Show a list of all the teams"<<"       ||" << endl;
        cout <<"||"<< BLUE << "2)" << RESET << " Add a new team" << "                     ||" << endl;
        cout <<"||"<< RED<<"3)"<<RESET<<" Delete a team" << "                      ||" << endl;
        cout <<"||"<< CYAN << "4)" << RESET << " Search a team by criteria" << "          ||" << endl;
        cout <<"||"<< PURPLE<<"5)"<<RESET<<" Update info about a team" << "           ||" << endl;
        cout << "||" << GRAY << "6)" << RESET << " Return back to the Main Menu" << "       ||" << endl;

        cout << "  ======================================";
        cout << endl;
        cout << endl;

        cout << "Enter your choice: ";
        userChoice = readInt();

        while (userChoice > 6 or userChoice < 1)
        {
            cout << endl;
            cout << RED << "The number you enter has to be between 1 and 6! Please, try again: " << RESET;
            userChoice = readInt();
        }

        system("cls");

        switch (userChoice)
        {
        case 1:
            showTeams(students, teams, t_index);
            cont = returnBack();
            break;
        case 2:
            enterTeam(students, teams, t_index);
            cont = returnBack();
            break;
        case 3:
            deleteTeam(teams, t_index);
            cont = returnBack();
            break;
        case 4:
            searchTeamMenu(students, st_index, teams, t_index, teachers, tch_index, school);
            cont = returnBack();
            break;
        case 5:
            updateTeamInfoMenu(students, st_index, teams, t_index, teachers, tch_index, school);
            cont = returnBack();
            break;
        case 6:
            displayMainMenu(students, st_index, teams, t_index, teachers, tch_index, school);
            cont = false;
            break;
        }
    }
}

//Shows a sub menu with options connected with teachers 
void displayTeachersMenu(STUDENT* students, int& st_index, TEAM* teams, int& t_index, TEACHER* teachers, int& tch_index, SCHOOL* school)
{
    bool cont = true;
    while (cont == true)
    {
       int  userChoice = 0;
       
        cout << endl;
        
        cout <<CYAN<< " _____ _____    _    ____ _   _ _____ ____  ____  " << endl;
        cout << "|_   _| ____|  / \\  / ___| | | | ____|  _ \\/ ___| " << endl;
        cout << "  | | |  _|   / _ \\| |   | |_| |  _| | |_) \\___ \\ " << endl;
        cout << "  | | | |___ / ___ \\ |___|  _  | |___|  _ < ___) |" << endl;
        cout << "  |_| |_____/_/   \\_\\____|_| |_|_____|_| \\_\\____/ " << RESET << endl<< endl;
                                                   
        cout << "  ======================================"<<endl;
        cout << "||"<< BLUE << "1)"<<RESET<<" Show a list of all the teachers" <<"    ||"<< endl;
        cout << "||" << PURPLE << "2)" << RESET << " Add a new teacher" <<"                  ||"<< endl;
        cout << "||"<< RED << "3)" << RESET << " Delete a teacher" <<"                   ||"<< endl;
        cout << "||"<< YELLOW << "4)" << RESET << " Search a teacher by criteria" <<"       ||"<< endl;
        cout << "||"<< GREEN << "5)" << RESET << " Update info about a teacher" <<"        ||"<< endl;
        cout << "||" << GRAY << "6)" << RESET << " Return back to the Main Menu" << "       ||" << endl;
        cout << "  ======================================";

        cout << endl;
        cout << "Enter your choice: ";
        userChoice = readInt();

        while (userChoice > 6 or userChoice < 1)
        {
            cout << endl;
            cout << RED << "The number you enter has to be between 1 and 6! Please, try again: " << RESET;
            userChoice = readInt();
        }

        system("cls");

        switch (userChoice)
        {
        case 1:
            showTeachers(teams, teachers, tch_index);
            cont = returnBack();
            break;
        case 2:
            enterTeacher(teams, teachers, tch_index);
            cont = returnBack();
            break;
        case 3:
            deleteTeacher(teachers, tch_index);
            cont = returnBack();
            break;
        case 4:
            searchTeacherMenu(students, st_index, teams, t_index, teachers, tch_index, school);
            cont = returnBack();
            break;
        case 5:
            updateTeacherInfoMenu(students, st_index, teams, t_index, teachers, tch_index, school);
            cont = returnBack();
            break;
        case 6:
            displayMainMenu(students, st_index, teams, t_index, teachers, tch_index, school);
            cont = false;
            break;
        }
    }
}

//Shows a sub menu with options connected with the school
void displaySchoolMenu(STUDENT* students, int& st_index, TEAM* teams, int& t_index, TEACHER* teachers, int& tch_index, SCHOOL* school)
{
    bool cont = true;
    while (cont == true)
    {
        int  userChoice = 0;

        cout << endl;
        cout << BLUE << "  ____   ____ _   _  ___   ___  _     " << endl;
            cout << " / ___| / ___| | | |/ _ \\ / _ \\| |    " << endl;
            cout << " \\___ \\| |   | |_| | | | | | | | |    " << endl;
            cout << "  ___) | |___|  _  | |_| | |_| | |___ " << endl;
            cout << " |____/ \\____|_| |_|\\___/ \\___/|_____|" << RESET << endl;
            cout << endl;
                                      

        cout << "  ================================================" << endl;
        cout << "||" << BLUE << "1)" << RESET << " Show the name and address of the school" << "      ||" << endl;
        cout << "||" << PURPLE << "2)" << RESET << " Show a list of all the students in the school" << "||" << endl;
        cout << "||" << RED << "3)" << RESET << " Show a list of all the teams in the school" << "   ||" << endl;
        cout << "||" << YELLOW << "4)" << RESET << " Show a list of all the teachers in the school" << "||" << endl;
        cout << "||" << GRAY << "5)" << RESET << " Return back to the Main Menu" << "                 ||" << endl;
        cout << "  ================================================";

        cout << endl<<endl;

        cout << "Enter your choice: ";
        userChoice = readInt();

        while (userChoice > 5 or userChoice < 1)
        {
            cout << endl;
            cout << RED << "The number you enter has to be between 1 and 5! Please, try again: " << RESET;
            userChoice = readInt();
        }

        system("cls");

        switch (userChoice)
        {
        case 1:
            showSchoolAddress(students, st_index, teams, t_index, teachers, tch_index, school);
            cont = returnBack();
            break;
        case 2:
            showStudents(students, st_index);
            cont = returnBack();
            break;
        case 3:
            showTeams(students, teams, t_index);
            cont = returnBack();
            break;
        case 4:
            showTeachers(teams, teachers, tch_index);
            cont = returnBack();
            break;
        case 5:
            displayMainMenu(students, st_index, teams, t_index, teachers, tch_index, school);
            cont = false;
            break;
        }
    }
}


//Shows the main menu of the program
void displayMainMenu(STUDENT* students, int& st_index, TEAM* teams,  int& t_index, TEACHER* teachers, int& tch_index, SCHOOL* school)
{
    int userChoice = 0;

    while (userChoice != 5)
    {
        cout << endl;
        
        cout << " __  __       _         __  __                      " << endl;
        cout << "|  \\/  |     (_)       |  \\/  |                   " << endl;
        cout << "| \\  / | __ _ _ _ __   | \\  / | ___ _ __  _   _   " << endl;
        cout << "| |\\/| |/ _` | | '_ \\  | |\\/| |/ _ \\ '_ \\| | | |" << endl;
        cout << "| |  | | (_| | | | | | | |  | |  __/ | | | |_| |    " << endl;
        cout << "|_|  |_|\\__,_|_|_| |_| |_|  |_|\\___|_| |_|\\__,_| " << endl;
  
        cout << endl;
        cout << endl;

        cout << "Which set of data would you like to work with?" << endl << endl;
        cout << "  =================" << endl;
        cout <<"||"<< YELLOW << "1)" << RESET<<" Students" <<"      ||"<< endl;
        cout <<"||"<< GREEN << "2)" << RESET<<" Teams"  <<"         ||"<< endl;
        cout <<"||"<< CYAN << "3)"<< RESET<<" Teachers"  <<"      ||"<< endl;
        cout <<"||"<< BLUE << "4)" << RESET<<" School"  <<"        ||"<< endl;
        cout << "||" << PURPLE << "5)" << RESET << " Exit" << "          ||" << endl;
        cout << "  =================" << endl;
        cout << endl;
        cout << "Enter your choice: ";
        userChoice = readInt();

        while (userChoice > 5 or userChoice < 1)
        {
            cout << endl;
            cout << RED << "The number you enter has to be between 1 and 5! Please, try again: " << RESET;
            userChoice = readInt();
        }

        system("cls");

        switch (userChoice)
        {
        case 1:
            displayStudentsMenu(students, st_index, teams, t_index, teachers, tch_index, school);
            break;
        case 2:
            displayTeamsMenu(students, st_index, teams, t_index, teachers, tch_index,school);
            break;
        case 3:
            displayTeachersMenu(students, st_index, teams, t_index, teachers, tch_index, school);
            break;
        case 4:
            displaySchoolMenu(students, st_index, teams, t_index, teachers, tch_index, school);
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
    SCHOOL school;

    int st_index = 0, t_index = 0, tch_index = 0;

    initStudents(students, st_index);
    initTeams(students, st_index, teams, t_index);
    initTeachers(teams, teachers, tch_index);
    initSchool(students, st_index, teams, t_index, teachers, tch_index, school);

    greetings();
    displayMainMenu(students, st_index, teams, t_index, teachers, tch_index, &school);
}
