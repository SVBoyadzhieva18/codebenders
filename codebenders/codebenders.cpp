#include <iostream>
#include <string>
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
    int numOfStudents;
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


/*=============================================================================*/

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
    students[9] = { "Galena", "Hadzhieva", 9, 'V', role::developerBackend, "geymarkata@gmail.com" };
    students[10] = { "Didi", "Popova", 10, 'A', role::QAEngineer, "Dida_D@abv.bg" };
    students[11] = { "Radomir", "Liliev", 9, 'B', role::scrumTrainer, "RadoGashtite@gmail.com" };


    index = 12;
}

void showStudent(STUDENT* students, int index)
{
    cout << "Student ID: " << index + 1 << endl;
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

    cout << " Role in team: " << endl;
    cout << "  1. Scrum Trainer" << endl;
    cout << "  2. QA Engineer" << endl;
    cout << "  3. Backend Developer" << endl;
    cout << "  4. Frontend Developer" << endl;
    cout << "Enter choice: ";
    cin >> choice;
    students[index].teamRole = role(choice - 1);

    cout << "E-mail: ";
    cin >> students[index].email;

    index++;
}

void deleteStudent(STUDENT* students, int& index, int position)
{
    for (int i = position; i < index - 1; i++)
    {
        students[i] = students[i + 1];
    }

    index--;
}

void updateStudentName(STUDENT* students, int position)
{
    cout << "Edit the name of the selected student:" << endl;
    cout << " First name: ";
    cin >> students[position].name;
    cout << " Last name: ";
    cin >> students[position].surname;
}

void updateStudentClass(STUDENT* students, int position)
{
    cout << "Edit the class of the selected student:" << endl;
    cout << " School year: ";
    cin >> students[position].schoolYear;
    cout << " Class name (capital letter): ";
    cin >> students[position].className;
}

void updateStudentRole(STUDENT* students, int position)
{
    int choice;
    cout << "Edit the role of the selected student (choose from the options listed below): " << endl << endl;

    cout << " 1. Scrum Trainer" << endl;
    cout << " 2. QA Engineer" << endl;
    cout << " 3. Backend Developer" << endl;
    cout << " 4. Frontend Developer" << endl << endl;

    cout << "Enter your choice: ";
    cin >> choice;

    if (choice == 1)
        students[position].teamRole = role::scrumTrainer;
    else if (choice == 2)
        students[position].teamRole = role::QAEngineer;
    else if (choice == 3)
        students[position].teamRole = role::developerBackend;
    else
        students[position].teamRole = role::developerFrontend;
}

void updateStudentEmail(STUDENT* students, int position)
{
    cout << "Edit the e-mail of the selected student:" << endl;
    cout << " New E-mail: ";
    cin >> students[position].email;
}

void searchStudentByName(STUDENT* students, int& index)
{
    string name, surname;
    cout << "Enter the first and last name of the student you are looking for: ";
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
    cout << "Show all the students from this class: ";
    cout << " School year: ";
    cin >> schoolYear;
    cout << " Class name: ";
    cin >> className;

    cout << endl;

    for (int i = 0; i < index; i++)
    {
        if (students[i].schoolYear == schoolYear and students[i].className == className)
        {
            showStudent(students, i);
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
    cin >> choice;
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
        }
    }
}

/*===========================================================================*/

void initTeams(STUDENT* students, int& index, TEAM* teams, int& t_index)
{
    teams[0] = { "Vikings", "We are here to win!", {10,2,2021}, {students[2], students[4], students[10]}, status::notActive, 3 };
    teams[1] = { "We Showed Up", "Hoping for the best with minimum effort!", {13,2,2021}, {students[7], students[9], students[11]}, status::inUse, 3 };
    teams[2] = { "Cereal Killers", "Trying our best", {20, 2, 2021},  {students[0], students[1], students[5]}, status::notArchived, 3 };

    t_index = 3;
}

void showTeam(STUDENT* students, TEAM* teams, int& t_index)
{
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

    cout << "Name of the team: ";
    getline(cin, teams[t_index].name);


    cout << "Description: ";
    getline(cin, teams[t_index].description);

    cout << "Date of set up: " << endl;
    cout << " Day: ";
    cin >> teams[t_index].dateOfSetUp.day;
    cout << " Month: ";
    cin >> teams[t_index].dateOfSetUp.month;
    cout << " Year: ";
    cin >> teams[t_index].dateOfSetUp.year;

    cout << "Number of members: ";
    cin >> number;

    teams[t_index].numOfStudents = number;

    cout << "Enter the ID numbers of the members of the team: " << endl;
    for (int i = 0; i < number; i++)
    {
        cout << " " << i + 1 << ". ";
        cin >> id;
        teams[t_index].teammates[i] = students[id - 1];
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

void updateTeamName(TEAM* teams, int pos)
{
    cout << "Edit the name of the selected team:" << endl;
    cout << " New team name: ";
    getline(cin, teams[pos].name);
}

void updateTeamDescription(TEAM* teams, int pos)
{
    cout << "Edit the desciption of the selected team: " << endl;
    cout << " New team description: ";
    getline(cin, teams[pos].description);
}

void updateTeamStatus(TEAM* teams, int pos)
{
    int choice;
    cout << "Edit the status of the selected team (choose from the options listed below): " << endl;
    cout << "1. In use" << endl;
    cout << "2. Not active" << endl;
    cout << "3. Not archived" << endl << endl;

    cout << "Enter your choice: ";
    cin >> choice;

    if (choice == 1)
        teams[pos].teamStatus = status::inUse;
    else if (choice == 2)
        teams[pos].teamStatus = status::notActive;
    else
        teams[pos].teamStatus = status::notArchived;
}

void addStudentToTeam(STUDENT* students, TEAM* teams, int position)
{
    int id;
    cout << "Enter the ID number of the student you want to be added to the selected team: ";
    cin >> id;

    teams[position].teammates[teams[position].numOfStudents] = students[id - 1];
    teams[position].numOfStudents++;
}

void removeStudentFromTeam(STUDENT* students, TEAM* teams, int t_index, int position)
{
    int numberOfStudents = teams[t_index].numOfStudents;

    for (int i = position; i < numberOfStudents - 1; i++)
    {
        teams[t_index].teammates[i] = teams[t_index].teammates[i + 1];
    }

    teams[t_index].numOfStudents--;
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
        }
    }
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
    cin >> choice;
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
        }
    }

}

void searchTeamByNumberOfMembers(STUDENT* students, TEAM* teams, int& t_index)
{
    int number;
    cout << "Enter teams with how many teammates you want to see (2-4): ";
    cin >> number;

    cout << endl;

    for (int i = 0; i < t_index; i++)
    {
        if (teams[i].numOfStudents == number)
        {
            showTeam(students, teams, i);
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
    cin >> number;

    teachers[tch_index].numOfTeams = number;

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

void updateTeacherName(TEACHER* teachers, int position)
{
    cout << "Edit the name of the selected teacher:" << endl;
    cout << " First name: ";
    cin >> teachers[position].name;
    cout << " Last name: ";
    cin >> teachers[position].surname;
}

void updateTeacherEmail(TEACHER* teachers, int position)
{
    cout << "Edit the e-mail of the selected teacher:" << endl;
    cout << " New E-mail: ";
    cin >> teachers[position].email;
}

void addTeamToTeacher(TEAM* teams, TEACHER* teachers, int position)
{
    int id;
    cout << "Enter the ID number of the team you want to be assisted by the selected tacher: ";
    cin >> id;

    teachers[position].teams[teachers[position].numOfTeams] = teams[id - 1];
    teachers[position].numOfTeams++;
}

void removeTeamFromTeacher(TEAM* teams, TEACHER* teachers, int tch_index, int position)
{
    int numberOfTeams = teachers[tch_index].numOfTeams;

    for (int i = position; i < numberOfTeams - 1; i++)
    {
        teachers[tch_index].teams[i] = teachers[tch_index].teams[i + 1];
    }

    teachers[tch_index].numOfTeams--;
}

/*==========================================================================*/

void greetings()
{
    cout << "Hello from us, the codebenders and welcome to out program!" << endl << endl;
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
    cout << "1. Name" << endl;
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
    cout << "1. Name" << endl;
    cout << "2. Team" << endl;

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



int studentSearchMenu()
{
    cout << endl;
    cout << "1. Show a list of all the students" << endl;
    cout << "2. Add a new student" << endl;
    cout << "3. Delete a student" << endl;
    cout << "4. Search a student by criteria" << endl;
    cout << "5. Update info about a student" << endl;

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

int teamSearchMenu()
{
    cout << endl;
    cout << "1. Show a list of all the teams" << endl;
    cout << "2. Add a new team" << endl;
    cout << "3. Delete a team" << endl;
    cout << "4. Search a team by criteria" << endl;
    cout << "5. Update info about a team" << endl;

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
    cout << "1. Show a list of all the teachers" << endl;
    cout << "2. Add a new teacher" << endl;
    cout << "3. Delete a teacher" << endl;
    cout << "4. Search a teacher by criteria" << endl;
    cout << "5. Update info about a teacher" << endl;

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
    showTeachers(teams, teachers, tch_index);
    enterTeacher(teams, teachers, tch_index);
    deleteTeacher(teachers, tch_index, 0);
    showTeachers(teams, teachers, tch_index);
}
