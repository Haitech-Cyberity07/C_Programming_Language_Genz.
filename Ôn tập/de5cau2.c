#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char maMay[50];
    char tenHang[50];
    int ram;
    double donGia;
}laptop;

void docDuLieu(FILE *f, laptop *a, int n);
void timLaptop(laptop *a, int n);
void sapXep(laptop *a, int n);
void ghiDuLieu(laptop *a, int n);

int main(){
    int n=0;
    FILE *f=fopen("laptop.txt", "r");
    if(f==NULL){
        printf("Loi: Mo file khong thanh cong!\n");
        return 1;
    }
    if(fscanf(f, "%d", &n)!=1){
        printf("Loi: Dinh dang so luong laptop khong hop le!\n");
        fclose(f);
        return 1;
    }
    laptop *a = (laptop *)malloc(n * sizeof(laptop));
    if(a==NULL){
        printf("Loi: Cap phat khong thanh cong!\n");
        fclose(f);
        return 1;
    }
    docDuLieu(f, a, n);
    timLaptop(a, n);
    sapXep(a, n);
    ghiDuLieu(a, n);
    fclose(f);
    free(a);
    printf("\nDa giai phong bo nho!\n");
    return 0;
}
void docDuLieu(FILE *f, laptop *a, int n){
    for(int i=0; i<n ;i++){
        fscanf(f, " %[^\n]", a[i].maMay);
        fscanf(f, " %[^\n]", a[i].tenHang);
        fscanf(f, "%d", &a[i].ram);
        if(a[i].ram <= 0){
            printf("RAM cua laptop thu %d phai lon hon 0!\n", i+1);
            printf("Loi: Doc du lieu khong thanh cong!\nChuong trinh da dung lai!\n");
            fclose(f);
            free(a);
            exit(1);
        }
        fscanf(f, "%lf", &a[i].donGia);
    }
    printf("Doc du lieu thanh cong!\n");
    printf("Danh sach thong tin cua cac laptop:\n");
    printf("%-10s | %-20s | %-10s | %-15s\n", "Ma may", "Ten hang", "RAM (Gb)", "Don gia");
    for(int i=0; i<n; i++){
        printf("%-10s | %-20s | %-10d | %-15.2f\n", a[i].maMay, a[i].tenHang, a[i].ram, a[i].donGia);
    }
    printf("\n");
}

void timLaptop(laptop *a, int n){
    int dem = 0;
    for(int i=0; i<n; i++){
        if(strcmp(a[i].tenHang, "Dell") == 0 && a[i].ram >= 8){
            dem++;
        }
    }
    if(dem>0){
        printf("Co %d laptop hang 'Dell' co RAM >= 8 GB\n", dem);
        printf("Danh sach thong tin cua cac laptop hang 'Dell' RAM 8GB:\n");
        printf("%-10s | %-20s | %-10s | %-15s\n", "Ma may", "Ten hang", "RAM (Gb)", "Don gia");
        for(int i=0; i<n; i++){
            if(strcmp(a[i].tenHang, "Dell") == 0 && a[i].ram >= 8){
                printf("%-10s | %-20s | %-10d | %-15.2f\n", a[i].maMay, a[i].tenHang, a[i].ram, a[i].donGia);
            }
        }
    }else{
        printf("Khong co laptop nao cua hang 'Dell' voi RAM >= 8 GB!\n");
    }
    printf("\n");
}

void sapXep(laptop *a, int n){
    for(int i=0; i<n-1; i++){
        for(int j=i+1; j<n; j++){
            if(a[i].donGia > a[j].donGia){
                laptop temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
}

void ghiDuLieu(laptop *a, int n){
    FILE *fOut = fopen("kq_laptop.txt", "w");
    if(fOut==NULL){
        printf("Loi: Mo file khong thanh cong!\n");
        return;
    }
    fprintf(fOut, "Danh sach thong tin cua cac laptop sau khi sap xep:\n");
    fprintf(fOut, "%-10s | %-20s | %-10s | %-15s\n", "Ma may", "Ten hang", "RAM (Gb)", "Don gia");
    for(int i=0; i<n; i++){
        fprintf(fOut, "%-10s | %-20s | %-10d | %-15.2f\n", a[i].maMay, a[i].tenHang, a[i].ram, a[i].donGia);
    }
    fclose(fOut);

    printf("Ghi du lieu thanh cong!\n");
}    

