// Ta cải tiến thuật toán Euclid bằng nhận xét sau :  
// UCLN của hai số nguyên không thay đổi khi thay 1 trong 2 số thành số dư của nó với số còn lại. 
// Có nghĩa là UCLN(a, b) = UCLN(b, a % b)
// Quá trình thay thế này được lặp đi lặp lại cho tới khi 1 trong 2 số bằng 0, 
// khi đó UCLN chính là số còn lại
#include <stdio.h>
int ucln(int a, int b){
    while (b!=0){
        //khởi tạo 1 biến để tính số dư của a chia cho b
        //(kể cả a có nhỏ hơn hay lớn hơn hay bằng b)
        int temp = a%b;
        a=b;
        b=temp;
    }
    return a;
}
int main(){
    int a=0, b=0;
    printf("Nhap vao 2 so nguyen a, b: ");
    scanf("%d %d", &a, &b);
    printf("Uoc chung lon nhat cua 2 so %d va %d la: ", a, b);

    printf("%d\n", ucln(a, b));
    return 0;
}