#include<iostream>
using namespace std;

void linearSearch(int a[],int n)
{
	int temp = -1;
	for(int i=0;i<n;i++)
	{
		if(a[i] == n)
		{
		cout <<"Number found at location: " << i << endl;
		temp = 0;
		}
	}
	if(temp == -1)
	{
		cout << "Number not found" << endl;
	}
}
int main()
{
	int arr[5]={1,5,4,8,25};
	int num;
	cout << "Enter a number to search" << endl;
	cin >> num;
	
	linearSearch(arr,num);
	
	return 0;
}
