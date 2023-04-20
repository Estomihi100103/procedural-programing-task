// 12S20026- Mastuari Rumapea
// 12S20050- Putri Manurung

#include<stdio.h>

int main(int _argv, char **_argc) {
  
    char str[256];
    int i=0;

    scanf("%[^\n]s",str);

    while(str[i])
    if (str[i]<100)
    {
        printf("0%d",str[i++]);
    }else{
        printf("%d",str[i++]);
    }

    return 0;
}
