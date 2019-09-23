#include <iostream>

template <typename T>
class smart_pointer {
private:
    T* m_pRawPointer;

public:
    smart_pointer(T* pData) : m_pRawPointer(pData) {}
    ~smart_pointer() {
        delete m_pRawPointer;
    }

    T& operator* () {
        return *(m_pRawPointer);
    }

    T* operator-> () {
        return m_pRawPointer;
    }
};

class Tmp {
private:
    int day;

public:
    Tmp(int day) : day(day) {}
    void displayDate() {
        std::cout << day << std::endl;
    }
};

int main(int argc, char** argv) {
    smart_pointer<int> p(new int(42));
    std::cout << *p << std::endl;
    smart_pointer<Tmp> tmp(new Tmp(45));
    tmp->displayDate();
    return 0;
}
