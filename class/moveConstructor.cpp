#include <iostream>
#include <string.h>
#include <string>

class MyString {
private:
    char* buffer;

public:
    // Constructor
    MyString(const char* input) {
        std::cout << "constructor " << std::endl;
        if (input) {
            buffer = new char[strlen(input) + 1];  // add '\0'
            strcpy(buffer, input);
        } else {
            buffer = NULL;
        }
    }

    // CopyConstructor
    MyString(const MyString& input) {
        std::cout << "copy constructor " << std::endl;
        if (input.buffer) {
            buffer = new char[strlen(input.buffer) + 1];
            strcpy(buffer, input.buffer);
        } else {
            buffer = NULL;
        }
    }

    // MoveConstructor
    MyString(MyString&& input) {
        std::cout << "move constructor " << std::endl;
        if (input.buffer != NULL) {
            buffer = input.buffer;  // take ownership i.e.  'move'
            input.buffer = NULL;
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

MyString testMove(MyString& input) {
    MyString copyInput(input.GetString());
    return std::move(copyInput);
}

int main(int argc, char** argv) {
    MyString* hello = new MyString("hello world");
    std::cout << "hello: " << hello->GetString() << std::endl;
    MyString copyHello(std::move(*hello));
    delete hello;
    std::cout << "copyHello: " << copyHello.GetString() << std::endl;
    MyString moveHello = testMove(copyHello);
    std::cout << "moveHello: " << moveHello.GetString() << std::endl;
    return 0;
}
