// Tương tự như kiểm tra số Fibonacci bằng vòng lặp,
// bạn cũng có thể sử dụng mảng để lưu lại các số trong dãy Fibonacci.
// Mỗi lần kiểm tra số bạn chỉ cần duyệt các số Fibonacci mà bạn đã lưu trong mảng và so sánh.
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
    long long n=0;
    printf("Nhap vao so nguyen n: ");
    scanf("%lld", &n);
    if(fibonacci(n)){
        printf("YES!\n");
    }else{
        printf("NO!\n");
    }

    return 0;
}