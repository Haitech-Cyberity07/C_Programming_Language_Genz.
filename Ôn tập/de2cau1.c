#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void docDuLieu(FILE *f, int *a, int n);
int checkSnt(int n);
void demSnt(int *a, int n);
void xoaTrungLap(int *a, int *n);

int main(){
    int n=0;
    FILE *f=fopen("dayso.txt", "r");
    if(f==NULL){
        printf("Loi: Mo file khong thanh cong!\n");
        return 1;
    }
    if(fscanf(f, "%d", &n) != 1){
        printf("Loi: Dinh dang phan tu khong hop le!\n");
        fclose(f);
        return 1;
    }
    int *a = (int *)malloc(n*sizeof(int));
    if(a==NULL){
        printf("Loi: Cap phat khong thanh cong!\n");
        fclose(f);
        return 1;
    }
    docDuLieu(f, a, n);
    demSnt(a, n);
    xoaTrungLap(a, &n); // dung con tro thi phai them ki tu '&' de the hien la dia chi
    fclose(f);
    free(a);
    printf("\nGiai phong bo nho thanh cong!\n");
    return 0;
}
void docDuLieu(FILE *f, int *a, int n){
    printf("Doc du lieu file thanh cong!\n");
    printf("\nCac phan tu cua mang trong file la:\n");
    for(int i=0; i<n; i++){
        fscanf(f, "%d", &a[i]);
        printf("%d ", a[i]);
    }
    printf("\n");
}
int checkSnt(int n){
    if(n<2){
        return 0;
    }else{
        for(int i=2; i<=sqrt(n); i++){
            if((n%i)==0){
                return 0;
            }
        }
        return 1;
    }
}
void demSnt(int *a, int n){
    int dem=0;
    for(int i=0; i<n; i++){
        if(checkSnt(a[i])){
            dem++;
        }
    }
    if(dem>0){
        printf("\nTrong mang co tat ca %d so nguyen to!\n", dem);
    }else{
        printf("\nKhong co so nguyen to nao trong mang!\n");
    }
}

void xoaTrungLap(int *a, int *n){
    int k=0; //kich thuoc moi cua mang(chua cac so duy nhat)
    for(int i=0; i<*n; i++){
        int daXuatHien = 0;
        for(int j=0; j<k; j++){
            if(a[i]==a[j]){
                daXuatHien = 1;//
                break;
            }
        }
        if(daXuatHien==0){
            a[k]=a[i];
            k++;
        }
    }
    *n=k; // sau khi da loc xong phan tu thi thay gia tri n ban dau bang gia tri k
          // k o day la so luong phan tu moi cua mang hay n luc nay se co so phan tu la k 

    printf("\nMang sau khi loai bo cac phan tu trung lap la:\n");
    for(int i=0; i<*n; i++){
        printf("%d ", a[i]);
    }
    printf("\n");
}
