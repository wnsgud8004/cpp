//(3) 가로나 세로 또는 대각선이 모두 0이거나 1인 부분을 찾아 화면으로 출력하는 함수 구현
 //void checkmap(int[5][5]);
 
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
    std::cout << "체커보드:" << std::endl;
    
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            std::cout << arr[i][j] << " ";  // 배열의 값을 출력
        }
        std::cout << std::endl;  // 행이 끝날 때 줄바꿈
    }
}

// 연속된 0 또는 1이 있는 행, 열, 대각선을 검사하는 함수
void checkmap(int arr[5][5]) {
    bool found = false;  // 일치하는 행, 열, 대각선이 있는지 여부를 저장하는 변수

    // 가로(행) 검사
    for (int i = 0; i < 5; i++) {
        if ((arr[i][0] == arr[i][1] && arr[i][1] == arr[i][2] &&
             arr[i][2] == arr[i][3] && arr[i][3] == arr[i][4])) {
            std::cout << "행 " << i << "이(가) 모두 " << arr[i][0] << " 입니다." << std::endl;
            found = true;
        }
    }

    // 세로(열) 검사
    for (int j = 0; j < 5; j++) {
        if ((arr[0][j] == arr[1][j] && arr[1][j] == arr[2][j] &&
             arr[2][j] == arr[3][j] && arr[3][j] == arr[4][j])) {
            std::cout << "열 " << j << "이(가) 모두 " << arr[0][j] << " 입니다." << std::endl;
            found = true;
        }
    }

    // 왼쪽 위 → 오른쪽 아래 (`\` 대각선) 검사
    if ((arr[0][0] == arr[1][1] && arr[1][1] == arr[2][2] &&
         arr[2][2] == arr[3][3] && arr[3][3] == arr[4][4])) {
        std::cout << "대각선 (\\)이 모두 " << arr[0][0] << " 입니다." << std::endl;
        found = true;
    }

    // 왼쪽 아래 → 오른쪽 위 (`/` 대각선) 검사
    if ((arr[4][0] == arr[3][1] && arr[3][1] == arr[2][2] &&
         arr[2][2] == arr[1][3] && arr[1][3] == arr[0][4])) {
        std::cout << "대각선 (/)이 모두 " << arr[4][0] << " 입니다." << std::endl;
        found = true;
    }

    // 일치하는 행, 열, 대각선이 없을 경우
    if (!found) {
        std::cout << "모두 0이거나 1인 행, 열, 대각선이 없습니다." << std::endl;
    }
}

int main() {
    int board[5][5];  // 5x5 크기의 배열 선언

    randomap(board);  // 배열을 랜덤한 0과 1로 채우는 함수 호출
    printMap(board);  // 생성된 배열을 보기 좋은 형식으로 출력

    std::cout << "\n연속된 0 또는 1을 찾는 결과:" << std::endl;
    checkmap(board);  // 연속된 0 또는 1이 있는 행, 열, 대각선을 검사하는 함수 호출

    return 0;  // 프로그램 정상 종료
}


