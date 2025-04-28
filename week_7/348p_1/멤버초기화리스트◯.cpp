//멤버 초기화 리스트를 사용한 경우
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
    // 기본 생성자 + 매개변수 생성자 (멤버 초기화 리스트 사용)
    MyTime(int h = 0, int m = 0, int s = 0, int ms = 0)
        : hours(h), minutes(m), seconds(s), millisec(ms) {}

    inline void convert(double duration);      // 초를 시:분:초로 변환
    inline void print() const;                  // 시간 출력
    inline MyTime add(MyTime t);                // 시간 덧셈
    inline void reset();                        // 시간 초기화
    inline void read();                         // 사용자 입력
};

// 초 단위(duration)를 시:분:초로 변환
inline void MyTime::convert(double duration) {
    int total = static_cast<int>(duration);
    hours = total / 3600;
    minutes = (total % 3600) / 60;
    seconds = total % 60;
    millisec = 0;
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
// ===== 메인 함수 (초기화 리스트 버전 테스트) =====
//
int main() {
    MyTime t1(1, 30, 15, 250); // 생성자 초기화 리스트로 초기화
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

    return 0;
}
