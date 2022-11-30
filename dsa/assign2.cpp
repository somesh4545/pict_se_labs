#include <iostream>
using namespace std;

#define MAX_LEN 60

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

int prec(char c)
{
    if (c == '^')
        return 3;
    else if (c == '/' || c == '*')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return -1;
}

string infixToPostFix(string str)
{
    string ans;

    Stack st;

    for (int i = 0; i < str.length(); i++)
    {
        char c = str[i];

        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
            ans += c;
        else if (c == '(')
            st.push(c);
        else if (c == ')')
        {
            while (st.stackTop() != '(')
            {
                ans += st.stackTop();
                st.pop();
            }
            st.pop();
        }
        else
        {
            while (!st.isEmpty() && prec(c) <= prec(st.stackTop()))
            {
                ans += st.stackTop();
                st.pop();
            }
            st.push(c);
        }
    }

    while (!st.isEmpty())
    {
        ans += st.stackTop();
        st.pop();
        /* code */
    }

    return ans;
}

string reverse(string str)
{
    string ans = "";
    for (int i = str.length() - 1; i >= 0; i--)
        ans += str[i];
    return ans;
}

string infixToPrefix(string str)
{
    string rev = reverse(str);
    for (int i = 0; i < rev.length(); i++)
    {
        if (rev[i] == '(')
            rev[i] = ')';
        else if (rev[i] == ')')
            rev[i] = '(';
    }

    string ans = infixToPostFix(rev);
    return reverse(ans);
}

int evalPost(string str)
{
    int ans = 0;

    Stack st;

    for (int i = 0; i < str.length(); i++)
    {
        if (isdigit(str[i]))
            st.push(str[i] - '0');
        else
        {
            int val1 = (int)st.stackTop();
            st.pop();
            int val2 = (int)st.stackTop();
            st.pop();
            switch (str[i])
            {
            case ('+'):
            {
                st.push(val2 + val1);
                break;
            }
            case ('-'):
            {
                st.push(val2 - val1);
                break;
            }
            case ('*'):
            {
                st.push(val2 * val1);
                break;
            }
            case ('/'):
            {
                st.push(val2 / val1);
                break;
            }
            }
        }
    }

    return st.stackTop();
}

int evalPre(string str)
{
    string rev = reverse(str);
    int ans = evalPost(rev);
    return ans;
}

int main()
{
    int ch = 0;

    do
    {
        cout << "\n\nEnter your choice 1.Inf to post 2.Inf to pre 3.Eval post 4.Eval pre 5.Exit: ";
        cin >> ch;

        switch (ch)
        {
        case 1:
        {

            string str;
            cout << "Enter string: ";
            cin >> str;
            string op = infixToPostFix(str);
            cout << "Infix to postfix: " << op;
            break;
        }
        case 2:
        {
            string str;
            cout << "Enter string: ";
            cin >> str;
            string op = infixToPrefix(str);
            cout << "Infix to prefix: " << op;
            break;
        }
        case 3:
        {
            string str;
            cout << "Enter string: ";
            cin >> str;
            int op = evalPost(str);
            cout << "The evaluation of postfix equation is = " << op;
            break;
        }
        case 4:
        {
            string str;
            cout << "Enter string: ";
            cin >> str;
            int op = evalPre(str);
            cout << "The evaluation of prefix equation is = " << op;
            break;
        }
        case 5:
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
    } while (ch != 5);
    return 0;
}
