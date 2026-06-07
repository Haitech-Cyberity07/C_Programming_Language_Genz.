#include <stdio.h>
#include <stdlib.h>
void nhap(int *, int);
void in(int *, int);
int find_max(int *, int);
void sapxep(int *, int);

int main(){
    int n;
    printf("Vui long nhap so phan tu cua mang: ");
    scanf("%d", &n);
    int *a=(int *)malloc(n*sizeof(int));// cấp phát động
    nhap(a, n);
    in(a,n);
    printf("Gia tri lon nhat la: %d\n", find_max(a,n));
    sapxep(a,n);
    printf("Phan tu cua mang sau khi sap xep la: ");
    in(a,n);
    free(a);
    return 0;
    
}
void nhap(int *a, int n){
    for(int i=0; i<n; i++){
        printf("Nhap phan tu thu %d: ", i+1);
        scanf("%d", a+i);
    }
}
void in (int *a, int n){
    printf("Mang vua nhap la: ");
    for(int i=0; i<n; i++)
    {
        printf("%d ", *(a+i));
    }
    printf("\n");
    
}
int find_max(int *a, int n){
    int max = *a;
    for (int i=0; i<n; i++){
        if(*(a+i)>max){
            max = *(a+i);
        }
    }
    return max;
}
void sapxep(int *a, int n){
    for(int i=0; i<n-1; i++){
        for(int j=i+1; j<n; j++){
            if(*(a+i)>*(a+j)){
                int temp = *(a+i);
                *(a+i)= *(a+j);
                *(a+j) = temp;
            }
        }
    }
}
 