
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
  float sebentar;
  float yangterbaik = 0.0;
  int y = 100;
  int n = 0;
  int i;
  int z;
  char penampung[100];

  do
  {

    fgets(teks, 102, stdin);
    teks[strlen(teks) - 1] = '\0';  // Mengapa kita membutuhkan \0 di akhir string di C?
                                    // itu digunakan untuk menunjukkan bahwa string selesai. itu menandai akhir dari string. itu terutama digunakan dalam tipe string. dengan string default berisi '\0\ karakter berarti menunjukkan akhir karakter dalam string. akhir array berisi ''\0' untuk menghentikan alokasi memori array untuk nama string
    tekssementara = strtok(teks, "#");
    if (teks[0] == '-' && teks[1] == '-' && teks[2] == '-')
    {
      return 0;
    }
    else if (strcmp(tekssementara, "student-add") == 0)
    {
      tekssementara = strtok(NULL, "#");
      strcpy(mahasiswa[n].nimsiswa, tekssementara);

      tekssementara = strtok(NULL, "#");
      strcpy(mahasiswa[n].namasiswa, tekssementara);

      tekssementara = strtok(NULL, "#");
      strcpy(mahasiswa[n].ip, tekssementara);
      sebentar = atof(mahasiswa[n].ip);

      n++;

      if (sebentar > yangterbaik)
      {
        yangterbaik = sebentar;
      }
    }
    else if (teks[12] == '-' && teks[13] == 'a' && teks[14] == 'l')
    {
      for (i = 0; i < n; i++)
      {
        printf("%s|%s|%s\n", mahasiswa[i].nimsiswa, mahasiswa[i].namasiswa, mahasiswa[i].ip);
      }
    }
    else if (teks[12] == '-' && teks[13] == 'b' && teks[14] == 'e' && teks[15] == 's')
    {
      gcvt(yangterbaik, 3, penampung); // Ini adalah fungsi perpustakaan yang didefinisikan di stdio. h file header. Fungsi ini digunakan untuk mengubah bilangan floating point menjadi string. Sintaks : gcvt (nilai float, int ndigit, char * buf); nilai float: Ini adalah nilai float atau double
      for (i = 0; i < n; i++)
      {
        if (strcmp(mahasiswa[i].ip, penampung) >= 0)
        {
          z = i;
        }
      }
      printf("%s|%s|%s\n", mahasiswa[z].nimsiswa, mahasiswa[z].namasiswa, mahasiswa[z].ip);
    }

  } while (y == 100);
}