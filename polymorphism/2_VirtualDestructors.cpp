#include <iostream>

class Fish {
public:
    Fish() {
        std::cout << "Contructed Fish" << std::endl;
    }

    // 可以在析构函数前面加上virtual，申明为虚函数
    virtual ~Fish() {
        std::cout << "Destroyed Fish" << std::endl;
    }

    virtual void Swim() {
        std::cout << "Fish swims!" << std::endl;
    }
};

class Tuna: public Fish {
public:
    Tuna() {
        std::cout << "Contructed Tuna" << std::endl;
    }

    ~Tuna() {
        std::cout << "Destroyed Tuna" << std::endl;
    }

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
    // 如果基类指针指向派生类对象，调用运算符delete时，只会删除基类对象，也就是只会调用基类对象的析构函数
    // 使用new在自由存储区堆区申请内存
    Fish* p = new Tuna;
    delete p;
    // 在栈上初始化
    Tuna myLunch;

    return 0;
}
