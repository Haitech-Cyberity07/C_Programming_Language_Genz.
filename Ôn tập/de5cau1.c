#include <stdio.h>
#include <math.h>
#include <stdlib.h>

typedef struct{
    int tu;
    int mau;
}phanSo;

void docDuLieu(FILE *f, phanSo *a, int n);
int ucln(int a, int b);
void rutGon(phanSo *a, int n);
void tongPhanSo(phanSo *a, int n);

int main(){
    int n=0;
    FILE *f=fopen("phanso.txt", "r");
    if(f==NULL){
        printf("Loi: Mo file khong thanh cong!\n");
        return 1;
    }
    if(fscanf(f, "%d", &n)!=1){
        printf("Loi: Dinh dang so phan tu khong hop le!\n");
        fclose(f);
        return 1;
    }
    phanSo *a=(phanSo *)malloc(n * sizeof(phanSo));
    if(a==NULL){
        printf("Loi: Cap phat khong thanh cong!\n");
        fclose(f);
        return 1;
    }
    docDuLieu(f, a, n);
    rutGon(a, n);
    tongPhanSo(a, n);
    fclose(f);
    free(a);
    printf("\nDa giai phong bo nho!\n");
    return 0;
}
void docDuLieu(FILE *f, phanSo *a, int n){
    for(int i=0; i<n; i++){
        fscanf(f, "%d", &a[i].tu);
        fscanf(f, "%d", &a[i].mau);
        if(a[i].mau == 0){
            printf("Loi: Vui long nhap mau so cho phan so %d khac 0!\n", i+1);
            printf("Doc du lieu khong thanh cong!\nChuong trinh da dung lai!\n");
            fclose(f);
            free(a);
            exit(1);
        }
    }
    printf("Doc du lieu thanh cong!\n");
    printf("Cac phan so duoc nhap vao mang la:\n");
    for(int i=0; i<n; i++){
        printf("Phan so %d: %d/%d\n", i+1, a[i].tu, a[i].mau);
    }
}
int ucln(int a, int b){
    while(b!=0){
        a = abs(a);
        b = abs(b);
        int temp = a%b;
        a=b;
        b=temp;
    }
    return a==0 ? 1 : a;
}
void rutGon(phanSo *a, int n){
    printf("\nCac phan so sau khi rut gon la:\n");
    for(int i=0; i<n; i++){
        if(a[i].tu == 0){
            a[i].mau = 1;
        }else{
            int timUcln = ucln(a[i].tu, a[i].mau);
            a[i].tu /= timUcln;
            a[i].mau /= timUcln;
            if(a[i].mau < 0){
                a[i].tu = -a[i].tu;
                a[i].mau = -a[i].mau;
            }
        }
        printf("Phan so %d: %d/%d\n", i+1, a[i].tu, a[i].mau);
    }
}

void tongPhanSo(phanSo *a, int n){
    // tao 2 bien lam tong cua tu va tong cua mau( mau khac 0 )
    int tongTu = 0;
    int tongMau = 1;
    for(int i=0; i<n; i++){
        tongTu = tongTu*a[i].mau + a[i].tu*tongMau;
        tongMau = tongMau*a[i].mau;
    }
    //tim UCLN cua tong tu va tong mau de tim ra phan so toi gian
    int timUclnTong = ucln(tongTu, tongMau);
    tongTu /= timUclnTong;
    tongMau /= timUclnTong;
    //Doi dau am len tu neu mau < 0
    if(tongMau < 0){
        tongTu = -tongTu;
        tongMau = -tongMau;
    }
    printf("\nTong cua tat ca phan so co trong mang duoi dang phan so toi gian la: %d/%d\n", tongTu, tongMau);
}