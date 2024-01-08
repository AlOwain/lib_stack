#pragma once
#include "../lib/linkedlist.h"

template <typename T>
class Stack {
public:
    Stack() {}

    void add(T value) { list.add_start(value); }
    void pop() { list.remove_start(); }

    void operator+=(T value) { add(value); }

    /*
     * This should pop a value from the Stack
     * the `operator--()` is a prefixed decrementor
     * while `operator--(int)` is a postfixed decrementor
     * the `int` is a dummy parameter that is only there to
     * distinguish between `--x` & `x--` with `x--` being
     * running in `operator--(int)` the actual int value
     * being passed is irrelevant.
    */
    void operator--() { pop(); }
    void operator--(int) { pop(); }

    int search(T value) { return list.search(value); }

    int size() { return list.size(); }

    Node<T> operator[](int index) { return list[index]; }

    friend std::ostream& operator<<(std::ostream &stream, Stack<T> stack)
    {
        return operator<<(stream, stack.list);
    }
private:
    LinkedList<T> list;
};
