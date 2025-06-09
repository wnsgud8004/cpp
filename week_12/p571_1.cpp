#include <iostream>
#include <stdexcept>
using namespace std;

//  예외 클래스 1: 잘못된 입금 시 사용
class InvalidDepositException : public exception {
    int amount; // 문제의 입금 금액 저장
public:
    InvalidDepositException(int amt) : amount(amt) {}

    // 예외 설명 메시지
    const char* what() const noexcept override {
        return "잘못된 입금 금액입니다.";
    }

    // 입금 금액 반환
    int getAmount() const { return amount; }
};

//  예외 클래스 2: 출금 금액이 잔액보다 많은 경우
class InsufficientFundsException : public exception {
    int amount; // 문제의 출금 금액 저장
public:
    InsufficientFundsException(int amt) : amount(amt) {}

    // 예외 설명 메시지
    const char* what() const noexcept override {
        return "잔액보다 많은 금액을 출금하려 했습니다.";
    }

    // 출금 금액 반환
    int getAmount() const { return amount; }
};

// 고객 계좌 클래스 정의
class CustomerAccount {
    int balance; // 잔고 정보

public:
    // 생성자: 초기 잔고 설정 (기본값은 0)
    CustomerAccount(int b = 0) : balance(b) {}

    // 현재 잔고 반환
    int getBalance() { return balance; }

    //  입금 함수
    int deposit(int amount) {
        // 음수 또는 0원 입금은 예외 발생
        if (amount <= 0)
            throw InvalidDepositException(amount);

        balance += amount; // 정상 입금 처리
        return balance;
    }

    //  출금 함수
    int withdraw(int amount) {
        // 출금 금액이 잔고보다 크면 예외 발생
        if (amount > balance)
            throw InsufficientFundsException(amount);

        balance -= amount; // 정상 출금 처리
        return balance;
    }
};

//  테스트용 main 함수
int main() {
    CustomerAccount account(1000); // 잔고 1000원으로 계좌 생성

    try {
        cout << "현재 잔고: " << account.getBalance() << endl;

        // 정상 입금
        cout << "500원 입금 중..." << endl;
        account.deposit(500);
        cout << "현재 잔고: " << account.getBalance() << endl;

        // 예외: 음수 입금 시도
        cout << "-300원 입금 시도 중..." << endl;
        account.deposit(-300);
    }
    catch (const InvalidDepositException& e) {
        // 잘못된 입금 예외 처리
        cout << "[예외 발생] " << e.what() << " (입금 금액: " << e.getAmount() << ")\n";
    }

    try {
        // 예외: 잔액보다 많은 금액 출금
        cout << "2000원 출금 시도 중..." << endl;
        account.withdraw(2000);
    }
    catch (const InsufficientFundsException& e) {
        // 출금 초과 예외 처리
        cout << "[예외 발생] " << e.what() << " (출금 금액: " << e.getAmount() << ")\n";
    }

    try {
        // 정상 출금
        cout << "1000원 출금 중..." << endl;
        account.withdraw(1000);
        cout << "현재 잔고: " << account.getBalance() << endl;
    }
    catch (...) {
        // 기타 예외 처리
        cout << "알 수 없는 예외가 발생했습니다.\n";
    }

    return 0;
}
