//Bài 3. Liệt kê ước nguyên tố của N
//cách 2: cách tối ưu
#include <stdio.h>
#include <math.h>
void snt_uc(int n){
    for(int i=2; i<=sqrt(n); i++){
        if(n%i==0){
            printf("%d ", i);
            while(n%i==0){
                n/=i;
            }
        }
    }
    if(n>1){
        printf("%d\n", n);
    }
}
int main(){
    int n=0;
    printf("Nhap so nguyen n: ");
    scanf("%d", &n);
    printf("Cac uoc nguyen to cua %d la: ", n);
    snt_uc(n);
    return 0;
}