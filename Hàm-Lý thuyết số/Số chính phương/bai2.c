//Bài 2. Liệt kê (đếm) các số chính phương từ a tới b. 
#include <stdio.h>
#include <math.h>

int main(){
    int a=0, b=0;
    printf("Nhap 2 so nguyen a va b: ");
    scanf("%d %d", &a, &b);
    int dem = 0;
    printf("So chinh phuong trong khoang tu %d den %d la: ", a, b);
    for (int i = sqrt(a); i <= sqrt(b); i++)
    {
        printf("%d ", i*i);
        dem ++;
    }
    printf("\nCo tat ca %d so chinh phuong trong khoang tu %d den %d!\n", dem, a, b);
    return 0;
}