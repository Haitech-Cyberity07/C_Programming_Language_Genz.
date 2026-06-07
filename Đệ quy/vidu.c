#include <stdio.h>
void recursive (int n){
    if(n>0){
        printf("%d ", n);
        // hàm ban đầu chỉ xét điều kiện n>0 rồi in 1 phần tử , nhưng khi recall lại ở hàm recursive
        //thì nó sẽ chạy đến khi điều kiện n sai (n<=0) thì mới dừng
        recursive(n-1);
    }
}
int main(){
    recursive(4);
    return 0;
}