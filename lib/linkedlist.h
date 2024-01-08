#pragma once
#include "node.h"

template <typename T>
class LinkedList {
public:
    LinkedList() { m_size = 0; head = nullptr; }

    // add_value(T value, int index):
    //      parameters:
    //          - T:            It takes the value you want to add, and adds it at the given index.
    //          - int:          It takes the placement of the value you want to add (the index).
    void add_value(T value, int index)
    {
        if (m_size == 0) return add_to_empty(value);
        if (index <= 0) return add_start(value);
        if (index >= m_size) return add_end(value);

        int iterator = 0;
        Node<T> *prev = head, *curr = head;
        while (curr->get_next() != nullptr && iterator != index)
        {
            prev = curr;
            curr = curr->get_next();
            iterator++;
        }
        prev->set_next(new Node<T>(value));
        prev->get_next()->set_next(curr);
        m_size++;
    }
    
    // remove_by_index(int index):
    //      parameters:
    //          - int:          Index of the item you want to remove (starts from 0).
    //      returns:
    //          - 0:            On success.
    //          - !0:           Error code.
    short remove_by_index(int index)
    {
        if (m_size <= 0) return -2;

        if (index <= 0) return remove_start();
        if (index >= m_size - 1) return remove_end();

        int iterator = 1;
        Node<T> *prev = head;
        Node<T> *curr = head->get_next();
        while (curr->get_next() != nullptr && iterator != index)
        {
            prev = curr;
            curr = curr->get_next();
            iterator++;
        }

        prev->set_next(curr->get_next());
        delete curr;
        m_size--;
        return 0;
    }

    // remove_by_value(T value):
    //      parameters:
    //          - T:            Value of the item you want to remove.
    //      returns:
    //          - 0:            On success.
    //          - !0:           Error code.
    short remove_by_value(T value) { return remove_by_index(search(value)); }

    // search(T value):
    //      parameters:
    //          - T:            The value you want to search for.
    //      returns:
    //          - <0:           On success, it returns the index to the item.
    //          - >0:           On failure, it returns the error code.
    int search(T value)
    {
        if (m_size <= 0) return -1;

        Node<T> *trav = head;
        for (int index = 0; index < m_size; index++)
        {
            if (trav->get_value() == value) return index;
            trav = trav->get_next();
        }
        return -2;
    }

    // add_start(T value):
    //      parameters:
    //          - T:            It takes the value you want to add, and adds it to the start of the list.
    void add_start(T value)
    {
        if (m_size == 0) return add_to_empty(value);

        Node<T> *second_item = head->get_next();
        head->set_next(new Node<T>(head->get_value()));
        head->set_value(value);
        head->get_next()->set_next(second_item);
        m_size++;
    }

    // add_end(T value):
    //      parameters:
    //          - T:            It takes the value you want to add, and adds it to the end of the list.
    void add_end(T value)
    {
        if (m_size == 0) return add_to_empty(value);

        Node<T> *prev = head;
        while (prev->get_next() != nullptr)
            prev = prev->get_next();
        prev->set_next(new Node<T>(value));

        m_size++;
    }
    // remove_start():
    //      returns:
    //          - 0:            On success.
    //          - <0:           On failure, it returns the error code.
    short remove_start()
    {
        Node<T> *temp = head;
        head = head->get_next();
        delete temp;
        m_size--;
        return 0;
    }

    // remove_end():
    //      returns:
    //          - 0:            On success.
    //          - <0:           On failure, it returns the error code.
    short remove_end()
    {
        if (m_size == 0) return -1;
        if (m_size == 1) return remove_start();

        Node<T> *curr = head;
        while (curr->get_next()->get_next() != nullptr)
            curr = curr->get_next();
        delete curr->get_next();
        curr->set_next(nullptr);
        m_size--;
        return 0;
    }

    // size():
    //      returns:
    //          - int:          Size of the list.
    int size() { return m_size; }

    // [] Operator:
    //      parameters:
    //          - int:          The index of the provided value.
    //      returns:
    //          - int:          Value at the provided index.
    Node<T> operator[](int index)
    {
        // FIXME: Should throw error.
        if (index < 0) exit(-1);
        if (index >= m_size) exit(-1);

        Node<T> *trav = head;
        int i = 0;
        while (i != index)
        {
            trav = trav->get_next();
            i++;
        }
        return *trav;
    }

    // << Operator:
    //      description:
    //          -               Adds the list to a stream and returns the stream.
    friend std::ostream& operator<<(std::ostream &stream, LinkedList<T> list)
    {
        if (list.size() == 0) return stream;

        Node<T> *trav = list.head;

        while (trav->get_next() != nullptr)
        {
            stream << trav->get_value() << ", ";
            trav = trav->get_next();
        }

        stream << trav->get_value();

        return stream;
    }

private:
    int m_size;
    Node<T> *head;

    void add_to_empty(T value) { head = new Node<T>(value); m_size++; }
};
