#include <iostream>

class Fish {
public:
    Fish() {
        std::cout << "Contructed Fish" << std::endl;
    }

    ~Fish() {
        std::cout << "Destroyed Fish" << std::endl;
    }

    virtual void Swim() {
        std::cout << "Fish swims!" << std::endl;
    }
};

class Test {
public:
    Test() {
        std::cout << "Contructed Test" << std::endl;
    }

    ~Test() {
        std::cout << "Destroyed Test" << std::endl;
    }

    void Swim() {
        std::cout << "Fish swims!" << std::endl;
    }

};

int main(int argc, char** argv) {

    std::cout << "size of Fish: " << sizeof(Fish) << std::endl;
    std::cout << "size of Test: " << sizeof(Test) << std::endl;
    return 0;
}
