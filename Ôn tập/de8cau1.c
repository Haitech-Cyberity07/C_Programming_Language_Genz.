#include <stdio.h>
#include <stdlib.h>

void docDuLieu(FILE *f, int *a, int n);
void mangDoiXung(int *a, int n);
void maxTongMang(int *a, int n);

int main(){
    int n=0;
    FILE *f = fopen("mangcon.txt", "r");
    if(f==NULL){
        printf("Loi: Mo file khong thanh cong!\n");
        return 1;
    }
    if(fscanf(f, "%d", &n)!=1){
        printf("Loi: Dinh dang so luong phan tu khong hop le!\n");
        fclose(f);
        return 1;
    }
    int *a = (int *)malloc(n * sizeof(int));
    if(a==NULL){
        printf("Loi: Cap phat khong thanh cong!\n");
        fclose(f);
        return 1;
    }
    docDuLieu(f, a, n);
    mangDoiXung(a, n);
    maxTongMang(a, n);
    fclose(f);

    free(a);
    printf("\nDa giai phong bo nho!\n");

    return 0;
}
void docDuLieu(FILE *f, int *a, int n){
    for(int i=0; i<n; i++){
        fscanf(f, "%d", &a[i]);
    }
    printf("Doc du lieu thanh cong!\n");
    printf("Mang trong file gom %d phan tu la: ", n);
    for(int i=0; i<n; i++){
        printf("%d ", a[i]);
    }
    printf("\n");
}
void mangDoiXung(int *a, int n){
    int doiXung = 1;
    for(int i=0; i<n/2; i++){
        if(a[i]!=a[n-1-i]){
            doiXung = 0;
            break;
        }
    }
    if(doiXung){
        printf("\nThong bao: Mang doi xung!\n");
    }else{
        printf("\nThong bao: Mang khong doi xung!\n");
    }
}
void maxTongMang(int *a, int n){
    int tongTemp = a[0]; //tongTemp de tinh toan
    int tongMax = a[0]; //tongMax de luu tru tong lon nhat se duoc in ra va cap nhat neu tongTemp > tongMax
    for(int i=1; i<n; i++){
        if(tongTemp < 0){
            tongTemp = a[i]; //neu tongTemp am thi nhay qua phan tu tiep theo de tinh (mang con moi)
        }else{
            tongTemp += a[i];//neu tongTemp khong am thi cu cong don vao
        }
        // het vong lap if-else dau tien ma tongTemp van am thi lai reset nhay toi phan tu tiep theo
        // cho den khi chay den het n ma van am thi so sanh voi tongMax , neu so am nao lon hon thi lay
        if(tongTemp > tongMax){
            tongMax = tongTemp;
        }
    }
    printf("\nTong cua mang con lien tiep lon nhat la: %d\n", tongMax);
}