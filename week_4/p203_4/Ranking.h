#ifndef RANKING_H
#define RANKING_H

#include <string>
#include <vector>
#include <fstream>
#include <ctime>

class Ranking {
private:
    // 랭킹 기록을 저장하는 구조체
    struct GameRecord {
        std::string playerName;  // 플레이어 이름
        int moves;               // 게임에 사용된 이동 횟수
        time_t gameTime;         // 게임 종료 시간
    };
    
    std::vector<GameRecord> records;  // 게임 기록을 저장할 벡터
    
    // 랭킹 파일에서 기록을 불러오는 함수
    void loadRankingFromFile(const std::string& filename);
    
    // 랭킹 파일에 기록을 저장하는 함수
    void saveRankingToFile(const std::string& filename);
    
    // 기록들을 이동 횟수에 따라 오름차순 정렬하는 함수
    void sortRecords();
    
public:
    // 기본 생성자
    Ranking();
    
    // 새로운 기록을 추가하는 함수
    void addRecord(const std::string& playerName, int moves, time_t gameTime);
    
    // 랭킹을 화면에 출력하는 함수
    void displayRanking() const;
    
    // 랭킹을 파일에 저장하는 함수
    void saveRanking(const std::string& filename);
    
    // 랭킹을 파일에서 불러오는 함수
    void loadRanking(const std::string& filename);
};

#endif // RANKING_H
