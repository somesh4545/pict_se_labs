#include <iostream>

class node
{
public:
    char data;
    node *next;

    node(int n)
    {
        data = n;
        next = NULL;
    }
};