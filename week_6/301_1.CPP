#include "MyTime.h"
#include <iomanip>

// 초 단위 시간(duration)을 시:분:초로 변환하여 멤버 변수에 저장
inline void MyTime::convert(double duration) {
    int total = static_cast<int>(duration); // 소수점 이하 절삭
    hours = total / 3600;
    minutes = (total % 3600) / 60;
    seconds = total % 60;
}

// 시간 출력 함수: hh:mm:ss 형식으로 출력 (0 채움 포함)
inline void MyTime::print() const {
    using std::cout;
    using std::setfill;
    using std::setw;

    cout << setfill('0') << setw(2) << hours << ":"
         << setfill('0') << setw(2) << minutes << ":"
         << setfill('0') << setw(2) << seconds << "\n";
}

// 시간 더하기 함수: t1.add(t2) 형태로 사용됨. 결과는 새로운 MyTime 객체로 반환
inline MyTime MyTime::add(MyTime t) {
    MyTime result;
    result.seconds = seconds + t.seconds;
    result.minutes = minutes + t.minutes + result.seconds / 60;
    result.hours = hours + t.hours + result.minutes / 60;
    result.minutes %= 60;
    result.seconds %= 60;
    return result;
}

// 시간 초기화 함수: 모든 멤버 변수(hours, minutes, seconds)를 0으로 설정
inline void MyTime::reset() {
    hours = minutes = seconds = 0;
}

// 사용자로부터 시, 분, 초를 입력받는 함수
inline void MyTime::read() {
    std::cout << "시(hour): ";
    std::cin >> hours;
    std::cout << "분(minute): ";
    std::cin >> minutes;
    std::cout << "초(second): ";
    std::cin >> seconds;
}

//
// ======== 메인 함수 테스트 코드 ========
//
int main() {
    MyTime t1, t2, t3;

    // t1 시간 입력
    std::cout << "[t1 입력]\n";
    t1.read();

    // t2 시간 입력
    std::cout << "[t2 입력]\n";
    t2.read();

    // t1과 t2의 합을 t3에 저장
    t3 = t1.add(t2);

    // t3 출력
    std::cout << "\n[t1 + t2 결과]\n";
    t3.print();

    // t3 초기화 후 출력
    std::cout << "\n[t3 초기화 후 출력]\n";
    t3.reset();
    t3.print();

    // convert 함수 테스트: 3661초 -> 01:01:01로 변환
    std::cout << "\n[초 단위 변환 테스트: 3661초 -> 시:분:초]\n";
    t3.convert(3661);
    t3.print();

    return 0;
}
