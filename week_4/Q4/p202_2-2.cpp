//(2) 체커보드를 보기 좋게 화면에 출력하는 함수를 구현
 //void printmap(int[5][5]);

#include <iostream>  
#include <cstdlib>   
#include <ctime>    

// 5x5 크기의 2차원 배열을 0과 1의 랜덤한 값으로 채우는 함수
void randomap(int arr[5][5]) {
    srand(time(0));  // 현재 시간을 기준으로 난수 생성 시드(seed) 설정

    // 5x5 배열을 순회하면서 0 또는 1을 랜덤하게 채움
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            arr[i][j] = rand() % 2;  // 0 또는 1을 랜덤하게 선택
        }
    }
}

// 5x5 배열을 보기 좋게 출력하는 함수
void printMap(int arr[5][5]) {
    std::cout << "   0 1 2 3 4" << std::endl; // 열 번호(0~4) 출력
    std::cout << "  -------------" << std::endl; // 구분선 출력

    for (int i = 0; i < 5; i++) {
        std::cout << i << " | "; // 행 번호(0~4) 출력
        for (int j = 0; j < 5; j++) {
            if (arr[i][j] == 1)
                std::cout << "■ "; // 1일 경우 검은색 블록 출력
            else
                std::cout << "□ "; // 0일 경우 흰색 블록 출력
        }
        std::cout << std::endl; // 한 행이 끝나면 줄바꿈
    }
}

int main() {
    int board[5][5];  // 5x5 크기의 배열 선언

    randomap(board);  // 배열을 랜덤한 0과 1로 채우는 함수 호출

    std::cout << "체커보드 생성 결과:" << std::endl;
    printMap(board);  // 생성된 배열을 보기 좋은 형식으로 출력

    return 0;  // 프로그램 정상 종료
}
