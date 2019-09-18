#include <iostream>

class FishDummyMember {
public:
    FishDummyMember() {
        std::cout << "FishDummyMember constructor" << std::endl;
    }

    ~FishDummyMember() {
        std::cout << "FishDummyMember destructor" << std::endl;
    }
};

// 实例化Fish，首先需要初始化成员，确保成员属性准备就绪，可供构造函数使用
class Fish {
private:
    FishDummyMember dummy;
    bool FreshWaterFish;

public:
    Fish() {
        std::cout << "Fish constructor" << std::endl;
    }

    ~Fish() {
        std::cout << "Fish destructor" << std::endl;
    }
};

class TunaDummyMember {
public:
    TunaDummyMember() {
        std::cout << "TunaDummyMember constructor" << std::endl;
    }

    ~TunaDummyMember() {
        std::cout << "TunaDummyMember destructor" << std::endl;
    }
};

// 首先从继承层次的顶部开始,继承的是Fish,因此实例化Fish
class Tuna: public Fish {
private:
    TunaDummyMember dummy;

public:
    Tuna() {
        std::cout << "Tuna constructor" << std::endl;
    }

    ~Tuna() {
        std::cout << "Tuna destructor" << std::endl;
    }
};


int main(int argc, char** argv) {
    Tuna myDinner;
    return 0;
}
