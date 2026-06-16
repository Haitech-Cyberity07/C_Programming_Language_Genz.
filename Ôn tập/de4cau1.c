#include <stdio.h>
#include <string.h>

void thongKeVanBan(FILE *f);

int main(){
    FILE *f=fopen("chuoi.txt", "r");
    if(f==NULL){
        printf("Loi: Mo file khong thanh cong!\n");
        return 1;
    }
    thongKeVanBan(f);
    fclose(f);
    return 0;
}

void thongKeVanBan(FILE *f){
    char tu[200]; // mang chua tam tung tu lay duoc
    char tuDaiNhat[200] = "";//mang luu ky luc tu dai nhat
    int tongSoTu = 0;
    int maxLen = 0;

    //doc du lieu tu tep
    //vong lap fscanf doc tung tu, bo qua khoang trang va xuong dong.
    while(fscanf(f, "%s", tu) == 1){
        tongSoTu++; // doc thanh cong 1 tu thi cong vao tong so tu
        int len = strlen(tu); // khai bao bien tam thoi bang dung do dai cua tu dau tien duoc doc
        if(len>maxLen){
            maxLen = len;
            strcpy(tuDaiNhat, tu); // copy noi dung cua 'tu' vao 'tuDaiNhat' coi nhu tu dau tien la tu dai nhat
        }
    }
    printf("Doc du lieu van ban thanh cong!\n");
    if(tongSoTu > 0){
        printf("Tong so tu co trong van ban la: %d\n", tongSoTu);
        printf("Tu co do dai lon nhat trong van ban la: %s (%d ky tu)\n", tuDaiNhat, maxLen);
    }else{
        printf("Van ban rong!\n");
    }
}