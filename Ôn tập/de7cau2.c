#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char maBN[50];
    char tenBN[50];
    int namSinh;
    int soNgayNamVien;
    double vienPhi;
}benhNhan;

void docVaTinhVienPhi(FILE *f, benhNhan *a, int n);
void benhNhanCaoTuoi(benhNhan *a, int n);
void sapXep(benhNhan *a, int n);
void ghiDuLieu(benhNhan *a, int n);

int main(){
    int n=0;
    FILE *f = fopen("benhnhan.txt", "r");
    if(f==NULL){
        printf("Loi: Mo file khong thanh cong!\n");
        return 1;
    }
    if(fscanf(f, "%d", &n)!=1){
        printf("Loi: Dinh dang so luong benh nhan khong hop le!\n");
        fclose(f);
        return 1;
    }
    benhNhan *a = (benhNhan *)malloc(n*sizeof(benhNhan));
    if(a==NULL){
        printf("Loi: Cap phat bo nho khong thanh cong!\n");
        fclose(f);
        return 1;
    }
    
    docVaTinhVienPhi(f, a, n);
    benhNhanCaoTuoi(a, n);
    sapXep(a, n);
    ghiDuLieu(a, n);

    fclose(f);
    free(a);
    printf("\nDa giai phong bo nho!\n");

    return 0;
}
void docVaTinhVienPhi(FILE *f, benhNhan *a, int n){
    for(int i=0; i<n; i++){
        fscanf(f, " %[^\n]", a[i].maBN);
        fscanf(f, " %[^\n]", a[i].tenBN);
        fscanf(f, "%d", &a[i].namSinh);
        fscanf(f, "%d", &a[i].soNgayNamVien);
        if(a[i].namSinh<=0 || a[i].soNgayNamVien<=0){
            printf("Thong tin cua benh nhan %d khong hop le!\n", i+1);
            printf("Chuong trinh da dung lai!\n");
            fclose(f);
            free(a);
            exit(1);
        }
    }
    printf("Doc du lieu thanh cong !\n");
    
    printf("Danh sach thong tin va vien phi cua cac benh nhan:\n");
    printf("%-15s | %-20s | %-10s | %-20s | %-20s\n", "Ma benh nhan", "Ten benh nhan", "Nam sinh", "So ngay nam vien", "Vien phi");
    for(int i=0; i<n; i++){
        a[i].vienPhi = a[i].soNgayNamVien * 200000;
        printf("%-15s | %-20s | %-10d | %-20d | %-20.2lf\n", a[i].maBN, a[i].tenBN, a[i].namSinh, a[i].soNgayNamVien, a[i].vienPhi);
    }
    printf("\n");
}
void benhNhanCaoTuoi(benhNhan *a, int n){
    int dem=0;
    for(int i=0; i<n; i++){
        if(2026 - a[i].namSinh > 60){
            dem++;
        }
    }
    if(dem>0){
        printf("Co %d benh nhan cao tuoi (Tren 60 tuoi)!\n", dem);
    }else{
        printf("Khong co benh nhan nao cao tuoi!\n");
    }
    printf("\n");
}

void sapXep(benhNhan *a, int n){
    for(int i=0; i<n-1; i++){
        for(int j=i+1; j<n; j++){
            if(a[i].vienPhi < a[j].vienPhi){
                benhNhan temp = a[i];
                a[i]=a[j];
                a[j]=temp;
            }
        }
    }
}

void ghiDuLieu(benhNhan *a, int n){
    FILE *fOut = fopen("vienphi.txt", "w");
    if(fOut == NULL){
        printf("Loi: Mo file de ghi khong thanh cong!\n");
        return ;
    }
    fprintf(fOut, "Danh sach thong tin va vien phi da duoc sap xep cua cac benh nhan:\n");
    fprintf(fOut, "%-15s | %-20s | %-10s | %-20s | %-20s\n", "Ma benh nhan", "Ten benh nhan", "Nam sinh", "So ngay nam vien", "Vien phi");
    for(int i=0; i<n; i++){
        fprintf(fOut, "%-15s | %-20s | %-10d | %-20d | %-20.2lf\n", a[i].maBN, a[i].tenBN, a[i].namSinh, a[i].soNgayNamVien, a[i].vienPhi);
    }
    fclose(fOut);
    printf("Ghi du lieu vao file vienphi.txt thanh cong!\n");

}