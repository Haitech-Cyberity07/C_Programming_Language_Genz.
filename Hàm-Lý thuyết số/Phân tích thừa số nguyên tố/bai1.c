//Bài 1. Phân tích bằng cách thêm dấu x giữa các thừa số
#include <stdio.h>
#include <math.h>
void phanTich(int n){
    for(int i=2; i<=sqrt(n); i++){
        while(n%i==0){
            printf("%d ", i);
            n/=i;
            if(n>1){
                printf("x ");
            }
        }
    }
    if(n>1) printf("%d", n);
}
int main(){
    int n=0;
    printf("Nhap so nguyen n can phan tich: ");
    scanf("%d", &n);
    printf("%d = ", n);
    phanTich(n);
    return 0;
}