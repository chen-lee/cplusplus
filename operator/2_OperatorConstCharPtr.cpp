#include <iostream>
#include <sstream>
#include <string>

class Date {
private:
    int day;
    std::string tmpStr;

public:
    Date (int day) : day(day) {};

    // ++ 前缀
    Date& operator ++ () {
        ++day;
        return *this;
    }

    // ++ 后缀
    Date operator ++ (int) {
        Date copy(day);
        ++day;
        return copy;
    }

    void getDay() {
        std::cout << "day: " << day << std::endl;
    }

    // 转化运算符
    /*
    * 转换操作符是一种特殊的类成员函数。它定义将类类型值转变为其他类型值
      的转换。转换操作符在类定义体内声明，在保留字 operator 之后跟着转换的目
      标类型：
    */
    operator const char*() {
        std::ostringstream os;
        os << day;
        tmpStr = os.str();
        return tmpStr.c_str();
    }

};

int main(int argc, char** argv) {
    Date date(25);
    const char* test = "12345";
    std::cout << date << " " << test << std::endl;
    return 0;
}
