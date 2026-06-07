//Tính tổng tự nhiên từ 1 tới N bằng đệ quy 
#include <stdio.h>
int tong(int n){
    if(n<=0){
        return 0;
    }
    else{
        return n + tong(n-1);
    }
}
int main(){
    printf("%d", tong(5));

    return 0;
}