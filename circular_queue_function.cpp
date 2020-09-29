#include<iostream>
using namespace std;

class CircularQueue{
    private:
        int front ;
        int rear ;
        int arr[5];
        int itemCount;

    public:
        CircularQueue()
        {
        	itemCount=0;
            front = -1;
            rear = -1;
            for(int i=0;i<5;i++)
            {
                arr[i]=0;
            }

        }

        bool isEmpty()
        {

            if (front == -1 && rear == -1)
                return true;
            else
                return false;
        }

        bool isFull()
        {
            if((rear+1)%5 == front))
               return true;
            else
                return false;
        }

        void enqueue(int val)
        {
            if(isFull()
            {
                cout << "Queue is full" << endl;
                return;
            }
            else if(isEmpty())
                {
                    rear=0;
                    front=0;
                    arr[rear]=val;
                    itemCount++;

                }
                else
                {
                    rear=(rear+1)%5;
                    arr[rear]=val;
                    itemCount++;
                }
        }

        int dequeue()
        {
        int x;
        if(isEmpty())
        {
            cout << "Queue is Empty" << endl;
            return 0;
        }
        else if(front == rear)
        {
            x=arr[front];
            arr[front]=0;
            front = -1;
            rear = -1;
            itemCount--;
            return x;
        }
        else
        {
            x=arr[front];
            arr[front]=0;
            front=(front+1)%5;
            itemCount--;
            return x;
        }
        }
        int count()
        {
            return (itemCount);
        }
        void display()
        {
            cout << "All values in the Queue" << endl;
            for (int i=0;i<5;i++)
            {
                cout << arr[i] << "  " <<endl;
            }
        }

};
int main ()
{


    circularQueue q1;
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
        cout<< "7. Clear Screen" << endl << endl;

        cin >> option;

        switch(option)
        {
        case 0:
            break;
        case 1:
            cout << "Enqueue operation\n Enter an item to Enqueue in the Queue" << endl;
            cin >> value;
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
        case 7:
            system("cls");
            break;

            default:
                cout << "Enter proper option number " << endl;
                break;
        }

   } while(option!=0);

    return 0;
}







