#include <stdio.h>
#include <stdlib.h>

void docVaInMaTran(FILE *f, int **a, int m, int n);
void maxCheoChinh(int **a, int m, int n);
int tongTungHang(int *m, int n);
void sapXepTheoTong(int **a, int m, int n);
void giaiPhongMaTran(int **a, int m);

int main(){
    int m=0, n=0;
    FILE *f=fopen("matran.txt", "r");
    if(f==NULL){
        printf("Loi: Mo file khong thanh cong!\n");
        return 1;
    }
    if(fscanf(f, "%d %d", &m, &n)!=2){
        printf("Loi: Dinh dang ma tran khong hop le!\n");
        fclose (f);
        return 1;
    }
    int **a=(int **)malloc(m*sizeof(int *));//Cap phat cho ma tran
    if(a==NULL){
        printf("Loi: Cap phat ma tran khong thanh cong!\n");
        fclose (f);
        return 1;
    }
    for(int i=0; i<m; i++){
        a[i]=(int *)malloc(n*sizeof(int));
        if(a[i]==NULL){
            printf("Loi: Cap phat cho cac phan tu trong tung hang khong thanh cong!\n");
            fclose(f);
            return 1;
        }
    }
    docVaInMaTran(f, a, m, n);
    maxCheoChinh(a, m, n);
    sapXepTheoTong(a, m, n);
    fclose(f);
    giaiPhongMaTran(a, m);
    return 0;
}
void docVaInMaTran(FILE *f, int **a, int m, int n){
    printf("Ma tran (%d x %d):\n", m, n);
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            fscanf(f, "%d", &a[i][j]);
            printf("%5d", a[i][j]);
        }
        printf("\n"); // xuong dong sau khi in xong 1 hang
    }
    printf("\n");
}

void maxCheoChinh(int **a, int m, int n){
    int max = a[0][0];
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(i==j){
                if(a[i][j] > max){
                    max = a[i][j];
                }
            }
        }
    }
    printf("Phan tu lon nhat tren duong cheo chinh co gia tri: %d\n", max);
}
//nhan vao con tro hang va tinh tong cac phan tu cua 1 hang
int tongTungHang(int *m, int n){
    int sum=0;
    for(int j=0; j<n; j++){
        sum+=m[j];  
    }
    return sum;
}
void sapXepTheoTong(int **a, int m, int n){
    for(int i=0; i<m-1; i++){
        for(int j=i+1; j<m; j++){
            if(tongTungHang(a[i], n) > tongTungHang(a[j], n)){
                //doi cho dia chi cua 2 hang
                int *temp = a[i];
                a[i]=a[j];
                a[j]=temp;
            }
        }
    }
    printf("\nMa tran sau khi sap xep theo tong cua tung hang tang dan la:\n");
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            printf("%5d", a[i][j]);
        }
        printf("\n");
    }
}

void giaiPhongMaTran(int **a, int m){
    for(int i=0; i<m; i++){
        free(a[i]);
    }
    free(a);
    printf("\nDa giai phong bo nho!\n");
}