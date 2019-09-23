#include <iostream>
#include <string.h>

class MyString {
private:
    char* buffer;

    MyString() : buffer(NULL) {
        std::cout << "default constructor called" << std::endl;
    }

public:
    // Constructor
    MyString(const char* input) {
        std::cout << "constructor called for: " << input << std::endl;
        if (input) {
            buffer = new char[strlen(input) + 1];  // add '\0'
            strcpy(buffer, input);
        } else {
            buffer = NULL;
        }
    }

    // CopyConstructor
    MyString(const MyString& input) {
        std::cout << "copy constructor" << std::endl;
        if (input.buffer) {
            buffer = new char[strlen(input.buffer) + 1];
            strcpy(buffer, input.buffer);
        } else {
            buffer = NULL;
        }
    }

    /* 如果提供了移动构造函数，当编译器意识到创建临时拷贝的时候，将转而使用移动构造函数和移动赋值运算符
    *
    */
    // MoveConstructor
    MyString(MyString&& input) {
        std::cout << "move constructor" << std::endl;
        if (input.buffer) {
            buffer = input.buffer;
            input.buffer = NULL;
        } else {
            buffer = NULL;
        }
    }

    // Copy assignment operator
    MyString& operator = (const MyString& input) {
        std::cout << "Copy assignment operator" << std::endl;
        if ((this != &input) && (input.buffer)) {
            if (buffer) {
                delete[] buffer;
            }

            buffer = new char[strlen(input.buffer) + 1];
            strcpy(buffer, input.buffer);
        }
    }

    // move assignment operator
    MyString& operator = (MyString&& input) {
        std::cout << "Move assignment operator" << std::endl;
        if ((this != &input) && (input.buffer)) {
            if (buffer) {
                delete[] buffer;
            }

            buffer = input.buffer;
            input.buffer = NULL;
        }
        return *this;
    }

    int GetLength() {
        return strlen(buffer);
    }

    MyString operator+ (const MyString& input) {
        std::cout << "operator + called: " << std::endl;
        MyString newString;

        if (input.buffer) {
            newString.buffer = new char[GetLength() + strlen(input.buffer) + 1];
            strcpy(newString.buffer, buffer);
            strcat(newString.buffer, input.buffer);
        }

        return newString;
    }

    // Destructor
    ~MyString() {
        if (buffer != NULL) {
            std::cout << "destructor" << std::endl;
            delete[] buffer;
        }
    }

    const char* GetString() {
        return buffer;
    }

    operator const char*() {
        return buffer;
    }
};


int main(int argc, char** argv) {
    MyString Hello("hello ");
    MyString World("world");
    MyString CPP(" of C++");

    MyString sayHello("overwrite this");
    sayHello = Hello + World + CPP;
    std::cout << sayHello << std::endl;
    return 0;
}
