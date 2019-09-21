#include <iostream>

class Fish {
public:
    virtual void Swim() = 0;
    virtual ~Fish() {
        std::cout << "delete Fish" << std::endl;
    }
    virtual Fish* Clone() = 0;
};

class Tuna: public Fish {
public:
    void Swim() {
        std::cout << "Tuna swims!" << std::endl;
    }

    Fish* Clone() {
        return new Tuna(*this);
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
    Fish* p = new Tuna();
    Fish* pCopy = p->Clone();
    pCopy->Swim();
    delete p;
    delete pCopy;

    return 0;
}
