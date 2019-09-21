#include <iostream>

// 抽象基类，可声明为纯虚函数
class Fish {
public:
    virtual void Swim() = 0;
    /*
    void Swim1() {
        std::cout << "Swim1" < std::endl;
    }
    */
    virtual ~Fish() {
        std::cout << "delete Fish" << std::endl;
    }
};

class Tuna: public Fish {
public:
    void Swim() {
        std::cout << "Tuna swims!" << std::endl;
    }

    ~Tuna() {
        std::cout << "delete Tuna" << std::endl;
    }
};

class Carp: public Fish {
public:
    void Swim() {
        std::cout << "Carp swims!" << std::endl;
    }

    ~Carp() {
        std::cout << "delete Carp" << std::endl;
    }
};

int main(int argc, char** argv) {
    // 指针
    Fish* p = new Tuna;
    p->Swim();
    delete p;
    p = new Carp;
    p->Swim();
    delete p;

    return 0;
}
