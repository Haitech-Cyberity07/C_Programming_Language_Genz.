// Bài 2 : Tính tổng chữ số của số N
// Bài toán cơ sở : S(N) = N nếu N < 10
// Công thức truy hồi : S(N) = N % 10 + S(N / 10) nếu N ≥ 10
#include <stdio.h>
int tongChuSo(long long n){
    if(n<10){
        return n;
    }else{
        return n%10 + tongChuSo(n/10);
    }
}
int main(){
    long long n=0;
    printf("Nhap so nguyen n: ");
    scanf("%lld", &n);
    printf("Tong cac chu so cua %lld la: %d", n, tongChuSo(n));
    return 0;
}