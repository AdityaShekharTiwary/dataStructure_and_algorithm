#include<stdio.h>
#include <string.h>
#include<stdlib.h>
#include <time.h>

void merge(int arr[], int l, int m, int r, int *ops)
{
    int n1 = m - l + 1;
    int n2 = r - m;

    int Left[n1], Right[n2];

    for (int i = 0; i < n1; i++)
        Left[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        Right[j] = arr[m + 1 + j];

    int i=0,j=0,k=l;

    while (i < n1 && j < n2) {
        if (Left[i] <= Right[j]) {
            arr[k] = Left[i];
            i++;
        }
        else {
            arr[k] = Right[j];
            j++;
        }
        k++;
        (*ops)++;
    }

    while (i < n1) {
        arr[k] = Left[i];
        i++;
        k++;
        (*ops)++;
    }

    while (j < n2) {
        arr[k] = Right[j];
        j++;
        k++;
        (*ops)++;
    }
}

void mergeSort(int arr[], int l, int r, int *ops)
{
    if(l>=r){
        return;
    }
    int m =l+ (r-l)/2;
    mergeSort(arr,l,m,ops);
    mergeSort(arr,m+1,r,ops);
    merge(arr,l,m,r,ops);
}
int ternarySearch(int l, int r, int key, int ar[],int *a)
{
    while (r >= l) {
            *a=*a+1;
            int mid1 = l + (r - l) / 3;
            int mid2 = r - (r - l) / 3;
            if (ar[mid1] == key) {
                return mid1;
            }
            if (ar[mid2] == key) {
                return mid2;
            }
    
            if (key < ar[mid1]) {

                r = mid1 - 1;
            }
            else if (key > ar[mid2]) {
                l = mid2 + 1;
            }
            else {
                l = mid1 + 1;
                r = mid2 - 1;
            }
        }

        return -1;
}

void printArray(int A[], int size)
{
    int i;
    for (i=0; i < size; i++)
    printf("%d ", A[i]);
    printf("\n\n");
}



int main()
{
    int stock[90];
    int num=10;

    int n = sizeof(stock) / sizeof(stock[0]);

    for(int i=0;i<n;i++) {
        stock[i]=num;
        num++;
    }
    //printf("%d",stock[89]);   

    int arr[27];
    int m = sizeof(arr) / sizeof(arr[0]);
   // for(int i=0;i<90;i++) printf("%d ",stock[i]);
    srand(time(NULL));

    for (int i = 0; i < 27; i++){
        arr[i] = stock[rand() % 89];
    }
    int ops=0;

    printf("Original random Array:- \n");
    printArray(arr,m);

    mergeSort(arr,0,m-1,&ops);

    printf("Array after merge sort:- \n");
    printArray(arr,m);
    printf("Number of Merge ops:- %d\n\n",ops);

    // Array for generating random index for my target array
    int b[27];
    for(int i=0;i<27;i++) b[i]=i;

    int targetIdx[3];
    for (int i = 0; i < 3; i++){
        targetIdx[i] = b[rand() % 26];
    }

    // Target array which contains target elements for our trinary search
    int target[3]={arr[targetIdx[1]],arr[targetIdx[2]],8};

    for(int i=0;i<3;i++){
        int actions=0;
        int idx=ternarySearch(0,m-1,target[i],arr,&actions);

        printf("Target element %d found at : %d \n",target[i],idx);
        printf("Number of ops for trinary search:- %d\n\n",actions);
    }





    return 0;
}