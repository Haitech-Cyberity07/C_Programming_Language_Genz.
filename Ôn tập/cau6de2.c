#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int stk;
    char tenKhachHang[50];
    double soDu;
}taiKhoan;

void docDuLieu(FILE *f, taiKhoan *a, int n);
void tongSoDu(taiKhoan *a, int n);
void maxSoDu(taiKhoan  *a, int n);
void locVaGhiDuLieu(taiKhoan *a, int n);

int main(){
    int n=0;
    FILE *f = fopen("taikhoan.txt", "r");
    if(f==NULL){
        printf("Loi: Mo file khong thanh cong!\n");
        return 1;
    }
    if(fscanf(f, "%d", &n)!=1){
        printf("Loi: Dinh dang so luong khong hop le!\n");
        fclose(f);
        return 1;
    }
    taiKhoan *a=(taiKhoan *)malloc(n * sizeof(taiKhoan));
    if(a==NULL){
        printf("Loi: Cap phat khong thanh cong!\n");
        fclose(f);
        return 1;
    }
    docDuLieu(f, a, n);
    tongSoDu(a, n);
    maxSoDu(a, n);
    locVaGhiDuLieu(a, n);
    fclose(f);
    free(a);

    return 0;
}
void docDuLieu(FILE *f, taiKhoan *a, int n){
    for(int i=0; i<n; i++){
        fscanf(f, "%d", &a[i].stk);
        if(a[i].stk == 0){
            printf("Loi: So tai khoan phai la 1 so khac 0!\n");
            printf("Doc danh sach khong thanh cong!\nChuong trinh da dung lai!\n");
            fclose(f);
            free(a);
            exit(1);
        }
        fscanf(f, " %[^\n]", a[i].tenKhachHang);
        fscanf(f, "%lf", &a[i].soDu);
    }
    printf("Doc danh sach thanh cong!\n");
    printf("Danh sach thong tin khach hang:\n");
    printf("%-15s | %-20s | %-20s\n", "So tai khoan", "Ten khach hang", "So du");
    for(int i=0; i<n; i++){
        printf("%-15d | %-20s | %-20.2lf\n", a[i].stk, a[i].tenKhachHang, a[i].soDu);
    }
    printf("\n");
}
void tongSoDu(taiKhoan *a, int n){
    double tong = 0.0;
    for(int i=0; i<n; i++){
        tong+=a[i].soDu;
    }
    printf("Tong so du cua tat ca cac khach hang la: %.2lf\n", tong);
}
void maxSoDu(taiKhoan *a, int n){
    double max = a[0].soDu;
    for(int i=1; i<n; i++){
        if(max < a[i].soDu){
            max = a[i].soDu;
        }
    }
    printf("\nThong tin khach hang co so du lon nhat la:\n");
    printf("%-15s | %-20s | %-20s\n", "So tai khoan", "Ten khach hang", "So du");
    for(int i=0; i<n; i++){
        if(a[i].soDu == max){
            printf("%-15d | %-20s | %-20.2lf\n", a[i].stk, a[i].tenKhachHang, a[i].soDu);
        }
    }
    printf("\n");
}
void locVaGhiDuLieu(taiKhoan *a, int n){
    FILE *fOut = fopen("canhbao.txt", "w");
    if(fOut==NULL){
        printf("\nLoi: Mo file khong thanh cong!\n");
        return ;
    }
    fprintf(fOut, "\nDanh sach khach hang co so du duoi 50k:\n");
    fprintf(fOut, "%-15s | %-20s | %-20s\n", "So tai khoan", "Ten khach hang", "So du");
    for(int i=0; i<n; i++){
        if(a[i].soDu < 50000){
            fprintf(fOut, "%-15d | %-20s | %-20.2lf\n", a[i].stk, a[i].tenKhachHang, a[i].soDu);
        }
    }
    fclose(fOut);
    printf("Ghi du lieu vao file canhbao.txt thanh cong!\n");
}