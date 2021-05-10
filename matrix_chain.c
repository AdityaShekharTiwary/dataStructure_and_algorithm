#include<stdio.h>
#include<string.h>
#define INT_MAX 30000

void printParenthesis(int i, int j, int n, int* bracket, int *name, int *ops)
{
    if (i == j) {
        printf("A%d",(*name)++);
        *ops+=1;
        return;
    }
 
    printf("(");
    printParenthesis(i, *((bracket + i * n) + j), n,
                     bracket, name,ops);

    printParenthesis(*((bracket + i * n) + j) + 1, j, n,
                     bracket, name,ops);
    printf(")");
}


int matrixChainOrder(int p[], int n, int* ops)
{
    int m[n][n];

    int bracket[n][n];

    for (int i = 1; i < n; i++)
        m[i][i] = 0;

    for (int L = 2; L < n; L++)
    {
        for (int i = 1; i < n - L + 1; i++)
        {
            int j = i + L - 1;
            m[i][j] = INT_MAX;
            for (int k = i; k <= j - 1; k++)
            {
                *ops+=1;
                int q = m[i][k] + m[k + 1][j]
                        + p[i - 1] * p[k] * p[j];
                if (q < m[i][j])
                {
                    *ops+=1;
                    m[i][j] = q;
                    bracket[i][j] = k;
                }
            }
        }
    }
    int name = 1;
    printf("Optimal Parenthesization is : ");
    printParenthesis(1, n - 1, n, (int*)bracket, &name,ops );
    return m[1][n - 1];

}

void printDimensionArray(int* a,int n){
    int i;
    printf("Dimensions are: \n");
    for(i=0;i<(n-1);i++)
        printf("A%d: %d x %d   ",(i+1),a[i],a[i+1]);
    printf("\n\n");
}

// Driver code
int main()
{
    int arr[] = { 30, 35, 15, 5, 10, 20, 25 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int ops=0;
    printf("\nThe dimension array is:\n");
    printDimensionArray(arr,n);
    int cost = matrixChainOrder(arr, n, &ops);
    printf("\nOptimal cost is: %d ops is %d\n",cost,ops);
 
    int arr2[] = { 5, 8, 10, 4, 14, 12 };
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    int ops2=0;
    printf("\nThe dimension array is:\n");
    printDimensionArray(arr2,n2);
    int cost2 = matrixChainOrder(arr2, n2, &ops2);
    printf("\nOptimal cost is: %d ops is %d\n",cost2,ops2);
 
    int arr3[] = { 10, 15, 20 };
    int n3 = sizeof(arr3) / sizeof(arr3[0]);
    int ops3=0;
    printf("\nThe dimension array is:\n");
    printDimensionArray(arr3,n3);
    int cost3 = matrixChainOrder(arr3, n3, &ops3);
    printf("\nOptimal cost is: %d ops is %d\n",cost3,ops3);
 
    int arr4[] = { 10, 10, 10, 10, 10 };
    int n4 = sizeof(arr4) / sizeof(arr4[0]);
    int ops4=0;
    printf("\nThe dimension array is:\n");
    printDimensionArray(arr4,n4);
    int cost4 = matrixChainOrder(arr4, n4, &ops4);
    printf("\nOptimal cost is: %d ops is %d\n",cost4,ops4);
 
    int arr5[] = { 20, 15, 10, 15, 25, 15, 10, 15, 30 };
    int n5 = sizeof(arr5) / sizeof(arr5[0]);
    int ops5=0;
    printf("\nThe dimension array is:\n");
    printDimensionArray(arr5,n5);
    int cost5 = matrixChainOrder(arr5, n5, &ops5);
    printf("\nOptimal cost is: %d ops is %d\n",cost5,ops5);
 
 

    return 0;
}