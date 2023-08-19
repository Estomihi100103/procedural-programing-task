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
    student.dorm = malloc(sizeof(struct dorm_t));
    student.dorm = NULL;
    return student;
}

void print_student(struct student_t *maha_siswa, int count)
{

    char jenis1[6];
    strcpy(jenis1, "male");
    char jenis2[8];
    strcpy(jenis2, "female");

    for (int i = 0; i < count; i++)
    {
        if (maha_siswa[i].id[0] == '\0' && maha_siswa[i].id[1] == '\0' && maha_siswa[i].id[2] == '\0')
        {
            
        }

        else if (maha_siswa[i].gender == GENDER_MALE)
        {
            printf("%s|%s|%s|%s\n", maha_siswa[i].id, maha_siswa[i].name, maha_siswa[i].year, jenis1);
        }
        else if (maha_siswa[i].gender == GENDER_FEMALE)
        {
            printf("%s|%s|%s|%s\n", maha_siswa[i].id, maha_siswa[i].name, maha_siswa[i].year, jenis2);
        }
    }
}



void print_student_detail(struct student_t *_student, int count)
{

char type1[50];
strcpy(type1,"male|unassigned" );
char type2[50];
strcpy(type2,"female|unassigned" );

    for (int i = 0; i < count; i++)
    {
        if (_student[i].dorm == NULL)
        {
            if (_student[i].gender == GENDER_MALE)
            {
                printf("%s|%s|%s|%s\n", _student[i].id, _student[i].name, _student[i].year,type1);
            }
            else if (_student[i].gender == GENDER_FEMALE)
            {
                printf("%s|%s|%s|%s\n", _student[i].id, _student[i].name, _student[i].year, type2);
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
    }
}





void assign_student(struct student_t *_student, struct dorm_t *_dorm, char *id, char *dorm_name)
{
    if (_dorm->residents_num < _dorm->capacity)
    {
        if (_student->gender == _dorm->gender)
        {
            _student->dorm = _dorm;
            _dorm->residents_num=_dorm->residents_num+1;
        }
    }
}

void move_student(struct student_t *_student, struct dorm_t *_dorm, struct dorm_t *old_dorm, char *id, char *dorm_name)
{
    if (_dorm->residents_num < _dorm->capacity)
    {
        if (_student->gender == _dorm->gender)
        {
            _student->dorm = _dorm;
            _dorm->residents_num++;
            old_dorm->residents_num=old_dorm->residents_num-1;
        }
    }
}


void dorm_empty(struct student_t *students, struct dorm_t *dorms, int std){

    for (int i = 0; i < std; i++){
        if (students[i].dorm==NULL){
            continue;
        } else if(strcmp(students[i].dorm->name, dorms->name)==0){
            students[i].dorm = NULL;
        }
    }
    
    dorms->residents_num = 0;
}