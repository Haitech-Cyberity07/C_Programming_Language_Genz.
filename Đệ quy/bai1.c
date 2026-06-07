// Số Fibonacci : Tim so fibonacci thu n
// Số Fibonacci có thể tính bằng hàm đệ quy dựa trên bài toán cơ sở và công thức truy hồi : 
// Bài toán cơ sở : F0 = 0, F1 = 1
// Công thức truy hồi : Fn = Fn-1 + Fn-2, n > 1
#include <stdio.h>
int fibo(int n){
    if(n==0||n==1){
        return n;
    }else{
        return fibo(n-1)+fibo(n-2);
    }
}
int main(){
    int n=0;
    printf("Nhap vao so nguyen n: ");
    scanf("%d", &n);
    printf("So fibonacci thu %d la: %d",n, fibo(n));
    return 0;
}