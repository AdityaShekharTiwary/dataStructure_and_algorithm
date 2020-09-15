#include<iostream>
using namespace std;

int binarysearch(int arr[],int left,int right,int x)
{
	while(left<=right)
	{
		int mid = left + (right - left)/2;
		if(arr[mid]==x)
		{
			return mid;
		}
		else if(arr[mid] < x)
		{
			left=mid+1;
		}
		else
		{
			right=mid-1;
		}

	}
	return -1;
}

int main()
{
	int num ;
	int myarr[10];
	int output;
	cout <<"Enter 10 integers in ASCENDING ORDER " << endl;
	for(int i=0;i<10;i++)
	{
		cin >> myarr[i];
	}
	cout << "Enter one number that you want to search" << endl;
	cin >> num;
	output=binarysearch(myarr,0,9,num);
	if(output == -1)
	{
		cout << "No match found" << endl;
	}
	else
	{
		cout << "Match found at index position: " << output << endl;
	}
	return 0;

}

