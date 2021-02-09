#include <stdio.h>
#include<conio.h>
#define MAX 10
       
    int stack[MAX];
	int top=-1;
	void push(int item);
	int pop();
	int peek();
	int isempty();
	int isfull();
	void display();
	
	main()
	    {
	    	int choice,item;
	    	while(1)
	    	    {
	    	    	printf("1,push\n");
	    	    	printf("2,pop\n");
	    	    	printf("3,diplay the top element\n");
	    	    	printf("4,display all stack element\n");
	    	    	printf("5,quit\n");
	    	    	printf("enter your choice :");
	    	    	scanf("%d",&choice);
	    	    	switch(choice)
	    	    	      {
	    	    	      	case 1:
	    	    	      		printf("Enter thr item to be pushed");
	    	    	      		scanf("%d" , &item);
	    	    	      		push(item);
	    	    	      		break;
	    	    	      		
	    	    	      	case 2:
							    item=pop();
								printf("poped item is : %d \n",item);
								break;
							
							case 3:
							    printf("item at the top is : %d\n",peek());
								break;
							
							case 4:
							    display();
								break;
								
						   
								 
							default:
							     printf("wrong choice\n");
								 	 	
						  }
				}
		}
       
        void push(int item)
           {
           	if(isfull())
           	  {
           	  	printf("stack overflow\n");
           	  	
			   }
			   
			   top=top+1;
			   stack[top]=item;
			   
		   }
		   
		int pop()
		   {
		   	int item;
		   	if(isempty())
		   	   {
		   	   	 printf("stack is underflow");
		   	   	 
		   	   	 
     			 }
     			 
     		 item=stack[top];
			 top=top-1;
			 return item;	 
			  } 
			  
		int peek()
		    {
		    	if(isempty())
		    	   {
		    	   	printf("Stack underflow \n");
		    	   		    	   	
				   }
				   return stack[top];
				   
			}
		
		int isempty()
		    {
		    	if(top==MAX-1)
		    	return 1;
		    	else
		    	return 0;
			}	
			
		int isfull()
		    {
		    	if(top==-1)
		    	return 1;
		    	else
		    	return 0;
			}	
		
		void display()
		    {
		    	int i;
		    	if(isempty())
		    	{
		    		printf("Stack is empty\n");
		    		return;
				}
				else
				 printf("Stack elements :\n");
				    for(i=top;i>=0;i--)
				     {
				      printf("%d\n", stack[i]);
				      printf("\n");
				   