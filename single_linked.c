#include <stdio.h>
#include <stdlib.h>

typedef struct linkedList
{
    int data;
    struct linkedList *next;

}S_Linked_List;

void initialise(S_Linked_List **aa_head)
{
    *aa_head=NULL;
}

void ins_sorted(S_Linked_List **aa_head, int n)
{
    S_Linked_List *tmp,*prev,*cur;
    tmp= (S_Linked_List*)malloc(sizeof(S_Linked_List));
    tmp->data=n;
    for(cur=*aa_head,prev=NULL;cur&&n>cur->data;cur=cur->next)
        prev=cur;
    tmp->next=cur;

    if(prev)
        prev->next=tmp;
    else
        *aa_head=tmp;

}

void printReverse(S_Linked_List *aa_head)
{
    if (aa_head == NULL) return;
    printReverse(aa_head->next);
    printf("%d ",aa_head->data);
}

void deleteNode(S_Linked_List** aa_head, int key)
{
    S_Linked_List* temp = *aa_head;
    S_Linked_List* prev = NULL;

    if (temp != NULL && temp->data == key)
    {
        *aa_head = temp->next;
        free(temp);
        return;
    }

    while (temp != NULL && temp->data != key)
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL)
        return;

    prev->next = temp->next;

    free(temp);
}

int main()
{
    S_Linked_List *S;
    initialise(&S);
    int x;
    while(1)
    {
        printf("Enter your choice:\n1.Insert in sorted order\n2.Reverse Display\n3.Delete\n3.Exit\n");
        scanf("%d",&x);

        switch(x)
        {
            case 1:
            printf("Enter number to be inserted: ");
            int m;
            scanf("%d",&m);
            ins_sorted(&S,m);
            printf("\n");
            break;

            case 2:
                printReverse(S);
                printf("\n");
            break;

            case 3:
                printf("Enter key value: ");
                int k;
                scanf("%d",&k);
                deleteNode(&S,k);
                printf("\n");
            break;

            case 4: exit(0);
            break;

            default: printf("Invalid Choice\n");
            }
    }

    return 0;
}

