#include <iostream>

template <class t> 
class node
{
public:

    t data;
    node *next;

    node(t n)
    {
        data = n;
        next = NULL;
    }
};