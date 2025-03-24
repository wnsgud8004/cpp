//문제: 정수를 입력받아 각 자리 숫자를 역순으로 만들어 반환하는 함수 reverse()를 구현하라 <방법2>

#include <stdio.h>  

// 함수 원형 (함수 선언) - reverse() 함수의 존재를 컴파일러에 미리 알림
int reverse(int);  

// 프로그램의 시작점 (main 함수)
int main()  
{
    int num, result;  // 사용자 입력 값(num)과 변환된 값(result)을 저장할 변수 선언

    // 사용자 입력 받기
    printf("정수를 입력하세요: ");  
    scanf("%d", &num);  // 사용자로부터 정수를 입력받아 num 변수에 저장

    // reverse() 함수 호출하여 숫자를 역순으로 변환
    result = reverse(num);

    // 변환된 결과 출력
    printf("역순 변환 결과: %d\n", result);

    return 0;  // 프로그램이 정상적으로 종료됨을 운영체제에 알림
}

// 정수를 역순으로 변환하는 함수 정의
int reverse(int num)
{
    int reversed = 0;  // 변환된 숫자를 저장할 변수

    // 입력된 숫자의 각 자리수를 추출하여 역순으로 변환
    while (num > 0)
    {
        reversed = reversed * 10 + (num % 10); // 마지막 자리를 reversed의 끝에 추가
        num /= 10;  // num에서 마지막 자리 제거
    }

    return reversed;  // 변환된 숫자 반환
}
