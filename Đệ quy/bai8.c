// Tìm chữ số lớn nhất (nhỏ nhất) của N
// Bài toán cơ sở : F(N) = N nếu N < 10
// Công thức truy hồi : F(N) = max(N % 10, F(N / 10)) với N ≥ 10
#include <stdio.h>
int timMax(long long n){
    if(n<10){
        return n;
    }else{
        long long temp = timMax(n/10);
        //dịch lần lượt sang trái 1 số
        return n%10 > temp ? n%10 : temp;
        //so sánh n%10 nếu lớn hơn giá trị temp thì lấy n%10 còn không thì láy temp
    }
        
}
int main(){
    long long n=0;
    printf("Nhap so nguyen n: ");
    scanf("%lld", &n);
    printf("So lon nhat trong cac chu so cua %lld la : %d", n, timMax(n));
    return 0;
}