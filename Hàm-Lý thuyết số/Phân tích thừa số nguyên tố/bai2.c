//Phân tích TSNT kèm số mũ
#include <stdio.h>
#include <math.h>
void phanTich(int n){
    
    for(int i=2; i<=sqrt(n); i++){
        int mu=0;//khoi tao gia tri cua mu trong vong lap de khi nhay sang i khac thi mu cung khac
        while(n%i==0){
            n/=i;//giam n de tim thua so nguyen to tiep theo
            mu++;//so mu cua tung thua so nguyen so se duoc tang len 1 don vi neu thoa man dieu kien vong lap while

        }
        if(mu!=0){
            printf("%d^%d ", i, mu);
            if(n>1){
                printf("x ");
            }
        }
    }
    if(n>1){
        printf("%d^1", n);
    }
}
int main(){
    int n=0; 
    printf("Nhap so nguyen n can phan tich: ");
    scanf("%d", &n);
    printf("%d = ", n);
    phanTich(n);
    return 0;
}