// 12S21004 - Estomihi Pangaribuan
// 12S21048 - Nessy Pentasonia Pangaribuan

#include<stdio.h>
#include<string.h>
  
struct data_tanggal
{
 int tahun;
 int bulan;
 int tanggal;
}; 

  
int main() 
{
 struct data_tanggal ultah;
    char indonesia[100];
  
   ultah.tanggal ; // akses elemen tanggal
   printf("masukkan tanggal: ");
   scanf("%d", &ultah.tanggal);
   printf("masukkan bulan: ");
   ultah.bulan;   // akses elemen bulan
   scanf("%d", &ultah.bulan);
   ultah.tahun; // akses elemen tahun
   printf("masukkan tahun: ");
   scanf("%d", &ultah.tahun);
   
   
   
   if( ultah.tanggal== 17  &&  ultah.bulan== 8 && ultah.tahun==1945){
       strcpy(indonesia , "merdeka");
   }else{
      strcpy(indonesia , " belum merdeka atau sudah merdeka ");
   }
   printf ("tanggal = %d, bulan = %d, tahun = %d"  ,ultah.tanggal, ultah.bulan, ultah.tahun); 
   printf("\nindonesia %s", indonesia);
   return 0; 
}