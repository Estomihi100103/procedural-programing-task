// 12S21004 - Estomihi Pangaribuan
// 12S21048 - Nessy Pentasonia Pangaribuan

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum nama_presiden{
soekarno,
soeharto,
habibie,
megawati,
sby,
jokowi
};

int main(int _argv, char **_argc)
{
  
   enum nama_presiden presiden;
  presiden=habibie;
  printf(" presiden habibie adalah presiden ke :%d",  presiden+1);
    return 0;
}
