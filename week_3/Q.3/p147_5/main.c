//문제: 정수를 입력받아 각 자리 숫자를 역순으로 만들어 반환하는 함수 reverse()를 구현하라 <방법5>

#include <stdio.h>   // 표준 입출력 라이브러리 포함
#include "reverse.h" // reverse 함수의 선언 포함

int main()
{
    int num; // 사용자 입력값을 저장할 변수

    // 사용자 입력 받기
    printf("정수를 입력하세요: ");
    scanf("%d", &num); // 사용자로부터 정수를 입력받아 num 변수에 저장

    // 역순 변환 및 결과 출력
    printf("역순 변환 결과: %d\n", reverse(num));

    return 0; // 프로그램 정상 종료
}
