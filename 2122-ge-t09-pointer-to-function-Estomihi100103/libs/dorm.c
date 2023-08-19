#include "dorm.h"
#include <stdio.h>
#include <string.h>

struct dorm_t create_dorm(char *_name, unsigned short _capacity, enum gender_t _gender){
    struct dorm_t asrama;
    strcpy(asrama.name, _name);
    asrama.capacity = _capacity;
    asrama.gender = _gender;
    asrama.residents_num = 0;
    return asrama;
}

void print_dorm(struct dorm_t *_dorm, int count){


     char tipe1[10];
    strcpy(tipe1, "male");
    char tipe2[10];
    strcpy(tipe2, "female");
    for (int i = 0; i < count; i++)
    {
        if (_dorm[i].gender==0){
            printf("%s|%d|%s|%d\n", _dorm[i].name, _dorm[i].capacity,tipe1, _dorm[i].residents_num);
        } else if(_dorm[i].gender==1){
            printf("%s|%d|%s|%d\n", _dorm[i].name, _dorm[i].capacity,tipe2, _dorm[i].residents_num);
        }
    }   
}
void print_dorm_detail(struct dorm_t *_dorm, int count){
     char tipe1[10];
    strcpy(tipe1, "male");
    char tipe2[10];
    strcpy(tipe2, "female");
    for (int i = 0; i < count; i++)
    {
        if (_dorm[i].gender==0){
            printf("%s|%d|%s|%d\n", _dorm[i].name, _dorm[i].capacity,tipe1, _dorm[i].residents_num);
        } else if(_dorm[i].gender==1){
            printf("%s|%d|%s|%d\n", _dorm[i].name, _dorm[i].capacity,tipe2, _dorm[i].residents_num);
        }
    }   
}