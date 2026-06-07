// Bài 3. Liệt kê ước nguyên tố của N
// Để liệt ước nguyên tố của N, cách đơn giản nhất bạn làm là viết 1 hàm số nguyên tố
// sau đó duyệt các ước của N và kiểm tra,
// nhưng thực ra ước nguyên tố chính là thừa số nguyên tố.
// Vậy nên khi làm các bài toán liên quan tới ước nguyên tố của 1 số nguyên
// bạn phải nghĩ ngay tới phân tích thừa số nguyên tố. 
#include <stdio.h>
#include <math.h>
int check_snt(int n){
    if(n<2){
        return 0;
    }
    for(int i=2; i<=sqrt(n); i++){
        if(n%i==0){
            return 0;
        }
    }
    return 1;
}
void snt_uc(int n){
    for(int i=1; i<=n; i++){
        if(n%i==0 && check_snt(i)){
            printf("%d ", i);
        }
    }
}
int main(){
    int n=0;
    printf("Nhap so nguyen n: ");
    scanf("%d", &n);
    printf("Cac uoc nguyen to cua %d la: ", n);
    snt_uc(n);
    return 0;
}