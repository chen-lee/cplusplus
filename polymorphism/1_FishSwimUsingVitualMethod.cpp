#include <iostream>

class Fish {
public:
    // 使用virtual将普通函数声明为虚函数，这样就可以使用基类的指针或者引用访问派生类的方法，避免被切除
    virtual void Swim() {
        std::cout << "Fish swims!" << std::endl;
    }
};

class Tuna: public Fish {
public:
    void Swim() {
        std::cout << "Tuna swims!" << std::endl;
    }
};

class Carp: public Fish {
public:
    void Swim() {
        std::cout << "Carp swims!" << std::endl;
    }
};

void testRef(Fish& fish) {
    fish.Swim();
}

int main(int argc, char** argv) {
    Carp myLunch;
    Tuna myDinner;
    // 指针
    Fish* p;
    p = &myLunch;
    p->Swim();
    p = &myDinner;
    p->Swim();

    // 引用
    testRef(myLunch);
    testRef(myDinner);
    return 0;
}
