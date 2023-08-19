// 12S21004 - Estomihi Pangaribuan
// 12S21048 - Nessy Pentasonia Pangaribuan

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./libs/dorm.h"
#include "./libs/student.h"
#include "./libs/gender.h"
#include "./libs/repository.h"


// void get_line(FILE *_stream, char *_buffer, unsigned int _size) {
// char ch = '\0';
// unsigned int i = 0;
// _buffer[i] = '\0';
// while (i < _size && (ch = fgetc(_stream)) != EOF) {                 (//nerima input dari buffer)
// if (ch == '\r') {
// continue;
// }
// if (ch == '\n') {
// break;
// }
// _buffer[i++] = ch;
// _buffer[i] = '\0';
// }
// }




int main(int _argc, char **_argv)
{
    struct dorm_t *dorms = malloc(100 * sizeof(struct dorm_t));
    struct student_t *students = malloc(100 * sizeof(struct student_t));
    char string[100];
    char nim[12];
    char nama_siswa[50];
    char tahun[6];
    char nama_asrama[50];
    unsigned short capacity;
    char *teks_sementara;
    int index_siswa, index_asrama;
    int sisw_a = 0, asram_a = 0;

    FILE *Mahasiswa=NULL;
    FILE *Asrama=NULL;
    FILE *output_file_mahasiswa = NULL;
    FILE *output_file_Asrama = NULL;

    Asrama = fopen("storage/dorm-repository.txt", "r");
    Mahasiswa = fopen("storage/student-repository.txt", "r");
    output_file_mahasiswa = fopen("./storage/student-repository.txt", "a");
    output_file_Asrama=fopen("storage/dorm-repository.txt", "a");

    char order1[30];
    strcpy(order1, "student-print-all-detail");
    char order2[14];
    strcpy(order2, "student-add");
    char order3[25];
    strcpy(order3, "dorm-print-all-detail");
    char order4[12];
    strcpy(order4, "dorm-add");
    char order5[18];
    strcpy(order5, "assign-student");
    char order6[15];
    strcpy(order6, "move-student");
    char order7[13];
    strcpy(order7, "dorm-empty");
    char order8[18];
    strcpy(order8, "dorm-print-all");

    while (1)
    {
        // asrama
        fscanf(Asrama, "%[^\n]\n", string);
        dorms[asram_a] = create_dorm_repository(string);
        asram_a++;
        if (feof(Asrama))
        {
            break;
        }
    }

    while (1)
    {
        // mahasiswa
        fscanf(Mahasiswa, "%[^\n]\n", string);
        teks_sementara = strtok(string, "|");
        strcpy(nim, teks_sementara);
        teks_sementara = strtok('\0', "|");
        strcpy(nama_siswa, teks_sementara);
        teks_sementara = strtok('\0', "|");
        strcpy(tahun, teks_sementara);
        teks_sementara = strtok('\0', "|");
        //printf("teks sementara adalah: %s\n", teks_sementara);
        if (strcmp(teks_sementara, "male") == 0)
        {
            students->gender == GENDER_MALE;
            students[sisw_a] = create_student_repository(nim, nama_siswa, tahun, GENDER_MALE);
        }
        else if (strcmp(teks_sementara, "female") == 0)
        {
            students->gender == GENDER_FEMALE;
            students[sisw_a] = create_student_repository(nim, nama_siswa, tahun, GENDER_FEMALE);
        }
        sisw_a++;
        if (feof(Mahasiswa))
        {
            break;
        }
    }

    while (1)
    {
        fflush(stdin);
        string[0] = '\0';
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
            string[c] = x;
            string[++c] = '\0';
        } while (1);

        teks_sementara = strtok(string, "#");
        if (strcmp(teks_sementara, "---") == 0)
        {
            break;
        }
        else if (strcmp(teks_sementara, order1) == 0) // student-print-all-detail
        {
            print_student_detail(students, sisw_a);
        }

        else if (strcmp(teks_sementara, "student-print-all") == 0)
        {
            print_student(students, sisw_a);
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
            {students->gender=GENDER_MALE;
                students[sisw_a] = create_student(nim, nama_siswa, tahun, GENDER_MALE);
                 fprintf(output_file_mahasiswa, "%s|%s|%s|male\n", nim, nama_siswa, tahun);

            }
            else
            {
                if (strcmp(teks_sementara, "female") == 0)
                {
                    students->gender=GENDER_FEMALE;
                    students[sisw_a] = create_student(nim, nama_siswa, tahun, GENDER_FEMALE);
                     fprintf(output_file_mahasiswa, "%s|%s|%s|female\n", nim, nama_siswa, tahun);
                }
            }
            sisw_a = sisw_a + 1;
        }
        else if (strcmp(teks_sementara, order8) == 0) // dorm-print-all
        {
            print_dorm(dorms, asram_a);
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
                fprintf(output_file_Asrama, "%s|%d|male\n", nama_asrama, capacity);
            }
            else if (strcmp(teks_sementara, "female") == 0)
            {
                dorms[asram_a] = create_dorm(nama_asrama, capacity, GENDER_FEMALE);
                 fprintf(output_file_Asrama, "%s|%d|female\n", nama_asrama, capacity);
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

        else if (strcmp(teks_sementara, order6) == 0) // move-student
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

            for (i = 0; i < asram_a; i++)
            {
                if (strcmp(dorms[i].name, nama_asrama) == 0)
                {
                    index_asrama = i;
                    break;
                }
            }

            if (index_siswa != -99 && index_asrama != -99)
            {
                if (students[index_siswa].dorm == '\0')
                {
                    assign_student(&students[index_siswa], &dorms[index_asrama], nim, nama_asrama);
                }
                else
                {
                    for (i = 0; i < asram_a; i++)
                    {
                        if (strcmp(students[index_siswa].dorm->name, dorms[i].name) == 0)
                        {
                            move_student(&students[index_siswa], &dorms[index_asrama], &dorms[i], nim, nama_asrama);
                            break;
                        }
                    }
                }
            }
        }

        else if (strcmp(teks_sementara, order7) == 0) // dorm-empty
        {
            teks_sementara = strtok('\0', "#");
            strcpy(nama_asrama, teks_sementara);
            index_siswa = -1;
            index_asrama = -1;
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

            for (int i = 0; i < asram_a; i++)
            {
                if (strcmp(dorms[i].name, nama_asrama) == 0)
                {
                    index_asrama = i;
                    break;
                }
            }
            for (int i = 0; i < asram_a; i++)
            {
                if (strcmp(dorms[i].name, nama_asrama) == 0)
                {
                    index_asrama = i;
                    break;
                }
            }
            if (index_asrama != -1)
            {
                dorm_empty(students, &dorms[index_asrama], sisw_a);
            }
        }

        else if (strcmp(teks_sementara, order7) == 0)
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

                    dorms[index_asrama].residents_num--;

                    break;
                }
            }
        }
    }
    fclose(Mahasiswa);
    fclose(Asrama);
    return 0;
}