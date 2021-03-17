#include <iostream>
#include <string>
#include <stdlib.h>
#include "data.h"
#include "presentation.h"
using namespace std;


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
