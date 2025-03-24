#include <stdio.h>

void print_number_format(int num) {
    if (num >= 10000) {
        printf("10000 미만의 숫자를 입력하세요.\n");
        return;
    }
    
    int thousands = num / 1000;
    int hundreds = (num % 1000) / 100;
    int tens = (num % 100) / 10;
    int ones = num % 10;

    if (thousands > 0) {
        printf("%d천 ", thousands);
    }
    if (hundreds > 0) {
        printf("%d백 ", hundreds);
    }
    if (tens > 0) {
        printf("%d십 ", tens);
    }
    if (ones > 0 || num == 0) {
        printf("%d", ones);
    }
    
    printf("\n");
}

int main() {
    int num;
    printf("10000 미만의 정수를 입력하세요: ");
    scanf("%d", &num);
    
    print_number_format(num);
    
    return 0;
}
