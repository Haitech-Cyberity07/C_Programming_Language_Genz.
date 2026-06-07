// Bài 1 (Mảng 1 chiều - Điểm sinh viên):
// Viết chương trình nhập vào mảng số thực biểu diễn điểm thi Kỹ thuật lập trình của n sinh viên.
// Yêu cầu: Viết hàm đếm số lượng sinh viên qua môn (điểm >= 4.0) và hàm tìm điểm số cao nhất lớp.
#include <stdio.h>
#include <stdlib.h>

//ham nhap diem cho n sinh vien
void nhapDiem(float a[], int n);
void inDiem(float a[], int n);
void demDiem(float a[], int n);

int main(){
    int n=0;
    printf("Nhap so luong sinh vien: ");
    scanf("%d", &n);
    float *a = (float*)malloc(n * sizeof(float));
    if(a==NULL){
        printf("Cap phat khong thanh cong!\n");
        return 1;
    }
    printf("\n");
    nhapDiem(a, n);
    printf("\nDanh sach diem cua sinh vien:\n");
    inDiem(a, n);
    printf("\n");
    demDiem(a, n);
    return 0;
}

void nhapDiem(float a[], int n){
    for(int i=0; i<n; i++){
        printf("Nhap diem cho sinh vien thu %d:", i+1);
        scanf("%f", &a[i]);
    }
}

void inDiem(float a[], int n){
    for(int i=0; i<n; i++){
        printf("Diem cua sinh vien thu %d la: %.2f\n", i+1, a[i]);
    }
}

void demDiem(float a[], int n){
    int dem=0;
    for(int i=0; i<n; i++){
        if(a[i]>=4){
            dem++;
        }
    }
    if(dem>0){
        printf("So sinh vien qua mon la: %d\n", dem);
    }else{
        printf("Khong co sinh vien nao qua mon!\n");
    }
}