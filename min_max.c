#include <stdio.h>
#include <stdlib.h>

struct pair
{
  int min;
  int max;
  int min_idx; //store the index on min
  int max_idx; //store the index of max
};

struct pair getMinMax(int arr[], int low, int high, int *ops)
{
  struct pair minmax,ml,mr;
  int mid;
  if(low==high)                 
  {
    (*ops)++;
    minmax.min=arr[low];
    minmax.max=arr[high];
    minmax.min_idx=low;
    minmax.max_idx=high;
    return minmax;
  }
  else if(low==high-1)
  {
    (*ops)++;
    if(arr[low]>arr[high])
    {
      minmax.min=arr[high];
      minmax.max=arr[low];
      minmax.min_idx=high;
      minmax.max_idx=low;
    }
    else
    {
      minmax.min=arr[low];
      minmax.max=arr[high];
      minmax.min_idx=low;
      minmax.max_idx=high;
    }
    return minmax;
  }
  mid=(low+high)/2;
  ml=getMinMax(arr,low,mid,ops);
  mr=getMinMax(arr,mid+1,high,ops);
  (*ops)++;
  if(ml.min>mr.min)        
  {
    //(*ops)++;
    minmax.min=mr.min;
    minmax.min_idx=mr.min_idx;
  }
  else 
  {
    //(*ops)++;
    minmax.min=ml.min;     
    minmax.min_idx=ml.min_idx;
  }
  if(ml.max>mr.max)
  {
   // (*ops)++;
    minmax.max=ml.max;
    minmax.max_idx=ml.max_idx;
  }
  else
  {
   // (*ops)++;
    minmax.max=mr.max;
    minmax.max_idx=mr.max_idx;
  }
  return minmax;
  
}


/// function to print array
void printArray(int A[], int size)
{
	int i;
	for (i=0; i < size; i++)
		printf("%d ", A[i]);
	printf("\n");
}


/* Driver program to test above function */
int main()
{
  int arr[] = {30,56,23,5,67,87,876,203,-4,56,-45,83,54,90,34,-40};
  int n = sizeof(arr) / sizeof(arr[0]);
  int ops=0;
  printf("\nThe input array is: \n");
  printArray(arr,n);
  struct pair minmax = getMinMax(arr, 0, n-1,&ops);
  printf("\nMinimum element is %d at index %d\n", minmax.min, minmax.min_idx);
  printf("\nMaximum element is %d at index %d\n", minmax.max, minmax.max_idx);
  printf("\nTotal ops: %d",ops);
 
  int arr2[] = {1,4,7,8,-3,-6,9,5};
  int n2 = sizeof(arr2) / sizeof(arr2[0]);
  int ops2=0;
  printf("\nThe input array is: \n");
  printArray(arr2,n2);
  struct pair minmax2 = getMinMax(arr2, 0, n2-1,&ops2);
  printf("\nMinimum element is %d at index %d\n", minmax2.min, minmax2.min_idx);
  printf("\nMaximum element is %d at index %d\n", minmax2.max, minmax2.max_idx);
  printf("\nTotal ops: %d",ops2);
 
  int arr3[] = {10,15,20,-25,-30,-35,50,55,65,75,-35,-76,-10,-45,105,205};
  int n3 = sizeof(arr3) / sizeof(arr3[0]);
  int ops3=0;
  printf("\nThe input array is: \n");
  printArray(arr3,n3);
  struct pair minmax3 = getMinMax(arr3, 0, n3-1,&ops3);
  printf("\nMinimum element is %d at index %d\n", minmax3.min, minmax3.min_idx);
  printf("\nMaximum element is %d at index %d\n", minmax3.max, minmax3.max_idx);
  printf("\nTotal ops: %d",ops3);
 
  int arr4[] = {-5,-4,-3,-2,-1,0,1,2,3,4,5,6,7,8,9};
  int n4 = sizeof(arr4) / sizeof(arr4[0]);
  int ops4=0;
  printf("\nThe input array is: \n");
  printArray(arr4,n4);
  struct pair minmax4 = getMinMax(arr4, 0, n4-1,&ops4);
  printf("\nMinimum element is %d at index %d\n", minmax4.min, minmax4.min_idx);
  printf("\nMaximum element is %d at index %d\n", minmax4.max, minmax4.max_idx);
  printf("\nTotal ops: %d",ops4);
 
  int arr5[] = {-10,50,-20,40,-30,50,-20,60};
  int n5 = sizeof(arr5) / sizeof(arr5[0]);
  int ops5=0;
  printf("\nThe input array is: \n");
  printArray(arr5,n5);
  struct pair minmax5 = getMinMax(arr5, 0, n5-1,&ops5);
  printf("\nMinimum element is %d at index %d\n", minmax5.min, minmax5.min_idx);
  printf("\nMaximum element is %d at index %d\n", minmax5.max, minmax5.max_idx);
  printf("\nTotal ops: %d",ops5);
 
}
