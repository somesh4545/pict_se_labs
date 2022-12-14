// Threaded Binary Tree
// Implement In-order Threaded Binary Tree and traverse it in In-order and Pre-order

#include <iostream>
using namespace std;

 class node
{
public:
    int data;
    node *left;
    node *right;
    bool leftNode, rightNode;

    node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
        leftNode=rightNode=false; 
    }
};

class TBT{
    node* root;

    TBT(){
        root = NULL;
    }

    void insert(node* newNode){
        if(root == NULL){
            root = newNode;
        }
    }
};

int main(){



    return 0;
}