#include <iostream>
#include <string.h>

class MyString {
private:
    char* buffer;

public:
    // Constructor
    MyString(const char* input) {
        if (input) {
            buffer = new char[strlen(input) + 1];  // add '\0'
            strcpy(buffer, input);
        } else {
            buffer = NULL;
        }
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
};


int main(int argc, char** argv) {
    MyString* hello = new MyString("hello world");
    std::cout << "hello: " << hello->GetString() << std::endl;
    MyString copyHello = *hello;
    delete hello;
    std::cout << "copyHello: " << copyHello.GetString() << std::endl;
    return 0;
}
