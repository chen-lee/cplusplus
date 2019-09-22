#include <iostream>

class Date {
private:
    int day;

public:
    Date (int day) : day(day) {};

    /* 关于如何区分前缀和后缀:
    * 同时定义前缀式操作符和后缀式操作符存在一个问题：它们的形参数目和类
      型相同，普通重载不能区别所定义的前缀式操作符还是后缀式操作符。

    * 为了解决这一问题， 后缀式操作符函数接受一个额外的（即， 无用的） int 型
      形参。使用后缀式操作符进，编译器提供 0 作为这个形参的实参。尽管我们的
      前缀式操作符函数可以使用这个额外的形参，但通常不应该这样做。那个形参不
      是后缀式操作符的正常工作所需要的， 它的唯一目的是使后缀函数与前缀函数区
      别开来。
      来源: 《C++ Primer》
    */

    // ++ 前缀
    Date& operator ++ () {
        ++day;
        return *this;
    }

    // ++ 后缀
    /*
    * 为了与内置操作符一致， 后缀式操作符应返回旧值（即，
      尚未自增或自减的值），并且，应作为值返回，而不是
      返回引用。
    */
    Date operator ++ (int) {
        Date copy(day);
        ++day;
        return copy;
    }

    void getDay() {
        std::cout << "day: " << day << std::endl;
    }

};

int main(int argc, char** argv) {
    Date date(25);
    date.getDay();
    ++ date;
    date.getDay();
    Date oldDate = date ++;
    date.getDay();
    oldDate.getDay();
    return 0;
}
