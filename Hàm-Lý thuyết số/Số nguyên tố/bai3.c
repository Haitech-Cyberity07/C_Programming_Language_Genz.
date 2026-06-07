// Liệt kê các số có tổng chữ số là số nguyên tố trong đoạn [1, N]
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
int tong_nt(int n){
    int tong=0;
    while(n){
        tong+=n%10;
        n/=10;//sau khi lấy số dư của n cộng vào tổng thì phải chia 10 để lấy số bên trái cộng vào tiếp
    }
    return check_snt(tong);// trả về giá trị là tổng nhưng phải là số nguyên tố
}
int main(){
    int n=0;
    printf("Nhap so nguyen n: ");
    scanf("%d", &n);
    printf("Cac so trong khoang [1;%d] co tong la so nguyen to la: ", n);
    for(int i=1; i<=n; i++){
        if(tong_nt(i)){
            printf("%d ", i);
        }
    }

    return 0;
}