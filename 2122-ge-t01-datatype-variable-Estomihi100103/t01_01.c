// 12S21004 - Estomihi Pangaribuan
// 12S21048 - Nessy Pentasonia Pangaribuan

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int _argv, char **_argc)
{
 int numerik;
char  kata [4];
int bolean;
float fraction;

printf("masukkan numerik:");
  scanf("%d", &numerik);
printf ("masukkan kata:");
 scanf(" %[^\n]s", kata);
printf("masukkan bolean:");
 scanf("%d", &bolean);
 printf("masukkan fraction:");
 scanf("%f", &fraction);


printf("%d\n", numerik);
printf("%s\n", kata);
printf("%d\n", bolean);
printf("%.3f",fraction );

  return 0;
}