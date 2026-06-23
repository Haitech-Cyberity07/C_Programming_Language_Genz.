#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char maCt[50];
    char tenCt[50];
    int soBanThang;
    int soKienTao;
    float diem;
}cauThu;

void docVaTinhDiem(FILE *f, cauThu *a, int n);
void sapXep(cauThu *a, int n);
void diemCaoNhat(cauThu *a, int n);           
void ghiDuLieu(cauThu *a, int n);

int main(){
    int n=0;
    FILE *f = fopen("cauthu.txt", "r");
    if(f==NULL){
        printf("Loi: Mo file khong thanh cong!\n");
        return 1;
    }
    if(fscanf(f, "%d", &n)!=1){
        printf("Loi: Dinh dang so luong cau thu khong hop le!\n");
        fclose(f);
        return 1;
    }
    cauThu *a = (cauThu *)malloc(n * sizeof(cauThu));
    if(a==NULL){
        printf("Loi: Cap phat khong thanh cong!\n");
        fclose(f);
        return 1;
    }
    docVaTinhDiem(f, a, n);
    sapXep(a, n);
    diemCaoNhat(a, n);
    ghiDuLieu(a, n);
    fclose(f);
    free(a);
    printf("\nDa giai phong bo nho!\n");

    return 0;
}
void docVaTinhDiem(FILE *f, cauThu *a, int n){
    for(int i=0; i<n; i++){
        fscanf(f, " %[^\n]", a[i].maCt);
        fscanf(f, " %[^\n]", a[i].tenCt);
        fscanf(f, "%d", &a[i].soBanThang);
        fscanf(f, "%d", &a[i].soKienTao);
        a[i].diem = a[i].soBanThang*2 + a[i].soKienTao;
    }
    printf("Doc du lieu thanh cong!\n");
    printf("Danh sach thong tin cac cau thu:\n");
    printf("%-15s | %-20s | %-15s | %-15s | %-15s\n", "Ma cau thu", "Ten cau thu", "So ban thang", "So kien tao", "Diem");
    for(int i=0; i<n; i++){
        printf("%-15s | %-20s | %-15d | %-15d | %-15.2f\n", a[i].maCt, a[i].tenCt, a[i].soBanThang, a[i].soKienTao, a[i].diem);
    }
    printf("\n");
}
void sapXep(cauThu *a, int n){
    for(int i=0; i<n-1; i++){
        for(int j=i+1; j<n; j++){
            if(a[i].diem<a[j].diem){
                cauThu temp = a[i];
                a[i]=a[j];
                a[j]=temp;
            }
        }
    }
}
void diemCaoNhat(cauThu *a, int n){
    int soLuong = (n<3) ? n : 3;
    printf("3 cau thu co diem danh gia cao nhat:\n");
    printf("%-15s | %-20s | %-15s | %-15s | %-15s\n", "Ma cau thu", "Ten cau thu", "So ban thang", "So kien tao", "Diem");
    for(int i=0; i<soLuong; i++){
        printf("%-15s | %-20s | %-15d | %-15d | %-15.2f\n", a[i].maCt, a[i].tenCt, a[i].soBanThang, a[i].soKienTao, a[i].diem);
    }
    printf("\n");
}
void ghiDuLieu(cauThu *a, int n){
    FILE *fOut = fopen("kq_cauthu.txt", "w");
    if(fOut == NULL){
        printf("Loi: Mo file ghi khong thanh cong!\n");
        return;
    }
    fprintf(fOut, "Danh sach thong tin cac cau thu:\n");
    fprintf(fOut, "%-15s | %-20s | %-15s | %-15s | %-15s\n", "Ma cau thu", "Ten cau thu", "So ban thang", "So kien tao", "Diem");
    for(int i=0; i<n; i++){
        fprintf(fOut, "%-15s | %-20s | %-15d | %-15d | %-15.2f\n", a[i].maCt, a[i].tenCt, a[i].soBanThang, a[i].soKienTao, a[i].diem);
    }
    fclose(fOut);
    printf("Ghi du lieu vao file kq_cauthu.txt thanh cong!\n");
}