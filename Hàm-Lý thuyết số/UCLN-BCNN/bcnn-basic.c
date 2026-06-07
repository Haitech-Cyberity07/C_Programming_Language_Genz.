// Bội Chung Nhỏ Nhất (BCNN) của 2 số a, b là số nhỏ nhất mà chia hết đồng thời cho cả a và b
// Thuật toán tự nhiên mà bạn dùng để tìm BCNN đó là duyệt từ số lớn hơn trong 2 số 
// và tăng dần cho tới khi gặp số đầu tiên chia hết cho cả a và b.
#include <stdio.h>
int bcnn(int a, int b){
    int max = a>b ? a:b;//cho sẵn a lớn hơn b, nếu đúng thì a = max, sai thì b=max;
    int ketQua=max;
    while(1){
        if(max%a==0 && max%b==0){
            ketQua=max;
            break;
        }
        ++max;
    }
    return ketQua;
}
int main(){
    int a=0, b=0;
    printf("Nhap 2 so nguyen duong a va b (a>0, b>0): ");
    scanf("%d %d", &a, &b);
    printf("Boi chung nho nhat cua hai so %d va %d la: %d\n", a, b, bcnn(a, b));
    return 0;
}