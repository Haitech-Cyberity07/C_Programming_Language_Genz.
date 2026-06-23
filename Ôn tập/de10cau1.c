#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void docDuLieu(FILE *f, int *a, int n);
void tachMang(int *a, int n, int *c, int *l, int *chan, int *le);
void inMang(const char *tieuDe, int *arr, int n);
void sapXep(int *arr, int n, int tangDan);

int main(){
    int n=0;
    int chan=0, le=0;
    FILE  *f = fopen("chanle.txt", "r");
    if(f==NULL){
        printf("Loi: Mo file khong thanh cong!\n");
        return 1;
    }
    if(fscanf(f, "%d", &n)!=1){
        printf("Loi: Dinh dang so luong phan tu khong hop le!\n");
        fclose(f);
        return 1;
    }
    int *a = (int *)malloc(n*sizeof(int));
    int *c = (int *)malloc(n*sizeof(int));
    int *l=(int *)malloc(n*sizeof(int));
    if(a==NULL || c==NULL || l==NULL){
        printf("Loi: Cap phat khong thanh cong!\n");
        fclose(f);
        return 1;
    }
    docDuLieu(f, a, n);
    tachMang(a, n, c, l , &chan, &le);
    //sau khi tach mang thi in ra man hinh
    inMang("Mang C (chan): ", c, chan);
    inMang("Mang L (le): ", l, le);
    //sap xep mang chan tang dan va mang le giam dan
    sapXep(c, chan, 1); // 1 tuc la khac 0 -> dung -> sap xep tang dan
    sapXep(l, le, 0); // 0 tuc la = 0 -> sai -> sap xep giam dan
    //in mang sau khi sap xep
    inMang("\nMang C sau khi sap xep: ", c, chan);
    inMang("Mang L sau khi sap xep: ", l, le);  
    fclose(f);
    free(a); free(c); free(l);
    printf("\nDa giai phong bo nho!\n");

    return 0;
}
void docDuLieu(FILE *f, int *a, int n){
    for(int i=0; i<n; i++){
        fscanf(f, "%d", &a[i]);
    }
    printf("Doc du lieu thanh cong!\n");
    printf("Mang vua nhap trong file la:");
    for(int i=0; i<n; i++){
        printf("%d ", a[i]);
    }
    printf("\n");
}
void tachMang(int *a, int n, int *c, int *l, int *chan, int *le){
    for(int i=0; i<n; i++){
        if(a[i]%2==0){
            c[*chan] = a[i];
            (*chan)++;
        }else{
            l[*le] = a[i];
            (*le)++;
        }
    }
    printf("\nTach mang thanh cong!\n");
}
void inMang(const char *tieuDe, int *arr, int n){
    printf("%s", tieuDe);
    if(n==0){
        printf("Khong co phan tu nao!\n");
        return;
    }
    for(int i=0; i<n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}
void sapXep(int *arr, int n, int tangDan){
    for(int i=0; i<n-1; i++){
        for(int j=i+1; j<n; j++){
            //Neu tangDan khac 0 dung thi sap xep tang dan, neu sai thi sap xep giam dan
            if(tangDan ? (arr[i]>arr[j]) : (arr[i]<arr[j])){
                int temp = arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
    }
}