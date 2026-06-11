#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char maSv[50];
    char tenSv[50];
    float toan, ly, hoa, dtb;
}sinhVien;

void docDuLieu(FILE *fIn, sinhVien *a, int n);
void sapXep(sinhVien *a, int n);
void top3MaxDiemTb(sinhVien *a, int n);
void ghiDuLieu(sinhVien *a, int n);

int main(){
    int n=0;
    FILE *fIn = fopen("sinhvien.txt", "r");
    if(fIn==NULL){
        printf("Loi: Mo file khong thanh cong!\n");
        return 1;
    }
    if(fscanf(fIn, "%d", &n)!=1){
        printf("Loi: Dinh dang sinh vien nhap vao khong hop le!\n");
        fclose (fIn);
        return 1;
    }
    sinhVien *a = (sinhVien *)malloc(n*sizeof(sinhVien));
    if(a==NULL){
        printf("Loi: Cao phat bo nho khong thanh cong!\n");
        fclose (fIn);
        return 1;
    }

    docDuLieu(fIn, a, n);
    sapXep(a, n);
    top3MaxDiemTb(a, n);
    ghiDuLieu(a, n);
    fclose(fIn);

    free(a);
    return 0;
}

void docDuLieu(FILE *fIn, sinhVien *a, int n){
    for(int i=0; i<n; i++){
        fscanf(fIn, " %[^\n]", a[i].maSv);
        fscanf(fIn, " %[^\n]", a[i].tenSv);
        fscanf(fIn, "%f %f %f", &a[i].toan, &a[i].ly, &a[i].hoa);
        a[i].dtb = 1.0*(a[i].toan + a[i].ly + a[i].hoa) / 3;
    }
    printf("Doc du lieu va tinh diem trung binh cho tung sinh vien thanh cong!\n");
}

void sapXep(sinhVien *a, int n){
    for(int i=0; i<n-1; i++){
        for(int j=i+1; j<n; j++){
            if(a[i].dtb < a[j].dtb){
                sinhVien temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
}

void top3MaxDiemTb(sinhVien *a, int n){
    printf("\nDanh sach 3 sinh vien co diem trung binh cao nhat la:\n");
    // khai bao gia tri top bang n hoac 3 (neu n<3 thi lay n con n khong nho hon 3 thi lay 3)
    int top = (n<3) ? n : 3;
    for(int i=0; i<top; i++){
        printf("%-10s | %-10s | DTB: %.2f\n", a[i].maSv, a[i].tenSv, a[i].dtb);
    }
    printf("\n");

}

void ghiDuLieu(sinhVien *a, int n){
    FILE *fOut = fopen("ketqua_sv.txt", "w");
    if(fOut == NULL){
        printf("Loi: Tao file khong thanh cong!\n");
        return;
    }else{
        for(int i=0; i<n; i++){
            fprintf(fOut, "%-10s|%-10s|DTB: %.2f\n", a[i].maSv, a[i].tenSv, a[i].dtb);
        }
    }
    fclose(fOut);
    printf("Da ghi du lieu vao tep ketqua_sv.txt thanh cong!\n");

}



