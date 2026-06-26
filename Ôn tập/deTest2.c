#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char hoTen[50];
    int namSinh;
    int namKetNap;
    int tuoiDoan;
}doanVien;
void docDuLieu(FILE *f, doanVien *a, int n);
void inDanhSach(doanVien *a, int n);
void sapXep(doanVien *a, int n);
void thongKe(doanVien *a, int n);
void ghiDuLieu(doanVien *a,int n);
int main(){
    FILE *f = fopen("input_test2.txt", "r");
    if(f==NULL){
        printf("Loi: Mo file doc khong thanh cong!\n");
        return 1;
    }
    int n=0;
    if(fscanf(f, "%d", &n)!=1){
        printf("Loi: Dinh dang n khong hop le!\n");
        fclose(f);
        return 1;
    }
    doanVien *a = (doanVien *)malloc(n*sizeof(doanVien));
    if(a==NULL){
        printf("Loi: Cap phat khong thanh cong!\n");
        fclose(f);
        return 1;
    }
    docDuLieu(f, a, n);
    sapXep(a, n);
    printf("\nDanh sach doan vien sau khi sap xep theo nam ket nap:\n");
    inDanhSach(a, n);
    thongKe(a, n);
    ghiDuLieu(a, n);
    fclose(f);
    free(a); printf("\nDa giai phong bo nho!\n");
}
void docDuLieu(FILE *f, doanVien *a, int n){
    for(int i=0; i<n; i++){
        fscanf(f, " %[^\n]", a[i].hoTen);
        fscanf(f, "%d", &a[i].namSinh);
        fscanf(f, "%d", &a[i].namKetNap);
        a[i].tuoiDoan = 2015 - a[i].namKetNap;
    }
    printf("Doc du lieu thanh cong!\n");
}
void inDanhSach(doanVien *a, int n){
    printf("%-20s | %-15s | %-15s\n", "Ho ten", "Nam sinh", "Nam ket nap");
    for(int i=0; i<n; i++){
        printf("%-20s | %-15d | %-15d\n", a[i].hoTen, a[i].namSinh, a[i].namKetNap);
    }
    printf("\n");
}
void sapXep(doanVien *a, int n){
    for(int i=0; i<n-1; i++){
        for(int j=i+1; j<n; j++){
            if(a[i].namKetNap > a[j].namKetNap){
                doanVien temp = a[i];
                a[i]=a[j];
                a[j]=temp;
            }
        }
    }
}
void thongKe(doanVien *a, int n){
    printf("Thong ke tuoi doan (doan vien ket nap sau 2007):\n");
    int dem[100]={0};//mang dem so luong nguoi theo tung muc tuoi doan
    int found = 0;
    for(int i=0; i<n; i++){
        if(a[i].namKetNap>2007){
            if(a[i].tuoiDoan>=0 && a[i].tuoiDoan<=100){
                dem[a[i].tuoiDoan]++;
                found = 1;
            }
        }
    }
    if(found==0){
        printf("Khong co doan vien nao ket nap sau 2007!\n");
        return;
    }
    for(int i=0; i<100; i++){
        if(dem[i]>0){
            printf("Tuoi doan %d: Co %d doan vien!\n", i, dem[i]);
        }
    }
}
void ghiDuLieu(doanVien *a, int n){
    FILE *fOut=fopen("output_test2.txt", "w");
    if(fOut==NULL){
        printf("Loi: Mo file ghi khong thanh cong!\n");
        return ;
    }
    fprintf(fOut, "\nDanh sach doan vien sau khi sap xep theo nam ket nap:\n");
    fprintf(fOut, "%-20s | %-15s | %-15s\n", "Ho ten", "Nam sinh", "Nam ket nap");
    for(int i=0; i<n; i++){
        fprintf(fOut, "%-20s | %-15d | %-15d\n", a[i].hoTen, a[i].namSinh, a[i].namKetNap);
    }
    fprintf(fOut, "\n");

    fprintf(fOut, "Thong ke tuoi doan (doan vien ket nap sau 2007):\n");
    int dem[100]={0};//mang dem so luong nguoi theo tung muc tuoi doan
    int found = 0;
    for(int i=0; i<n; i++){
        if(a[i].namKetNap>2007){
            if(a[i].tuoiDoan>=0 && a[i].tuoiDoan<100){
                dem[a[i].tuoiDoan]++;
                found = 1;
            }
        }
    }
    if(found==0){
        fprintf(fOut, "Khong co doan vien nao ket nap sau 2007!\n");
        return;
    }
    for(int i=0; i<100; i++){
        if(dem[i]>0){
            fprintf(fOut, "Tuoi doan %d: Co %d doan vien!\n", i, dem[i]);
        }
    }
    fclose(fOut);
    printf("Ghi ket qua vao file thanh cong!\n");
}