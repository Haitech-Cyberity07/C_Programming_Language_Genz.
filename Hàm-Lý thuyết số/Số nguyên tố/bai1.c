//Liệt kê và đếm các số nguyên tố từ 1 tới N
#include <stdio.h>
#include <math.h>

int snt(int n){
    if(n<2){
        return 0;
    }
    //cho vòng lặp chạy từ 2 đến căn n, nếu có phần tử nào chia hết cho 2 thì tức là có nhiều hơn 2 ước
    //do đó trả về return 0 tức là sai, kết thúc luôn vòng lặp
    //sở dĩ cho vòng lặp chỉ chạy đến căn n là do chạy đến căn n là đủ xét hết các ước đại diện cho cặp ước của n rồi
    for(int i=2; i<=sqrt(n); i++){
        if(n%i==0) return 0;
    }
    return 1;
}

int main(){
    int n=0, dem = 0;
    printf("Nhap so nguyen n: ");
    scanf("%d", &n);

    printf("Trong khoang [1;%d] co cac so nguyen to sau: ", n);
    for(int i=1; i<=n; i++){
        if(snt(i)){
            printf("%d ", i);
            dem++;
        }
    }
    printf("\nCo tat ca %d so nguyen to trong khoang [1;%d]!\n", dem, n);

    return 0;
}