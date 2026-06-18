#include <stdio.h>
#include <stdlib.h>

void docDuLieu(FILE *f, int *a, int *b, int n, int m);
void tapHopGiao(int *a, int *b, int *c, int n, int m, int *p);
void sapXepVaIn(int *c, int p);

int main(){
    int n=0, m=0, p=0;
    FILE *f= fopen("taphop.txt", "r");
    if(f==NULL){
        printf("Loi: Mo file khong thanh cong!\n");
        return 1;
    }
    if(fscanf(f, "%d %d", &n, &m)!=2){
        printf("Loi: Dinh dang mang A va B khong hop le!\n");
        fclose(f);
        return 1;
    }
    int *a = (int *)malloc(n * sizeof(int));
    int *b = (int *)malloc(m * sizeof(int));
    int *c = (int *)malloc(n * sizeof(int));
    if(a==NULL || b==NULL || c==NULL){
        printf("Loi: Cap phat bo nho khong thanh cong!\n");
        fclose(f);
        return 1;
    }
    docDuLieu(f, a, b, n ,m);
    tapHopGiao(a, b, c, n, m, &p);
    sapXepVaIn(c, p);
    
    fclose(f);
    free(a);
    free(b);
    free(c);
    printf("\nDa giai phong bo nho!\n");
    
    return 0;
}
void docDuLieu(FILE *f, int *a, int *b, int n, int m){
    for(int i=0; i<n; i++){
        fscanf(f, "%d", &a[i]);
    }
    for(int j=0; j<m; j++){
        fscanf(f, "%d", &b[j]);
    }
    printf("Doc du lieu thanh cong!\n");
    printf("Mang A gom cac phan tu: ");
    for(int i=0; i<n; i++){
        printf("%d ", a[i]);
    }
    printf("\n");
    printf("Mang B gom cac phan tu: ");
    for(int j=0; j<m; j++){
        printf("%d ", b[j]);
    }
    printf("\n");
}

void tapHopGiao(int *a, int *b, int *c, int n, int m, int *p){
    *p = 0;
    printf("\nTap hop giao cua hai mang A va B gom cac phan tu: ");
    for(int i=0; i<n; i++){
        int trungLap = 0;
        //dung 1 vong lap xet trong mang A 
        //tim trong mang A xem phan tu tiep theo co giong no khong, 
        //neu giong thi dung vong lap lai de nhay sang phan tu tiep theo 
        for(int k=0; k<i; k++){
            if(a[i]==a[k]){
                trungLap = 1;
                break;
            }
        }
        if(trungLap){
            continue;
        }
        for(int j=0; j<m; j++){
            if(a[i]==b[j]){
                printf("%d ", a[i]);
                c[*p] = a[i]; // luu tat ca phan tu tap hop giao cua A va B vao C
                (*p)++; // tang kich thuoc C len 1
                //dung lenh break de tranh phan tu trung lap o mang B
                break;
            }
        }
    }
    printf("\n");
}
void sapXepVaIn(int *c, int p){
    for(int i=0; i<p-1; i++){
        for(int j=i+1; j<p; j++){
            if(c[i]>c[j]){
                int temp = c[i];
                c[i]=c[j];
                c[j]=temp;
            }
        }
    }
    printf("\nCac phan tu trong tap hop giao cua A va B sau khi sap xep theo thu tu tang dan la: ");
    for(int i=0; i<p; i++){
        printf("%d ", c[i]);
    }
}
