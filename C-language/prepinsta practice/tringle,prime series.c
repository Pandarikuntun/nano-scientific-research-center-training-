#include <stdio.h>

int checkPrime(int num) {
    if (num <= 1) return 0;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) return 0;
    }
    return 1;
}

int main() {
    int rows, i, j, current_num = 2;

    printf("Enter the number of rows: ");
    scanf("%d", &rows);

    for (i = 1; i <= rows; i++) {
      
         

        
        for (j = 1; j <= i; j++) {
            while (!checkPrime(current_num)) {
                current_num++;
            }
            printf("%3d", current_num);
            current_num++;
        }
        printf("\n");
    }

    return 0;
}

