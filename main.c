#include <stdio.h>

#define MAX_SIZE 50

void displayArray(int borrows[], int n) {
    printf("[");
    for (int i = 0; i < n; i++) {
        printf("%d", borrows[i]);
        if (i < n - 1) {
            printf(", ");
        }
    }
    printf("]\n");
}

int main() {
    int borrows[MAX_SIZE] = {12,7,20,5,16};
    int n = 5;
    int choice;

    while (1) {
        printf("\n");
        printf("=====================================================\n");
        printf("        CHUONG TRINH QUAN LY LICH MUON SACH BOOKHUB \n");
        printf("=====================================================\n");
        printf("1. Them so luot muon sach\n");
        printf("2. Sua so luot muon sach\n");
        printf("3. Xoa so luot muon sach\n");
        printf("4. Tim kiem so luot muon sach\n");
        printf("0. Thoat chuong trinh\n");
        printf("=====================================================\n");
        printf("Vui long nhap lua chon cua ban (0 - 4): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                int value, pos;

                if (n >= MAX_SIZE) {
                    printf("Mang da day, khong the them!\n");
                    break;
                }

                printf("Nhap gia tri can them: ");
                scanf("%d", &value);

                printf("Nhap vi tri can chen: ");
                scanf("%d", &pos);

                if (pos < 1 || pos > n + 1) {
                    printf("Vi tri chen khong hop le!\n");
                    break;
                }

                for (int i = n; i >= pos; i--) {
                    borrows[i] = borrows[i - 1];
                }

                borrows[pos - 1] = value;
                n++;

                printf("Mang sau khi them: ");
                displayArray(borrows, n);
                break;
            }

            case 2: {
                int pos, newValue;

                printf("Nhap vi tri can sua: ");
                scanf("%d", &pos);

                if (pos < 1 || pos > n) {
                    printf("Vi tri sua khong hop le!\n");
                    break;
                }

                printf("Nhap gia tri moi: ");
                scanf("%d", &newValue);

                if (newValue < 0) {
                    printf("So luot muon khong hop le!\n");
                    break;
                }

                borrows[pos - 1] = newValue;

                printf("Mang sau khi sua: ");
                displayArray(borrows, n);
                break;
            }

            case 3: {
                int pos;

                if (n == 0) {
                    printf("Mang rong, khong the xoa!\n");
                    break;
                }

                printf("Nhap vi tri can xoa: ");
                scanf("%d", &pos);

                if (pos < 1 || pos > n) {
                    printf("Vi tri xoa khong hop le!\n");
                    break;
                }

                for (int i = pos - 1; i < n - 1; i++) {
                    borrows[i] = borrows[i + 1];
                }

                n--;

                printf("Mang sau khi xoa: ");
                displayArray(borrows, n);
                break;
            }

            case 4: {
                int target;
                int count = 0;

                printf("Nhap gia tri can tim: ");
                scanf("%d", &target);

                printf("Tim thay tai vi tri: ");

                for (int i = 0; i < n; i++) {
                    if (borrows[i] == target) {
                        printf("%d ", i + 1);
                        count++;
                    }
                }

                if (count == 0) {
                    printf("\nKhong tim thay gia tri trong mang!\n");
                } else {
                    printf("\nTong so lan xuat hien: %d\n", count);
                }

                break;
            }

            case 0:
                printf("Thoat chuong trinh!\n");
                return 0;

            default:
                printf("Lua chon khong hop le!\n");
        }
    }

    return 0;
}