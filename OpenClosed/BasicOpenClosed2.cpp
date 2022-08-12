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

//고객에 추가 요구 사항이 발생 했다 
//Cow와 Sheep을 추가해 달라고 했다 .
//이것을 해결 하기 위해서 어떻게 해야 하는가?
void hey(Animal& animal) {
    if (animal.getType() == "Cat") {
        cout << "야옹~~~" << endl;
    }
    else if (animal.getType() == "Dog") {
        cout << "멍멍멍~~~" << endl;

    }
    //추가된 부분 --> Open Close 위반임 
    else if (animal.getType() == "Cow") {
        cout << "음매 음매~~" << endl;
    }
    else if (animal.getType() == "Sheep") {
        cout << "매~~ 매~~" << endl;
    }
}


int main(int argc, char** args) {
    Animal bingo("Dog");
    Animal kitty("Cat");

    hey(bingo);
    hey(kitty);
    //추가된 부분 
    Animal cow("Cow");
    Animal sheep("Sheep");
    hey(cow);
    hey(sheep);

    return 0;
}

//고객에 추가 요구 사항이 발생 했다 
//Cow와 Sheep을 추가해 달라고 했다 .
//이것을 해결 하기 위해서 어떻게 해야 하는가?