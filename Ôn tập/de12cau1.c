//So hoan hao la so ma tong cac uoc thuc su cua no (khong phai chinh no) bang chinh no
// -uoc: so ma n co the chia het duoc: n%i == 0
// -cho chay tu 1 den n: tong+=i
// -kiem tra neu tong == n va n khac 1 thi la so hoan hao(do 1 k phai so hoan hao)
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void docDuLieu(FILE *f, int *a, int n);
int soHoanHao(int n);
void demVaTinh(int *a, int n);

int main(){
    FILE *f = fopen("sohoanhao.txt", "r");
    if(f==NULL){
        printf("Loi: Mo file khong thanh cong!\n");
        return 1;
    }
    int n=0;
    if(fscanf(f, "%d", &n)!=1){
        printf("Loi: Dinh dang n khong hop le!\n");
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
    demVaTinh(a, n);
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
    printf("Mang vua nhap la: ");
    for(int i=0; i<n; i++){
        printf("%d ",a[i]);
    }
    printf("\n");
}
int soHoanHao(int n){
    int tong=1;// cho tong bang 1 thi vong lap chay tu 2 la duoc
    for(int i=2; i<n; i++){
        if(n%i==0){
            tong+=i;
        }
    }
    if(tong == n && n!=1){
        return 1;
    }
    return 0;
}
void demVaTinh(int *a, int n){
    int dem = 0;
    int tong = 0;
    for(int i=0; i<n; i++){
        if(soHoanHao(a[i])){
            if(dem==0){
                printf("\nCac so hoan hao trong mang la:");
            }
            printf("%d ", a[i]);
            dem++;
            tong+=a[i];
        }
    }
    if(dem>0){
        printf("\nCo %d so hoan hao trong mang!\n", dem);
        printf("Trung binh cong cac so hoan hao la: %.2f\n", (float)tong/dem);
    }else{
        printf("Khong co so hoan hao nao trong mang!\n");
    }
}