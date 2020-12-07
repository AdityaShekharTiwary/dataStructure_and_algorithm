#include<bits/stdc++.h>
using namespace std;

class Stack
{
private:
    int top;
    int arr[5];

public:
    Stack()
    {
         top=-1;
        for(int i=0;i<5;i++)
        {
            arr[i]=0;
        }
    }
    // is empty

    bool isEmpty()
    {
        if(top==-1)
            return true;
        else
            return false;
    }

    // is full

    bool isFull()
    {
        if(top==4)
            return true;
        else
            return false;
    }

    // push

    void push(int val)
    {
        if(isFull())
        {
            cout<<"Stack overflow"<<endl;
        }
        else
        {
            top++;
            arr[top]=val;
        }
    }

    // pop

    int pop()
    {
        if(isEmpty())
        {
            cout<<"Stack underflow"<<endl;
        }
        else
        {
            int popedvalue=arr[top];
            arr[top]=0;
            top--;
            return popedvalue;
        }
    }

        //peek

        int peek(int pos)
        {
            if(isEmpty())
            {
                cout<<"Stack Underflow"<<endl;
            }
            else
            {
                return arr[pos];
            }
        }

        // change value

        void change(int pos,int val)
        {
            if(isEmpty())
            {
                cout<<"Stack Underflow"<<endl;
            }
            else
            {
                arr[pos]=val;
                cout<<"Value changed"<<endl;
            }
        }
        void display()
        {
            if(isEmpty())
            {
                cout<<"Stack Underflow"<<endl;
            }
            else
            {
                for(int i=4;i>=0;i--)
                {
                    cout<<arr[i]<<" ";
                    cout<<endl;
                }
            }


        }


};
int main()
{
    Stack s1;
    int option,position,value;
    do
    {
       cout << "what operation do you want to perform ? select option number . Enter 0 to exit " << endl;
       cout << "1. Push()" <<endl;
       cout << "2. Pop()" <<endl;
       cout << "3. isEmpty()"<<endl;
       cout << "4. isFull()"<<endl;
       cout << "5. peek()"<<endl;
       cout << "6. change"<<endl;
       cout << "7. display"<<endl;
       cout << "8. Clear Screen"<<endl<<endl;
       cin>>option;
       switch(option)
       {
            case 1:
                cout<<"Enter a value to be pushed"<<endl;
                cin>>value;
                s1.push(value);
                break;
            case 2:
                cout<<"Popped value is "<<s1.pop()<<endl;
                break;
            case 3:
                if(s1.isEmpty())
                    cout<<"STACk is Empty"<<endl;
                else
                    cout<<"STACK is not empty"<<endl;
                break;
            case 4:
                if(s1.isFull())
                {
                    cout<<"STACK is full"<<endl;
                }
                else
                {
                    cout<<"STACK is not full"<<endl;
                }
                break;
            case 5:
                cout<<"Enter potion to peek"<<endl;
                cin>>position;
                cout<<"Peeked element is"<<s1.peek(position)<<endl;
                break;
            case 6:
                cout<<"Enter position"<<endl;
                cin>>position;
                cout<<"Enter value"<<endl;
                cin>>value;
                s1.change(position,value);
            case 7:
                cout<<"Display function called"<<endl;
                s1.display();
                break;

            default:
                cout << "Enter Proper Option number " << endl;

       }
    }
    while (option!=0);

   return 0;
}



