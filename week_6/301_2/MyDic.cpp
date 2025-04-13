#include "MyDic.h"
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

// 생성자: 단어 수를 0으로 초기화
inline MyDic::MyDic() : nWords(0) {}

// 단어 추가 함수
inline void MyDic::add(string eng, string kor) {
    if (nWords < MAXWORDS) {
        words[nWords].eng = eng;
        words[nWords].kor = kor;
        nWords++;
    } else {
        cout << "단어장이 가득 찼습니다.\n";
    }
}

// 파일에서 단어장 로드 (CSV 형식: 영어,한글)
inline void MyDic::load(string filename) {
    ifstream fin(filename);
    if (!fin) {
        cerr << "파일을 열 수 없습니다.\n";
        return;
    }

    string line;
    while (getline(fin, line) && nWords < MAXWORDS) {
        istringstream iss(line);
        string eng, kor;
        getline(iss, eng, ','); // 영어 단어 (콤마 기준)
        getline(iss, kor);      // 한글 단어 (줄 끝까지)
        add(eng, kor);          // 단어 추가
    }
    fin.close();
}

// 단어장을 파일에 저장 (CSV 형식: 영어,한글)
inline void MyDic::store(string filename) {
    ofstream fout(filename);
    if (!fout) {
        cerr << "파일을 저장할 수 없습니다.\n";
        return;
    }

    for (int i = 0; i < nWords; ++i) {
        fout << words[i].eng << "," << words[i].kor << "\n";
    }

    fout.close();
}

// 단어장 전체 출력
inline void MyDic::print() {
    for (int i = 0; i < nWords; ++i) {
        cout << i + 1 << ". " << words[i].eng << " : " << words[i].kor << "\n";
    }
}

// 인덱스로 영어 단어 가져오기
inline string MyDic::getEng(int id) {
    if (id >= 0 && id < nWords) {
        return words[id].eng;
    } else {
        return "";
    }
}

// 인덱스로 한글 단어 가져오기
inline string MyDic::getKor(int id) {
    if (id >= 0 && id < nWords) {
        return words[id].kor;
    } else {
        return "";
    }
}

// 메인 함수
int main() {
    MyDic dic;

    // 단어 등록
    dic.add("apple", "사과");
    dic.add("computer", "컴퓨터");
    dic.add("book", "책");

    // 현재 단어장 출력
    cout << "\n[현재 등록된 단어 목록]\n";
    dic.print();

    // 단어장 파일로 저장
    dic.store("mydic.txt");
    cout << "\n[단어장이 파일에 저장되었습니다.]\n";

    // 새로운 객체 생성 후 파일에서 단어장 불러오기
    MyDic newDic;
    newDic.load("mydic.txt");

    // 불러온 단어장 출력
    cout << "\n[파일에서 읽은 단어 목록]\n";
    newDic.print();

    return 0;
}
