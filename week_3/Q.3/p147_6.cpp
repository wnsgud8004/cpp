#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "p147_6.h"  // 헤더 파일 포함
#include <math.h>     // pow() 함수 사용을 위해 추가

#define TOTAL_QUESTIONS 10  // 총 문제 개수

// 구구단 곱셈 문제 함수
int playGuguOnce()
{
    int num1, num2, answer, user_input;
    num1 = rand() % 8 + 2;  // 2~9 사이의 랜덤 숫자 생성
    num2 = rand() % 8 + 2;
    answer = num1 * num2;

    printf("%d × %d = ? ", num1, num2);
    scanf("%d", &user_input);

    return user_input == answer;  // 정답 여부 반환
}

// 두 자리 수 곱셈 문제 함수
int playTwoDigitMultiplication()
{
    int num1, num2, answer, user_input;
    num1 = rand() % 90 + 10;  // 10~99 사이의 랜덤 숫자 생성
    num2 = rand() % 90 + 10;
    answer = num1 * num2;

    printf("%d × %d = ? ", num1, num2);
    scanf("%d", &user_input);

    return user_input == answer;  // 정답 여부 반환
}

// n자리 수 덧셈 문제 함수
int playAddition(int digits)
{
    int num1, num2, answer, user_input;
    int base = pow(10, digits - 1);  // 해당 자리 수의 최소값 계산
    num1 = rand() % base + base;  // digits 자리 수의 랜덤 숫자 생성
    num2 = rand() % base + base;
    answer = num1 + num2;

    printf("%d + %d = ? ", num1, num2);
    scanf("%d", &user_input);

    return user_input == answer;  // 정답 여부 반환
}

int main()
{
    int choice, i;
    time_t start_time, end_time;

    srand(time(NULL));  // 랜덤 시드 초기화

    // 게임 선택 메뉴 출력
    printf("게임을 선택하세요:\n");
    printf("1: 구구단 곱셈\n");
    printf("2: 두 자리 수 곱셈\n");
    printf("3~9: 해당 자리 수의 덧셈\n");
    printf("선택: ");
    scanf("%d", &choice);

    // 입력값 검증
    if (choice < 1 || choice > 9)
    {
        printf("잘못된 입력입니다. 프로그램을 종료합니다.\n");
        return 1;
    }

    start_time = time(NULL);  // 게임 시작 시간 기록

    for (i = 0; i < TOTAL_QUESTIONS; i++)
    {
        int correct = 0;

        // 선택한 게임 모드 실행
        if (choice == 1)
            correct = playGuguOnce();
        else if (choice == 2)
            correct = playTwoDigitMultiplication();
        else
            correct = playAddition(choice);

        // 오답 처리
        if (!correct)
        {
            printf("오답입니다! 게임에서 탈락했습니다.\n");
            return 1;
        }
        printf(" 정답!\n");
    }

    end_time = time(NULL);  // 게임 종료 시간 기록
    int total_time = (int)(end_time - start_time);  // 총 소요 시간 계산
    
    // 점수 계산 (기본 100점, 시간당 감점)
    int score = 100 - (total_time / 2);
    if (score < 0) score = 0;

    // 최종 결과 출력
    printf("\n 모든 문제를 맞혔습니다!\n");
    printf(" 총 소요 시간: %d초\n", total_time);
    printf(" 최종 점수: %d점\n", score);

    return 0;
}