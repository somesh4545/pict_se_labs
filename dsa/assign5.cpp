#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;

    node()
    {
        data = 0;
        left = NULL;
        right = NULL;
    }

    node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }

    void setData(int val)
    {
        data = val;
    }
};

class bst
{

public:
    node *root;

    bst()
    {
        root = NULL;
    }

    node *insert(node *root, node *n)
    {
        if (root == NULL)
        {
            return n;
        }
        if (root->data > n->data)
        {
            root->left = insert(root->left, n);
        }
        else if (root->data < n->data)
        {
            root->right = insert(root->right, n);
        }
        else if (root->data == n->data)
        {
            cout << "Same value\n";
            return root;
        }
        return root;
    }

    void inorder(node *root)
    {
        if (root == NULL)
            return;
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }

    void preorder(node *root)
    {
        if (root == NULL)
            return;
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }

    void postorder(node *root)
    {
        if (root == NULL)
            return;
        postorder(root->left);
        postorder(root->right);
        cout << root->data << " ";
    }

    node *findSuccessor(node *n)
    {
        n = n->right;
        while (n->left != NULL)
            n = n->left;
        return n;
    }

    node *deleteNode(node *root, int val)
    {
        if (root->data == val)
        {
            if (root->left == NULL && root->right == NULL)
            {
                return NULL;
            }
            else if (root->left == NULL && root->right != NULL)
            {
                node *temp = root->right;
                delete root;
                return temp;
            }
            else if (root->left != NULL && root->right == NULL)
            {
                node *temp = root->left;
                delete root;
                return temp;
            }
            else
            {
                node *temp = findSuccessor(root);
                root->data = temp->data;
                root->right = deleteNode(root->right, temp->data);
            }
        }
        else if (root->data > val)
        {
            root->left = deleteNode(root->left, val);
        }
        else if (root->data < val)
        {
            root->right = deleteNode(root->right, val);
        }
        return root;
    }

    void search(node *root, int val)
    {
        if (root == NULL)
        {
            cout << "Value not found" << endl;
            return;
        };
        if (root->data == val)
        {
            cout << "Value found in the tree" << endl;
            return;
        }
        else if (root->data > val)
        {
            search(root->left, val);
        }
        else if (root->data < val)
        {
            search(root->right, val);
        }
    }

    int height(node *root)
    {
        if (root == NULL)
            return 0;
        int l = 1 + height(root->left);
        int r = 1 + height(root->right);
        return max(l, r);
    }
};

int main()
{
    bst *tree = new bst();

    int ch = 0;

    do
    {
        cout << "\nEnter your choice 1.Insert 2.Search 3.Display 4.Delete 5.Height 6.Exit: ";
        cin >> ch;

        switch (ch)
        {
        case 1:
        {

            int data;
            cout << "Enter node value: ";
            cin >> data;
            tree->root = tree->insert(tree->root, new node(data));
            break;
        }
        case 2:
        {
            int val;
            cout << "Enter node value to search: ";
            cin >> val;
            tree->search(tree->root, val);
            break;
        }
        case 3:
        {
            cout << "Inorder = ";
            tree->inorder(tree->root);
            cout << endl;
            break;
        }
        case 4:
        {
            int del;
            cout << "Enter node value to delete: ";
            cin >> del;
            tree->deleteNode(tree->root, del);
            break;
        }
        case 5:
        {
            cout << "Height of tree is = " << tree->height(tree->root) << endl;
            break;
        }
        case 6:
        {
            cout << "\nProgram ends";
            break;
        }
        default:
        {
            cout << "Invalid choice";
            break;
        }
        }
    } while (ch != 6);

    return 0;
}