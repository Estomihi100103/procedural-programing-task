// 12S21004 - Estomihi Pangaribuan


#include <stdio.h>
#include <string.h>

int main(int _argv, char **_argc)
{
  int jumlahbuku;
  float hargabuku, hargaakhir, diskon, harga, a, b, c;
  char kosong[5];
  strcpy(kosong, "-");

  scanf("%d", &jumlahbuku);
  scanf("%f", &hargabuku);
  a = (double)15 / 100;
  b = (double)10 / 100;
  c = (double)5 / 100;

  harga = jumlahbuku * hargabuku;

  if (hargabuku >= 500000)
  {
    diskon = harga * a;
    hargaakhir = harga - diskon;
  }
  else if (harga > 100000)
  {
    diskon = harga * b;
    hargaakhir = harga - diskon;
  }
  else if (harga >= 50000)
  {
    diskon = harga * c;
    hargaakhir = harga - diskon;
  }
  else if (harga < 50000)
  {

    strcpy(kosong, "---");
  }

  if (strcmp(kosong, "---") == 0)
  {
    printf("\n%s", kosong);
    printf("\n%.2f", harga);
  }
  else
  {
    printf("\n%.2f", diskon);
    printf("\n%.2f", hargaakhir);
  }

  return 0;
}
