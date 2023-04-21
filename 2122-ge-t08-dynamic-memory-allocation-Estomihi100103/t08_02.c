
// 12S21004 - Estomihi Pangaribuan
// 12S21048 - Nessy Pentasonia Pangaribuan

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./libs/dorm.h"
#include "./libs/student.h"

void getString(char *str)
{
    int c = 0;
    str[0] = '\0';
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
        str[c] = x;
        str[++c] = '\0';
    } while (1);
}

int main(int _argc, char **_argv)
{
    struct student_t *mahasiswa = malloc(100 * sizeof(struct student_t));
    struct dorm_t *asrama = malloc(100 * sizeof(struct dorm_t));

    char nama[50];
    char id[15];
    char year[6];
    char *str = malloc(100 * sizeof(char));
    char *teks_sementara;
    int i = 0, idxDorm = 0;

    do
    {
        getString(str);

        if (strcmp(str, "---") == 0)
        {
            break;
        }

        teks_sementara = strtok(str, "#");

        if (strcmp(teks_sementara, "student-add") == 0)
        {
            teks_sementara = strtok(NULL, "#");
            strcpy(id, teks_sementara);

            teks_sementara = strtok(NULL, "#");
            strcpy(nama, teks_sementara);

            teks_sementara = strtok(NULL, "#");
            strcpy(year, teks_sementara);

            teks_sementara = strtok(NULL, "#");
            if (strcmp(teks_sementara, "male") == 0)
            {
                mahasiswa[i] = create_student(id, nama, year, GENDER_MALE);
            }
            else if (strcmp(teks_sementara, "female") == 0)
            {
                mahasiswa[i] = create_student(id, nama, year, GENDER_FEMALE);
            }
            i++;
        }
        else if (strcmp(teks_sementara, "student-print-all") == 0)
        {
            print_student(mahasiswa, i);
        }
        else if (strcmp(teks_sementara, "dorm-add") == 0)
        {
            char nama_asrama[20];
            int capacity;

            teks_sementara = strtok(NULL, "#");
            strcpy(nama_asrama, teks_sementara);
            teks_sementara = strtok(NULL, "#");
            capacity = atoi(teks_sementara);
            teks_sementara = strtok(NULL, "#");

            if (strcmp(teks_sementara, "male") == 0)
            {
                asrama[idxDorm] = create_dorm(nama_asrama, capacity, GENDER_MALE);
            }
            else if (strcmp(teks_sementara, "female") == 0)
            {
                asrama[idxDorm] = create_dorm(nama_asrama, capacity, GENDER_FEMALE);
            }
            idxDorm++;
        }
        else if (strcmp(teks_sementara, "dorm-print-all")==0)
        {
            print_dorm(asrama, idxDorm);
        }

    } while (1);

    return 0;
}
