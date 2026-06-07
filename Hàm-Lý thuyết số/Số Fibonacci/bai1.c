//Bài 1. In ra các số Fibonacci từ 1 đến N
#include <stdio.h>
#include <math.h>

long long fibonacci(long long n){
   //F[i] : So fibonacci thu i
   long long F[100];
   F[0] = 0; F[1] = 1;
   for(int i = 2; i <= 92; i++){
      F[i] = F[i - 1] + F[i - 2];
   }
   //Kiem tra
   for(int i = 0; i <= 92; i++){
      if(n == F[i]){
         return 1;
      }
   }
   return 0;
}
int main(){
    int n=0;
    printf("Nhap so nguyen n: ");
    scanf("%d", &n);
    printf("Cac so fibonacci trong doan [0;%d] la: ", n);
    for(int i=0; i<=n; i++){
        if(fibonacci(i)){
            printf("%d ", i);
        }
    }
    return 0;
}