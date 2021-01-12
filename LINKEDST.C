#include<stdio.h>
#include<conio.h>
#include<limits.h>

#define CAPACITY 10000

struct stack
{
	int data;
	struct stack *next;
}*top;

int size=0;

void push(int element);
int pop();

int main()
{
	int choice,data;
	while(1)
	{
		printf("STACK IMPLIMENTATON");
		printf("1.push\n2.pop\n3.size\n4.exit\n");
		printf("enter your choice : ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				printf("enter data to push into stack :");
				scanf("%d",&data);
				push(data);
				break;
			case 2:
				data=pop();
				if(data != INT_MIN)
					printf("data => %d\n",data);
				break;
			case 3:
				printf("stack size : %d\n",size);
				break;
			case 4:
				printf("exiting from app \n");
				exit(0);
				break;
			default:
				printf("invalid input !! try again\n ");
		}
		printf("\n\n");
	}


}

void push(int element)
{
	struct stack* newnode=(struct stack*)malloc(sizeof(struct stack));
	if(size >= CAPACITY)
	{
		printf("stack overflow, cant add more values\n ");
		return;
	}

	newnode->data=element;
	newnode->next=top;
	top=newnode;
	size++;
	printf("data pushed to stack \n ");
}

int pop()
{
	int data = 0;
	struct stack *topnode;
	if(size <=0 || !top)
	{
		printf("empty stack!");

	return INT_MIN;
	}
	topnode=top;
	data=top->data;
	top=top->next;
	free(topnode);
	size--;
	return data;
}


