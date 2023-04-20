// 12S21004 - Estomihi Pangaribuan
// 12S21048 - Nessy Pentasonia Pangaribuan

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void getString(char str[])
{
  str[0] = '\0';
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
    str[c] = x;
    str[++c] = '\0';
  } while (1);
}

enum gender
{
  MALE,
  FEMALE
};

struct Mahasiswa
{
  char nama[20];
  char nim[10];
  char tahun[5];
  enum gender jenis_kelamin;
};

int main(int _argv, char **_argc)
{
  struct Mahasiswa *students = malloc(sizeof(struct Mahasiswa) * 10);

  char *str = malloc(sizeof(char) * 20);
  getString(str);

  char *token;
  int sumBoys = 0, sumGirls = 0;

  if (strcmp(str, "register") == 0)
  {
    while (1)
    {
      getString(str);
      if (strcmp(str, "---") == 0)
      {
        break;
      }
      else
      {
        token = strtok(str, "|");
        token = strtok(NULL, "|");
        token = strtok(NULL, "|");
        token = strtok(NULL, "|");
        if (strcmp(token, "MALE") == 0)
        {
          sumBoys++;
        }
        else if (strcmp(token, "FEMALE") == 0)
        {
          sumGirls++;
        }
      }
    }
  }
  else if (strcmp(str, "---") == 0)
  {
   return 0;
  }

  printf("%d|%d", sumBoys, sumGirls);

  return 0;
}