// OpenClosed.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <string>

using namespace std;

class Animal {//추상 클래스 -> 객채화 할 수 없음
public:
    //일반 함수 선언
    virtual void speak() = 0;//순수가상함수
};

void hey(Animal& animal) {
    animal.speak();
}

class Cat : public Animal {
public:
    virtual void speak() override {
        cout << "야옹~~~" << endl;
    }
};

class Dog : public Animal {
public:
    virtual void speak() override {
        cout << "멍멍멍~~~" << endl;
    }
};

int main(int argc, char** args) {
    Dog bingo;
    Cat kitty;

    hey(bingo);
    hey(kitty);

    return 0;
}
