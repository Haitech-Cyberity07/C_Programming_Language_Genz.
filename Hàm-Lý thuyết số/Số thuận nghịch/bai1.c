// Bai 1: kiem tra so nguyen n co phai so thuan nghich khong
#include <stdio.h>
int thuan_nghich(int n){
    int m=0, temp = n;
    while(n!=0){
        m=m*10 + n%10; // dao nguoc so nguyen n
        n/=10;
    }
    //so sanh voi m xem so ban dau co bang so dao nguoc khong
    if(temp == m){
        return 1;
    }else{
        return 0;
    }
}
int main(){
    int n=0;
    printf("Nhap so nguyen n: ");
    scanf("%d", &n);

    if(thuan_nghich(n)){
        printf("%d la so thuan nghich!\n", n);
    }else{
        printf("%d khong phai la so thuan nghich!\n", n);
    }

    return 0;
}