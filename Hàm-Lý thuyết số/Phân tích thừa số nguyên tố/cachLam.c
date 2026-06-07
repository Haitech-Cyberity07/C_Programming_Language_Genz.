// Phân tích thừa số nguyên tố là cách biểu diễn số tự nhiên N dưới dạng tích các thừa số nguyên tố,
// cách biểu diễn này là duy nhất với số tự nhiên N
// Thuật toán Trial division :
// Duyệt các số d từ 2 tới √N
// Nếu N chia hết cho d thì tiến hành lấy N chia cho d cho tới khi còn chia hết
// Sau khi duyệt xong các số từ 2 tới √N mà N vẫn khác 1 thì N chính là thừa số nguyên tố cuối cùng 
#include <stdio.h>
#include <math.h>
void phanTich(int n){
    for(int i=2; i<=sqrt(n); i++){
        //neu n chia het cho i, i se la thua so nguyen to
        while(n%i==0){
            printf("%d ", i);
            n/=i;// sau khi chia thi n giam de tim thua so nguyen to tiep theo
        }
    }
    if(n>1){
        printf("%d ", n);
    }
    
}
int main(){
    int n=0; 
    printf("Nhap so nguyen n can phan tich thanh thua so nguyen to: ");
    scanf("%d", &n);
    printf("%d = ", n);
    phanTich(n);
    return 0;
}