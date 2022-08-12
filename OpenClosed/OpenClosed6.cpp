// OpenClosed.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
#include <stdlib.h>
#include <iostream>
#include <string>
#include <vector>
#include <functional>


// 특별화, static, 명시적인 표현, 값
// 일반화, dynamic, indirect

using namespace std;
enum class Color { RED, GREEN, BLUE };
enum class Size { SMALL, MEDIUM, LARGE };

struct Product {
    string name;
    Color color;
    Size size;
};

bool isColorEqual(Color color) {
    return color == Color::GREEN;
}

//bool (*p)(Color);
//bool (*p)(Color&);->함수포인터 변수
//bool (*)(Color&);  -> 함수포인터 타입 
//function<bool(Color&)> c++ function class 를 이용한 함수 포인터 선언 
////bool (*p)(T&);

//람다를 이용한 좀더 나은 필터를 구현한다 
template<typename T>
struct BetterFitler {
    vector<T> filter(vector<T> items, function<bool(T&)> is_satisfied) {
        vector<T> result;
        for (auto item : items) {
            if (is_satisfied(item)) {
                result.push_back(item);
            }
        }
        return result;
    }
};


int arr[] = { 5,2,6,8,3,6,8 };
int arr2[] = { 5,2,6,8,3,6,8 };
int arr3[] = { 5,2,6,8,3,6,8 };
int arr4[] = { 5,2,6,8,3,6,8 };
int compare(const void* s1, const void* s2) {
    const int* v1 = (const int*)s1;
    const int* v2 = (const int*)s2;
    return (*v1 - *v2);
}

void test() {
    qsort(arr, 7, sizeof(int), compare);

    qsort(arr, 7, sizeof(int), [](const void* s1, const void* s2)
        { return (*(const int*)s1 - *(const int*)s2); }
    );
}

int main()
{
    //for (auto& v : arr) {
    //    cout << " => " << v << endl;
    //}

    //cout << "\n\n\n";
    //qsort(arr, 7, sizeof(int), compare);
    //qsort(arr2, 7, sizeof(int), compare);
    //qsort(arr3, 7, sizeof(int), compare);
    //qsort(arr4, 7, sizeof(int), compare);

    //qsort(arr, 7, sizeof(int), [](const void* s1, const void* s2) {
    //    return (*(const int*)s1 - *(const int*)s2);
    //    });
    //qsort(arr2, 7, sizeof(int), [](const void* s1, const void* s2) {
    //    return (*(const int*)s1 - *(const int*)s2);
    //    });
    //qsort(arr3, 7, sizeof(int), [](const void* s1, const void* s2) {
    //    return (*(const int*)s1 - *(const int*)s2);
    //    });
    //qsort(arr4, 7, sizeof(int), [](const void* s1, const void* s2) {
    //    return (*(const int*)s1 - *(const int*)s2);
    //    });

    //auto compare2 = [](const void* s1, const void* s2) {
    //    return (*(const int*)s1 - *(const int*)s2);
    //};

    //qsort(arr, 7, sizeof(int), compare2);
    //qsort(arr2, 7, sizeof(int), compare2);
    //qsort(arr3, 7, sizeof(int), compare2);
    //qsort(arr4, 7, sizeof(int), compare2);

    //for (auto& v : arr) {
    //    cout << " => " << v << endl;
    //}

    Product apple{ "사과", Color::GREEN, Size::SMALL };
    Product tree{ "나무", Color::GREEN, Size::LARGE };
    Product house{ "말", Color::BLUE, Size::LARGE };
    vector<Product> all;
    all.emplace_back(apple);
    all.emplace_back(tree);
    all.emplace_back(house);

    BetterFitler<Product> betterFilter;

    auto greenItems = betterFilter.filter(all, [](Product& item) {return item.color == Color::GREEN; });
    for (const auto& item : greenItems) {
        cout << item.name << " is green" << endl;
    }

    auto sizeItems = betterFilter.filter(all, [](Product& item) {return item.size == Size::LARGE; });
    for (const auto& item : sizeItems) {
        cout << item.name << " is large" << endl;
    }

    auto colorSizeItems = betterFilter.filter(all, [](Product& item) {return item.color == Color::GREEN && item.size == Size::LARGE; });
    for (const auto& item : colorSizeItems) {
        cout << item.name << " is large and green" << endl;
    }


}