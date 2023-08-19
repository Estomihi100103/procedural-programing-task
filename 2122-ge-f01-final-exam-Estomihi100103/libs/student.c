#include "student.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct student_t create_student(char *_id, char *_name, char *_year, enum gender_t _gender)
{
    struct student_t student;
    strcpy(student.id, _id);
    strcpy(student.name, _name);
    strcpy(student.year, _year);
    student.gender = _gender;
    student.dorm = NULL;

    return student;
}

void print_student_detail(struct student_t *_student, int count)
{

    char type1[50];
    strcpy(type1, "male");
     char cond[10];
    strcpy(cond, "left");
    char type2[50];
    strcpy(type2, "female");
   

    int i = 0;

    while (i < count)
    {
        if (_student[i].id[0] == NULL && _student[i].id[1] == NULL && _student[i].id[2] == NULL)
        {


        }


        else if (_student[i].dorm == '\0')
        {
            if (_student[i].gender == GENDER_MALE)
            {
                printf("%s|%s|%s|%s|%s\n", _student[i].id, _student[i].name, _student[i].year, type1, cond);
            }
            else if (_student[i].gender == GENDER_FEMALE)
            {
                printf("%s|%s|%s|%s|%s\n", _student[i].id, _student[i].name, _student[i].year, type2, cond);
            }
        }
        else
        {
            if (_student[i].gender == GENDER_MALE)
            {
                printf("%s|%s|%s|male|%s\n", _student[i].id, _student[i].name, _student[i].year, _student[i].dorm->name);
            }
            else if (_student[i].gender == GENDER_FEMALE)
            {
                printf("%s|%s|%s|female|%s\n", _student[i].id, _student[i].name, _student[i].year, _student[i].dorm->name);
            }
        }
        i++;
    }
}

//


void assign_student(struct student_t *_student, struct dorm_t *_dorm, char *id, char *dorm_name)
{
    if (_dorm->residents_num < _dorm->capacity && _student->gender == _dorm->gender)
    {
        _student->dorm = _dorm;
        _dorm->residents_num = _dorm->residents_num + 1;
    }
}

void student_leave(struct student_t *_siswa, struct dorm_t *_asrama_siswa)
{
    if (_siswa->dorm != NULL)
    {
        _siswa->dorm =NULL;
    }
}
