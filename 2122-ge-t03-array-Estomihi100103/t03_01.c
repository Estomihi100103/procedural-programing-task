// 12S21004 - Estomihi Pangaribuan
// 12S21048 - Nessy Pentasonia Pangaribuan

#include <stdio.h>

int main(int _argc, char **_argv)
{
  

  int a, b;
  scanf("%d", &a);
  int data[a];
  int max, min;

  for (b = 0; b <= a - 1; b++)
  {
    scanf("%d", &data[b]);
  }
//find max and min

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

  printf("\n%d", min);
  printf("\n%d", max);

  return 0;
}
