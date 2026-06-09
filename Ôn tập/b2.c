// Câu 1-1 (5 điểm). Mảng một chiều Cho tệp văn bản dayso.txt chứa thông tin về một dãy số nguyên. 
// Dòng đầu tiên chứa số nguyên $n$ là số phần tử của dãy. 
// Dòng thứ hai chứa $n$ số nguyên phân tách nhau bằng dấu cách. 
// Hãy viết chương trình thực hiện:
// Đọc dữ liệu từ tệp vào mảng. 
// Tính trung bình cộng các số lẻ trong dãy.
// Đếm xem có bao nhiêu số nguyên tố xuất hiện trong mảng.
// Sắp xếp dãy theo thứ tự giảm dần và in kết quả ra màn hình.
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void docVaInMang(FILE *f, int *a, int n);
void tbcSoLe(int *a, int n);
int checkSnt(int x);
void demSoNguyenTo(int *a, int n);
void sapXepGiamDan(int *a, int n);

int main(){
    int n=0;
    FILE *f = fopen("dayso.txt", "r");
    if(f==NULL){
        printf("Loi: Mo file khong thanh cong !\n");
        return 1;
    }
    if(fscanf(f, "%d", &n)!=1){
        printf("Loi: Vui long nhap duy nhat 1 so!\n");
        return 1;
    }
    int *a = (int *)malloc(n*sizeof(int));
    if(a==NULL){
        printf("Loi: Cap phat khong thanh cong!\n");
        fclose(f);
        return 1;
    }
    docVaInMang(f, a, n);
    tbcSoLe(a, n);
    demSoNguyenTo(a, n);
    sapXepGiamDan(a, n);
    fclose(f);
    free(a);
    return 0;
}

void docVaInMang(FILE *f, int *a, int n){
    printf("Mang vua nhap gom %d phan tu la: ", n);
    for(int i=0; i<n; i++){
        fscanf(f, "%d", &a[i]);
        printf("%d ", a[i]);
    }
    printf("\n");
}

void tbcSoLe(int *a, int n){
    int dem=0, tong=0;
    for(int i=0; i<n; i++){
        if(a[i]%2!=0){
            tong+=a[i];
            dem++;
        }
    }
    if(dem>0){
        printf("Trung binh cong cac so le trong mang la: %.2f\n", (float)tong/dem);
    }else{
        printf("Khong co so le trong mang!\n");
    }
}

int checkSnt(int x){
    if(x<2){
        return 0;
    }else{
        for(int i=2; i<=sqrt(x); i++){
            if(x%i==0){
                return 0;
            }
        }
        return 1;
    }
}
void demSoNguyenTo(int *a, int n){
    int demSnt=0;
    for(int i=0; i<n; i++){
        if(checkSnt(a[i])){
            demSnt++;
        }
    }
    if(demSnt > 0){
        printf("Co %d so nguyen to trong mang!\n", demSnt);
    }else{
        printf("Khong co so nguyen to nao trong mang!\n");
    }
}

void sapXepGiamDan(int *a, int n){
    //Dung thuat toan sap xep noi bot(bubble sort)
    for(int i=0; i<n-1; i++){
        for(int j=i+1; j<n; j++){
            if(a[i]<a[j]){
                int temp = a[i];
                a[i]=a[j];
                a[j]=temp;
            }
        }
    }
    printf("Mang sau khi sap xep theo thu tu giam dan la: ");
    for(int i=0; i<n; i++){
        printf("%d ", a[i]);
    }
    printf("\n");
}


