#ifndef MYTIME_H
#define MYTIME_H

// 시간 정보를 저장하는 구조체
struct MyTime {
    int hours;
    int minutes;
    int seconds;
};

// ① 값을 반환하는 방식
// 두 시간 t1과 t2를 더한 결과를 반환
MyTime addTime(MyTime t1, MyTime t2);

// ② 참조 전달 방식
// 결과를 참조 변수 t3에 저장
void addTime(MyTime t1, MyTime t2, MyTime& t3);

// ③ 포인터 전달 방식
// 결과를 포인터 pt가 가리키는 위치에 저장
void addTime(MyTime t1, MyTime t2, MyTime* pt);

#endif // MYTIME_H
