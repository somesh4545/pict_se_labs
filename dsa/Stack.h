#include <iostream>
#include "node.h"
using namespace std;

class Stack
{
    node *top;

    public:
    Stack() { top = NULL; }

    void push(int n)
    {
        node *temp = new node(n);
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

    char stackTop()
    {
        if (top != NULL)
            return top->data;
        else
            exit(1);
    }

    void display()
    {
        node *temp = top;

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