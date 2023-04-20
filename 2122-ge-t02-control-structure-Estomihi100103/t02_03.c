// 12S21004 - Estomihi Pangaribun


#include <stdio.h>

int main(int _argv, char **_argc)
{
  char operasi;
  int nilaipertama, hasilakhir, bilangan, i;

  scanf("%c", &operasi);
  if (operasi == '*')
  {
    nilaipertama = 1;
  }
  else if (operasi == '+')
  {
    nilaipertama = 0;
  }
  else if (operasi == '-')
  {
    nilaipertama = 0;
  }

  for (i = 1; i <= 4; i++)
  {
    scanf("%i", &bilangan);

    if (bilangan == -1)
    {
      printf("0");
      break;
    }

    if (operasi == '*')
    {
      hasilakhir = nilaipertama * bilangan;
      nilaipertama = hasilakhir;
    }
    else if (operasi == '+')
    {
      hasilakhir = nilaipertama + bilangan;
      nilaipertama = hasilakhir;
    }
    else if (operasi == '-')
    {
      hasilakhir = nilaipertama - bilangan;
      hasilakhir = -hasilakhir;
      nilaipertama = hasilakhir;
    }
    printf("%i\n", hasilakhir);
  }

  return 0;
}
