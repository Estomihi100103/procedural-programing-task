// 12S21004 - Estomihi Pangaribuan
// 12S21048 - Nessy Pentasonia Pangaribuan

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int _argv, char **_argc)
{

  char kata[100];
  int panjang, i;
  int a;
  char urutan;
  // fgets(kata, sizeof kata, stdin);
  scanf(" %[^\n]", &kata);
  panjang = strlen(kata) - 2;
  scanf("%d", &a);

  for (i = 0; i <= panjang - 1; i++)
  {

    kata[i] = kata[i];
    // if (kata[i] < kata[i + 1])
    //{
    urutan = kata[i];

    printf("%03d", urutan + a);
  }
  //}

  return 0;
}
