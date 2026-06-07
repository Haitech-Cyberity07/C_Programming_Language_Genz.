//Bài 1. In ra các số chính phương từ 1 tới N và đếm xem có bao nhiêu số chính phương
#include <stdio.h>
#include <math.h>
//Phương pháp tối ưu
int main(){
    int n=0;
    int dem=0;
    printf("Nhap vao so nguyen n:");
    scanf("%d", &n);
    printf("Cac so chinh phuong tu 1 toi %d la: ", n);
    for(int i=1; i<=sqrt(n); i++){
        printf("%d ", i*i);
        dem++;
    }
    printf("\nCo tat ca %d so chinh phuong!\n", dem);

    return 0;
}