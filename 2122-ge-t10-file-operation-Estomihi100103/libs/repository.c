#include "repository.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/**
 * @brief Define the complete function definition here. Be sure to enlist the prototype of each function
 * defined here in the corresponding header file.
 *
 */

struct dorm_t create_dorm_repository(char *input)
{
  struct dorm_t asrama;
  strcpy(asrama.name, strtok(input, "|"));
  asrama.capacity = atoi(strtok(NULL, "|"));
  char *yoru = strtok(NULL, "|");
  if (strcmp(yoru, "male") == 0)
  {
    asrama.gender = GENDER_MALE;
  }
  else if (strcmp(yoru, "female") == 0)
  {
    asrama.gender = GENDER_FEMALE;
  }
  asrama.residents_num = 0;
  return asrama;
}


struct student_t create_student_repository(char *_id, char *_name, char *_year, enum gender_t _gender)
{
  struct student_t mahasiswa;
  strcpy(mahasiswa.id, _id);
  strcpy(mahasiswa.name, _name);
  strcpy(mahasiswa.year, _year);
  mahasiswa.gender = _gender;
  mahasiswa.dorm = NULL;
  mahasiswa.dorm = malloc(1 * sizeof(struct dorm_t));
  strcpy(mahasiswa.dorm->name, "unassigned");

  return mahasiswa;
}