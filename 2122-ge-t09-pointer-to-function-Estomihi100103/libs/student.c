#include "student.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct student_t create_student(char *_id, char *_name, char *_year,enum gender_t _gender){
    struct student_t mahasiswa;
    strcpy(mahasiswa.id, _id);
    strcpy(mahasiswa.name, _name);
    strcpy(mahasiswa.year, _year);
    mahasiswa.gender = _gender;
    mahasiswa.dorm = malloc (sizeof(struct dorm_t));
    mahasiswa.dorm = '\0';
    return mahasiswa;
}
void print_student(struct student_t *_student, int count){
     char tipe1[10];
    strcpy(tipe1, "male");
    char tipe2[10];
    strcpy(tipe2, "female");
    for (int i = 0; i < count; i++)
    {
        if (_student[i].gender==0){
            printf("%s|%s|%s|%s\n", _student[i].id, _student[i].name, _student[i].year, tipe1);
        } else if (_student[i].gender==GENDER_FEMALE){
            printf("%s|%s|%s|%s\n", _student[i].id, _student[i].name, _student[i].year, tipe2);
        }
    }
}
void print_student_detail(struct student_t *_student, int count){
     char tipe1[10];
    strcpy(tipe1, "male");
    char tipe2[10];
    strcpy(tipe2, "female");
char cond[20];
strcpy(cond, "unassigned");




    for (int i = 0; i < count; i++)
    {
        if (_student[i].dorm == '\0'){
            if (_student[i].gender==0){
                printf("%s|%s|%s|%s|%s\n", _student[i].id, _student[i].name, _student[i].year, tipe1, cond);
            } else if (_student[i].gender==1){
                printf("%s|%s|%s|%s|%s\n", _student[i].id, _student[i].name, _student[i].year, tipe2, cond);
            }
        } else {
            if (_student[i].gender==0){
                printf("%s|%s|%s|%s|%s\n", _student[i].id, _student[i].name, _student[i].year,tipe1, _student[i].dorm->name);
            } else if (_student[i].gender==1){
                printf("%s|%s|%s|%s|%s\n", _student[i].id, _student[i].name, _student[i].year,tipe2 ,_student[i].dorm->name);
            }
        }
    }
}
void assign_student(struct student_t *_student,struct dorm_t *_dorm, char *id, char *dorm_name){
    if (_dorm->residents_num < _dorm->capacity){
        if (_student->gender == _dorm->gender){
            _student->dorm = _dorm;
            _dorm->residents_num++;
        }
    }
}
void move_student(struct student_t *_student, struct dorm_t *_dorm, struct dorm_t *old_dorm, char *id, char *dorm_name){
    if (_dorm->residents_num < _dorm->capacity){
        if (_student->gender == _dorm->gender){
            _student->dorm = _dorm;
            _dorm->residents_num++;
            old_dorm->residents_num--;
        }
    }
}