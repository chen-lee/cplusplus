#include <iostream>

class Fish {
public:
    bool FreshWaterFish;
    void Swim() {
        if (FreshWaterFish) std::cout << "Swims in lake" << std::endl;
        else std::cout << "Swims in sea" << std::endl;
    }
};

class Tuna: public Fish {
public:
    Tuna() {
        FreshWaterFish = false;
    }
};

class Carp: public Fish {
public:
    Carp() {
        FreshWaterFish = true;
    }
};

int main(int argc, char** argv) {
    Carp myLunch;
    Tuna myDinner;
    myLunch.Swim();
    myDinner.Swim();
    return 0;
}
