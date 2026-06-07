//Tìm số nguyên tố nhỏ nhất nhưng lớn hơn n
#include <stdio.h>
#include <math.h>
int check_snt(int n){
    if(n<2){
        return 0;
    }
    for(int i=2; i<=sqrt(n); i++){
        if(n%i==0){
            return 0;//không phải là số nguyên tố do đã chia hết cho 2
        }
    }
    return 1;//là số nguyên tố(true)
}
int main(){
    int n=0;
    printf("Nhap so nguyen n: ");
    scanf("%d", &n);

    printf("So nguyen to nho nhat nhung lon hon %d la: ", n);
    while(1){
        if(check_snt(n)){
            printf("%d", n);
            break;
        }
        ++n;
    }
    return 0;
}