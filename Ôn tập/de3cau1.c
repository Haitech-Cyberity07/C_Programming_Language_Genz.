#include <stdio.h>
#include <math.h>
#include <stdlib.h>
typedef struct{
    float x, y; 
}diem;
void docDuLieu(FILE*f, diem *a, int n);
void khoangCachMax(diem *a, int n);
void gocPhanTuThuNhat(diem *a, int n);

int main(){
    int n=0;
    FILE *f=fopen("toado.txt", "r");
    if(f==NULL){
        printf("Loi: Mo file khong thanh cong!\n");
        return 1;
    }
    if(fscanf(f, "%d", &n)!=1){
        printf("Loi: Dinh dang so diem khong hop le!\n");
        fclose(f);
        return 1;
    }
    diem *a=(diem*)malloc(n*sizeof(diem));
    if(a==NULL){
        printf("Loi: Cap phat khong thanh cong!\n");
        fclose(f);
        return 1;
    }
    docDuLieu(f, a, n);
    khoangCachMax(a, n);
    gocPhanTuThuNhat(a, n);
    fclose(f);
    free(a);
    printf("\nGiai phong bo nho thanh cong!\n");
    return 0;
}
void docDuLieu(FILE *f, diem *a, int n){
    printf("Doc du lieu thanh cong!\n");
    printf("\nCac toa do trong mang la: ");
    for(int i=0; i<n; i++){
        fscanf(f, "%f %f", &a[i].x, &a[i].y);
        printf("(%.2f, %.2f)", a[i].x, a[i].y);
        if(i<n-1){
            printf(", ");
        }
    }
    printf("\n");
}
void khoangCachMax(diem *a, int n){
    double maxDistance = 0.0;
    int flag1=0, flag2=0;
    for(int i=0; i<n-1; i++){
        for(int j=i+1; j<n; j++){
            double d = sqrt(pow(a[i].x - a[j].x, 2) + pow(a[i].y - a[j].y, 2));
            if(d > maxDistance){
                maxDistance = d;
                flag1 = i;
                flag2 = j;
            }
        }
    }
    printf("\nKhoang cach giua 2 diem xa nhau nhat la: %.2lf\n", maxDistance);
    printf("Khoang cach lon nhat la khoang cach giua 2 diem (%.2f, %.2f) va (%.2f, %.2f)!\n", a[flag1].x, a[flag1].y, a[flag2].x, a[flag2].y);
}
void gocPhanTuThuNhat(diem *a, int n){
    int dem=0;
    for(int i=0; i<n; i++){
        if(a[i].x>0 && a[i].y>0){
            dem++;
        }
    }
    if(dem>0){
        printf("\nCo %d diem nam trong goc phan tu thu nhat!\n", dem);
    }else{
        printf("\nKhong co diem nao nam trong goc phan tu thu nhat!\n");
    }
}