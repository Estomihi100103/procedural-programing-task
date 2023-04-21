#include "student.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**
 * @brief Define the complete function definition here. Be sure to enlist the prototype of each function
 * defined here in the corresponding header file.
 *
 */

struct student_t create_student(char *_id, char *_name, char *_year,
                                enum gender_t _gender)
{

    struct student_t mahasiswa;
    strcpy(mahasiswa.id, _id);
    strcpy(mahasiswa.name, _name);
    strcpy(mahasiswa.year, _year);
    mahasiswa.gender = _gender;
    mahasiswa.dorm = malloc(sizeof(struct dorm_t));
    mahasiswa.dorm = NULL;
    return mahasiswa;
}

void print_student(struct student_t mahasiswa)
{

    if (mahasiswa.dorm == NULL)
    {
        printf("%s|", mahasiswa.id);
        printf("%s|", mahasiswa.name);
        printf("%s|", mahasiswa.year);

        if (mahasiswa.gender == GENDER_MALE)
        {
            printf("male|");
        }
        else if (mahasiswa.gender == GENDER_FEMALE)
        {
            printf("female|");
        }
        printf("unassigned\n");
    }
    else
    {
        printf("%s|", mahasiswa.id);
        printf("%s|", mahasiswa.name);
        printf("%s|", mahasiswa.year);

        if (mahasiswa.gender == GENDER_MALE)
        {
            printf("male|");
        }
        else if (mahasiswa.gender == GENDER_FEMALE)
        {
            printf("female|");
        }
        printf("%s\n", mahasiswa.dorm->name);
    }
}

struct student_t assign_student(struct student_t mahasiswa,struct dorm_t *asrama )
{
    for (int i = 0; i <2; i++)
    {
           if (mahasiswa.gender==asrama[i].gender && asrama[i].residents_num < asrama[i].capacity)
    {
        asrama[i].residents_num++;
        mahasiswa.dorm=&asrama[i];
    }
    }
    
    return mahasiswa;
}








/*struct student_t assign_student(struct student_t mahasiswa, struct dorm_t *asrama)
{
    for (int j = 0; j < 2; j++)
    {
        if (asrama[j].residents_num < asrama[j].capacity && mahasiswa.gender == asrama[j].gender)

        {
           mahasiswa.dorm = &asrama[j];
            asrama[j].residents_num++;
        }
    }
    return mahasiswa;
}*/
