//Chuyển đổi cơ số từ hệ thập phân sang hệ lục phân
#include <stdio.h>
void luc_Phan(long long n){
    if(n<16){
        if(n<10){
            printf("%d", n);
        }else{
            printf("%c", (n+55));
        }
    }else{
        luc_Phan(n/16);
        int soDu = n%16;
        if(soDu<10){
            printf("%d", soDu);
        }else{
            printf("%c", (55+soDu));
        }
    }
}
int main(){
    long long n=0;
    printf("Nhap vao so nguyen n: ");
    scanf("%lld", &n);
    printf("%lld chuyen doi co so sang he luc phan co dang: ", n);
    luc_Phan(n);
    return 0;
}
