#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct {
    char ten[50];
    float x, y;
} toado;

void input(toado *p, int n);
void output(toado *p, int n);
double tongKc(toado *p, int n);
void gocPhanTu(toado *p, int n);

int main() {
    int n;
    printf("Nhap so diem: "); scanf("%d", &n);
    getchar();

    toado *p = (toado*)malloc(n * sizeof(toado));
    if (p == NULL) { 
        printf("Khong du bo nho!\n");
        return 1;
    }

    input(p, n);
    output(p, n);

    double tong = tongKc(p, n);
    printf("Tong khoang cach tu cac diem den goc toa do: %.2lf\n", tong);

    gocPhanTu(p, n);

    free(p);
    return 0;
}

void input(toado *p, int n) {
    for (int i = 0; i < n; i++) {
        printf("Thong tin diem thu %d:\n", i + 1);
        printf("Nhap ten diem: ");
        fgets(p[i].ten, sizeof(p[i].ten), stdin);
        p[i].ten[strcspn(p[i].ten, "\n")] = '\0';
        printf("Toa do x: "); scanf("%f", &p[i].x);
        printf("Toa do y: "); scanf("%f", &p[i].y);
        getchar();
    }
    printf("\n");
}

void output(toado *p, int n) {
    for (int i = 0; i < n; i++) {
        printf("Diem thu %d: %s (%.2f, %.2f)\n", i + 1, p[i].ten, p[i].x, p[i].y);
    }
}

double tongKc(toado *p, int n) {
    double tong = 0;
    for (int i = 0; i < n; i++) {
        double d = sqrt(pow(p[i].x, 2) + pow(p[i].y, 2));
        printf("Khoang cach tu diem %s den goc toa do: %.2lf\n", p[i].ten, d);
        tong += d;
    }
    return tong;
}

void gocPhanTu(toado *p, int n) {
    int gocphantu = 0;
    printf("Nhap vao goc phan tu muon tim kiem (1-4): ");
    scanf("%d", &gocphantu);

    if (gocphantu < 1 || gocphantu > 4) { 
        printf("Goc phan tu khong hop le! Chi nhap tu 1 den 4.\n");
        return;
    }

    int dem = 0; 
    for (int i = 0; i < n; i++) {
        int thuoc = 0;
        if      (gocphantu == 1 && p[i].x > 0 && p[i].y > 0) thuoc = 1;
        else if (gocphantu == 2 && p[i].x < 0 && p[i].y > 0) thuoc = 1;
        else if (gocphantu == 3 && p[i].x < 0 && p[i].y < 0) thuoc = 1;
        else if (gocphantu == 4 && p[i].x > 0 && p[i].y < 0) thuoc = 1;

        if (thuoc) {
            printf("%s (%.2f, %.2f)\n", p[i].ten, p[i].x, p[i].y);
            dem++;
        }
    }

    if (dem == 0) 
        printf("Khong co diem nao thuoc goc phan tu thu %d.\n", gocphantu);
}