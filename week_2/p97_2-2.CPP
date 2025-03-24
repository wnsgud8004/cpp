#include <stdio.h>

void print_number_format(int num) {
    if (num >= 10000 || num < 0) {
        printf("0 이상 10000 미만의 숫자를 입력하세요.\n");
        return;
    }

    if (num == 0) {
        printf("0\n");
        return;
    }

    int thousands = num / 1000;
    int hundreds = (num % 1000) / 100;
    int tens = (num % 100) / 10;
    int ones = num % 10;

    int printed = 0; 

    if (thousands > 0) {
        printf("%d천", thousands);
        printed = 1;
    }
    if (hundreds > 0) {
        if (printed) printf(" ");
        printf("%d백", hundreds);
        printed = 1;
    }
    if (tens > 0) {
        if (printed) printf(" ");
        printf("%d십", tens);
        printed = 1;
    }
    if (ones > 0) {
        if (printed) printf(" ");
        printf("%d", ones);
    }
    
    printf("\n");
}

int main() {
    int num;
    printf("0 이상 10000 미만의 정수를 입력하세요: ");

    if (scanf("%d", &num) != 1) {
        printf("올바른 정수를 입력하세요.\n");
        return 1; 
    }

    print_number_format(num);

    return 0;
}
