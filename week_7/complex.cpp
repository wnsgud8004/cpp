//a = 1+2i, b = 3+4i, c = ?
//5가지 함수 구현

#include <iostream>
using namespace std;

// 복소수 클래스 정의
class Complex {
private:
    double real; // 실수부
    double imag; // 허수부

public:
    // 생성자
    Complex(double r = 0.0, double i = 0.0) : real(r), imag(i) {}

    // 복소수 출력 함수
    void print() const {
        cout << real << " + " << imag << "i\n";
    }

    // 3. 멤버 함수 (void, 참조 전달)
    void add(Complex& a, Complex& b) {
        real = a.real + b.real;
        imag = a.imag + b.imag;
    }

    // 4. 멤버 함수 (return, 참조 전달)
    Complex add(const Complex& other) const {
        return Complex(real + other.real, imag + other.imag);
    }

    // 5. 연산자 오버로딩
    Complex operator+(const Complex& other) const {
        return Complex(real + other.real, imag + other.imag);
    }

    // 실수부 접근 함수
    double getReal() const { return real; }

    // 허수부 접근 함수
    double getImag() const { return imag; }
};

// 1. 일반 함수 (void, 참조 전달)
// a와 b를 더한 결과를 c에 저장
void add(const Complex& a, const Complex& b, Complex& c) {
    c = Complex(a.getReal() + b.getReal(), a.getImag() + b.getImag());
}

// 2. 일반 함수 (return, 값 전달)
// a와 b를 더한 결과를 반환
Complex add(Complex a, Complex b) {
    return Complex(a.getReal() + b.getReal(), a.getImag() + b.getImag());
}

int main() {
    // 복소수 객체 a = 1 + 2i, b = 3 + 4i, c는 결과 저장용
    Complex a(1, 2), b(3, 4), c;

    cout << "[1. 일반 함수 (void, 참조 전달)]\n";
    add(a, b, c);   // a + b 결과를 c에 저장
    c.print();

    cout << "[2. 일반 함수 (return, 값 전달)]\n";
    c = add(a, b);  // add 함수의 반환값을 c에 저장
    c.print();

    cout << "[3. 멤버 함수 (void, 참조 전달)]\n";
    c.add(a, b);    // 멤버 함수로 a + b 결과를 c에 저장
    c.print();

    cout << "[4. 멤버 함수 (return, 참조 전달)]\n";
    c = a.add(b);   // a.add(b) 결과를 c에 저장
    c.print();

    cout << "[5. 연산자 오버로딩]\n";
    c = a + b;      // 연산자 오버로딩으로 a + b
    c.print();

    return 0;
}
