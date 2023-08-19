// 12S21004 Estomihi Pangaribuan
// 12S210048 Nessy Pangaribuan

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "libs/dorm.h"
#include "libs/student.h"

int main(int _argc, char **_argv)
{
    struct dorm_t *dorms = malloc(50 * sizeof(struct dorm_t));
    struct student_t *students = malloc(50 * sizeof(struct student_t));
    char string[100];
    char nim[12];

    char nama_siswa[50];
    char tahun[6];
    char nama_asrama[50];
    unsigned short capacity;
    char *teks_sementara;
    int index_siswa, index_asrama;
    int sisw_a = 0, asram_a = 0;

    char order1[50];
    strcpy(order1, "student-print-all-detail");
    char order2[20];
    strcpy(order2, "student-add");
    char order3[50];
    strcpy(order3, "dorm-print-all-detail");
    char order4[20];
    strcpy(order4, "dorm-add");
    char order5[50];
    strcpy(order5, "assign-student");
    char order7[50];
    strcpy(order7, "dorm-empty");
    char order8[50];
    strcpy(order8, "student-leave");

    while (1)
    {

        fgets(string, 100, stdin);
        string[strlen(string) - 1] = '\0';

       /* if (strcmp(string, "---") != 0)
        {
            string[strlen(string) - 1] = '\0';
        }*/

        teks_sementara = strtok(string, "#");

        if (strcmp(teks_sementara, "---") == 0)
        {
            break;
        }

        else if (strcmp(teks_sementara, order1) == 0) // student-print-all-detail
        {
            print_student_detail(students, sisw_a);
        }

        else if (strcmp(teks_sementara, order2) == 0) // student-add
        {

            teks_sementara = strtok('\0', "#");
            strcpy(nim, teks_sementara);
            teks_sementara = strtok('\0', "#");
            strcpy(nama_siswa, teks_sementara);
            teks_sementara = strtok('\0', "#");
            strcpy(tahun, teks_sementara);
            teks_sementara = strtok('\0', "#");

            if (strcmp(teks_sementara, "male") == 0)
            {
                students[sisw_a] = create_student(nim, nama_siswa, tahun, GENDER_MALE);
            }
            else
            {
                if (strcmp(teks_sementara, "female") == 0)
                {
                    students[sisw_a] = create_student(nim, nama_siswa, tahun, GENDER_FEMALE);
                }
            }
            sisw_a = sisw_a + 1;
        }

        else if (strcmp(teks_sementara, order3) == 0) // dorm-print-all-detail
        {
            print_dorm_detail(dorms, asram_a);
        }

        else if (strcmp(string, order4) == 0) // dorm-add
        {
            teks_sementara = strtok('\0', "#");
            strcpy(nama_asrama, teks_sementara);
            teks_sementara = strtok('\0', "#");
            capacity = atoi(teks_sementara);
            teks_sementara = strtok('\0', "#");
            if (strcmp(teks_sementara, "male") == 0)
            {
                dorms[asram_a] = create_dorm(nama_asrama, capacity, GENDER_MALE);
            }
            else if (strcmp(teks_sementara, "female") == 0)
            {
                dorms[asram_a] = create_dorm(nama_asrama, capacity, GENDER_FEMALE);
            }
            asram_a++;
        }

        else if (strcmp(teks_sementara, order5) == 0) // assign-student
        {
            teks_sementara = strtok('\0', "#");
            strcpy(nim, teks_sementara);
            teks_sementara = strtok('\0', "#");
            strcpy(nama_asrama, teks_sementara);

            index_siswa = -99;
            index_asrama = -99;
            int i = 0;

            while (i < sisw_a)
            {
                if (strcmp(students[i].id, nim) == 0)
                {
                    index_siswa = i;
                    break;
                }
                i++;
            }

            for (i = 0; i < sisw_a; i++)
            {
                if (strcmp(dorms[i].name, nama_asrama) == 0)
                {
                    index_asrama = i;
                    break;
                }
            }

            if (index_siswa != -99 && index_asrama != -99)
            {
                assign_student(&students[index_siswa], &dorms[index_asrama], nim, nama_asrama);
            }
        }

        else if (strcmp(teks_sementara, order7) == 0) // dorm-empty
        {
            teks_sementara = strtok('\0', "#");
            strcpy(nama_asrama, teks_sementara);

            for (int i = 0; i < asram_a; i++)
            {
                if (strcmp(dorms[i].name, nama_asrama) == 0)
                {
                    index_asrama = i;
                    break;
                }
            }

            for (int i = 0; i < sisw_a; i++)
            {
                if (strcmp(students[i].dorm->name, nama_asrama) == 0)
                {
                    strcpy(students[index_asrama].dorm->name, "unassigned");

                    dorms[index_asrama].residents_num = dorms[index_asrama].residents_num - 1;

                    break;
                }
            }
        }

        else if (strcmp(teks_sementara, order8) == 0) // student-leave
        {
            teks_sementara = strtok('\0', "#");
            index_siswa = 0;
            index_asrama = 0;
            int i = 0;

            while (i < sisw_a)
            {
                if (strcmp(students[i].id, teks_sementara) == 0)
                {
                    index_siswa = i;
                    break;
                }
                i++;
            }

            for (int i = 0; i < asram_a; i++)
            {
                if (strcmp(students[index_siswa].dorm->name, dorms[i].name) == 0)
                {
                    index_asrama = i;
                    break;
                }
            }
            student_leave(&students[index_siswa], &dorms[index_asrama]);
        }
    }
    return 0;
}
