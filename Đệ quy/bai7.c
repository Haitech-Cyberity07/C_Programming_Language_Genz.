// Bài 3. Tính tổng chữ số chẵn (lẻ) của N
// Bài toán cơ sở : S(N) = 0 nếu N lẻ, N nếu N chẵn với N < 10
// Công thức truy hồi : S(N) = S(N / 10) nếu N lẻ, N % 10 + S(N / 10) nếu N chẵn với N ≥ 10
#include <stdio.h>
int tongChan(long long n){
    //diem dung
    if(n==0){
        return 0;
    }
    int soDu = n%10;//lay chu so cuoi cung
    if(soDu%2==0){
        return soDu+tongChan(n/10);// neu chu so cuoi chan, lay no roi cong phan con lai
    }else{
        return tongChan(n/10);//neu chu so cuoi le, bo qua no roi xet cac phan con lai
    }
}
int main(){
    long long n=0;
    printf("Nhap vao so nguyen n: ");
    scanf("%lld", &n);
    printf("Tong cac chu so chan cua %lld la: %d", n, tongChan(n));
    return 0;
}