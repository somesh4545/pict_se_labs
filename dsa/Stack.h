#include <iostream>
#include "node.h"
using namespace std;

template <class t>
class Stack
{
    node<t> *top;

    public:
    Stack() { top = NULL; }

    void push(t n)
    {
        node<t> *temp = new node<t>(n);
        temp->next = top;
        top = temp;
    }

    bool isEmpty()
    {
        return top == NULL;
    }

    void pop()
    {
        if (top == NULL)
            return;
        else
            top = top->next;
    }

    t stackTop()
    {
        if (top != NULL)
            return top->data;
        else
            exit(1);
    }

    void display()
    {
        node<t> *temp = top;

        if (top == NULL)
        {
            cout << "Stack is empty";
        }
        else
        {
            while (temp != NULL)
            {
                cout << temp->data;
                temp = temp->next;
            }
        }
    }
};