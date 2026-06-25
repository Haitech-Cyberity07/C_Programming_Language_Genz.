#include <string.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct{
    char ma[50];
    char ten[50];
    int namSX;
    double doanhThu;
}phim;

void docDuLieu(FILE *f, phim *a, int n);
void doanhThuMax(phim *a, int n);
void sapXepVaGhi(phim *a, int n);

int main(){
    FILE *f = fopen("phim.txt", "r");
    if(f==NULL){
        printf("Loi: Mo file khong thanh cong!\n");
        return 1;
    }
    int n=0;
    if(fscanf(f, "%d", &n)!=1){
        printf("Loi: Dinh dang n khong hop le!\n");
        fclose(f);
        return 1;
    }
    phim *a = (phim *)malloc(n * sizeof(phim));
    if(a==NULL){
        printf("Loi: Cap phat khong thanh cong!\n");
        fclose(f);
        return 1;
    }
    docDuLieu(f, a, n);
    doanhThuMax(a, n);
    sapXepVaGhi(a, n);
    fclose(f);
    free(a);
    printf("Da giai phong bo nho!\n");
    return 0;
}
void docDuLieu(FILE *f, phim *a, int n){
    for(int i=0; i<n; i++){
        fscanf(f, " %[^\n]", a[i].ma);
        fscanf(f, " %[^\n]", a[i].ten);
        fscanf(f, "%d", &a[i].namSX);
        fscanf(f, "%lf", &a[i].doanhThu);
    }
    printf("Doc du lieu thanh cong!\n");
    printf("Danh sach cac bo phim:\n");
    printf("%-15s | %-20s | %-15s | %-15s\n", "Ma phim", "Ten phim", "Nam san xuat", "Doanh thu");
    for(int i=0; i<n; i++){
        printf("%-15s | %-20s | %-15d | %-15.2lf\n", a[i].ma, a[i].ten, a[i].namSX, a[i].doanhThu);
    }
    printf("\n");
}

void doanhThuMax(phim *a, int n){
    double max = -1.0;
    int found = -1;
    for(int i=0; i<n; i++){
        if(a[i].namSX>=2010 && a[i].namSX<=2020){
            if(a[i].doanhThu > max){
                max = a[i].doanhThu;
                found = i;
            }
        }
    }
    if(found!=-1){
        printf("Phim co doanh thu cao nhat la:\n");
        printf("Ma phim : %s\nTen phim : %s\nNam san xuat: %d\nDoanh thu: %.2lf\n", a[found].ma, a[found].ten, a[found].namSX, max);
    }else{
        printf("Khong co phim nao san xuat trong giai doan 2010-2020\n");
    }
}
void sapXepVaGhi(phim *a, int n){
    FILE *fOut = fopen("kq_phim.txt", "w");
    if(fOut == NULL){
        printf("Mo file ghi khong thanh cong!\n");
        return;
    }
    for(int i=0; i<n-1; i++){
        for(int j=i+1; j<n; j++){
            if(a[i].doanhThu < a[j].doanhThu){
                phim temp = a[i];
                a[i]=a[j];
                a[j]=temp;
            }
        }
    }
    fprintf(fOut, "Danh sach cac phim sau khi sap xep theo doanh thu giam dan la:\n");
    fprintf(fOut, "%-15s | %-20s | %-15s | %-15s\n", "Ma phim", "Ten phim", "Nam san xuat", "Doanh thu");
    for(int i=0; i<n; i++){
        fprintf(fOut, "%-15s | %-20s | %-15d | %-15.2lf\n", a[i].ma, a[i].ten, a[i].namSX, a[i].doanhThu);
    }
    fclose(fOut);
    printf("\nGhi du lieu thanh cong!\n");
    printf("\n");
}