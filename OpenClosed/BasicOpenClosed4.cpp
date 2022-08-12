// OpenClosed.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <string>

using namespace std;

class Animal {
public:
    virtual void speak() = 0;
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


//추가된 부분 --> Open Close 문제 없음 
class Cow : public Animal {
public:
    virtual void speak() override {
        cout << "음매 음매~~" << endl;
    }
};

class Sheep : public Animal {
public:
    virtual void speak() override {
        cout << "매~~ 매~~" << endl;
    }
};

int main(int argc, char** args) {
    Dog bingo;
    Cat kitty;
    hey(bingo);
    hey(kitty);

    //추가 가능 구현 
    Cow cow;
    Sheep sheep;
    hey(cow);
    hey(sheep);

    return 0;
}
