#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "student.h"

struct student_t create_student(char *_id, char *_name, char *_year,
                                enum gender_t _gender)
{
    struct student_t siswa;
    strcpy(siswa.id, _id);
    strcpy(siswa.name, _name);
    strcpy(siswa.year, _year);
    siswa.gender = _gender;

    return siswa;
}

void print_student(struct student_t *maha_siswa, int count)
{
    for (int i = 0; i < count; i++)
    {
        printf("%s|%s|%s|%s\n", maha_siswa[i].id, maha_siswa[i].name, maha_siswa[i].year, gender_to_text(maha_siswa[i].gender));
    }
}
