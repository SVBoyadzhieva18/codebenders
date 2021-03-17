#include <iostream>
#include <string>
#include <stdlib.h>
#include "data.h"
#include "presentation.h"
using namespace std;

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

//Statically fills up an array of teams
void initTeams(STUDENT* students, int& index, TEAM* teams, int& t_index)
{
    teams[0] = { "Vikings", "We are here to win!", {10,2,2021}, {students[2], students[4], students[10]}, status::notActive, 3, 1 };
    teams[1] = { "We Showed Up", "Hoping for the best with minimum effort!", {13,2,2021}, {students[7], students[9], students[11]}, status::inUse, 3, 1 };
    teams[2] = { "Cereal Killers", "Trying our best", {20, 2, 2021},  {students[0], students[1], students[5]}, status::notArchived, 3, 1 };

    t_index = 3;
}

//Statically fills up an array of teachers
void initTeachers(TEAM* teams, TEACHER* teachers, int& tch_index)
{
    teachers[0] = { "Ivelina", "Staykova", {teams[0], teams[1]}, "iStaikova@abv.bg", 2 };
    teachers[1] = { "Yordan", "Kamenov", {teams[2]}, "yordanKA@gmail.com", 1 };

    tch_index = 2;
}

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