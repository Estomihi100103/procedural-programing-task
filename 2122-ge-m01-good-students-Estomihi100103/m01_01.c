// 12S21004 - Estomihi Pangaribuan

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct MAHASISWA_T
{
  char nimsiswa[102];
  char namasiswa[102];
  char ip[102];
};

int main(int _argc, char **_argv)
{

  struct MAHASISWA_T mahasiswa[102];
  char teks[102];
  char *tekssementara;
  int n = 0;
  int y = 100;
  do
  {
    fgets(teks, 102, stdin);
    tekssementara = strtok(teks, "#");
    // hasil nya adalah :student-add

    if (teks[0] == '-' && teks[1] == '-' && teks[2] == '-')
    {
      break;
    }
    else if (strcmp(tekssementara, "student-add") == 0)
    {

      tekssementara = strtok(NULL, "#");
      strcpy(mahasiswa[n].nimsiswa, tekssementara);

      tekssementara = strtok(NULL, "#");
      strcpy(mahasiswa[n].namasiswa, tekssementara);
      tekssementara = strtok(NULL, "#");
      strcpy(mahasiswa[n].ip, tekssementara);
      n++;
    }

    else if (teks[12] == '-' && teks[13] == 'a' && teks[14] == 'l')
    {
      for (int i = 0; i < n; i++)
      {
        printf("%s|%s|%s", mahasiswa[i].nimsiswa, mahasiswa[i].namasiswa, mahasiswa[i].ip);
      }
    }
  } while (y == 100);
}
