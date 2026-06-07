//Liệt kê các số hoàn hảo trong đoạn [1;N]
//Số hoàn hảo là số mà tổng các ước thực sự của nó (không tính chính nó) bằng chính nó. 
#include <stdio.h>
#include <math.h>
int perfectNum(int n){
    int tong=0;
    for(int i=1; i<=sqrt(n); i++){
        if(n%i==0){
            tong+=i;
            if(i!=n/i){
                tong+=n/i;
            }
        }
    }
    if(tong-n==n){
        return 1;
    }
    return 0;
}
int main(){
    int n=0;
    printf("Nhap so nguyen n: ");
    scanf("%d", &n);
    printf("Cac so hoan hao trong doan [1;%d]: ", n);
    for(int i=1; i<=n; i++){
        if(perfectNum(i)){
            printf("%d ", i);
        }
    }

    return 0;
}