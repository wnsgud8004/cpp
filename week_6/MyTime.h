#ifndef MYTIME_H
#define MYTIME_H

#include <iostream>

class MyTime {
private:
    int hours;
    int minutes;
    int seconds;

public:
    MyTime() : hours(0), minutes(0), seconds(0) {}

    inline void convert(double duration);       // 초 단위를 시:분:초로 변환
    inline void print() const;                  // 01:02:03 형식으로 출력
    inline MyTime add(MyTime t);                // 시간 덧셈
    inline void reset();                        // 모든 시간 0으로 초기화
    inline void read();                         // 사용자로부터 입력
};

#endif
