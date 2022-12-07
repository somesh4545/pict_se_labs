#include <iostream>
using namespace std;

class node
{
public:
    char data;
    node *left;
    node *right;
    node *next;

    node()
    {
        left = NULL;
        right = NULL;
        next = NULL;
    }

    node(char val)
    {
        data = val;
        left = NULL;
        right = NULL;
        next = NULL;
    }

    void setData(int val)
    {
        data = val;
    }
};

class Stack{
    public:

        node *top;
        Stack(){
            top = NULL;
        }
        
        void push(char val){
            node* temp = new node(val);
            temp->next = top;
            top = temp;
        }

        void push(node* node){
            node->next = top;
            top = node;
        }

        node* pop(){
            if(top == NULL) return NULL;
            node *temp = top;
            top = top->next;
            return temp;
        }

        node* stackTop(){
            return top;
        }
};

class ExpressionTree{
    public:
        node *root;
        ExpressionTree(){
            root = NULL;
        }

        node* createTreeFromPostfix(string eq) {
            Stack* st = new Stack();
            for(int i=0; i<eq.length(); i++){
                char c = eq[i];
                if((c>='a' && c<='z') || (c>='A' && c<='Z')){
                    st->push(c);
                }else{
                    node* fe = st->pop();
                    node* se = st->pop();
                    node* temp = new node(c);
                    temp->right = fe;
                    temp->left = se;
                    st->push(temp);
                }
            }
            return st->stackTop();
        }

        string reverse(string str){
             string ans = "";
            for (int i = str.length() - 1; i >= 0; i--)
                ans += str[i];
            return ans;

        }

        node* createTreeFromPrefix(string eq){
            string rev = reverse(eq);
            node* temp = createTreeFromPostfix(rev);
            return temp;
        }

        void displayTree(node* root) {
            if(root == NULL) return;
            displayTree(root->left);
            cout << root->data << " ";
            displayTree(root->right);
        }


};


int main()
{

    ExpressionTree* et = new ExpressionTree();
    string str;
    cout << "Enter a postfix equation: ";
    cin >> str;
    et->root = et->createTreeFromPostfix(str);
    et->displayTree(et->root);
    cout << endl;

    cout << "\nEnter a prefix equation: ";
    cin >> str;
    et->root = et->createTreeFromPrefix(str);
    et->displayTree(et->root);
    cout << endl;
    return 0;
}