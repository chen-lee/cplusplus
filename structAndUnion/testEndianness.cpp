#include <iostream>

#define BIGENDIAN 0
#define LITTLEENDIAN 1

int testByteOrderMethod1() {
    short int word = 0x0001;
    char *byte = (char*)&word;
    return byte[0] ? LITTLEENDIAN : BIGENDIAN;
}

union Test {
    int number;
    char s;
};

int testByteOrderMethod2() {
    Test test;
    test.number = 0x01000002;
    return test.s == 0x02;
}

int main(int argc, char **argv) {
    std::cout << testByteOrderMethod1() << std::endl;
    std::cout << testByteOrderMethod2() << std::endl;
    return 0;
}
