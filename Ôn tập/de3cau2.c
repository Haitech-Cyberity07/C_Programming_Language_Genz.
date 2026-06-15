#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char maNv[50];
    char tenNv[50];
    float heSoLuong;
    int soNgayCong;
    double luong;
}nhanVien;
void docDuLieu(FILE *fIn, nhanVien *a, int n);
void tinhLuong(nhanVien *a, int n);
void luongMin(nhanVien *a, int n);
void sapXep(nhanVien *a, int n);
void ghiDuLieu(nhanVien *a, int n);

int main(){
    int n=0;
    FILE *fIn = fopen("nhanvien.txt", "r");
    if(fIn==NULL){
        printf("Loi:Mo tep khong thanh cong\n");
        return 1;
    }    
    if(fscanf(fIn, "%d", &n)!=1){
        printf("Loi: Dinh dang so luong khong hop le!\n");
        fclose(fIn);
        return 1;
    }
    nhanVien *a=(nhanVien *)malloc(n*sizeof(nhanVien));
    if(a==NULL){
        printf("Cap phat khong thanh cong!\n");
        fclose(fIn);
        return 1;
    }
    docDuLieu(fIn, a, n);
    tinhLuong(a, n);
    luongMin(a, n);
    sapXep(a, n);
    ghiDuLieu(a, n);
    fclose(fIn);
    free(a);
    printf("\nDa giai phong bo nho!\n");
    return 0;
}
void docDuLieu(FILE *fIn, nhanVien *a, int n){
    for(int i=0; i<n; i++){
        fscanf(fIn, " %[^\n]", a[i].maNv);
        fscanf(fIn, " %[^\n]", a[i].tenNv);
        fscanf(fIn, "%f", &a[i].heSoLuong);
        fscanf(fIn, "%d", &a[i].soNgayCong);
    }
    printf("Doc du lieu thanh cong!\n");
}

void tinhLuong(nhanVien *a, int n){
    printf("\nDanh sach thong tin cua nhan vien:\n");
    for(int i=0; i<n; i++){
        a[i].luong = a[i].heSoLuong * a[i].soNgayCong * 1500000;
    }
    printf("%-15s | %-15s | %-15s | %-15s | %-15s\n", "Ma nhan vien", "Ho va ten", "He so luong", "So ngay cong", "Luong");
    for(int i=0; i<n; i++){
        printf("%-15s | %-15s | %-15.2f | %-15d | %-15.2lf\n", a[i].maNv, a[i].tenNv, a[i].heSoLuong, a[i].soNgayCong, a[i].luong);
    }
    printf("\n");
}

void luongMin(nhanVien *a, int n){
    double luongMin=a[0].luong;
    int flag=0;
    for(int i=0; i<n; i++){
        if(a[i].luong<luongMin){
            luongMin = a[i].luong;
            flag = i;
        }
    }
    printf("\nNhan vien co luong thap nhat cong ty la:\nMa nhan vien: %s\nHo va ten: %s\nHe so luong: %.2f\nSo ngay cong: %d\nLuong: %.2lf\n", a[flag].maNv, a[flag].tenNv, a[flag].heSoLuong, a[flag].soNgayCong, luongMin);
}

void sapXep(nhanVien *a, int n){
    for(int i=0; i<n-1; i++){
        for(int j=i+1; j<n; j++){
            if(strcmp(a[i].tenNv, a[j].tenNv)>0){
                nhanVien temp = a[i];
                a[i]=a[j];
                a[j]=temp;
            }
        }
    }
}
void ghiDuLieu(nhanVien *a, int n){
    FILE *fOut = fopen("luong_nv.txt", "w");
    if(fOut == NULL){
        printf("\nGhi file khong thanh cong!\n");
        return;
    }else{
        printf("\nGhi du lieu thanh cong!\n");
    }
    fprintf(fOut, "\nDanh sach nhan vien sau khi sap xep la:\n");
    fprintf(fOut, "%-15s | %-15s | %-15s | %-15s | %-15s\n", "Ma nhan vien", "Ho va ten", "He so luong", "So ngay cong", "Luong");
    for(int i=0; i<n; i++){
        fprintf(fOut, "%-15s | %-15s | %-15.2f | %-15d | %-15.2lf\n", a[i].maNv, a[i].tenNv, a[i].heSoLuong, a[i].soNgayCong, a[i].luong);
    }
    fprintf(fOut, "\n");
    fclose(fOut);
}