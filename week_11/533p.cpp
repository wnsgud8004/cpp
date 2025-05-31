#include <iostream>
#include <iomanip>
using namespace std;

class TimeHMS {
private:
    int hour, min, sec;

    // 시간 단위 조정 함수
    void normalize() {
        int total = hour * 3600 + min * 60 + sec;
        if (total < 0) total = 0;
        hour = total / 3600;
        min = (total % 3600) / 60;
        sec = total % 60;
    }

public:
    TimeHMS(int h = 0, int m = 0, int s = 0) : hour(h), min(m), sec(s) {
        normalize();
    }

    // 1. + 연산자 중복
    TimeHMS operator+(const TimeHMS& other) const {
        return TimeHMS(hour + other.hour, min + other.min, sec + other.sec);
    }

    // 2. - 연산자 중복
    TimeHMS operator-(const TimeHMS& other) const {
        int total1 = hour * 3600 + min * 60 + sec;
        int total2 = other.hour * 3600 + other.min * 60 + other.sec;
        return TimeHMS(0, 0, total1 - total2);
    }

    // 3. ==, != 연산자 중복
    bool operator==(const TimeHMS& other) const {
        return hour == other.hour && min == other.min && sec == other.sec;
    }

    bool operator!=(const TimeHMS& other) const {
        return !(*this == other);
    }

    // 4. 전위 증감 연산자 중복 (++tl, --t1)
    TimeHMS& operator++() {
        hour++;
        normalize();
        return *this;
    }

    TimeHMS& operator--() {
        hour--;
        normalize();
        return *this;
    }

    // 5. 후위 증감 연산자 중복 (t1++, t1--)
    TimeHMS operator++(int) {
        TimeHMS temp = *this;
        sec++;
        normalize();
        return temp;
    }

    TimeHMS operator--(int) {
        TimeHMS temp = *this;
        sec--;
        normalize();
        return temp;
    }

    // 6. 인덱스 연산자 중복 (0:hour, 1:min, 2:sec)
    int operator[](int index) const {
        switch(index) {
            case 0: return hour;
            case 1: return min;
            case 2: return sec;
            default: return -1;
        }
    }

    // 7. int로의 형 변환
    operator int() const {
        return hour * 3600 + min * 60 + sec;
    }

    // 8. double로의 형 변환
    operator double() const {
        return hour + min / 60.0 + sec / 3600.0;
    }

    // 9. 정수 * TimeHMS (외부 함수로 friend 선언)
    friend TimeHMS operator*(int n, const TimeHMS& t);

    // 10. 입출력 연산자 중복
    friend ostream& operator<<(ostream& os, const TimeHMS& t);
    friend istream& operator>>(istream& is, TimeHMS& t);
};

// 9. 곱셈 연산자 중복
TimeHMS operator*(int n, const TimeHMS& t) {
    int total = (int)t * n;
    return TimeHMS(0, 0, total);
}

// 10. 출력 연산자
ostream& operator<<(ostream& os, const TimeHMS& t) {
    os << setfill('0') << setw(2) << t.hour << ":"
       << setw(2) << t.min << ":"
       << setw(2) << t.sec;
    return os;
}

// 입력 연산자
istream& operator>>(istream& is, TimeHMS& t) {
    is >> t.hour >> t.min >> t.sec;
    t.normalize();
    return is;
}

// 11. 테스트용 메인 함수
int main() {
    TimeHMS t1(1, 20, 30), t2(4, 35, 46), t3;

    t3 = t1 + t2;
    cout << "t1 + t2 = " << t3 << endl;

    t3 = t2 - t1;
    cout << "t2 - t1 = " << t3 << endl;

    cout << boolalpha;
    cout << "t1 == t2? " << (t1 == t2) << endl;
    cout << "t1 != t2? " << (t1 != t2) << endl;

    ++t1;
    cout << "++t1: " << t1 << endl;

    t2--;
    cout << "t2--: " << t2 << endl;

    cout << "t1[0] (hour): " << t1[0] << ", t1[1] (min): " << t1[1] << ", t1[2] (sec): " << t1[2] << endl;

    int seconds = (int)t1;
    double hours = (double)t1;
    cout << "t1 in seconds: " << seconds << ", in hours: " << fixed << setprecision(2) << hours << endl;

    TimeHMS t4 = 2 * t1;
    cout << "2 * t1 = " << t4 << endl;

    TimeHMS inputTime;
    cout << "시간 입력 (시 분 초): ";
    cin >> inputTime;
    cout << "입력된 시간: " << inputTime << endl;

    return 0;
}
