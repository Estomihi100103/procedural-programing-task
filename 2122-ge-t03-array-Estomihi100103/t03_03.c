// 12S21004 - Estomihi Pangaribuan
// 12S21048 - Nessy Pentasonia Pangaribuan

#include <stdio.h>

int main(int _argc, char **_argv)
{
  float ratarata;
  int a, b, jaraknilaiterjauh;
  scanf("%d", &a);
  int data[a];
  int jaraknilai[a];
  int max, min;
  ratarata = 0;

  for (b = 0; b <= a - 1; b++)
  {
    scanf("%d", &data[b]);
    ratarata = ratarata + data[b];
  }
  max = data[0];
  min = data[0];
  for (b = 0; b <= a - 1; b++)
  {
    if (data[b] >= max)
    {
      max = data[b];
    }
  }
  for (b = 0; b <= a - 1; b++)
  {
    if (data[b] <= min)
    {
      min = data[b];
    }
  }
  for (b = 0; b <= a - 2; b++)
  {
    jaraknilai[b] = data[b] - data[b + 1];
  }
  jaraknilai[b] = data[0];
  jaraknilaiterjauh = data[0];

  for (b = 2; b <= a - 2; b++)
  {
    if (jaraknilai[b] > jaraknilaiterjauh)
    {
      jaraknilaiterjauh = jaraknilai[b];
    }
  }

  ratarata = ratarata / a;
  printf("\n%d", min);
  printf("\n%d", max);
  printf("\n%.2f", ratarata);
  printf("\n%d", jaraknilaiterjauh);
  return 0;
}
