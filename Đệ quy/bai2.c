// Tổ hợp chập K của N (C(n, k)) được tính đệ quy dựa vào bài toán cơ sở và công thức truy hồi sau :
// Bài toán cơ sở : C(n, 0) = 1 và C(n, n) = 1
// Công thức truy hồi : C(n, k) = C(n - 1, k - 1) + C(n - 1, k) 
#include <stdio.h>
int toHop(int n,int k){
    if(k>n){
        return 0;
    }
    if(k==0||k==n){
        return 1;
    }else{
        return toHop(n-1, k-1)+toHop(n-1, k);
    }
}
int main(){
    int n=0, k=0;
    printf("Nhap so nguyen n va k: ");
    scanf("%d %d", &n, &k);
    printf("To hop chap %d cua %d la: %d", k,n,toHop(n, k));
    return 0;
}