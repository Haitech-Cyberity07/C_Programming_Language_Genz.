//cau1:
#include <stdio.h>
#include <stdlib.h>

void nhapDuLieu(FILE *f, int *a, int *b, int n, int m);
void inMang(int *arr, int soLuong);
void timMax(int *a, int n);
void timMin(int *b, int m);
void sapXep(int *arr, int soLuong);

int main(){
    FILE *f = fopen("input_test1.txt", "r");
    if(f==NULL){
        printf("Loi: Mo file doc khong thanh cong!\n");
        return 1;
    }
    int n=0, m=0;
    if(fscanf(f, "%d %d", &n, &m)!=2){
        printf("Loi: Dinh dang n va m khong hop le!\n");
        fclose(f);
        return 1;
    }
    int *a=(int *)malloc(n*sizeof(int));
    int *b=(int *)malloc(m*sizeof(int));
    if(a==NULL || b==NULL){
        printf("Loi: Cap phat mang khong thanh cong");
        fclose(f);
        return 1;
    }
    nhapDuLieu(f, a, b, n ,m);
    printf("Mang a vua nhap la: ");
    inMang(a, n);
    printf("Mang b vua nhap la: ");
    inMang(b, m);
    timMax(a, n);
    timMin(b, m);
    printf("Mang a sau khi sap xep tang dan: ");
    sapXep(a, n);
    inMang(a, n);
    printf("Mang b sau khi sap xep tang dan: ");
    sapXep(b, m);
    inMang(b, m);
    fclose(f);
    free(a); free(b);
    printf("\nDa giai phong bo nho!\n");
    
    return 0;
}
void nhapDuLieu(FILE *f, int *a, int *b, int n, int m){
    for(int i=0; i<n; i++){
        fscanf(f, "%d", &a[i]);
    }
    for(int j=0; j<m; j++){
        fscanf(f, "%d", &b[j]);
    }
    printf("Nhap du lieu thanh cong!\n");
}
void inMang(int *arr, int soLuong){
    for(int i=0; i<soLuong; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}
void timMax(int *a, int n){
    int max = -1e9;
    for(int i=0; i<n; i++){
        if(a[i]>max){
            max = a[i];
        }
    }
    printf("Phan tu lon nhat trong mang a la: %d\n", max);
}
void timMin(int *b, int m){
    int min = 1e9;
    for(int i=0; i<m; i++){
        if(b[i]<min){
            min = b[i];
        }
    }
    printf("Phan tu nho nhat trong mang b la: %d\n", min);
}
void sapXep(int *arr, int soLuong){
    for(int i=0; i<soLuong-1; i++){
        for(int j=i+1; j<soLuong; j++){
            if(arr[i]>arr[j]){
                int temp = arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
    }
}