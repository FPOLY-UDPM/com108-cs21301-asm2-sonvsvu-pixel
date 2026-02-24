/******************************************************************************
 * Họ và tên: [Nguyễn Trường Sơn]
 * MSSV:      [PS48636]
 * Lớp:       [COM108 - CS21302]
 *****************************************************************************/

// Tạo file asm2.c và hoàn thiện nội dung Assignment từ nội dung file asm1.c


// Danh sách các chức năng trong ASM1:
// 1. Chức năng số 1: Kiểm tra số nguyên
// 2. Chức năng số 2. Tìm Ước số chung và bội số chung của 2 số 
// 3. Chức năng số 3: Chương trình tính tiền cho quán Karaoke
// 4. Chức năng số 4: Tính tiền điện 
// 5. Chức năng số 5: Chức năng đổi tiền 
// 6. Chức năng số 6: Xây dựng chức năng tính lãi suất vay ngân hàng vay trả góp 
// 7. Chức năng số 7: Xây dựng chương trình vay tiền mua xe
// 8. Chức năng số 8: Sắp xếp thông tin sinh viên
// 9. Chức năng số 9: Xây dựng game FPOLY-LOTT
// 10. Chức năng số 10: Xây dựng chương trình tính toán phân số 
// Viết chương trình C thực hiện các chức năng trên


#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>

// ================= CHỨC NĂNG 1 =================
void kiemTraSoNguyen() {
    float n;

    printf("Nhap so: ");
    scanf("%f", &n);

    if (n - (int)n == 0)
        printf("Day la so nguyen\n");
    else
        printf("Day la so thuc\n");
}

    // Kiem tra so nguyen to
    int laSNT = 1;
    if (n < 2) laSNT = 0;

    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            laSNT = 0;
            break;
        }
    }

    if (laSNT)
        printf("La so nguyen to\n");
    else
        printf("Khong phai so nguyen to\n");
}

// ================= CHỨC NĂNG 2 =================
int UCLN(int a, int b) {
    a = abs(a);
    b = abs(b);
    while (b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

void ucln_bcnn() {
    int a, b;
    printf("Nhap 2 so: ");
    scanf("%d%d", &a, &b);

    if (a == 0 || b == 0) {
        printf("UCLN = %d\n", abs(a + b));
        printf("BCNN = 0\n");
        return;
    }

    int ucln = UCLN(a, b);
    int bcnn = abs(a * b) / ucln;

    printf("UCLN = %d\n", ucln);
    printf("BCNN = %d\n", bcnn);
}

// ================= CHỨC NĂNG 3 =================
void tinhTienKaraoke() {
    int gioVao, gioRa;
    printf("Nhap gio vao (12-23): ");
    scanf("%d", &gioVao);
    printf("Nhap gio ra (12-23): ");
    scanf("%d", &gioRa);

    if (gioVao < 12 || gioRa > 23 || gioRa <= gioVao) {
        printf("Gio khong hop le!\n");
        return;
    }

    int gio = gioRa - gioVao;
    int tien;

    if (gio <= 3)
        tien = gio * 50000;
    else
        tien = 3 * 50000 + (gio - 3) * 35000;

    printf("Tien phai tra: %d VND\n", tien);
}

// ================= CHỨC NĂNG 4 =================
void tinhTienDien() {
    int kwh;
    printf("Nhap so dien: ");
    scanf("%d", &kwh);

    int tien = 0;

    if (kwh <= 50)
        tien = kwh * 1678;
    else if (kwh <= 100)
        tien = 50 * 1678 + (kwh - 50) * 1734;
    else if (kwh <= 200)
        tien = 50 * 1678 + 50 * 1734 + (kwh - 100) * 2014;
    else
        tien = 50 * 1678 + 50 * 1734 + 100 * 2014 + (kwh - 200) * 2536;

    printf("Tien dien: %d VND\n", tien);
}

// ================= CHỨC NĂNG 5 =================
void doiTien() {
    int tien;
    printf("Nhap so tien: ");
    scanf("%d", &tien);

    int menhGia[] = {500000,200000,100000,50000,20000,10000,5000,2000,1000};

    for (int i = 0; i < 9; i++) {
        int soTo = tien / menhGia[i];
        if (soTo > 0) {
            printf("%d to %d\n", soTo, menhGia[i]);
            tien %= menhGia[i];
        }
    }
}

// ================= CHỨC NĂNG 6 =================
void vayTraGop() {
    double tienVay;
    double laiSuat = 0.05;

    printf("Nhap so tien vay: ");
    scanf("%lf", &tienVay);

    double gocHangThang = tienVay / 12;
    double duNo = tienVay;

    printf("Thang | Goc | Lai | Du no\n");

    for (int i = 1; i <= 12; i++) {
        double lai = duNo * laiSuat;
        duNo -= gocHangThang;

        printf("%5d | %8.0lf | %8.0lf | %8.0lf\n",
               i, gocHangThang, lai, duNo);
    }
}

// ================= CHỨC NĂNG 7 =================
void vayMuaXe() {
    double giaXe;
    printf("Nhap gia xe: ");
    scanf("%lf", &giaXe);

    double traTruoc = giaXe * 0.3;
    double tienVay = giaXe - traTruoc;

    printf("Tra truoc: %.0lf\n", traTruoc);
    printf("Tien vay: %.0lf\n", tienVay);
}

// ================= CHỨC NĂNG 8 =================
void sapXepSinhVien() {
    int n;
    printf("Nhap so sinh vien: ");
    scanf("%d", &n);

    char ten[50][50];
    float diem[50];

    for (int i = 0; i < n; i++) {
        printf("Nhap ten: ");
        scanf("%s", ten[i]);
        printf("Nhap diem: ");
        scanf("%f", &diem[i]);
    }

    for (int i = 0; i < n-1; i++) {
        for (int j = i+1; j < n; j++) {
            if (diem[i] < diem[j]) {
                float tmp = diem[i];
                diem[i] = diem[j];
                diem[j] = tmp;

                char t[50];
                strcpy(t, ten[i]);
                strcpy(ten[i], ten[j]);
                strcpy(ten[j], t);
            }
        }
    }

    printf("\nDanh sach sau khi sap xep:\n");
    for (int i = 0; i < n; i++) {
        printf("%s - %.1f\n", ten[i], diem[i]);
    }
}

// ================= CHỨC NĂNG 9 =================
void fpolyLott() {
    srand(time(NULL));

    int soMay = rand() % 10;
    int soNguoi;

    printf("Nhap so (0-9): ");
    scanf("%d", &soNguoi);

    printf("So may: %d\n", soMay);

    if (soNguoi == soMay)
        printf("Chuc mung ban da trung!\n");
    else
        printf("Chuc ban may man lan sau!\n");
}

// ================= CHỨC NĂNG 10 =================
void tinhPhanSo() {
    int a,b,c,d;

    printf("Nhap phan so 1 (a b): ");
    scanf("%d%d", &a, &b);

    printf("Nhap phan so 2 (c d): ");
    scanf("%d%d", &c, &d);

    if (b == 0 || d == 0) {
        printf("Mau so khong hop le!\n");
        return;
    }

    int tu = a*d + b*c;
    int mau = b*d;

    int ucln = UCLN(tu, mau);
    tu /= ucln;
    mau /= ucln;

    printf("Tong = %d/%d\n", tu, mau);
}

// ================= MAIN =================
int main() {
    int chon;

    do {
        printf("\n===== MENU =====\n");
        printf("1. Kiem tra so nguyen\n");
        printf("2. UCLN & BCNN\n");
        printf("3. Karaoke\n");
        printf("4. Tien dien\n");
        printf("5. Doi tien\n");
        printf("6. Vay tra gop\n");
        printf("7. Vay mua xe\n");
        printf("8. Sap xep sinh vien\n");
        printf("9. FPOLY-LOTT\n");
        printf("10. Phan so\n");
        printf("0. Thoat\n");
        printf("Chon: ");
        scanf("%d", &chon);

        switch (chon) {
            case 1: kiemTraSoNguyen(); break;
            case 2: ucln_bcnn(); break;
            case 3: tinhTienKaraoke(); break;
            case 4: tinhTienDien(); break;
            case 5: doiTien(); break;
            case 6: vayTraGop(); break;
            case 7: vayMuaXe(); break;
            case 8: sapXepSinhVien(); break;
            case 9: fpolyLott(); break;
            case 10: tinhPhanSo(); break;
        }

    } while (chon != 0);

    return 0;
}