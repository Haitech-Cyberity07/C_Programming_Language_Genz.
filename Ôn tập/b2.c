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

int docFile(int *a, int n);
void tbcSoLe(int *a, int n);
void demSoNguyenTo(int *a, int n);
void sapXepGiamDan(int *a, int n);

int main(){
    int n;
    int *a = (int *)malloc(n*sizeof(int));
}
int docFile(int *a, int n){
    FILE *f=fopen("dayso.txt", "r");
    if(f==NULL){
        printf("Loi: Mo file khong thanh cong!\n");
        return 1;
    }
    fscanf(f, "%d", &n);
    for(int i=0; i<n; i++){
        fscanf(f, "%d", &a[i]);
    }
    fclose(f);
    return n;
}