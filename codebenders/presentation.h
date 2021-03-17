#pragma once
#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

//Asks the user to input an integer and outputs an error message if they enter something else
int readInt();

//Outputs a single student from the students array
void showStudent(STUDENT* students, int index);

//Outputs a list of all of the students in the students array
void showStudents(STUDENT* students, int index);

//Inputs data for a new student in the students array
void enterStudent(STUDENT* students, int& index);

//Deletes a particular student from the students array
void deleteStudent(STUDENT* students, int& index);

//Edits the name of a student
void updateStudentName(STUDENT* students);

//Edits the class of a student
void updateStudentClass(STUDENT* students);

//Edits the team role of a student
void updateStudentRole(STUDENT* students);

//Edits the e-mail of a student
void updateStudentEmail(STUDENT* students);

//Searches for students by their first and last name
void searchStudentByName(STUDENT* students, int& index);

//Searches for students by their class (year and class name)
void searchStudentsByClass(STUDENT* students, int& index);

//Searches for students by their role in their team
void searchStudentsByRole(STUDENT* students, int& index);

//Searches for students who don't have a team yet
void searchStudentsWithoutATeam(STUDENT* students, int& index);

//Outputs a single team from the teams array
void showTeam(STUDENT* students, TEAM* teams, int& t_index);

//Outputs a list of all of the teams in the teams array
void showTeams(STUDENT* students, TEAM* teams, int& t_index);

//Inputs data for a new team in the teams array
void enterTeam(STUDENT* students, TEAM* teams, int& t_index);

//Deletes a particular team from the teams array
void deleteTeam(TEAM* teams, int& t_index);

//Edits the name of a team
void updateTeamName(TEAM* teams);

//Edits the description of a team
void updateTeamDescription(TEAM* teams);

//Edits the status of a team
void updateTeamStatus(TEAM* teams);

//Adds a new member to a particular team
void addStudentToTeam(STUDENT* students, TEAM* teams);

//Removes a member from a particular team
void removeStudentFromTeam(STUDENT* students, TEAM* teams);
//Searches for teams by their name 
void searchTeamByName(STUDENT* students, TEAM* teams, int& t_index);

//Searches for teams by their status
void searchTeamByStatus(STUDENT* students, TEAM* teams, int& t_index);

//Searches for teams by the number of their members
void searchTeamByNumberOfMembers(STUDENT* students, TEAM* teams, int& t_index);

//Searches for teams which haven't been assigned a teacher yet
void searchTeamsWithoutATeacher(STUDENT* students, TEAM* teams, int& t_index);

//Outputs a single teacher from the teachers array
void showTeacher(TEAM* teams, TEACHER* teachers, int& tch_index);

//Outputs a list of all of the teachers in the teachers array
void showTeachers(TEAM* teams, TEACHER* teachers, int& tch_index);

//Inputs data for a new teacher in the teachers array
void enterTeacher(TEAM* teams, TEACHER* teachers, int& tch_index);

//Deletes a particular teacher from the teachers array
void deleteTeacher(TEACHER* teachers, int& tch_index);

//Edits the name of a teacher
void updateTeacherName(TEACHER* teachers);

//Edits the email of a teacher
void updateTeacherEmail(TEACHER* teachers);

//Assigns a new team to a particular teacher
void addTeamToTeacher(TEAM* teams, TEACHER* teachers);

//Removes a team from a particular teacher
void removeTeamFromTeacher(TEAM* teams, TEACHER* teachers);

//Searches for teachers by their first and last names
void searchTeacherByName(TEAM* teams, TEACHER* teachers, int& tch_index);

//Searches for teachers by their emails
void searchTeacherByEmail(TEAM* teams, TEACHER* teachers, int& tch_index);

//Outputs information about the school
void showSchoolAddress(STUDENT* students, int& st_index, TEAM* teams, int& t_index, TEACHER* teachers, int& tch_index, SCHOOL* school);

//print spaces
void spaces(int count);

//Displays a greeting for the user in the beginning when the program is started
void greetings();


//Asks the user if they want to stay in the same menu or to return one menu back 
bool returnBack();


//Shows options for searching for students by different criteria
void searchStudentMenu(STUDENT* students, int& st_index, TEAM* teams, int& t_index, TEACHER* teachers, int& tch_index, SCHOOL* school);

//Shows options for editing different information about a particular student
void  updateStudentInfoMenu(STUDENT* students, int& st_index, TEAM* teams, int& t_index, TEACHER* teachers, int& tch_index, SCHOOL* school);

//Shows options for searching for teams by different criteria
void searchTeamMenu(STUDENT* students, int& st_index, TEAM* teams, int& t_index, TEACHER* teachers, int& tch_index, SCHOOL* school);

//Shows options for editing different information about a particular team
void updateTeamInfoMenu(STUDENT* students, int& st_index, TEAM* teams, int& t_index, TEACHER* teachers, int& tch_index, SCHOOL* school);

//Shows options for searching for teachers by different criteria
void searchTeacherMenu(STUDENT* students, int& st_index, TEAM* teams, int& t_index, TEACHER* teachers, int& tch_index, SCHOOL* school);

//Shows options for editing different information about a particular teacher
void updateTeacherInfoMenu(STUDENT* students, int& st_index, TEAM* teams, int& t_index, TEACHER* teachers, int& tch_index, SCHOOL* school);



//Shows a sub menu with options connected with teachers 
void displayTeachersMenu(STUDENT* students, int& st_index, TEAM* teams, int& t_index, TEACHER* teachers, int& tch_index, SCHOOL* school);

//Shows a sub menu with options connected with teams
void displayTeamsMenu(STUDENT* students, int& st_index, TEAM* teams, int& t_index, TEACHER* teachers, int& tch_index, SCHOOL* school);

//Shows a sub menu with options connected with students
void displayStudentsMenu(STUDENT* students, int& st_index, TEAM* teams, int& t_index, TEACHER* teachers, int& tch_index, SCHOOL* school);

//Shows a sub menu with options connected with the school
void displaySchoolMenu(STUDENT* students, int& st_index, TEAM* teams, int& t_index, TEACHER* teachers, int& tch_index, SCHOOL* school);

//Shows the main menu of the program
void displayMainMenu(STUDENT* students, int& st_index, TEAM* teams, int& t_index, TEACHER* teachers, int& tch_index, SCHOOL* school);