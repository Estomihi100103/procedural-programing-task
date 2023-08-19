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
    char *data;
    int INDEX_SISWA, index_asrama;
    int std = 0, dorm = 0;

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
        while (1)
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
        }
        data = strtok(teks, "#");
        if (strcmp(data, "---") == 0)
        {
            return 0;
        }
        else if (strcmp(data, perintah1) == 0)
        {
            print_student(students, std);
        }
        else if (strcmp(data, perintah2) == 0)
        {
            print_student_detail(students, std);
        }
        else if (strcmp(data, perintah3) == 0)
        {

            data = strtok('\0', "#");
            strcpy(id, data);
            data = strtok('\0', "#");
            strcpy(student_name, data);
            data = strtok('\0', "#");
            strcpy(year, data);
            data = strtok('\0', "#");
            if (strcmp(data, tipe1) == 0)
            {
                students[std] = create_student(id, student_name, year, GENDER_MALE);
            }
            else if (strcmp(data, tipe2) == 0)
            {
                students[std] = create_student(id, student_name, year, GENDER_FEMALE);
            }
            std++;
        }
        else if (strcmp(data, perintah4) == 0)
        {
            print_dorm(dorms, dorm);
        }
        else if (strcmp(teks, perintah5) == 0)
        {
            data = strtok('\0', "#");
            strcpy(dorm_name, data);
            data = strtok('\0', "#");
            capacity = atoi(data);
            data = strtok('\0', "#");
            if (strcmp(data, tipe1) == 0)
            {
                dorms[dorm] = create_dorm(dorm_name, capacity, GENDER_MALE);
            }
            else if (strcmp(data, tipe2) == 0)
            {
                dorms[dorm] = create_dorm(dorm_name, capacity, GENDER_FEMALE);
            }
            dorm++;
        }
        else if (strcmp(data, perintah6) == 0)
        {
            data = strtok('\0', "#");
            strcpy(id, data);
            data = strtok('\0', "#");
            strcpy(dorm_name, data);
            INDEX_SISWA = 0;
            index_asrama = 0;
            for (int i = 0; i < std; i++)
            {
                if (strcmp(students[i].id, id) == 0)
                {
                    INDEX_SISWA = i;
                    break;
                }
            }
            for (int i = 0; i < std; i++)
            {
                if (strcmp(dorms[i].name, dorm_name) == 0)
                {
                    index_asrama = i;
                    break;
                }
            }
            assign_student(&students[INDEX_SISWA], &dorms[index_asrama], id, dorm_name);
        }
        else if (strcmp(data, perintah7) == 0)
        {
            data = strtok('\0', "#");
            strcpy(id, data);
            data = strtok('\0', "#");
            strcpy(dorm_name, data);
            INDEX_SISWA = 0;
            index_asrama = 0;
            for (int i = 0; i < std; i++)
            {
                if (strcmp(students[i].id, id) == 0)
                {
                    INDEX_SISWA = i;
                    break;
                }
            }
            for (int i = 0; i < std; i++)
            {
                if (strcmp(dorms[i].name, dorm_name) == 0)
                {
                    index_asrama = i;
                    break;
                }
            }
            assign_student(&students[INDEX_SISWA], &dorms[index_asrama], id, dorm_name);
        }
    }

    return 0;
}