#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct{
    char maChuyenBay[50];
    char noiDi[50];
    char noiDen[50];
    double giaVe;
}chuyenBay;

void docDuLieu(FILE *f, chuyenBay *a, int n);
void haNoi(chuyenBay *a, int n);
void sapXep(chuyenBay *a, int n);
void ghiDuLieu(chuyenBay *a, int n);

int main(){
    int n=0;
    FILE *f=fopen("chuyenbay.txt", "r");
    if(f==NULL){
        printf("Loi: Mo file khong thanh cong!\n");
        return 1;
    }
    if(fscanf(f, "%d", &n)!=1){
        printf("Loi: Dinh dang so chuyen bay khong hop le!\n");
        fclose(f);
        return 1;
    }
    chuyenBay *a=(chuyenBay *)malloc(n * sizeof(chuyenBay));
    if(a==NULL){
        printf("Loi: Cap phat khong thanh cong!\n");
        fclose(f);
        return 1;
    }
    docDuLieu(f, a, n);
    haNoi(a, n);
    sapXep(a, n);
    ghiDuLieu(a, n);
    fclose(f);
    free(a);
    printf("Da giai phong bo nho!\n");

    return 0;
}
void docDuLieu(FILE *f, chuyenBay *a, int n){
    for(int i=0; i<n; i++){
        fscanf(f, " %[^\n]", a[i].maChuyenBay);
        fscanf(f, " %[^\n]", a[i].noiDi);
        fscanf(f, " %[^\n]", a[i].noiDen);
        fscanf(f, "%lf", &a[i].giaVe);
    }
    printf("Doc du lieu vao mang thanh cong!\n");
    printf("\nDanh sach thong tin cac chuyen bay:\n");
    printf("%-15s | %-20s | %-20s | %-15s \n", "Ma chuyen bay", "Noi di", "Noi den", "Gia ve");
    for(int i=0; i<n; i++){
        printf("%-15s | %-20s | %-20s | %-15.2lf \n", a[i].maChuyenBay, a[i].noiDi, a[i].noiDen, a[i].giaVe);
    }
    printf("\n");
}
void haNoi(chuyenBay *a, int n){
    int dem=0;
    for(int i=0; i<n; i++){
        if(strcmp(a[i].noiDi, "Hanoi") == 0){
            dem++;
        }
    }
    if(dem>0){
        printf("\nCo %d chuyen bay co noi di la 'Hanoi'\n", dem);
        printf("Thong tin cac chuyen bay do la:\n");
        printf("%-15s | %-20s | %-20s | %-15s \n", "Ma chuyen bay", "Noi di", "Noi den", "Gia ve");
        for(int i=0; i<n; i++){
            if(strcmp(a[i].noiDi, "Hanoi")==0){
                printf("%-15s | %-20s | %-20s | %-15.2lf \n", a[i].maChuyenBay, a[i].noiDi, a[i].noiDen, a[i].giaVe);
            }
        }
        printf("\n");
    }else{
        printf("\nKhong co chuyen bay nao co noi di la 'Hanoi'\n");
    }
}

void sapXep(chuyenBay *a, int n){
    for(int i=0; i<n-1; i++){
        for(int j=i+1; j<n; j++){
            if(a[i].giaVe < a[j].giaVe){
                chuyenBay temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
}
void ghiDuLieu(chuyenBay *a, int n){
    FILE *fOut = fopen("ds_chuyenbay.txt", "w");
    if(fOut==NULL){
        printf("Loi: Ghi file khong thanh cong!\n");
        return;
    }
    printf("\nGhi du lieu thanh cong!\n");
    fprintf(fOut, "\nDanh sach thong tin cac chuyen bay sau khi sap xep:\n");
    fprintf(fOut, "%-15s | %-20s | %-20s | %-15s \n", "Ma chuyen bay", "Noi di", "Noi den", "Gia ve");
    for(int i=0; i<n; i++){
        fprintf(fOut, "%-15s | %-20s | %-20s | %-15.2lf \n", a[i].maChuyenBay, a[i].noiDi, a[i].noiDen, a[i].giaVe);
    }
    printf("\n");
    fclose(fOut);
}