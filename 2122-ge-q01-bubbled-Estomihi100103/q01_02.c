// 12S21004 - Estomihi Pangaribuan

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int _argv, char **_argc)
{
    int panjang, d, n, b, count = 1, panjangkata;
    b = 0;
    char kata[200];
    scanf("%s", kata);
    panjang = strlen(kata);
    panjangkata = panjang;
    int hasil[panjang];

    char katabaru[panjangkata - count];
    for (n = 0; n < panjangkata; n++)
    {
        if (kata[n] == ',')
        {
            count++;
        }
        else
        {
            if (kata[n] != ',')
            {
                katabaru[b] = kata[n];
                b++;
            }
        }
    }

    for (n = 0; n < count; n++)
    {
        hasil[n] = (int)katabaru[n];
    }

    for (n = 0; n < count; n++)
    {
        for (b = n + 1; b < count; b++)
        {
            if (hasil[n] < hasil[b])
            {
                d = hasil[n];
                hasil[n] = hasil[b];
                hasil[b] = d;
            }
        }
    }
    for (n = 0; n <= count - 1; n++)
    {
        if (n == count - 1)
        {
            printf("%c", hasil[n]);
        }
        else
        {
            printf("%c,", hasil[n]);
        }
    }

    return 0;
}