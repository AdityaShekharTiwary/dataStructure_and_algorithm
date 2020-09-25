#include <stdio.h>
#include <stdlib.h>

typedef struct doubly_linked_list
{
    int data;
    struct doubly_linked_list *prev,*next;
}DLL;

void initialise(DLL **aah)
{
    *aah=NULL;
}

void ins_ser(DLL **aah, int n)
{
    DLL *cur,*prv,*tmp;
    tmp=(DLL*)malloc(sizeof(DLL));

    tmp->data=n;
    tmp->next=tmp->prev=NULL;

    for(cur=*aah,prv=NULL; cur; cur=cur->next)
        prv=cur;

    if(prv)
    {
        prv->next=tmp;
        tmp->prev=prv;
    }
    else
        *aah=tmp;
}

void deletion(DLL **aah, int n)
{
    DLL *cur,*prv;
        int flag=0;
    for(cur=*aah,prv=NULL; cur; cur=cur->next)
    {
        if(cur->data==n)
        {
            flag=1;
            if(prv)
            {
                prv->next=cur->next;
                if(cur->next)
                    (cur->next)->prev=prv;
            }
            else
            {
                *aah=cur->next;
                if(cur->next)
                    (cur->next)->prev=NULL;
            }
            free(cur);
            printf("\n%d has been deleted",n);
            return;
        }
        else
            prv=cur;
    }
    if(!flag)
        printf("\n%d not found",n);
}
void dispFor(DLL *ah)
{
    if(ah==NULL)
    {
        printf("EMPTY LIST");
        return;
    }
    while(ah)
    {
        printf("%d ",ah->data);
        ah=ah->next;
    }
}


int main()
{
    DLL *D;
    initialise(&D);

    while(1)
    {
        printf("Enter your choice:\n1.Insertion\n2.Deletion of integer\n3.Display\n4.Exit\n");
        int ch;
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: printf("\nEnter number: ");
            int m;
            scanf("%D",&m);
            ins_ser(&D,m);
            break;

            case 2: printf("\nEnter number: ");
            int x;
            scanf("%D",&x);
            deletion(&D,x);
            break;
            case 3: printf("\n");
            dispFor(D);
            break;

            case 4: exit(0);

            default: printf("INVALID CHOICE");
        }
        printf("\n\n");
    }
    return 0;
}

