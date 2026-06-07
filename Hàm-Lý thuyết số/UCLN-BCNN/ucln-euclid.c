// Thuật toán Euclid phát biểu như sau :  
// UCLN của hai số nguyên không thay đổi khi thay số lớn hơn bằng hiệu của nó với số nhỏ hơn
// Quá trình thay thế này được lặp đi lặp lại cho tới khi 2 số bằng nhau,
// khi đó UCLN chính là 1 trong 2 số.
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
int main(){
    int a=0, b=0;
    printf("Nhap vao 2 so nguyen a, b: ");
    scanf("%d %d", &a, &b);
    printf("Uoc chung lon nhat cua 2 so %d va %d la: ", a, b);

    printf("%d\n", ucln(a, b));
    return 0;
}