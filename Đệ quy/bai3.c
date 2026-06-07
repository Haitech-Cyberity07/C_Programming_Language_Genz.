//Chuyển đổi cơ số hệ nhị phân
#include <stdio.h>
void nhi_Phan(long long n){
    if(n<2){
        printf("%d", n);
    }else{
        nhi_Phan(n/2);//thuc hien chia lay nguyen n cho 2 den khi n<2
        //lệnh printf ở dưới sẽ thực hiện ngầm , chia xem dư 1 hay 0
        printf("%d",n%2);//rồi in theo thứ tự từ cuối cùng lên đầu tiên khi đã thỏa mãn điều kiện n<2
    }
}
int main(){
    long long n=0;
    printf("Nhap vao so nguyen n: ");
    scanf("%lld", &n);
    printf("%lld chuyen doi sang he nhi phan co dang:", n);
    nhi_Phan(n);
    return 0;
}