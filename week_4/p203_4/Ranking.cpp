#include "Ranking.h"
#include <iostream>
#include <algorithm>

using namespace std;

// 기본 생성자 - 파일에서 랭킹 데이터를 불러옴
Ranking::Ranking() {
    loadRankingFromFile("ranking.dat");
}

// 파일에서 랭킹 기록을 불러오는 함수
void Ranking::loadRankingFromFile(const string& filename) {
    ifstream file(filename, ios::binary);
    if (!file) return;  // 파일이 없으면 리턴
    
    GameRecord record;
    // 파일에서 기록을 하나씩 읽어서 벡터에 추가
    while (file.read(reinterpret_cast<char*>(&record), sizeof(record))) {
        records.push_back(record);
    }
    file.close();
    sortRecords();  // 랭킹 기록을 정렬
}

// 파일에 랭킹 기록을 저장하는 함수
void Ranking::saveRankingToFile(const string& filename) {
    ofstream file(filename, ios::binary);
    for (const auto& record : records) {
        file.write(reinterpret_cast<const char*>(&record), sizeof(record));  // 기록을 파일에 쓰기
    }
    file.close();
}

// 기록을 이동 횟수에 따라 오름차순 정렬하는 함수
void Ranking::sortRecords() {
    sort(records.begin(), records.end(), [](const GameRecord& a, const GameRecord& b) {
        return a.moves < b.moves;  // 이동 횟수가 적은 순으로 정렬
    });
    // 상위 10개만 유지
    if (records.size() > 10) {
        records.resize(10);
    }
}

// 새로운 게임 기록을 랭킹에 추가하는 함수
void Ranking::addRecord(const string& playerName, int moves, time_t gameTime) {
    GameRecord newRecord = {playerName, moves, gameTime};
    records.push_back(newRecord);
    sortRecords();  // 기록 정렬
}

// 랭킹을 화면에 출력하는 함수
void Ranking::displayRanking() const {
    cout << "Top 10 Rankings:\n";
    for (const auto& record : records) {
        cout << record.playerName << " - Moves: " << record.moves << " - Time: " << ctime(&record.gameTime);
    }
}

// 랭킹을 파일에 저장하는 함수
void Ranking::saveRanking(const string& filename) {
    saveRankingToFile(filename);
}

// 파일에서 랭킹을 불러오는 함수
void Ranking::loadRanking(const string& filename) {
    loadRankingFromFile(filename);
}
