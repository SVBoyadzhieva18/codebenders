#pragma once
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


//Statically fills up an array of students
void initStudents(STUDENT* students, int& index);

//Statically fills up an array of teams
void initTeams(STUDENT* students, int& index, TEAM* teams, int& t_index);

//Statically fills up an array of teachers
void initTeachers(TEAM* teams, TEACHER* teachers, int& tch_index);

//Initializes a variable of type SCHOOL
void initSchool(STUDENT* students, int& st_index, TEAM* teams, int& t_index, TEACHER* teachers, int& tch_index, SCHOOL& school);