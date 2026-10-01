
#include <stdio.h>
#include <string.h>

#define MAX 50

int main(void) {
    char dsMaPhieu[MAX][20];
    char dsMaSV[MAX][20];
    int dsSoNgay[MAX];
    double dsTienPhat[MAX];
    int dsTrangThai[MAX];

    int soLuong = 0;
    int luaChon;

    do {
        printf("\n========== HE THONG QUAN LY PHI PHAT ==========\n");
        printf("1. Them moi phieu phat qua han\n");
        printf("2. Hien thi danh sach & Thong ke tai chinh\n");
        printf("3. Cap nhat phieu phat\n");
        printf("4. Xoa phieu phat (Da thanh toan)\n");
        printf("5. Thoat\n");
        printf("================================================\n");
        printf("Chon chuc nang (1-5): ");
        scanf("%d", &luaChon);

        switch (luaChon) {

            // CASE 1: THEM MOI PHIEU PHAT
            case 1: {
                if (soLuong >= MAX) {
                    printf("Danh sach phieu phat da day!\n");
                    break;
                }

                char maMoi[20];
                int trung = 0;

                printf("\n--- THEM MOI PHIEU PHAT ---\n");
                printf("Nhap ma phieu muon: ");
                scanf("%19s", maMoi);

                // Kiem tra ma phieu trung lap
                for (int i = 0; i < soLuong; i++) {
                    if (strcmp(dsMaPhieu[i], maMoi) == 0) {
                        trung = 1;
                        break;
                    }
                }

                if (trung == 1) {
                    printf("Ma phieu da ton tai!\n");
                    break;
                }

                strcpy(dsMaPhieu[soLuong], maMoi);

                printf("Nhap ma sinh vien: ");
                scanf("%19s", dsMaSV[soLuong]);

                printf("Nhap so ngay qua han: ");
                scanf("%d", &dsSoNgay[soLuong]);

                if (dsSoNgay[soLuong] <= 0) {
                    printf("So ngay qua han phai lon hon 0!\n");
                    break;
                }

                // Tinh tien phat luy tien
                if (dsSoNgay[soLuong] <= 7) {
                    dsTienPhat[soLuong] = dsSoNgay[soLuong] * 5000;
                } else {
                    dsTienPhat[soLuong] =
                        (7 * 5000) + ((dsSoNgay[soLuong] - 7) * 10000);
                }

                // Mac dinh chua thanh toan
                dsTrangThai[soLuong] = 0;

                printf("\n[Thanh cong] Da them phieu phat %s.\n",
                       dsMaPhieu[soLuong]);
                printf("Tien phat: %.1f VND\n",
                       dsTienPhat[soLuong]);
                printf("Trang thai: Chua thanh toan.\n");

                soLuong++;

                break;
            }

            // CASE 2: HIEN THI DANH SACH VA THONG KE
            case 2: {
                if (soLuong == 0) {
                    printf("Danh sach phieu phat dang rong!\n");
                    break;
                }

                double tongDaThu = 0;
                double tongNo = 0;

                printf("\n================ DANH SACH PHIEU PHAT ================\n");
                printf("%-5s %-15s %-15s %-12s %-20s %-20s\n",
                       "STT", "Ma phieu", "Ma SV", "So ngay",
                       "Tien phat (VND)", "Trang thai");

                for (int i = 0; i < soLuong; i++) {
                    printf("%-5d %-15s %-15s %-12d %-20.1f %-20s\n",
                           i + 1,
                           dsMaPhieu[i],
                           dsMaSV[i],
                           dsSoNgay[i],
                           dsTienPhat[i],
                           dsTrangThai[i] == 1
                               ? "Da thanh toan"
                               : "Chua thanh toan");

                    if (dsTrangThai[i] == 1) {
                        tongDaThu += dsTienPhat[i];
                    } else {
                        tongNo += dsTienPhat[i];
                    }
                }

                printf("=======================================================\n");
                printf("Tong tien phat da thu: %.1f VND\n", tongDaThu);
                printf("Tong tien phat con no: %.1f VND\n", tongNo);

                break;
            }

            // CASE 3: CAP NHAT PHIEU PHAT
            case 3: {
                if (soLuong == 0) {
                    printf("Danh sach phieu phat dang rong!\n");
                    break;
                }

                char maCanTim[20];
                int pos = -1;

                printf("\n--- CAP NHAT PHIEU PHAT ---\n");
                printf("Nhap ma phieu muon can cap nhat: ");
                scanf("%19s", maCanTim);

                // Tim kiem tuyen tinh
                for (int i = 0; i < soLuong; i++) {
                    if (strcmp(dsMaPhieu[i], maCanTim) == 0) {
                        pos = i;
                        break;
                    }
                }

                if (pos == -1) {
                    printf("Khong tim thay ma phieu nay trong he thong!\n");
                    break;
                }

                printf("\nTim thay phieu: %s\n", dsMaPhieu[pos]);
                printf("1. Cap nhat so ngay qua han\n");
                printf("2. Xac nhan thanh toan\n");
                printf("Chon thao tac: ");

                int thaoTac;
                scanf("%d", &thaoTac);

                if (thaoTac == 1) {
                    int ngayMoi;

                    printf("Nhap so ngay qua han moi: ");
                    scanf("%d", &ngayMoi);

                    if (ngayMoi <= 0) {
                        printf("So ngay qua han phai lon hon 0!\n");
                        break;
                    }

                    dsSoNgay[pos] = ngayMoi;

                    // Tinh lai tien phat
                    if (ngayMoi <= 7) {
                        dsTienPhat[pos] = ngayMoi * 5000;
                    } else {
                        dsTienPhat[pos] =
                            (7 * 5000) + ((ngayMoi - 7) * 10000);
                    }

                    printf("Cap nhat thanh cong!\n");
                    printf("So ngay qua han moi: %d\n", dsSoNgay[pos]);
                    printf("Tien phat moi: %.1f VND\n", dsTienPhat[pos]);

                } else if (thaoTac == 2) {
                    if (dsTrangThai[pos] == 1) {
                        printf("Phieu nay da duoc thanh toan truoc do!\n");
                    } else {
                        dsTrangThai[pos] = 1;
                        printf("Xac nhan thanh toan thanh cong!\n");
                        printf("So tien da thu: %.1f VND\n",
                               dsTienPhat[pos]);
                    }

                } else {
                    printf("Lua chon khong hop le!\n");
                }

                break;
            }

            // CASE 4: XOA PHIEU PHAT
            case 4: {
                if (soLuong == 0) {
                    printf("Danh sach phieu phat dang rong!\n");
                    break;
                }

                char maCanXoa[20];
                int pos = -1;

                printf("\n--- XOA PHIEU PHAT ---\n");
                printf("Nhap ma phieu muon can xoa: ");
                scanf("%19s", maCanXoa);

                // Tim vi tri can xoa
                for (int i = 0; i < soLuong; i++) {
                    if (strcmp(dsMaPhieu[i], maCanXoa) == 0) {
                        pos = i;
                        break;
                    }
                }

                if (pos == -1) {
                    printf("Khong tim thay ma phieu nay trong he thong!\n");
                    break;
                }

                // Chi cho xoa phieu da thanh toan
                if (dsTrangThai[pos] == 0) {
                    printf("Khong the xoa phieu phat CHUA thanh toan de tranh meo mo so sach tai chinh!\n");
                    break;
                }

                // Don cac mang sang trai
                for (int i = pos; i < soLuong - 1; i++) {
                    strcpy(dsMaPhieu[i], dsMaPhieu[i + 1]);
                    strcpy(dsMaSV[i], dsMaSV[i + 1]);
                    dsSoNgay[i] = dsSoNgay[i + 1];
                    dsTienPhat[i] = dsTienPhat[i + 1];
                    dsTrangThai[i] = dsTrangThai[i + 1];
                }

                soLuong--;

                printf("Xoa phieu phat thanh cong!\n");

                break;
            }

            // CASE 5: THOAT
            case 5:
                printf("Cam on ban da su dung he thong!\n");
                break;

            default:
                printf("Lua chon khong hop le! Vui long chon lai.\n");
        }

    } while (luaChon != 5);

    return 0;
}