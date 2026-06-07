//Để tìm BCNN bạn có thể dựa vào kiến thức : BCNN(a, b) = a * b / UCLN(a, b). 
#include <stdio.h>
int ucln(int a, int b){
    if(a==0 || b==0){
        return a+b;
    }
    while(a!=b){
        if(a>b){
            a=a-b;//thay thế số lớn hơn bằng hiệu của a với số nhỏ hơn là b
        }else{
            b=b-a;//thay thế só lơn hơn bằng hiệu của b với số nhỏ hơn là a
        }
    }
    return a;// hoặc b vì theo thuật toán euclid thì cuối cùng ucln cũng về 2 số a=b;
}
int bcnn(int a, int b){
    return a*b/ucln(a,b); 
}
int main(){
    int a=0, b=0;
    printf("Nhap 2 so nguyen duong a va b (a>0, b>0): ");
    scanf("%d %d", &a, &b);
    printf("Boi chung nho nhat cua hai so %d va %d la: %d\n", a, b, bcnn(a, b));
    return 0;
}