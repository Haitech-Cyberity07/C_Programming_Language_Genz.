//Su dung mang in ra n so fibonacci dau tien
#include <stdio.h>
#include <math.h>
void fibonacci(int n){
    long long f[100];
    f[0]=0;
    f[1]=1;
    for(int i=2; i<n; i++){
        f[i]=f[i-1]+f[i-2];
    }
    for(int i=0; i<n; i++){
        printf("%lld ", f[i]);
    }
}
int main(){
    int n=0;
    printf("Nhap so nguyen n: ");
    scanf("%d", &n);
    printf("%d so fibonacci dau tien la: ", n);
    fibonacci(n);
    return 0;
}