//두개의 시간을 더하는 다음 함수를 다음과 같이 세 방법으로 구현하라
#include <iostream>
#include "mytime.h"
using namespace std;


// ① 값을 반환하는 방식
// 두 시간 t1, t2를 더한 결과를 새로운 MyTime 구조체에 담아 return 함.
// 함수 외부에서 결과를 받아 사용함.
MyTime addTime(MyTime t1, MyTime t2) {
    MyTime result;
    result.seconds = t1.seconds + t2.seconds;
    result.minutes = t1.minutes + t2.minutes + result.seconds / 60;
    result.hours = t1.hours + t2.hours + result.minutes / 60;
    result.minutes %= 60;
    result.seconds %= 60;
    return result;  // 계산 결과를 반환
}

// ② 참조(reference) 전달 방식
// 결과를 저장할 MyTime 객체를 참조로 전달 받아 함수 안에서 직접 수정함.
// 복사 없이 직접 접근하므로 효율적이고 안전함.
void addTime(MyTime t1, MyTime t2, MyTime& t3) {
    t3.seconds = t1.seconds + t2.seconds;
    t3.minutes = t1.minutes + t2.minutes + t3.seconds / 60;
    t3.hours = t1.hours + t2.hours + t3.minutes / 60;
    t3.minutes %= 60;
    t3.seconds %= 60;
}

// ③ 포인터(pointer) 전달 방식
// 결과를 저장할 구조체의 주소를 전달받아, 포인터를 통해 해당 구조체의 값을 직접 수정함.
// C 스타일의 전통적인 방식이며, 널 포인터 체크 등 주의가 필요함.
void addTime(MyTime t1, MyTime t2, MyTime* pt) {
    pt->seconds = t1.seconds + t2.seconds;
    pt->minutes = t1.minutes + t2.minutes + pt->seconds / 60;
    pt->hours = t1.hours + t2.hours + pt->minutes / 60;
    pt->minutes %= 60;
    pt->seconds %= 60;
}

int main() {
    MyTime t1 = {1, 45, 50}; // 첫 번째 시간
    MyTime t2 = {2, 30, 15}; // 두 번째 시간

    // ① 반환값 사용 방식 테스트
    MyTime sum1 = addTime(t1, t2); // 함수에서 결과를 반환받음
    cout << "① 반환값 사용: " << sum1.hours << ":" << sum1.minutes << ":" << sum1.seconds << endl;

    // ② 참조 방식 테스트
    MyTime sum2;
    addTime(t1, t2, sum2); // sum2를 참조로 전달 → 함수 안에서 직접 수정됨
    cout << "② 참조 전달: " << sum2.hours << ":" << sum2.minutes << ":" << sum2.seconds << endl;

    // ③ 포인터 방식 테스트
    MyTime sum3;
    addTime(t1, t2, &sum3); // sum3의 주소를 전달 → 함수 안에서 직접 수정됨
    cout << "③ 포인터 전달: " << sum3.hours << ":" << sum3.minutes << ":" << sum3.seconds << endl;

    return 0;
}
