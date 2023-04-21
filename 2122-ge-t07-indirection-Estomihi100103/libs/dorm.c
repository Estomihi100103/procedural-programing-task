#include "dorm.h"
#include <stdio.h>
#include <string.h>

/**
 * @brief Define the complete function definition here. Be sure to enlist the prototype of each function
 * defined here in the corresponding header file.
 *
 */

struct dorm_t create_dorm(char *_name, unsigned short _capacity, enum gender_t _gender)
{
    struct dorm_t asrama;
    strcpy(asrama.name, _name);
    asrama.capacity = _capacity;
    asrama.gender = _gender;
    asrama.residents_num = 0;

    return asrama;
}

void print_dorm(struct dorm_t asrama)
{

    printf("%s|", asrama.name);
    printf("%d|", asrama.capacity);

    if (asrama.gender == GENDER_MALE)
    {
        printf("male|");
    }
    else if (asrama.gender == GENDER_FEMALE)
    {
        printf("female|");
    }
    printf("%d\n", asrama.residents_num);
}
