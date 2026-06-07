//Kiểm tra số nguyên tố bằng cách đếm ước
#include <stdio.h>
#include <math.h>
int check_snt(int n){
    int dem=0;
    for(int i=1; i<=sqrt(n); i++){
        if(n%i==0){
            ++dem;
                if(i!=n/i){
                    ++dem;
                }
        }
        
    }
    if(dem==2){
        return 1;//true
    }else{
        return 0;//false
    }
}
int main(){
    int n=0;
    printf("Nhap so nguyen n: ");
    scanf("%d", &n);
    printf("Cac so nguyen to trong khoang [1;%d] la: ", n);
    for(int i=1; i<=n; i++){
        if(check_snt(i)){
            printf("%d ", i);
        }
    }

    return 0;
}