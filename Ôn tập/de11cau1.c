#include <stdio.h>
#include <stdlib.h>

void docDuLieu(FILE *f, int **a, int *n, int *k);
void dichTrai(int *a, int n, int k);
void inMang(int *a, int n);

int main(){
    FILE *f = fopen("rotate.txt", "r");
    if(f==NULL){
        printf("Loi: Mo file khong thanh cong!\n");
        return 1;
    }
    int n=0, k=0;
    int *a = NULL;
    docDuLieu(f, &a, &n, &k);
    printf("Mang ban dau: ");
    inMang(a, n);
    dichTrai(a, n, k);
    printf("\nMang sau khi dich chuyen mang sang trai %d vi tri la: ", k);
    inMang(a, n);
    fclose(f);
    free(a);
    printf("\nDa giai phong bo nho!\n");

    return 0;
}
void docDuLieu(FILE *f, int **a, int *n, int *k){
    if(fscanf(f, "%d %d", n, k)!=2){
        printf("Loi: Doc n va k khong thanh cong!\n");
        fclose(f);
        exit(1);
    }
    *a = (int *)malloc((*n)*sizeof(int));
    if(*a==NULL){
        printf("Loi: Cap phat khong thanh cong!\n");
        fclose(f);
        exit(1);
    }
    for(int i=0; i<*n; i++){
        fscanf(f, "%d", &(*a)[i]);
    }
    printf("Doc du lieu thanh cong!\n");
}
void dichTrai(int *a, int n, int k){
    k=k%n;//ep k ve so du cua n de tranh viec dich trai thua vong
    //vi du dich trai 12 vi tri voi n=5 thi tuc la chay 2 vong n va dich 2 o thi lay so du cua k chia n cho de
    if(k==0){
        return;//neu k = n thi tuc la giu nguyen mang khong doi
    }
    for(int i=0; i<k; i++){
        //danh dau phan tu dau tien lam moc
        int flag = a[0];
        //dich phan tu len 1 don vi, bao nhieu k thi dich bay nhieu don vi
        for(int j=0; j<n-1; j++){
            a[j]=a[j+1];
        }
        a[n-1]=flag;//dich chuyen xong gan phan tu cuoi cung len phan tu dau tien
        //1 2 3 4 5 dchuyen 2 vi tri
        //lan dich chuyen 1(chay tu a[0]->a[3], chua lai a[4] tuc la so 5):
        // 2 3 4 5 5 -> dich chuyen 1 don vi xong gan a[n-1] = flag (a[0]) 
        //mang luc nay la: 2 3 4 5 1
        //tuong tu voi lan dich chuyen thu 2
    }
}
void inMang(int *a, int n){
    for(int i=0; i<n; i++){
        printf("%d ", a[i]);
    }
    printf("\n");
}