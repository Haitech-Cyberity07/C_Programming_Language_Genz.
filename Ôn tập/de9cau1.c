#include <stdio.h>
#include <stdlib.h>
//Function prototype
int timMaxBac(int a, int b);
void docDuLieu(FILE *f, int *arr, int bac);
void congDaThuc(int *a, int n, int *b, int m, int *c, int maxBac);
void inDaThuc(int *c, int maxBac);

int main(){
    int n=0, m=0;
    FILE *f = fopen("haidathuc.txt", "r");
    if(f==NULL){
        printf("Loi: Mo file khong thanh cong!\n");
        return 1;
    }
    if(fscanf(f, "%d", &n)!=1){
        printf("Loi: Dinh dang bac n cua da thuc khong hop le!\n");
        fclose(f);
        return 1;
    }
    int *a = (int *)malloc((n+1)*sizeof(int)); //da thuc bac n khi cap phat phai cong them 1 do co he so tu do
    if(a==NULL){
        printf("Loi: Cap phat khong thanh cong!\n");
        fclose(f);
        return 1;
    }
    docDuLieu(f, a, n);
    if(fscanf(f, "%d", &m)!=1){
        printf("Loi: Dinh dang bac m cua da thuc khong hop le!\n");
        fclose(f);
        return 1;
    }
    int *b = (int *)malloc((m+1)*sizeof(int)); // tuong tu nhu bac n
    if(b==NULL){
        printf("Loi: Cap phat khong thanh cong!\n");
        fclose(f);
        return 1;
    }
    docDuLieu(f, b, m);
    int maxBac = timMaxBac(n, m);
    int *c = (int *)malloc((maxBac + 1) * sizeof(int));
    if(c==NULL){
        printf("Loi: cap phat khong thanh cong!\n");
        fclose(f);
        return 1;
    }
    congDaThuc(a, n, b, m, c, maxBac);
    inDaThuc(c, maxBac);
    fclose(f);
    free(a);
    free(b);
    free(c);
    printf("\nDa giai phong bo nho!\n");

    return 0;
}
int timMaxBac(int a, int b){
    return (a>b) ? a : b;
}
void docDuLieu(FILE  *f, int *arr, int bac){
    for(int i=0; i<=bac; i++){
        //i<=bac la do co he so tu do cho nen them 1 phan tu
        fscanf(f, "%d", &arr[i]);
    }
    printf("Doc du lieu thanh cong!\n");
}
void congDaThuc(int *a, int n, int *b, int m, int *c, int maxBac){
    for(int i=0; i<=maxBac; i++){
        int heSoP = (i<=n) ? a[i] : 0;
        int heSoQ = (i<=m) ? b[i] : 0;
        c[i] = heSoP + heSoQ;
    }
    printf("Da tra he so ve da thuc R(x)!\n");
}
void inDaThuc(int *c, int maxBac){
    printf("Da thuc cua R(x) la:\n");
    printf("R(x) = ");
    for(int i=maxBac; i>=0; i--){
        if(i>0){
            printf("%dx^%d", c[i], i);
            if(c[i-1]>=0){
                printf(" + ");
            }else{
                printf(" ");
            }
        }else if(i==0){
            printf("%d", c[i]);
        }
    }
}
