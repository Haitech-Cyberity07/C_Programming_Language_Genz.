#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char ma[50];
    char ten[50];
    int soTinChi;
    double hocPhi;
    double trungBinh;
}khoaHoc;

void docVaTinh(FILE *f, khoaHoc *a, int n);
void lietKe(khoaHoc *a, int n);
void sapXepVaGhi(khoaHoc *a, int n);

int main(){
    FILE *f = fopen("khoahoc.txt", "r");
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
    khoaHoc *a = (khoaHoc *)malloc(n * sizeof(khoaHoc));
    if(a==NULL){
        printf("Loi: cap phat khong thanh cong!\n");
        fclose(f);
        return 1;
    }
    docVaTinh(f, a, n);
    lietKe(a, n);
    sapXepVaGhi(a, n);
    fclose(f);
    free(a);
    printf("\nDa giai phong bo nho!\n");
    return 0;
}
void docVaTinh(FILE *f, khoaHoc *a, int n){
    for(int i=0; i<n; i++){
        fscanf(f, " %[^\n]", a[i].ma);
        fscanf(f, " %[^\n]", a[i].ten);
        fscanf(f, "%d", &a[i].soTinChi);
        if(a[i].soTinChi <= 0){
            printf("Loi: So tin cua khoa hoc %s khong hop le!\n", a[i].ten);
            printf("Chuong trinh da dung lai!\n");
            fclose(f);
            free(a);
            exit(1);
        }
        fscanf(f, "%lf", &a[i].hocPhi);
        a[i].trungBinh = a[i].hocPhi / a[i].soTinChi;
    }
    printf("Doc du lieu thanh cong!\n");
    printf("Danh sach cac khoa hoc:\n");
    printf("%-15s | %-20s | %-15s | %-15s | %-15s\n", "Ma khoa hoc", "Ten khoa hoc", "So tin chi", "Hoc phi", "Trung binh/Tin");
    for(int i=0; i<n; i++){
        printf("%-15s | %-20s | %-15d | %-15.2lf | %-15.2lf\n", a[i].ma, a[i].ten, a[i].soTinChi, a[i].hocPhi, a[i].trungBinh);
    }
    printf("\n");
}
void lietKe(khoaHoc *a, int n){
    int dem=0;
    for(int i=0; i<n; i++){
        if(a[i].soTinChi >= 3){
            if(dem==0){
                printf("Cac khoa hoc co 3 tin chi tro len:\n");
                printf("%-15s | %-20s | %-15s | %-15s | %-15s\n", "Ma khoa hoc", "Ten khoa hoc", "So tin chi", "Hoc phi", "Trung binh/Tin");
            }
            printf("%-15s | %-20s | %-15d | %-15.2lf | %-15.2lf\n", a[i].ma, a[i].ten, a[i].soTinChi, a[i].hocPhi, a[i].trungBinh);
            dem++;
        }   
    }
    if(dem==0){
        printf("Khong co khoa hoc nao co 3 tin chi tro len!\n");
    }
    printf("\n");
}
void sapXepVaGhi(khoaHoc *a, int n){
    FILE *fOut = fopen("kq_khoahoc.txt", "w");
    if(fOut == NULL){
        printf("Loi: Mo file ghi khong thanh cong!\n");
        return;
    }
    for(int i=0; i<n-1; i++){
        for(int j=i+1; j<n; j++){
            if(strcmp(a[i].ten, a[j].ten)>0){
                khoaHoc temp = a[i];
                a[i]=a[j];
                a[j]=temp;
            }
        }
    }
    fprintf(fOut, "Danh sach khoa hoc theo ten Alphabet: \n");
    fprintf(fOut, "%-15s | %-20s | %-15s | %-15s | %-15s\n", "Ma khoa hoc", "Ten khoa hoc", "So tin chi", "Hoc phi", "Trung binh/Tin");
    for(int i=0; i<n; i++){
        fprintf(fOut, "%-15s | %-20s | %-15d | %-15.2lf | %-15.2lf\n", a[i].ma, a[i].ten, a[i].soTinChi, a[i].hocPhi, a[i].trungBinh);
    }
    fclose(fOut);
    printf("Ghi du lieu vao file kq_khoahoc.txt thanh cong!\n");
    
}