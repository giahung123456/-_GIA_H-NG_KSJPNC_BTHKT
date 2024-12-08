#include <stdio.h>

int main() {
    int arr[100], n = 0, choice;

    do {
        printf("\nMENU\n");
        printf("1. Nhap so luong va gia tri cho cac phan tu\n");
        printf("2. In mang\n");
        printf("3. Dem so luong so hoan hao\n");
        printf("4. Dem so luong so nguyen to\n");
        printf("5. Tim gia tri lon thu 2\n");
        printf("6. Tim gia tri nho thu 2\n");
        printf("7. Them phan tu tai vi tri\n");
        printf("8. Xoa phan tu tai vi tri\n");
        printf("9. Sap xep mang tang dan\n");
        printf("10. Sap xep mang giam dan\n");
        printf("11. Tim kiem phan tu\n");
        printf("12. Xoa phan tu trung lap va in phan tu doc nhat\n");
        printf("13. Sap xep va hien thi so chan dung truoc, so le dung sau\n");
        printf("14. Dao nguoc mang\n");
        printf("15. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                printf("Nhap so luong phan tu: ");
                scanf("%d", &n);
                for (int i = 0; i < n; i++) {
                    printf("Nhap gia tri phan tu thu %d: ", i + 1);
                    scanf("%d", &arr[i]);
                }
                break;
            }

            case 2: {
                printf("Cac phan tu trong mang: ");
                for (int i = 0; i < n; i++) {
                    printf("%d ", arr[i]);
                }
                printf("\n");
                break;
            }

            case 3: {
                int count = 0;
                for (int i = 0; i < n; i++) {
                    int sum = 0;
                    for (int j = 1; j <= arr[i] / 2; j++) {
                        if (arr[i] % j == 0) sum += j;
                    }
                    if (sum == arr[i]) count++;
                }
                printf("So luong so hoan hao: %d\n", count);
                break;
            }

            case 4: {
                int count = 0;
                for (int i = 0; i < n; i++) {
                    int isPrime = 1;
                    if (arr[i] < 2) isPrime = 0;
                    for (int j = 2; j * j <= arr[i]; j++) {
                        if (arr[i] % j == 0) {
                            isPrime = 0;
                            break;
                        }
                    }
                    if (isPrime) count++;
                }
                printf("So luong so nguyen to: %d\n", count);
                break;
            }

            case 5: {
                if (n < 2) {
                    printf("Mang khong du phan tu.\n");
                } else {
                    int max1 = arr[0], max2 = -1;
                    for (int i = 1; i < n; i++) {
                        if (arr[i] > max1) {
                            max2 = max1;
                            max1 = arr[i];
                        } else if (arr[i] > max2 && arr[i] != max1) {
                            max2 = arr[i];
                        }
                    }
                    if (max2 == -1)
                        printf("Khong co gia tri lon thu 2.\n");
                    else
                        printf("Gia tri lon thu 2: %d\n", max2);
                }
                break;
            }

            case 6: {
              
				 int arr[100], n, min, second_min;
				
						printf("Nhap so luong phan tu: ");
				    	scanf("%d", &n);
				
				    		if (n < 2) {
				        	printf("Mang phai co it nhat 2 phan tu!\n");
				        	return 0;
				    	}
				
					    	for (int i = 0; i < n; i++) {
					        printf("Nhap gia tri phan tu thu %d: ", i + 1);
					        scanf("%d", &arr[i]);
					    	}
					
					    	min = second_min = arr[0];
					    
					    	if (arr[1] < min) {
					        	second_min = min;
					        	min = arr[1];
								    } else {
								        second_min = arr[1];
								    }
								
								    for (int i = 2; i < n; i++) {
								        if (arr[i] < min) {
								            second_min = min;
								            min = arr[i];
								        } else if (arr[i] < second_min && arr[i] != min) {
								            second_min = arr[i];
								        }
								    }
								
								    printf("Gia tri nho thu 2 trong mang la: %d\n", second_min);
								    break;
						       }

            case 7: {
                int pos, value;
                if (n == 100) {
                    printf("Mang da day. Khong the them phan tu.\n");
                } else {
                    printf("Nhap vi tri can them (0 den %d): ", n);
                    scanf("%d", &pos);
                    printf("Nhap gia tri can them: ");
                    scanf("%d", &value);
                    for (int i = n; i > pos; i--) {
                        arr[i] = arr[i - 1];
                    }
                    arr[pos] = value;
                    n++;
                    printf("Da them phan tu.\n");
                }
                break;
            }

            case 8: {
                int pos;
                printf("Nhap vi tri can xoa (0 den %d): ", n - 1);
                scanf("%d", &pos);
                for (int i = pos; i < n - 1; i++) {
                    arr[i] = arr[i + 1];
                }
                n--;
                printf("Da xoa phan tu.\n");
                break;
            }

            case 9: {
                for (int i = 0; i < n - 1; i++) {
                    for (int j = i + 1; j < n; j++) {
                        if (arr[i] > arr[j]) {
                            int temp = arr[i];
                            arr[i] = arr[j];
                            arr[j] = temp;
                        }
                    }
                }
                printf("Mang da duoc sap xep tang dan.\n");
                break;
            }

            case 10: {
                for (int i = 0; i < n - 1; i++) {
                    for (int j = i + 1; j < n; j++) {
                        if (arr[i] < arr[j]) {
                            int temp = arr[i];
                            arr[i] = arr[j];
                            arr[j] = temp;
                        }
                    }
                }
                printf("Mang da duoc sap xep giam dan.\n");
                break;
            }

            case 11: {
                int value, found = 0;
                printf("Nhap gia tri can tim: ");
                scanf("%d", &value);
                for (int i = 0; i < n; i++) {
                    if (arr[i] == value) {
                        printf("Tim thay %d tai vi tri %d.\n", value, i);
                        found = 1;
                        break;
                    }
                }
                if (!found) printf("Khong tim thay gia tri %d.\n", value);
                break;
            }

            case 12: {
                int unique[100], uniqueCount = 0;
                for (int i = 0; i < n; i++) {
                    int found = 0;
                    for (int j = 0; j < uniqueCount; j++) {
                        if (arr[i] == unique[j]) {
                            found = 1;
                            break;
                        }
                    }
                    if (!found) {
                        unique[uniqueCount++] = arr[i];
                    }
                }
                printf("Phan tu doc nhat: ");
                for (int i = 0; i < uniqueCount; i++) {
                    printf("%d ", unique[i]);
                }
                printf("\n");
                break;
            }

            case 13: {
                int even[100], odd[100], evenCount = 0, oddCount = 0;
                for (int i = 0; i < n; i++) {
                    if (arr[i] % 2 == 0) {
                        even[evenCount++] = arr[i];
                    } else {
                        odd[oddCount++] = arr[i];
                    }
                }
                printf("Cac so chan: ");
                for (int i = 0; i < evenCount; i++) {
                    printf("%d ", even[i]);
                }
                printf("\nCac so le: ");
                for (int i = 0; i < oddCount; i++) {
                    printf("%d ", odd[i]);
                }
                printf("\n");
                break;
            }

            case 14: {
                for (int i = 0; i < n / 2; i++) {
                    int temp = arr[i];
                    arr[i] = arr[n - i - 1];
                    arr[n - i - 1] = temp;
                }
                printf("Mang da duoc dao nguoc.\n");
                break;
            }

            case 15: {
                printf("Thoat chuong trinh.\n");
                break;
            }

            default:
                printf("Lua chon khong hop le. Vui long chon lai!\n");
        }
    } while (choice != 15);

    return 0;
}