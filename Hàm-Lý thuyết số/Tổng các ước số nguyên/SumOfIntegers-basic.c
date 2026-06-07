#include <stdio.h>
int sumIntegers (int n){
    int tong = 0;
    for(int i=1; i<=n; i++){
        if(n%i==0){
            tong += i;
        }
    }
    return tong;
}
int countIntegers(int n){
    int count=0;
    for(int i=1; i<=n; i++){
        if(n%i==0){
            count++;
        }
    }
    return count;
}
int main(){
    int N = 0;
    printf("Nhap so nguyen N: ");
    scanf("%d", &N);
    printf("Tong cac uoc cua N: %d\n", sumIntegers(N));
    printf("The number of the divisors of %d is: %d\n",N, countIntegers(N));
    return 0;
}