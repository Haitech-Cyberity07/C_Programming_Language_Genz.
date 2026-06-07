// Ước Chung Lớn Nhất (UCLN) của 2 số a, b là số lớn nhất mà 2 số a và b cùng chia hết
// Thuật toán tự nhiên mà bạn dùng để tìm UCLN đó là duyệt từ số nhỏ hơn trong 2 số về tới 1, số nào mà cả a và b chia hết đầu tiên sẽ là UCLN
// Chú ý rằng UCLN(a, 0) = a
#include <stdio.h>

int ucln(int a, int b){
    if(a==0 || b==0){
        return a+b;
    }
    int min = a < b ? a : b; // lấy luôn a nhỏ hơn b, nếu đúng thì a = min, sai thi b=min
    for(int i=min; i>=1; i--){
        if(a%i==0 && b%i==0){
            return i;
        }
    }
    return 1;
}

int main(){
    int a=0, b=0;
    printf("Nhap vao 2 so nguyen a, b: ");
    scanf("%d %d", &a, &b);
    printf("Uoc chung lon nhat cua 2 so %d va %d la: ", a, b);

    printf("%d\n", ucln(a, b));
    return 0;
}