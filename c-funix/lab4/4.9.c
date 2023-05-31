#include <stdio.h>

int main() {
    unsigned int id_nhan_vien;
    printf("Nhap id nhan vien: ");
    scanf("%u", &id_nhan_vien);

    unsigned int so_gio_lam_viec;
    printf("Nhap so gio lam viec: ");
    scanf("%u", &so_gio_lam_viec);

    unsigned int tien_luong_moi_gio;
    printf("Nhap tien luong moi gio: ");
    scanf("%u", &tien_luong_moi_gio);

    printf("\nID nhan vien: %d", id_nhan_vien);
    printf("\nTien luong thang: %d\n", so_gio_lam_viec * tien_luong_moi_gio);
    return 0;
}
