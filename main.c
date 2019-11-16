#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

struct node 
{
  int key;
  void * data;
  struct node * link;

};

typedef struct node * listptr;

void push(int key,listptr *head)
{
    listptr temp = (struct node *)malloc(sizeof(struct node));
    temp->key=key;
    int *n;
    char *c;
    float *f;
    switch (key)
    {
     case 1 : printf("Enter the integer value \n");
             n=(int *)malloc(sizeof(int));
	     scanf("%d",n); 
	     temp->data=n;
             break;
             
     case 2 : printf("Enter the float value \n");
             f=(float *)malloc(sizeof(float));
             scanf("%f",f);
	     temp->data=f;
             break;

     case 3 : printf("Enter the char value \n");
            c=(char *)malloc(sizeof(char));
             scanf("%c",c);
	     scanf("%c",c);
	      
	     temp->data=c;
             break;      
    }

	temp->link=*head;
	*head=temp;

	    
    

}
void display(listptr head)
{
	listptr temp=head;
	int count=1,n;
	char c;
	float f;
	
	while(temp!=NULL)
	{
		switch(temp->key)
		{
			case 1:printf("The data in node number %d is an integer : ",count);
			       printf("%d\n",*(int *)(temp->data));
			       break;
			case 2:printf("The data in node number %d is float : ",count);
                              
			       printf("%f\n",*(float *)(temp->data));
                               break;
			case 3:printf("The data in node number %d is a char : ",count);
                              
			       printf("%c\n",*(char *)(temp->data));
                               break;
			
		}
		count++;
		temp=temp->link;
	}
	
}
listptr pop(listptr *head)
{
	listptr temp;
	temp=*head;
	listptr ptr=(listptr)malloc(sizeof(struct node));
	ptr->key=temp->key;
	ptr->data=temp->data;
	ptr->link=NULL;
	*head=temp->link;
	temp->link=NULL;
	free(temp);
	return ptr;
}
void main()
{
	listptr head=NULL,temp;
	int ch,key;
	while(1)
	{
		printf("Enter 1 for push, 2 for pop, 3 for display and 4 for exit\n");
		scanf("%d",&ch);
   		switch(ch)
		{
			case 1: printf("Enter 1 for int, 2 for float, 3 for char\n");
				scanf("%d",&key);
				push(key,&head);
				break;
			case 2:if(head==NULL)
				       printf("Stack underflow\n");
			       else {
				       temp=pop(&head);
				       switch(temp->key)
       					 {
                				case 1:printf("%d has been popped out\n",*(int*)(temp->data));
                        				break;
                				case 2:printf("%f has been popped out\n",*(float *)(temp->data));
                       					break;
                				case 3:printf("%c has been popped out\n",*(char *)(temp->data));
                       					break;
        				}
				}

			       break;
			case 3: if(head!=NULL)
				display(head);	
				else
					printf("Empty Linked List \n");
				break;
			case 4:exit(0);
			default:printf("Invalid choice\n");
	
		}
	}	
}	