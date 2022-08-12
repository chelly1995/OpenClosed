// OpenClosed.cpp : �� ���Ͽ��� 'main' �Լ��� ���Ե˴ϴ�. �ű⼭ ���α׷� ������ ���۵ǰ� ����˴ϴ�.
#include <stdlib.h>
#include <iostream>
#include <string>
#include <vector>
#include <functional>


// Ư��ȭ, static, ������� ǥ��, ��
// �Ϲ�ȭ, dynamic, indirect

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
//bool (*p)(Color&);->�Լ������� ����
//bool (*)(Color&);  -> �Լ������� Ÿ�� 
//function<bool(Color&)> c++ function class �� �̿��� �Լ� ������ ���� 
////bool (*p)(T&);

//���ٸ� �̿��� ���� ���� ���͸� �����Ѵ� 
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

    Product apple{ "���", Color::GREEN, Size::SMALL };
    Product tree{ "����", Color::GREEN, Size::LARGE };
    Product house{ "��", Color::BLUE, Size::LARGE };
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