// Phương pháp tối ưu hơn để kiểm tra số hoàn hảo đó là sử dụng định lý Euclid - Euler. Định lý này phát biểu như sau
// Nếu p là số nguyên tố và 2p - 1 cũng là số nguyên tố thì : 2p-1 * (2p - 1) sẽ là một số hoàn hảo.
#include <stdio.h>
#include <math.h>
int check_snt(long long n){
    if(n<2) return 0;//loại số âm và 0, 1
    for(int i=2; i<=sqrt(n); i++){
        if(n%i==0) return 0;
    }
    return 1;
}
int perfectNum(long long n){
    for(int p=1; p<=33; p++){
        if(check_snt(p)){
            long long temp1=pow(2,p)-1;
            if(check_snt(temp1)){
                long long temp2=pow(2, p-1);
                if(temp1*temp2==n){
                    return 1;
                }
            }
        }
    }
    return 0;
}
int main(){
    int n=0;
    printf("Nhap so nguyen n: ");
    scanf("%d", &n);
    printf("So hoan hao trong doan [1;%d] la: ", n);
    for(long long i=1; i<=n; i++){
        if(perfectNum(i)){
            printf("%d ", i);
        }
    }
    return 0;
}