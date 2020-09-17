#include<iostream>
using namespace std;

void insertionSort(int arr[])
{
    int j=0,key=0;
    for(int i=1;i<5;i++)
    {
        key=arr[i];    // Picking the next element
        j = i-1;
        while(j>=0 && arr[j]>key)
        {
            arr[j+1] = arr[j];
            j=j-1;
        }
        arr[j+1] = key;
    }

}

int main()
{
    int myarr[5];
    cout <<"Enter five integer"<< endl;
    for(int i=0;i<5;i++)
    {
        cin>>myarr[i];
    }
    cout <<"Before sorting"<< endl;
     for(int i=0;i<5;i++)
    {
        cout<<myarr[i]<<" " ;
    }
    cout << endl;
    insertionSort(myarr);
    cout <<"After sorting"<< endl;
     for(int i=0;i<5;i++)
    {
        cout<<myarr[i]<<" " ;
    }
    return 0;
}
