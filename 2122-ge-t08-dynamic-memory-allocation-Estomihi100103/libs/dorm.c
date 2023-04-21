#include "dorm.h"
#include "student.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

struct dorm_t create_dorm(char *_name, unsigned short _capacity, enum gender_t _gender)
{
    struct dorm_t asrama;
    strcpy(asrama.name, _name);
    asrama.capacity = _capacity;
    asrama.gender = _gender;
    return asrama;
}

void print_dorm(struct dorm_t *_dorm, int count)
{
    for (int i = 0; i < count; i++)
    {
         printf("%s|%d|%s\n", _dorm[i].name, _dorm[i].capacity, gender_to_text(_dorm[i].gender));
    }
}
