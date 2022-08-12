// OpenClosed.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <string>

using namespace std;

class Animal {
private:
    string type;
public:
    Animal(string type) : type(type) {

    }
    const string& getType() const { return type; }
};

//사용하는 기능 : client 
void hey(Animal& animal) {
    if (animal.getType() == "Cat") {
        cout << "야옹~~~" << endl;
    }
    else if (animal.getType() == "Dog") {
        cout << "멍멍멍~~~" << endl;
    }
}

void main(int argc, char** args) {
    Animal bingo("Dog");
    Animal kitty("Cat");

    hey(bingo);
    hey(kitty);
}

/*
        #Cow와 Sheep을 추가하기위해 hey함수의 수정이 필요하다.

        hey(bingo)
        hey(kitty)
        */
