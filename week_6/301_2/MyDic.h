#ifndef MYDIC_H
#define MYDIC_H

#include <string>
using namespace std;

#define MAXWORDS 100

// 하나의 단어 쌍을 위한 구조체
struct WordPair {
    string eng; // 영어 단어
    string kor; // 한글 설명
};

// 나만의 단어장 클래스
class MyDic {
    WordPair words[MAXWORDS];  // 저장된 단어 배열
    int nWords;                // 현재 등록된 단어의 수

public:
    MyDic();  // 생성자

    void add(string eng, string kor);          // 하나의 단어 추가
    void load(string filename);                // 파일에서 단어 읽기
    void store(string filename);               // 파일에 단어 저장
    void print();                              // 모든 단어 출력
    string getEng(int id);                     // id번째 영어 단어 반환
    string getKor(int id);                     // id번째 한글 설명 반환
};

#endif // MYDIC_H
