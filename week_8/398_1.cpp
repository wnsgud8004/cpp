//1.Sample 객체의 개수를 관리하는 정적 변수 Count와 출력을 해주는 함수 pritcounto를 구현하라.
//2.생성자 Sample(const char* name)에서 클래스 Sample의 name을 this와 new 키워 드를 이용하여 초기화하라.
//3.클래스 Sample의 소멸자 ~Sample()을 만들어라. 소멸자에는 Char* name을 동적해 제 시켜주는 코드를 작성하라.
//4.클래스 Sample의 복사 생성자를 만들어라.

#include <iostream>
#include <cstring> // strcpy, strlen 사용

class Sample {
private:
    char* name;                  // 문자열 이름 (동적 할당)
    static int count;            // 객체 개수를 저장하는 정적 멤버

public:
    // 기본 생성자
    Sample() {
        name = nullptr;
        count++;
    }

    // 생성자 (문자열로 초기화, new 사용)
    Sample(const char* name) {
        this->name = new char[strlen(name) + 1];  // 문자열 공간 동적 할당
        strcpy(this->name, name);                // 문자열 복사
        count++;
    }

    // 복사 생성자
    Sample(const Sample& other) {
        this->name = new char[strlen(other.name) + 1];
        strcpy(this->name, other.name);
        count++;
    }

    // 소멸자 (동적 메모리 해제)
    ~Sample() {
        delete[] name;
        count--;
    }

    // 정적 멤버 함수: 객체 수 출력
    static void printCount() {
        std::cout << "Sample 객체 수: " << count << std::endl;
    }

    // 디버깅용 출력 함수
    void printName() const {
        std::cout << "이름: " << (name ? name : "없음") << std::endl;
    }
};

// 정적 변수 초기화
int Sample::count = 0;

int main() {
    Sample::printCount(); // 현재 객체 수 확인

    Sample a("sample");   // 생성자 호출
    a.printName();
    Sample::printCount(); // 1

    Sample b(a);          // 복사 생성자 호출
    b.printName();
    Sample::printCount(); // 2

    return 0; // 소멸자 자동 호출
}
