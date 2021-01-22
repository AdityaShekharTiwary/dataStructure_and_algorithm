#include <stdio.h>
#include<bits/stdc++.h>
#include <stdlib.h>
#define MAX 500
#include<cstdio>
using namespace std;
typedef struct bs_tree
{
    int data;
    struct bs_tree *left, *right;
}BS_TREE;

void initialise(BS_TREE **aa_root)
{
    *aa_root=NULL;
}

void ins_rec(BS_TREE **aa_root, int n)
{
    if(*aa_root==NULL)
    {
        *aa_root=(BS_TREE*)malloc(sizeof(BS_TREE));
        (*aa_root)->data=n;
        (*aa_root)->left=(*aa_root)->right=NULL;
    }
    else if(n<=(*aa_root)->data)
        ins_rec(&(*aa_root)->left,n);
    else
        ins_rec(&(*aa_root)->right,n);

}


void sorted(BS_TREE *a_root)
{
    if(a_root==NULL)
        return;
    else
    {
        sorted(a_root->left);
        printf("%d ",a_root->data);
        sorted(a_root->right);
    }
}

int height(BS_TREE *a_root)
{
    if(!a_root) return 0;
    return max(height(a_root->left),height(a_root->right)+1);
}

int main()
{
    BS_TREE *T;
    initialise(&T);

    while(1)
    {
        printf("Enter your choice:\n1.Insert \n2.Sorted \n3.height\n4.Exit\n");
        int ch;
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: printf("Enter number: ");
                int n;
                scanf("%d",&n);
                ins_rec(&T,n);
                printf("\n");
                break;

            case 2: sorted(T);
                printf("\n");
                break;

            case 3: height(T);
                printf("\n");
                break;

            case 4: exit(0);
        }
    }
    return 0;
}


