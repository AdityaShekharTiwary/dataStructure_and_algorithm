#include<stdio.h>
#include<stdlib.h>
#define INT_MIN -10000

// A utility funtion to find maximum of two integers
int max(int a, int b) { return (a > b) ? a : b; }

// A utility funtion to find maximum of three integers
int max3(int a, int b, int c) { return max(max(a, b), c); }

int maxCrossingSum(int arr[], int l, int m, int h, int *ops, int *l_idx, int *r_idx)    
{
    int sum=0,i;
    int left_sum=INT_MIN,right_sum=INT_MIN;
    for(i=m;i>=l;i--)
    {
        sum+=arr[i];
        (*ops)++;
        if(sum>left_sum)
        {
            
            left_sum=sum;
            *l_idx=i;
        }
    }
    sum=0;
    for(i=m+1;i<=h;i++)
    {
        sum+=arr[i];
        (*ops)++;
        if(sum>right_sum)
        {
            
            right_sum=sum;
            *r_idx=i;
        }
    }
    
    return(max3(left_sum+right_sum,left_sum,right_sum));
}


int maxSubArraySum(int arr[], int l, int h, int *ops, int *l_idx, int *r_idx)
{
    int L,R,C,m;
    if(l==h)
    {
        return arr[l];
    }
    else
    {
        m=(l+h)/2;
        L=maxSubArraySum(arr,l,m,ops,l_idx,r_idx);
        R=maxSubArraySum(arr,m+1,h,ops,l_idx,r_idx);
        C=maxCrossingSum(arr,l,m,h,ops,l_idx,r_idx);
        return(max3(L,R,C));
    }

}

/// function to print array
void printArrayWithMarkers(int arr[], int size, int l, int r)
{
	int i;
	for (i=0; i < size; i++){
        if((i==l)&&(i!=r))
            printf("[%d ", arr[i]);
        else if((i!=l)&&(i==r))
            printf("%d] ", arr[i]);
        else if((i==l)&&(i==r))
            printf("[%d] ", arr[i]);
        else
            printf("%d ", arr[i]);

    }
    printf("\n");
}

/*Driver program to test maxSubArraySum*/
int main()
{
    int arr[] = {-1, -2, -3, 4, 5, 6, -3, 7, 8, 9, -10, -15};
    int n = sizeof(arr) / sizeof(arr[0]);
    int ops=0;
    int l_index=0, r_index=0;
    int max_sum = maxSubArraySum(arr, 0, n - 1, &ops, &l_index, &r_index);
    printf("\nInput array and sequence markers is:\n");
    printArrayWithMarkers(arr,n,l_index,r_index);
    printf("\n\nMaximum contiguous sum is %d", max_sum);
    printf("\n\nNumber of ops: %d\n\n", ops);
 
    int arr2[] = {4,5,-1,-3,6,7,8,-3,-1};
    n = sizeof(arr2) / sizeof(arr2[0]);
    ops=0;
    l_index=0, r_index=0;
    max_sum = maxSubArraySum(arr2, 0, n - 1, &ops, &l_index, &r_index);
    printf("\nInput array and sequence markers is:\n");
    printArrayWithMarkers(arr2,n,l_index,r_index);
    printf("\n\nMaximum contiguous sum is %d", max_sum);
    printf("\n\nNumber of ops: %d\n\n", ops);
 
    int arr3[] = {100,243,-200,-105,345,156,-456,508};
    n = sizeof(arr3) / sizeof(arr3[0]);
    ops=0;
    l_index=0, r_index=0;
    max_sum = maxSubArraySum(arr3, 0, n - 1, &ops, &l_index, &r_index);
    printf("\nInput array and sequence markers is:\n");
    printArrayWithMarkers(arr3,n,l_index,r_index);
    printf("\n\nMaximum contiguous sum is %d", max_sum);
    printf("\n\nNumber of ops: %d\n\n", ops);
 
    int arr4[] = {-1,-2,-3,-4,-5,5,4,3,2,1,-100};
    n = sizeof(arr4) / sizeof(arr4[0]);
    ops=0;
    l_index=0, r_index=0;
    max_sum = maxSubArraySum(arr4, 0, n - 1, &ops, &l_index, &r_index);
    printf("\nInput array and sequence markers is:\n");
    printArrayWithMarkers(arr4,n,l_index,r_index);
    printf("\n\nMaximum contiguous sum is %d", max_sum);
    printf("\n\nNumber of ops: %d\n\n", ops);
 
    int arr5[] = {-5,10,-25,10,20,3,-6,2};
    n = sizeof(arr5) / sizeof(arr5[0]);
    ops=0;
    l_index=0, r_index=0;
    max_sum = maxSubArraySum(arr5, 0, n - 1, &ops, &l_index, &r_index);
    printf("\nInput array and sequence markers is:\n");
    printArrayWithMarkers(arr5,n,l_index,r_index);
    printf("\n\nMaximum contiguous sum is %d", max_sum);
    printf("\n\nNumber of ops: %d\n\n", ops);
 

    return 0;
}