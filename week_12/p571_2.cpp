#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <stdexcept>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <termios.h>
#include <unistd.h>
using namespace std;

class Monster;

// ======================= FileException =========================
class FileException : public exception {
private:
    string filename;
    string mode; // "read" or "write"
public:
    FileException(const string& fname, const string& m)
        : filename(fname), mode(m) {}

    const char* what() const noexcept override {
        return ("FileException: Failed to " + mode + " file " + filename).c_str();
    }
};

// ======================= RankingBoard =========================
class RankingBoard {
private:
    vector<pair<string, int>> rankings;
    string filename;

public:
    RankingBoard(const string& fname) : filename(fname) {}

    void load() {
        ifstream fin(filename);
        if (!fin) throw FileException(filename, "read");

        rankings.clear();
        string name;
        int score;
        while (fin >> name >> score) {
            rankings.emplace_back(name, score);
        }
        fin.close();
    }

    void save(const string& fname = "") {
        string targetFile = fname.empty() ? filename : fname;
        ofstream fout(targetFile);
        if (!fout) throw FileException(targetFile, "write");

        for (auto& entry : rankings) {
            fout << entry.first << ' ' << entry.second << '\n';
        }
        fout.close();
    }

    void addRanking(const string& name, int score) {
        rankings.emplace_back(name, score);
        sort(rankings.begin(), rankings.end(), [](const auto& a, const auto& b) {
            return a.second > b.second;
        });
        if (rankings.size() > 10) rankings.pop_back(); // 최대 10명 유지
    }

    void print() const {
        cout << "===== 랭킹 보드 =====\n";
        for (auto& entry : rankings) {
            cout << entry.first << " : " << entry.second << '\n';
        }
    }
};

// ======================= getch 대체 구현 (Linux) =========================
char linux_getch() {
    struct termios oldt, newt;
    char ch;
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    read(STDIN_FILENO, &ch, 1);
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    return ch;
}

// ======================= Matrix, Monster 등 기존 클래스 정의 (생략) =========================
// 기존 코드에 포함된 Matrix, Monster 및 파생 클래스들은 그대로 유지됩니다.

// ======================= Main Function =========================
string inputPassword() {
    const string correct = "admin123";
    string input;
    char ch;
    cout << "관리자 비밀번호를 입력하세요: ";
    while ((ch = linux_getch()) != '\n') { // Enter 키 입력 전까지
        if (ch == '\b' || ch == 127) {
            if (!input.empty()) {
                input.pop_back();
                cout << "\b \b";
            }
        } else {
            input += ch;
            cout << '*';
        }
    }
    cout << endl;
    return input == correct ? correct : "";
}

int main() {
    srand((unsigned int)time(nullptr));
    RankingBoard board("ranking.txt");

    try {
        board.load();
    } catch (const FileException& e) {
        cerr << e.what() << endl;
        if (inputPassword() == "admin123") {
            cout << "비밀번호 인증 성공: 기본 랭킹을 생성하고 게임을 시작합니다.\n";
            board.addRanking("Default", 0);
        } else {
            cout << "비밀번호가 틀렸습니다. 프로그램을 종료합니다.\n";
            return 1;
        }
    }

    // 예시 게임 환경 (몬스터 생성 및 게임 루프 생략)
    // 예제: Monster* m = new Zombie(1, 1);
    // 게임 플레이 코드 여기에 삽입

    string playerName;
    int finalScore = 20; // 예제 점수. 실제로는 플레이어의 아이템 수로 계산

    cout << "플레이어 이름 입력: ";
    cin >> playerName;

    board.addRanking(playerName, finalScore);

    try {
        board.save();
    } catch (const FileException& e) {
        cerr << e.what() << endl;
        cout << "파일 저장 중 오류 발생. 관리자 비밀번호를 다시 입력하세요.\n";
        if (inputPassword() == "admin123") {
            string newFile;
            cout << "새로 저장할 파일 이름을 입력하세요: ";
            cin >> newFile;
            try {
                board.save(newFile);
                cout << "랭킹이 성공적으로 저장되었습니다.\n";
            } catch (const FileException& e2) {
                cerr << e2.what() << endl;
                cout << "파일 저장에 실패했습니다. 프로그램을 종료합니다.\n";
                return 1;
            }
        } else {
            cout << "비밀번호가 틀렸습니다. 프로그램을 종료합니다.\n";
            return 1;
        }
    }

    board.print();
    return 0;
}
