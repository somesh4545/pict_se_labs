#include <iostream>
using namespace std;
#define MAX_SIZE 5

class queue
{
public:
    int q[MAX_SIZE];
    int front, rear;

    queue()
    {
        front = -1;
        rear = -1;
    }

    void enqueue(int val)
    {
        if (front == -1 && rear == -1)
        {
            front = 0;
            rear = 0;
            q[rear] = val;
        }
        else if ((rear + 1) % MAX_SIZE == front)
        {
            cout << "Queue is overflow..\n"
                 << endl;
        }
        else
        {
            rear = (rear + 1) % MAX_SIZE;
            q[rear] = val;
        }
    }

    void dequeue()
    {
        if ((front == -1) && (rear == -1))
        {
            printf("Queue is underflow..\n");
        }
        else if (front == rear)
        {
            cout << "The dequeued element is " << q[front] << endl;
            front = -1;
            rear = -1;
        }
        else
        {
            cout << "The dequeued element is " << q[front] << endl;
            front = (front + 1) % MAX_SIZE;
        }
    }

    void display()
    {

        if (front == -1 && rear == -1)
            cout << "Queue is empty..\n";
        else
        {
            printf("Elements in a Queue are: ");
            int i = front;
            do
            {
                if (i != front)
                    cout << ",";
                cout << q[i];
                i = (i + 1) % MAX_SIZE;
            } while (i != (rear + 1) % MAX_SIZE);
            cout << endl;
        }
    }
};

int main()
{
    queue q;
    int ch = 0;

    do
    {
        cout << "\nEnter your choice 1.Enqueue 2.Dequeue 3.Display 4.Exit: ";
        cin >> ch;

        switch (ch)
        {
        case 1:
        {

            int num;
            cout << "Enter number: ";
            cin >> num;
            q.enqueue(num);
            // q.display();
            break;
        }
        case 2:
        {
            q.dequeue();
            // q.display();
            break;
        }
        case 3:
        {
            q.display();
            break;
        }
        case 4:
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
    } while (ch != 4);

    return 0;
}
