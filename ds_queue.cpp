#include<iostream>
using namespace std;

class queue{
private:
    int front;
    int rear;
    int arr[5];
public:
    queue()
    {
        int front=-1;
        int rear=-1;
        for(int i=0;i<5;i++)
        {
            arr[i]=0;
        }
    }

    // IS empty

    bool isEmpty()
    {
        if(front==-1 && rear==-1)
            return true;
        else
            return false;
    }

    // iS full

    bool isFull()
    {
        if(rear==4)
            return true;
        else
            return false;
    }

    void enqueue(int x)
    {
        if(isFull())
        {
            cout<<"Queue is full"<<endl;
            return ;
        }
        else if(isEmpty())
        {
            front=0;
            rear=0;
            arr[rear]=x;
        }
        else
        {
            rear++;
            arr[rear]=x;
        }
    }

    // dequeue

    int dequeu()
    {
        int x;
        if(isEmpty())
        {
            cout<<"Queue is Empty"<<endl;
            return 0;
        }
        else if(front==rear)
        {
            x=arr[front];
            arr[front]=0;
            front=-1;
            rear=-1;
            return x;
        }
        else
        {
            x=arr[front];
            arr[front]=0;
            front++;
            return x;
        }
    }

    // Count of Queue

    int count()
    {
        return (rear-front+1);
    }

    // Display

    void display()
    {
        for(int i=0;i<5;i++)
        {
            cout<<arr[i];
        }
    }
} ;


int main()
{
    queue q1;
    int option,value;
    do
    {
        cout << "\n\nWhat operation do you want to perform ? Select option no. Enter 0 to exit"<< endl;
        cout << "1. Enqueue()" << endl;
        cout << "2. Dequeue()" << endl;
        cout << "3. isEmpty()" << endl;
        cout << "4. is Full()" << endl;
        cout << "5.count()" << endl;
        cout << "6. display()" << endl;
        cout << endl;

        cin >> option;
        switch(option)
        {
        case 0:
            break;
        case 1:
            cout<<"Enqueue operation called"<<endl<<"Enter value to be inserted"<<endl;
            cin>>value;
            q1.enqueue(value);
            break;

        case 2:
            cout << "Dequeue Operation \n Dequeued value" << endl;
            break;

        case 3:
            if(isEmpty())
                cout << "Queue is empty " << endl;
            else
                cout << "Queue is not empty" << endl;
            break;

        case 4:
            if(isFull())
                cout << "Queue is full " << endl;
            else
                cout << "Queue is not full" << endl;
            break;

        case 5:
            cout << "Count Operation \n Count of item in the queue :"<< q1.count() << endl;
            break;

        case 6:
            cout << "Display functionCalled - " << endl;
            q1.display();
            break;

            default:
                cout << "Enter proper option number " << endl;
                break;
        }

   }
    while(option!=0);
    return 0;
}
