#include "stack.h"
#include <iostream>

int main(int argc, char** argv)
{
    Stack<int> x;
    x.add(0);
    x += 1;
    x += 2;
    x--;
    x += 3;
    x += 4;
    x--;
    x.pop();
    std::cout << x.search(1) << std::endl;
    std::cout << x.search(0) << std::endl;
    x--;
    --x;
    std::cout << x.search(0) << std::endl;
    std::cout << x << std::endl;

    x += 0;
    x += 1;
    x += 2;
    x += 3;
    x += 4;
    x += 5;

    std::cout << x << std::endl;
    std::cout << x.search(3) << std::endl;
    std::cout << x.search(0) << std::endl;
    std::cout << x[5] << std::endl;
    std::cout << x.search(x[2].get_value()) << std::endl;

    Stack<Stack<char>> y;

    Stack<char> s;
    s += 'a';
    s += 'b';
    s += 'c';
    y += s;

    Stack<char> f;
    f.add('d');
    f.add('e');
    f.add('f');
    std::cout << y << std::endl;
    y += f;
    std::cout << y << std::endl;
    y--;
    std::cout << f << std::endl;
    std::cout << y << std::endl;
    y--;
}
