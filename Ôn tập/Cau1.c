//Bài 1: 
//Cho tệp văn bản (tên tệp nhập từ bàn phím) chứa các phần tử ma trận số nguyên m*n
//Tệp có cấu trúc như sau: 
//Dòng đầu là số phần tử (kích thước ma trận) m và n
//Dòng tiếp theo là các phần tử của ma trận
//- Yêu cầu hãy tạo các hàm thực hiện yêu cầu sau: 
//+ Đọc ma trận từ tệp đó và in ra màn hình
//+ Tính trung bình cộng các phần tử có giá trị không âm của ma trận
//+ Tìm giá trị lớn nhất của ma trận và in ra vị trí của nó
//+ ...
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void docVaInMaTran(FILE *f, int **a, int m, int n);
void trungBinh(int **a, int m, int n);
void findMax(int **a, int m, int n);
void giaiPhongBoNho(int **a, int m);

int main(){
	int m=0, n=0;
	char tenTep[256]="";
	printf("Nhap ten tep(vi du input.txt): ");
	scanf("%256s", tenTep);
	getchar();

	FILE *f = fopen(tenTep, "r");
	if(f==NULL){
		printf("Loi: Mo file khong thanh cong!\n");
		return 1;	
	}
	if (fscanf(f, "%d %d", &m, &n) != 2){
		printf("Loi: Dinh dang ma tran khong hop le!\n");
		fclose(f);
		return 1;
	}
	int **a = (int **)malloc(m*sizeof(int *));
	if(a==NULL){
		printf("Loi: Cap phat bo nho khong thanh cong!\n");
		fclose(f);
		return 1;
	}
	for(int i=0; i<m; i++){
		a[i] = (int *)malloc(n*sizeof(int));
		if(a[i] == NULL){
			printf("Loi: Cap phat bo nho khong thanh cong!\n");
			fclose(f);
			return 1;
		}
	}
	docVaInMaTran(f, a, m ,n);
	fclose(f);
	trungBinh(a, m, n);
	findMax(a, m, n);
	giaiPhongBoNho(a, m);
	
	return 0;
}
void docVaInMaTran(FILE *f, int **a, int m, int n){
	printf("Ma tran vua nhap la:\n");
	for(int i=0; i<m; i++){
		for(int j=0; j<n; j++){
			fscanf(f, "%d", &a[i][j]);
			printf("%d\t", a[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}
void trungBinh(int **a, int m, int n){
	int dem=0;
	int tong=0;
	for(int i=0; i<m ;i++){
		for(int j=0; j<n; j++){
			if(a[i][j]>=0){
				tong+=a[i][j];
				dem++;
			}
		}
	}
	if(dem>0){
		printf("Trung binh cac phan tu khong am cua ma tran la: %.2f\n", (float)tong/dem);
	}else{
		printf("Khong co phan tu khong am trong ma tran!\n");
	}
}
void findMax(int **a, int m, int n){
	int max=a[0][0];
	for(int i=0; i<m; i++){
		for(int j=0; j<n; j++){
			if(a[i][j]>max){
				max=a[i][j];	
			}
		}
	}
	printf("Gia tri lon nhat trong ma tran la: %d\n", max);
	printf("Vi tri cua phan tu lon nhat trong ma tran la:\n");
	for(int i=0; i<m; i++){
		for(int j=0; j<n; j++){
			if(a[i][j]==max){
				printf("(Hang %d, Cot %d)\n", i+1, j+1);
			}
		}
	}
	printf("\n");
}
void giaiPhongBoNho(int **a, int m){
	for(int i=0; i<m; i++){
		free(a[i]);
	}
	free(a);
	printf("Da giai phong bo nho!\n");
}