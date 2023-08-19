// nim nama
// nim nama

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "libs/dorm.h"
#include "libs/student.h"

int main()
{
    struct dorm_t *dorms = malloc(150 * sizeof(struct dorm_t));
    struct student_t *students = malloc(150 * sizeof(struct student_t));
    char teks[100];
    char id[12];
    char student_name[40];
    char year[5];
    char dorm_name[40];
    unsigned short capacity;
    char *tekssementara;
    int index_siswa, index_asrama;
    int siswa = 0, asrama = 0;

    char tipe1[10];
    strcpy(tipe1, "male");
    char tipe2[10];
    strcpy(tipe2, "female");

    char perintah1[25];
    strcpy(perintah1, "student-print-all");
    char perintah2[30];
    strcpy(perintah2, "student-print-all-detail");
    char perintah3[25];
    strcpy(perintah3, "student-add");

    char perintah4[25];
    strcpy(perintah4, "dorm-print-all-detail");

    char perintah5[25];
    strcpy(perintah5, "dorm-add");
    char perintah6[25];
    strcpy(perintah6, "assign-student");
    char perintah7[25];
    strcpy(perintah7, "move-student");



    while (1)
    {
        teks[0] = '\0';
        int c = 0;

do
{
   char x = getchar();
            if (x == '\r')
            {
                continue;
            }
            if (x == '\n')
            {
                break;
            }
            teks[c] = x;
            teks[++c] = '\0';
} while (1);




     
        tekssementara = strtok(teks, "#");
        if (strcmp(tekssementara, "---") == 0)
        {
            break;
        }
        else if (strcmp(tekssementara, perintah1) == 0)
        {
            print_student(students, siswa);
        }
        else if (strcmp(tekssementara, perintah2) == 0)
        {
            print_student_detail(students, siswa);
        }
        else if (strcmp(tekssementara, perintah3) == 0)
        {
            tekssementara = strtok('\0', "#");
            strcpy(id, tekssementara);
            tekssementara = strtok('\0', "#");
            strcpy(student_name, tekssementara);
            tekssementara = strtok('\0', "#");
            strcpy(year, tekssementara);
            tekssementara = strtok('\0', "#");
            if (strcmp(tekssementara, tipe1) == 0)
            {
                students[siswa] = create_student(id, student_name, year, GENDER_MALE);
            }
            else if (strcmp(tekssementara, tipe2) == 0)
            {
                students[siswa] = create_student(id, student_name, year, GENDER_FEMALE);
            }
            siswa++;
        }
        else if (strcmp(tekssementara, perintah4) == 0)
        {
            print_dorm(dorms, asrama);
        }
        else if (strcmp(teks, perintah5) == 0)
        {
            tekssementara = strtok('\0', "#");
            strcpy(dorm_name, tekssementara);
            tekssementara = strtok('\0', "#");
            capacity = atoi(tekssementara);
            tekssementara = strtok('\0', "#");
            if (strcmp(tekssementara, tipe1) == 0)
            {
                dorms[asrama] = create_dorm(dorm_name, capacity, GENDER_MALE);
            }
            else if (strcmp(tekssementara, tipe2) == 0)
            {
                dorms[asrama] = create_dorm(dorm_name, capacity, GENDER_FEMALE);
            }
            asrama++;
        }
        else if (strcmp(tekssementara, perintah6) == 0)
        {
            tekssementara = strtok('\0', "#");
            strcpy(id, tekssementara);
            tekssementara = strtok('\0', "#");
            strcpy(dorm_name, tekssementara);
            index_siswa = 0;
            index_asrama = 0;
            for (int i = 0; i < siswa; i++)
            {
                if (strcmp(students[i].id, id) == 0)
                {
                    index_siswa = i;
                    break;
                }
            }
            for (int i = 0; i < siswa; i++)
            {
                if (strcmp(dorms[i].name, dorm_name) == 0)
                {
                    index_asrama = i;
                    break;
                }
            }
            assign_student(&students[index_siswa], &dorms[index_asrama], id, dorm_name);
        }
        else if (strcmp(tekssementara, perintah7) == 0)
        {
            tekssementara = strtok('\0', "#");
            strcpy(id, tekssementara);
            tekssementara = strtok('\0', "#");
            strcpy(dorm_name, tekssementara);
            index_siswa = 0;
            index_asrama = 0;
            for (int i = 0; i < siswa; i++)
            {
                if (strcmp(students[i].id, id) == 0)
                {
                    index_siswa = i;
                    break;
                }
            }
            for (int i = 0; i < asrama; i++)
            {
                if (strcmp(dorms[i].name, dorm_name) == 0)
                {
                    index_asrama = i;
                    break;
                }
            }
            if (students[index_siswa].dorm == '\0')
            {
                assign_student(&students[index_siswa], &dorms[index_asrama], id, dorm_name);
            }
            else
            {
                for (int i = 0; i < asrama; i++)
                {
                    if (strcmp(students[index_siswa].dorm->name, dorms[i].name) == 0)
                    {
                        move_student(&students[index_siswa], &dorms[index_asrama], &dorms[i], id, dorm_name);
                        break;
                    }
                }
            }
        }
    }

    return 0;
}