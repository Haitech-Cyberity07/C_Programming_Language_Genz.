#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct{
    char maDon[50];
    char tenKH[50];
    int soLuongSP;
    double donGia;
    double giaTri;
}donHang;

void docDuLieu(FILE *f, donHang *a, int n);
void timDonHang(donHang *a, int n);
void sapXepVaGhi(donHang *a, int n);

int main(){
    FILE *f = fopen("donhang.txt", "r");
    if(f==NULL){
        printf("Loi: Mo file khong thanh cong!\n");
        return 1;
    }
    int n=0;
    if(fscanf(f, "%d", &n)!=1){
        printf("Loi: Dinh dang so luong don hang khong thanh cong!\n");
        fclose(f);
        return 1;
    }
    donHang *a = (donHang *)malloc(n*sizeof(donHang));
    if(a==NULL){
        printf("Loi: Cap phat khong thanh cong !\n");
        fclose(f);
        return 1;
    }
    docDuLieu(f, a, n);
    timDonHang(a, n);
    sapXepVaGhi(a, n);
    fclose(f);
    free(a);
    printf("\nDa giai phong bo nho!\n");

    return 0;
}
void docDuLieu(FILE *f, donHang *a, int n){
    for(int i=0; i<n; i++){
        fscanf(f, " %[^\n]", a[i].maDon);
        fscanf(f, " %[^\n]", a[i].tenKH);
        if(fscanf(f, "%d", &a[i].soLuongSP)!=1){
            printf("Loi: So luong don hang cua khach hang %d khong hop le!\n", i+1);
            fclose(f);
            free(a);
            exit(1);
        }
        fscanf(f, "%lf", &a[i].donGia);
        a[i].giaTri = a[i].soLuongSP * a[i].donGia;
    }
    printf("Doc du lieu thanh cong!\n");
    printf("Thong tin cac don hang:\n");
    printf("%-15s | %-20s | %-15s | %-15s | %-15s\n", "Ma don hang", "Ten khach hang", "So luong SP", "Don gia", "Gia tri don");
    for(int i=0; i<n; i++){
        printf("%-15s | %-20s | %-15d | %-15.2lf | %-15.2lf\n", a[i].maDon, a[i].tenKH, a[i].soLuongSP, a[i].donGia, a[i].giaTri);
    }
    printf("\n");
}
void timDonHang(donHang *a, int n){
    int dem = 0;
    for(int i=0; i<n; i++){
        if(a[i].giaTri > 1000000){
            if(dem==0){
                printf("Don hang co gia tri > 1000000:\n");
                printf("%-15s | %-20s | %-15s | %-15s | %-15s\n", "Ma don hang", "Ten khach hang", "So luong SP", "Don gia", "Gia tri don");
            }
            printf("%-15s | %-20s | %-15d | %-15.2lf | %-15.2lf\n", a[i].maDon, a[i].tenKH, a[i].soLuongSP, a[i].donGia, a[i].giaTri);
            dem++;
        }
    }
    if(dem==0){
        printf("Khong co don hang nao co gia tri > 1 trieu vnd!\n");
    }
}
void sapXepVaGhi(donHang *a, int n){
    FILE *fOut = fopen("output_donhang.txt", "w");
    if(fOut==NULL){
        printf("Loi: Mo file ghi khong thanh cong!\n");
        return;
    }
    for(int i=0; i<n-1; i++){
        for(int j=i+1; j<n; j++){
            if(a[i].soLuongSP<a[j].soLuongSP){
                donHang temp = a[i];
                a[i]=a[j];
                a[j]=temp;
            }
        }
    }
    fprintf(fOut, "Danh sach don hang theo so luong giam dan la:\n");
    fprintf(fOut, "%-15s | %-20s | %-15s | %-15s | %-15s\n", "Ma don hang", "Ten khach hang", "So luong SP", "Don gia", "Gia tri don");
    for(int i=0; i<n; i++){
        fprintf(fOut, "%-15s | %-20s | %-15d | %-15.2lf | %-15.2lf\n", a[i].maDon, a[i].tenKH, a[i].soLuongSP, a[i].donGia, a[i].giaTri);
    }
    fclose(fOut);
    printf("\nGhi du lieu vao file output_donhang.txt thanh cong!\n");
}