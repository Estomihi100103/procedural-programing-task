#include "dorm.h"
#include <stdio.h>
#include <string.h>

struct dorm_t create_dorm(char *_name, unsigned short _capacity, enum gender_t _gender)
{
    struct dorm_t dorm;
    strcpy(dorm.name, _name);
    dorm.capacity = _capacity;
    dorm.gender = _gender;
    dorm.residents_num = 0;
    return dorm;
}


void print_dorm_detail(struct dorm_t *_dorm, int count)
{
    char type1[50];
    strcpy(type1, "male");
    char type2[50];
    strcpy(type2, "female");

    int i = 0;
    while (i < count)
    {
        if (_dorm[i].name[0] == NULL)
        {

        }
        else if (_dorm[i].gender == 0)
        {
            printf("%s|%d|%s|%d\n", _dorm[i].name, _dorm[i].capacity, type1, _dorm[i].residents_num);
        }
        else if (_dorm[i].gender == 1)
        {
            printf("%s|%d|%s|%d\n", _dorm[i].name, _dorm[i].capacity, type2, _dorm[i].residents_num);
        }

        i++;
    }
}