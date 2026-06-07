//Số chính phương
#include <stdio.h>
#include <math.h>
int ps (int n){
    int squareRoot = sqrt(n);
    if(squareRoot*squareRoot == n){
        return 1;
    }else{
        return 0;
    }
}
int main(){
    int n;
    printf("Nhap so nguyen n: ");
    scanf("%d", &n);
    if(ps(n)==1){
        printf("%d la so chinh phuong!\n", n);
    }else{
        printf("%d khong phai so chinh phuong!\n", n);
    }

    return 0;
}