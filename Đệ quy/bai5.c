// Bài 1. Đếm số chữ số của số N
// Bài toán cơ sở : D(N) = 1 nếu N < 10
// Công thức truy hồi : D(N) = 1 + D(N / 10) nếu N ≥ 10
#include <stdio.h>
int demChuSo(long long n){
    if(n<10){
        return 1;
    }else{
        return 1 + demChuSo(n/10);
    }
}
int main(){
    long long n=0;
    printf("Nhap vao so nguyen n: ");
    scanf("%lld", &n);
    printf("So chu so cua %lld la: %d", n, demChuSo(n));
    return 0;
}