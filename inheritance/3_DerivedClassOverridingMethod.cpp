#include <iostream>

class Fish {
private:
    bool FreshWaterFish;

public:
    Fish(const bool IsFreshWater): FreshWaterFish(IsFreshWater) {}

    void Swim() {
        if (FreshWaterFish) std::cout << "Swims in lake" << std::endl;
        else std::cout << "Swims in sea" << std::endl;
    }
};

class Tuna: public Fish {
public:
    Tuna(): Fish(false) {
    }

    void Swim() {
        std::cout << "Tuna swims real fast" << std::endl;
    }
};

class Carp: public Fish {
public:
    Carp(): Fish(true) {
    }

    void Swim() {
        std::cout << "Crap swims real slow" << std::endl;
    }
};

int main(int argc, char** argv) {
    Carp myLunch;
    Tuna myDinner;
    myLunch.Swim();
    myDinner.Swim();
    myDinner.Fish::Swim();
    return 0;
}
