#include <stdio.h>
#include <math.h>
int perfectNum(int n){
    int tong=1;//khai báo biến tổng bằng 1 để loại bỏ ước n của n
    //cho i chạy từ 2 để loại bỏ cặp ước cuối (1,n).
    for(int i=2; i<=sqrt(n); i++){
        if(n%i==0){
            tong+=i;
            if(i!=n/i){
                tong+=n/i;
            }
        }
    }
    if(tong==n && n!=1){
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