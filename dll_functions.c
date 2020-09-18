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

void ins_sor(DLL **aah,int n)
{
    DLL *p,*cur,*tmp;
    tmp=(DLL*)malloc(sizeof(DLL));
    tmp->data=n;
    tmp->next=tmp->prev=NULL;

    for(cur=*aah,p=NULL; cur && n>cur->data; cur=cur->next)
        p=cur;

    tmp->next=cur;

    if(cur)
        cur->prev=tmp;

    if(p)
    {
        p->next=tmp;
        tmp->prev=p;
    }
    else
        *aah=tmp;

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

void dispRev(DLL *ah)
{
    if(ah==NULL)
    {
        printf("EMPTY LIST");
        return;
    }

    while(ah->next)
        ah=ah->next;

    while(ah)
    {
        printf("%d ",ah->data);
        ah=ah->prev;
    }
}

int main()
{
    DLL *D;
    initialise(&D);

    while(1)
    {
        printf("Enter your choice:\n1.Insertion sorted\n2.Insertion serial\n3.Deletion of integer\n4.Display in Forward manner\n5.Display in Reverse manner\n6.Exit\n");
        int ch;
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: printf("\nEnter number: ");
            int n;
            scanf("%D",&n);
            ins_sor(&D,n);
            break;

            case 2: printf("\nEnter number: ");
            int m;
            scanf("%D",&m);
            ins_ser(&D,m);
            break;

            case 3: printf("\nEnter number: ");
            int x;
            scanf("%D",&x);
            deletion(&D,x);
            break;

            case 4: printf("\n");
            dispFor(D);
            break;

            case 5: printf("\n");
            dispRev(D);
            break;

            case 6: exit(0);

            default: printf("INVALID CHOICE");
        }
        printf("\n\n");
    }
    return 0;
}
