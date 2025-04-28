#ifndef MYTIME_H
#define MYTIME_H

#include <iostream>
#include <iomanip> // setw, setfill 사용 위해 추가

class MyTime {
private:
    int hours;
    int minutes;
    int seconds;
    int millisec; // 밀리초(millisecond) 추가

public:
    // 기본 생성자 + 매개변수 생성자 (초기화 리스트 사용)
    MyTime(int h = 0, int m = 0, int s = 0, int ms = 0)
        : hours(h), minutes(m), seconds(s), millisec(ms) {}

    //  새로 추가: 실수형 초(duration)를 받아 초기화하는 생성자
    MyTime(double duration) {
        int totalMillisec = static_cast<int>(duration * 1000); // 초를 밀리초로 변환
        hours = totalMillisec / (3600 * 1000);
        minutes = (totalMillisec % (3600 * 1000)) / (60 * 1000);
        seconds = (totalMillisec % (60 * 1000)) / 1000;
        millisec = totalMillisec % 1000;
    }

    inline void convert(double duration);      // 초를 시:분:초로 변환
    inline void print() const;                 // 시간 출력
    inline MyTime add(MyTime t);               // 시간 덧셈
    inline void reset();                       // 시간 초기화
    inline void read();                        // 사용자 입력
};

// 초 단위(duration)를 시:분:초로 변환 (멤버에 저장)
inline void MyTime::convert(double duration) {
    int totalMillisec = static_cast<int>(duration * 1000);
    hours = totalMillisec / (3600 * 1000);
    minutes = (totalMillisec % (3600 * 1000)) / (60 * 1000);
    seconds = (totalMillisec % (60 * 1000)) / 1000;
    millisec = totalMillisec % 1000;
}

// 시간 출력 (hh:mm:ss.mmm 형식)
inline void MyTime::print() const {
    using std::cout;
    using std::setfill;
    using std::setw;

    cout << setfill('0') << setw(2) << hours << ":"
         << setw(2) << minutes << ":"
         << setw(2) << seconds << "."
         << setw(3) << millisec << "\n";
}

// 두 MyTime 객체를 더한 결과 반환
inline MyTime MyTime::add(MyTime t) {
    MyTime result;
    result.millisec = millisec + t.millisec;
    result.seconds = seconds + t.seconds + result.millisec / 1000;
    result.minutes = minutes + t.minutes + result.seconds / 60;
    result.hours = hours + t.hours + result.minutes / 60;
    result.millisec %= 1000;
    result.seconds %= 60;
    result.minutes %= 60;
    return result;
}

// 시간 초기화
inline void MyTime::reset() {
    hours = minutes = seconds = millisec = 0;
}

// 사용자 입력 받기
inline void MyTime::read() {
    std::cout << "시(hour): "; std::cin >> hours;
    std::cout << "분(minute): "; std::cin >> minutes;
    std::cout << "초(second): "; std::cin >> seconds;
    std::cout << "밀리초(millisecond): "; std::cin >> millisec;
}

#endif

//
// ===== 메인 함수 (초기화 리스트 버전 + double 생성자 테스트) =====
//
int main() {
    MyTime t1(1, 30, 15, 250); // 정수형 매개변수 생성자 사용
    MyTime t2;

    std::cout << "[t2 입력]\n";
    t2.read();

    MyTime t3 = t1.add(t2); // 두 시간 합치기

    std::cout << "\n[t1 + t2 결과]\n";
    t3.print();

    std::cout << "\n[t3 초기화 후 출력]\n";
    t3.reset();
    t3.print();

    std::cout << "\n[3661초 변환 테스트]\n";
    t3.convert(3661);
    t3.print();

    //  실수형 초 입력 테스트 (예: 7322.789초 -> 시:분:초:밀리초 변환)
    std::cout << "\n[실수형 초 입력 테스트]\n";
    MyTime t4(7322.789);
    t4.print();

    return 0;
}
