#include<iostream>
using namespace std;
#define MAX 1000

class stack{
    int top;

    int arr[5];

    public:

    Stack()
    {
        top=-1;
        for(int i =0;i<5;i++)
        {
            arr[i]=0;
        }
    }

    /*bool isFull;
    int push;
    int pop;
    bool isEmpty;*/

    bool isFull()
    {
        if(top == 4)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    bool isEmpty()
    {
        if(top == -1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    void push(int val)
    {
        if(isFull())
        {
            cout << "Stack Overflow"<< endl;
        }
        else
        {
            top++;
            arr[top] = val;
        }
    }

    int pop()
    {
        if(isEmpty())
            cout << "Stack Underflow" << endl;
        else
        {
            int popvalue = arr[top];
            arr[top]=0;
            top--;
            return popvalue;
        }
    }

    int peek(int pos)
    {
        if(isEmpty())
            cout << "Stack Underflow" << endl;
        else
        {
            int x = arr[top];
            return x;
        }
    }
};

int main()
{
    stack s;
    int option,position,value;

    do
    {
       cout << "what operation do you want to perform ? select option number . Enter 0 to exit " << endl;
       cout << "1. Push()" <<endl;
       cout << "2. Pop()" <<endl;
       cout << "3. isEmpty()"<<endl;
       cout << "4. isFull()"<<endl;
       cout << "5. peek()"<<endl;

       cin >> option;

       switch(option)
       {
       case 1:
        cout << "Enter a value to be pushed" << endl;
        cin >> value;
        s.push(value);
        break;

       case 2:
        cout << "Enter value to be poped" << s.pop();
        break;

       case 3:
           if(s.isEmpty())
            cout << "Stack is empty"<< endl;
           else
            cout << "Stack is not empty" << endl;
        break;

       case 4:
           if(s.isFull())
            cout << "Stack is Full " << endl;
           else
            cout << "Stack is not full" << endl;
        break;

        case 5:
            cout <<"Enter the pos you want to peek" <<endl;
            cin >> position ;
            cout << " Value at is: " << s.peek(position) << endl;
        break;
        default :
            cout << "Enter a valid option" << endl;
            }
        }while(option!=0);


    return 0;
}
