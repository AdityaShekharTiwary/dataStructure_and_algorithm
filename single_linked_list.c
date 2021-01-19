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

void display(S_Linked_List *a_head)
{
    for(;a_head;a_head=a_head->next)
        printf("%d\t",a_head->data);
    printf("\n");
}
int main()
{
    S_Linked_List *S;
    initialise(&S);
    int x;
    while(1)
    {
        printf("Enter your choice:\n1.Insert in sequential order\n2.Insert in sorted order\n3.Display\n4.Exit\n");
        scanf("%d",&x);

        switch(x)
        {
            case 1:
            printf("Enter number to be inserted: ");
            int m;
            scanf("%d",&m);
            ins_sorted(&S,m);
            break;

            case 2: display(S);
            break;

            case 3: exit(0);
            break;

            default: printf("Invalid Choice\n");
            }
    }

    return 0;
}
