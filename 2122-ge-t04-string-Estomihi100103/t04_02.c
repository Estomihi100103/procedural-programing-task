// 12S21004 - Estomihi Pangaribuan
// 12S21048 - Nessy Pentasonia Pangaribuan

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int _argv, char **_argc)
{

  char kata[100];
  int sifting, panjang, i;
  fgets(kata, sizeof kata, stdin);
  panjang = strlen(kata) - 1;

  scanf("%d", &sifting);
  if (sifting > 255)
  {
    sifting = sifting % 255;
  }
  else if (sifting <= -255)
  {
    sifting = sifting % -255;
  }
  else if (sifting <= 255)
  {
    sifting = sifting;
  }

  for (i = 0; i <= panjang - 1; i++)
  {
    if (kata[i] < 100)
    {
      kata[i] = kata[i] + sifting;
      printf("0%d", kata[i]);
    }
    else
    {
      kata[i] = kata[i] + sifting;
      printf("%d", kata[i]);
    }
  }

  printf("\n");

  for (i = 0; i <= panjang - 1; i++)
  {
    printf("%c", kata[i]);
  }

  return 0;
}
