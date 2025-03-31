#include <iostream>
#include <vector>
#include <fstream>
#include <ctime>
#include <algorithm>
#include "Ranking.h"  // Ranking 헤더 파일 포함

using namespace std;

class PuzzleGame {
private:
    int size;  // 퍼즐 크기
    vector<vector<int>> board;  // 퍼즐 보드
    vector<pair<int, int>> moveHistory;  // 이동 기록
    time_t startTime, endTime;  // 게임 시작 및 종료 시간
    int moveCount;  // 이동 횟수
    Ranking ranking;  // 랭킹 객체

public:
    // 생성자
    PuzzleGame(int s) : size(s), moveCount(0) {
        board.resize(size, vector<int>(size));
        initializeBoard();
        startTime = time(nullptr);
    }

    // 퍼즐 보드를 초기화하고 무작위로 섞는 함수
    void initializeBoard() {
        vector<int> numbers;
        for (int i = 0; i < size * size; ++i) {
            numbers.push_back(i);  // 숫자 0부터 size*size까지 추가
        }
        random_shuffle(numbers.begin(), numbers.end());  // 무작위 섞기
        for (int i = 0, k = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j, ++k) {
                board[i][j] = numbers[k];
            }
        }
    }

    // 퍼즐 보드를 출력하는 함수
    void displayBoard() {
        for (const auto& row : board) {
            for (int cell : row) {
                if (cell == 0)
                    cout << "   ";  // 빈 칸은 공백으로
                else
                    cout << cell << " ";  // 숫자 출력
            }
            cout << endl;
        }
    }

    // 빈 칸을 기준으로 퍼즐 조각을 움직이는 함수
    void move(int dx, int dy) {
        int emptyX, emptyY;
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                if (board[i][j] == 0) {
                    emptyX = i;
                    emptyY = j;
                }
            }
        }
        int newX = emptyX + dx;
        int newY = emptyY + dy;
        if (newX >= 0 && newX < size && newY >= 0 && newY < size) {
            swap(board[emptyX][emptyY], board[newX][newY]);  // 빈 칸과 조각을 교환
            moveHistory.push_back({dx, dy});
            moveCount++;  // 이동 횟수 증가
        }
    }

    // 게임을 저장하는 함수
    void saveGame(const string& filename) {
        ofstream file(filename, ios::binary);
        file.write(reinterpret_cast<char*>(&size), sizeof(size));
        file.write(reinterpret_cast<char*>(&moveCount), sizeof(moveCount));
        file.write(reinterpret_cast<char*>(&startTime), sizeof(startTime));
        for (const auto& row : board) {
            file.write(reinterpret_cast<const char*>(row.data()), row.size() * sizeof(int));
        }
        file.close();
    }

    // 저장된 게임을 불러오는 함수
    void loadGame(const string& filename) {
        ifstream file(filename, ios::binary);
        if (!file) {
            cout << "Failed to load game!" << endl;
            return;
        }
        file.read(reinterpret_cast<char*>(&size), sizeof(size));
        file.read(reinterpret_cast<char*>(&moveCount), sizeof(moveCount));
        file.read(reinterpret_cast<char*>(&startTime), sizeof(startTime));
        board.resize(size, vector<int>(size));
        for (auto& row : board) {
            file.read(reinterpret_cast<char*>(row.data()), row.size() * sizeof(int));
        }
        file.close();
    }

    // 게임 종료 후 랭킹 기록을 추가하는 함수
    void endGame(const string& playerName) {
        endTime = time(nullptr);
        ranking.addRecord(playerName, moveCount, endTime);  // 랭킹에 기록 추가
        ranking.saveRanking("ranking.dat");  // 랭킹 파일에 저장
        ranking.displayRanking();  // 랭킹 출력
    }
};

int main() {
    // 게임 시작
    PuzzleGame game(4);
    game.displayBoard();  // 퍼즐 보드 출력
    game.move(0, 1);  // 퍼즐 조각 움직이기
    game.move(1, 0);
    game.displayBoard();  // 다시 퍼즐 보드 출력
    game.saveGame("game_save.dat");  // 게임 저장
    
    // 게임 종료 및 랭킹 기록
    string playerName;
    cout << "Enter your name: ";
    cin >> playerName;
    game.endGame(playerName);  // 게임 종료 후 랭킹 추가 및 출력
    
    return 0;
}
