//Bài 2. In ra N số Fibonacci đầu tiên (N≥1)
#include <stdio.h>
#include <math.h>
void fibonacci(int n){
    if(n==1){
        printf("0\n");
    }else{
        printf("0 1 ");
        long long fn1=0, fn2=1, fn;
        for(int i=2; i<n; i++){
            fn= fn1+fn2;
            printf("%lld ", fn);
            fn1=fn2;
            fn2=fn;
        }
    }
    //ham void khong co return gia tri
}
int main(){
    int n=0;
    printf("Nhap so nguyen n: ");
    scanf("%d", &n);
    printf("%d so fibonacci dau tien la: ", n);
    fibonacci(n);
    return 0;
}