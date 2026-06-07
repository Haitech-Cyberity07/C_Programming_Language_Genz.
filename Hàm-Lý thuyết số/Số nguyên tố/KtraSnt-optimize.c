//phương pháp tối ưu
//duyệt từ 2 đến căn n

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
    printf("Nhap vao so nguyen n: ");
    scanf("%d", &n);

    printf("Cac so nguyen to trong khoang [1;%d] la: ", n);
    for(int i=1; i<=n; i++){
        if(check_snt(i)){
            printf("%d ", i);
        }
    }
    return 0;
}