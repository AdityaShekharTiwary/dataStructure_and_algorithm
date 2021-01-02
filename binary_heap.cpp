#include<bits/stdc++.h>
using namespace std;

void swap(int *x,int *y);

class MinHeap
{
    int *arr;
    int capacity;
    int heap_size;

public:

    MinHeap(int capacity);
    void MinHeapify(int );

    int parent(int i)
    {
    return (i-1)/2;
    }
    int left(int i)
    {
        return 2*i+1;
    }
    int right(int i)
    {
        return 2*i+2;
    }

    int extractMin();

    void decreaseKey(int i, int new_val);

    int getMin()
    {
        return arr[0];

    }

    void deleteKey(int i);

    void insertKey(int k);
};


MinHeap::MinHeap(int cap)
{
    heap_size=0;
    capacity=cap;
    arr=new int [cap];
}

void MinHeap::insertKey(int k)
{
    if(heap_size==capacity)
    {
        cout<<"Overflow cant insert new key"<<endl;
        return ;
    }
    heap_size++;
    int i=heap_size-1;
    arr[i]=k;

    while(i != 0 && arr[parent(i)]>arr[i])
    {
        swap(&arr[i], &arr[parent(i)]);
        i=parent(i);
    }
}

void MinHeap::decreaseKey(int i,int new_val)
{
    arr[i]=new_val;
    while(i!=0 && arr[parent(i)]>arr[i])
    {
        swap(&arr[i],&arr[parent(i)]);
        i=parent(i);
    }
}

int MinHeap::extractMin()
{
    if(heap_size<=0)
        return INT_MAX;
    if(heap_size==1)
    {
        heap_size--;
        return arr[0];
    }
    int root=arr[0];
    arr[0]=arr[heap_size-1];
    heap_size;
    MinHeapify(0);
    return root;
}

void MinHeap::deleteKey(int i)
{
    decreaseKey(i , INT_MIN);
    extractMin();
}

void MinHeap::MinHeapify(int i)
{
    int l = left(i);
    int r = right(i);
    int smallest = i;
    if (l < heap_size && arr[l] < arr[i])
        smallest = l;
    if (r < heap_size && arr[r] < arr[smallest])
        smallest = r;
    if (smallest != i)
    {
        swap(&arr[i], &arr[smallest]);
        MinHeapify(smallest);
    }
}

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}


int main()
{
    MinHeap h(11);
    h.insertKey(3);
    h.insertKey(2);
    h.deleteKey(1);
    h.insertKey(15);
    h.insertKey(5);
    h.insertKey(4);
    h.insertKey(45);
    cout << h.extractMin() << " ";
    cout << h.getMin() << " ";
    h.decreaseKey(2, 1);
    cout << h.getMin();
    return 0;
}








