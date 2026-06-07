#include <stdio.h>
void dequy(int n){
    if(n>0){
        printf("Loi goi ham khi n=%d\n", n);
        dequy(n-1);
    }
    printf("Ham khi n=%d ket thuc!\n", n);
}
int main(){
    dequy(4);
    return 0;
}