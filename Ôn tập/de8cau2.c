#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char ma[50];
    float dienTich;
    double donGia;
    char phanLoai[50];
    double tongGiaTri;
}bds;
void docDuLieuVaTinhGiaTri(FILE *f, bds *a, int n);
void inChungCu(bds *a, int n);
void sapXep(bds *a, int n);
void ghiDuLieu(bds *a, int n);

int main(){
    int n=0;
    FILE *f = fopen("bds.txt", "r");
    if(f==NULL){
        printf("Loi: Mo file khong thanh cong!\n");
        return 1;
    }
    if(fscanf(f, "%d", &n)!=1){
        printf("Loi: Dinh dang so luong khong hop le!\n");
        fclose(f);
        return 1;
    }
    bds *a = (bds *)malloc(n * sizeof(bds));
    if(a==NULL){
        printf("Loi: Cap phat khong thanh cong!\n");
        fclose(f);
        return 1;
    }
    docDuLieuVaTinhGiaTri(f, a, n);
    inChungCu(a, n);
    sapXep(a, n);
    ghiDuLieu(a, n);
    fclose(f);

    free(a);
    printf("\nDa giai phong bo nho!\n");

    return 0;
}
void docDuLieuVaTinhGiaTri(FILE *f, bds *a, int n){
    for(int i=0; i<n; i++){
        fscanf(f, " %[^\n]", a[i].ma);
        fscanf(f, "%f", &a[i].dienTich);
        fscanf(f, "%lf", &a[i].donGia);
        fscanf(f, " %[^\n]", a[i].phanLoai);
        if(strcmp(a[i].phanLoai, "DatNen")!=0 && strcmp(a[i].phanLoai, "ChungCu")!=0){
            printf("Loi: Phan loai mo hinh BDS khong hop le!\n");
            printf("Chuong trinh da dung lai!\n");
            fclose(f);
            free(a);
            exit(1);
        }
        a[i].tongGiaTri = a[i].dienTich * a[i].donGia;
    }
    printf("Doc du lieu thanh cong!\n");
    printf("Danh sach bat dong san:\n");
    printf("%-15s | %-15s | %-15s | %-15s | %-15s\n", "Ma BDS", "Dien Tich", "Don Gia", "Loai", "Tong Gia Tri");
    for(int i=0; i<n; i++){
        printf("%-15s | %-15.2f | %-15.2lf | %-15s | %-15.2f\n", a[i].ma, a[i].dienTich, a[i].donGia, a[i].phanLoai, a[i].tongGiaTri);
    }
    printf("\n");
}
void inChungCu(bds *a, int n){
    int dem = 0;
    for (int i = 0; i < n; i++) {
        if (strcmp(a[i].phanLoai, "ChungCu") == 0 && a[i].dienTich > 70) {
            // Chỉ in dòng tiêu đề duy nhất 1 lần khi bắt được phần tử đầu tiên
            if (dem == 0) {
                printf("Cac bat dong san loai 'ChungCu' co dien tich > 70m2 la:\n");
                printf("%-15s | %-15s | %-15s | %-15s | %-15s\n", "Ma BDS", "Dien Tich", "Don Gia", "Loai", "Tong Gia Tri");
            }
            // In thông tin phần tử
            printf("%-15s | %-15.2f | %-15.2lf | %-15s | %-15.2f\n", a[i].ma, a[i].dienTich, a[i].donGia, a[i].phanLoai, a[i].tongGiaTri);
            dem++;
        }
    }
    if (dem == 0) {
        printf("Khong co bat dong san nao thuoc loai 'ChungCu' va dien tich > 70m2!\n");
    }
    printf("\n");
}

void sapXep(bds *a, int n){
    for(int i=0; i<n-1; i++){
        for(int j=i+1; j<n; j++){
            if(a[i].tongGiaTri < a[j].tongGiaTri){
                bds temp = a[i];
                a[i]=a[j];
                a[j]=temp;
            }
        }
    }
}
void ghiDuLieu(bds *a, int n){
    FILE *fOut = fopen("kq_bds.txt", "w");
    if(fOut==NULL){
        printf("Loi: Mo file ghi khong thanh cong!\n");
        return;
    }
    fprintf(fOut, "Danh sach bat dong san sau khi sap xep:\n");
    fprintf(fOut, "%-15s | %-15s | %-15s | %-15s | %-15s\n", "Ma BDS", "Dien Tich", "Don Gia", "Loai", "Tong Gia Tri");
    for(int i=0; i<n; i++){
        fprintf(fOut, "%-15s | %-15.2f | %-15.2lf | %-15s | %-15.2f\n", a[i].ma, a[i].dienTich, a[i].donGia, a[i].phanLoai, a[i].tongGiaTri);
    }
    fclose(fOut);
    printf("Ghi du lieu thanh cong!\n");
}