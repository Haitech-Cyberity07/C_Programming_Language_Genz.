#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct{
    char ma[50];
    char ten[50];
    int namXb;
    float giaTien;
}sach;
void docDuLieu(FILE *f, sach *a, int n);
void thongKe(sach *a, int n);
void sapXep(sach *a, int n);
void ghiDuLieu(sach *a, int n);

int main(){
    int n=0;
    FILE *f=fopen("sach.txt", "r");
    if(f==NULL){
        printf("Loi: Mo file khong thanh cong!\n");
        return 1;
    }
    if(fscanf(f, "%d", &n) != 1){
        printf("Loi: Dinh dang so luong sach khong hop le!\n");
        fclose(f);
        return 1;
    }
    sach *a = (sach *)malloc(n*sizeof(sach));
    if(a==NULL){
        printf("Loi: cap phat khong thanh cong!\n");
        fclose (f);
        return 1;
    }
    docDuLieu(f, a, n);
    thongKe(a, n);
    sapXep(a, n);
    ghiDuLieu(a, n);
    fclose(f);
    free(a);
    printf("Giai phong bo nho thanh cong!\n");
    return 0;

}
void docDuLieu(FILE *f, sach *a, int n){
    double tong=0.0;
    for(int i=0; i<n; i++){
        fscanf(f, " %[^\n]", a[i].ma);
        fscanf(f, " %[^\n]", a[i].ten);
        fscanf(f, "%d", &a[i].namXb);
        fscanf(f, "%f", &a[i].giaTien);
        tong+=a[i].giaTien;
    }
    printf("Doc du lieu thanh cong!\n");
    printf("\nDanh sach thong tin cac cuon sach:\n");
    printf("%-10s | %-20s | %-15s | %-15s\n", "Ma sach", "Ten sach", "Nam xuat ban", "Gia tien");
    for(int i=0; i<n; i++){
        printf("%-10s | %-20s | %-15d | %-15.2f\n", a[i].ma, a[i].ten, a[i].namXb, a[i].giaTien);
    }
    printf("\nTong gia tri cua %d cuon sach la: %.2lf", n, tong);
}
void thongKe(sach *a, int n){
    int dem=0;
    for(int i=0; i<n; i++){
        if(a[i].namXb >= 2020){
            dem++;
        }
    }
    if(dem>0){
        printf("\nSo luong sach duoc xuat ban sau nam 2020 la %d\n", dem);
    }else{
        printf("\nKhong co sach nao duoc xuat ban sau nam 2020!\n");
    }
}
void sapXep(sach *a, int n){
    for(int i=0; i<n-1; i++){
        for(int j=i+1; j<n; j++){
            if(a[i].giaTien > a[j].giaTien){
                sach temp1 = a[i];
                a[i]=a[j];
                a[j]=temp1;
            }else if(a[i].giaTien == a[j].giaTien){
                if(a[i].namXb < a[j].namXb){
                    sach temp2 = a[i];
                    a[i]=a[j];
                    a[j]=temp2;
                }
            }
        }
    }
}
void ghiDuLieu(sach *a, int n){
    FILE *fOut = fopen("output_sach.txt", "w");
    if(fOut == NULL){
        printf("\nLoi: Ghi du lieu khong thanh cong!\n");
        return;
    }else{
        fprintf(fOut, "\nDanh sach thong tin cac cuon sach sau khi sap xep la:\n");
        fprintf(fOut, "%-10s | %-20s | %-15s | %-15s\n", "Ma sach", "Ten sach", "Nam xuat ban", "Gia tien");
        for(int i=0; i<n; i++){
            fprintf(fOut, "%-10s | %-20s | %-15d | %-15.2f\n", a[i].ma, a[i].ten, a[i].namXb, a[i].giaTien);
        }
    }
    printf("\nDa ghi ket qua sap xep vao tep output_sach.txt thanh cong!\n");
    fclose(fOut);
}