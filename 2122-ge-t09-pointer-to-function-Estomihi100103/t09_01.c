// nim nama
// nim nama

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "libs/dorm.h"
#include "libs/student.h"

int main()
{
    struct student_t *students = malloc(150 * sizeof(struct student_t));
    char teks[100];
    char id[12];
    char name[40];
    char year[5];
    char *tekssementara;
    int i = 0;

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

        /*        }else if (strstr(tekssementara, "student-print-all") != NULL)
                {
                    print_student(students, j);
                }
                  else if (strstr(tekssementara, "student-print-all-detail") != NULL)
                {
                    pr
        */

        tekssementara = strtok(teks, "#");
        if (strcmp(tekssementara, "---") == 0)
        {
            return 0;
        }
        else if (strcmp(tekssementara, perintah1) == 0)
        {
            print_student(students, i);
        }
        else if (strcmp(tekssementara, perintah2) == 0)
        {
            print_student_detail(students, i);
        }
        else if (strcmp(tekssementara, perintah3) == 0)
        {

            tekssementara = strtok('\0', "#");
            strcpy(id, tekssementara);
            tekssementara = strtok('\0', "#");
            strcpy(name, tekssementara);
            tekssementara = strtok('\0', "#");
            strcpy(year, tekssementara);
            tekssementara = strtok('\0', "#");

            if (strcmp(tekssementara, tipe1) == 0)
            {
                students[i] = create_student(id, name, year, GENDER_MALE);
            }
            else if (strcmp(tekssementara, tipe2) == 0)
            {
                students[i] = create_student(id, name, year, GENDER_FEMALE);
            }
            i++;
        }
    }

    return 0;
}
