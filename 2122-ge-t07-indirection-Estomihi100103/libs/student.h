#ifndef STUDENT_H
#define STUDENT_H

#include "gender.h"
#include "dorm.h"

/**
 * @brief define your structure, enums, globally accessible variables, and function prototypes here.
 * The actual function implementation should be defined in the corresponding source file.
 *
 */

struct student_t
{
    char id[12];
    char name[40];
    char year[5];
    enum gender_t gender;
    struct dorm_t *dorm;
    char asrama_tujuan[15];
};

struct student_t create_student(char *_id, char *_name, char *_year,
                                enum gender_t _gender);
void print_student(struct student_t mahasiswa);
struct student_t assign_student(struct student_t students, struct dorm_t *dorms);

#endif
