//Tính tổng chữ số của số tự nhiên N
//Công thức truy hồi : Sum(N) = N % 10 + Sum(N / 10) với N ≥ 10
#include <stdio.h>
int sum(int n){
    if(n<10){
        return n;
    }else{
        return n%10+sum(n/10);
        //tức là nhập vào số n lớn hơn hoặc bằng 10
        //sau đó chia lấy dư cho 10 để lấy hàng đơn vị, rồi chia lấy nguyên 10 để dịch sang trái lấy số tiếp theo để thực hiện phép cộng 
    }
}
int main(){
    printf("%d", sum(12345));
    return 0;
}
