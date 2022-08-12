// OpenClosed.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;
enum class Color { RED, GREEN, BLUE };
enum class Size { SMALL, MEDIUM, LARGE };

struct Product {
    string name;
    Color color;
    Size size;
};

//조건을 비교할 수 있는 템플릿 클래스 선언 
template <typename T>
struct Specification {
    virtual bool is_satisfied(T item) const = 0;
};

//목록을 대상으로 하여 조건에 맞는 자료를 찾을 수 있는 템플릿 필터 기능 클래스 
template<typename T>
struct Filter {
    virtual vector<T> filter(vector<T> items, Specification<T>& spec) = 0;
};

//좀더 나은 필터를 구현한다 
template<typename T>
struct BetterFitler : Filter<T> {
    vector<T> filter(vector<T> items, Specification<T>& spec) override {
        vector<T> result;
        for (auto item : items) {
            if (spec.is_satisfied(item)) {
                result.push_back(item);
            }
        }
        return result;
    }
};

template<typename T>
struct ColorSpecification : Specification<T> {
    Color color;
    explicit ColorSpecification(Color color) : color(color) {}

    virtual bool is_satisfied(T item) const override {
        return item.color == color;
    }
};

template<typename T>
struct SizeSpecification : Specification<T> {
    Size size;
    explicit SizeSpecification(Size size) : size(size) {}

    virtual bool is_satisfied(T item) const override {
        return item.size == size;
    }
};

int main()
{
    Product apple{ "사과", Color::GREEN, Size::SMALL };
    Product tree{ "나무", Color::GREEN, Size::LARGE };
    Product house{ "말", Color::BLUE, Size::LARGE };
    vector<Product> all;
    all.emplace_back(apple);
    all.emplace_back(tree);
    all.emplace_back(house);

    BetterFitler<Product> betterFilter;
    ColorSpecification<Product> green(Color::GREEN);

    vector<Product> greenItems = betterFilter.filter(all, green);
    for (const auto& item : greenItems) {
        cout << item.name << " is green" << endl;
    }

    SizeSpecification<Product> large(Size::LARGE);

    vector<Product> largeItems = betterFilter.filter(all, large);
    for (const auto& item : largeItems) {
        cout << item.name << " is large" << endl;
    }
}
