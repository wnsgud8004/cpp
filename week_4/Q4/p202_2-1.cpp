//(1) 5x5 크기의 2차원 배열에 0과 1을 임의로 채우는 함수를 구현 
   //void randomap(int[5][5]);

#include <iostream>  
#include <cstdlib>   
#include <ctime>    

// 5x5 크기의 2차원 배열을 랜덤한 0과 1로 채우는 함수
void randomap(int arr[5][5]) {
    srand(time(0));  // 매번 실행할 때마다 다른 난수를 생성하기 위해 시드 설정

    // 5x5 배열을 순회하면서 0 또는 1을 랜덤하게 채움
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            arr[i][j] = rand() % 2;  // 0 또는 1 중 하나를 랜덤하게 선택
        }
    }
}

// 5x5 배열을 출력하는 함수
void printMap(int arr[5][5]) {
    // 배열의 모든 요소를 출력하여 체커보드 형태로 표시
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            std::cout << arr[i][j] << " ";  // 현재 요소 출력
        }
        std::cout << std::endl;  // 한 행이 끝날 때 줄바꿈
    }
}

int main() {
    int board[5][5];  // 5x5 크기의 배열 선언

    randomap(board);  // 배열을 랜덤한 0과 1로 채우는 함수 호출

    std::cout << "체커보드 생성 결과:" << std::endl;
    printMap(board);  // 생성된 배열 출력

    return 0;  // 프로그램 정상 종료
}
