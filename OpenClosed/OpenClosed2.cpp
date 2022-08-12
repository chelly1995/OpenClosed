// OpenClosed.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;
enum class Color {RED, GREEN, BLUE};
enum class Size {SMALL, MEDIUM, LARGE};

struct Product {
    string name;
    Color color;
    Size size;
};

struct ProductFilter {
    static vector<Product> by_color(vector<Product> items, Color color) {
        vector<Product> result;
        for (auto item : items) {
            if (item.color == color) {
                result.push_back(item);
            }
        }
        return result;
    }
    //고객의 요청으로 size에 대한 필터링 기능 추가 
    static vector<Product> by_size(vector<Product> items, Size size) {
        vector<Product> result;
        for (auto& item : items) {
            if (item.size == size) {
                result.push_back(item);
            }
        }
        return result;
    }
    //고객의 요청으로 color와 size에 대한 필터링 기능 추가 
    static vector<Product> by_size(vector<Product> items, Color color, Size size) {
        vector<Product> result;
        for (auto& item : items) {
            if (item.color == color && item.size == size) {
                result.push_back(item);
            }
        }
        return result;
    }

};

int main()
{
    Product apple{ "사과", Color::GREEN, Size::SMALL };
    Product tree{ "나무", Color::GREEN, Size::LARGE };
    Product house{ "말", Color::BLUE, Size::LARGE };
    vector<Product> all{ apple , tree, house };

    vector<Product> greenItems = ProductFilter::by_color(all, Color::GREEN);
    for (const auto& item : greenItems) {
        cout << item.name << " is green" << endl;
    }

    vector<Product> largeItems = ProductFilter::by_size(all, Size::LARGE);
    for (const auto& item : largeItems) {
        cout << item.name << " is Large size" << endl;
    }
}

