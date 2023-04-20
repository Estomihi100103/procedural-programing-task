// 12S21004 - Estomihi Pangaribun


#include <stdio.h>

int main(int _argv, char **_argc)
{
   int x;
   scanf("%d", &x);
   switch (x)
   {
   case 1:
      printf("\nstaple food");
      printf("\nyou need side dishes");
      break;
   case 2:
      printf("\nside dishes");
      printf("\nstaple food");
      printf("\nyou need vegetables");
      break;
   case 3:
      printf("\nvegetables");
      printf("\nside dishes");
      printf("\nstaple food");
      printf("\ngood");
      break;
   case 4:
      printf("\nfruits");
      printf("\nvegetables");
      printf("\nside dishes");
      printf("\nstaple food");
      printf("\nvery good");
      break;
   case 5:
      printf("\nmilk");
      printf("\nfruits");
      printf("\nvegetables");
      printf("\nside dishes");
      printf("\nstaple food");
      printf("\nperfect");
   }

   return 0;
}
