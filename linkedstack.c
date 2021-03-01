#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<limits.h>//for INT_MIN
#define CAPACITY 1000 //Stack maximum capacity
//Define stack node structure
struct stack
{
 int data;
 struct stack *next;
 }
 *top;
 //stack size
 int size=0;
 /* function declaration to perfom push and pop on stack */
 void push(int element);
 int pop();
 void main()
 {
  int choice,data;
  clrscr();
  while(1)
  {
   /*menu*/
   printf("-------------------------------------\n");
   printf("STACK IMPLEMENTATION PROGRAM\n");
   printf("-------------------------------------\n");
   printf("1.Push\n");
   printf("2.Pop\n");
   printf("3.Size\n");
   printf("4.Exit\n");
   printf("-------------------------------------\n");
   printf("Enter your choice:\n");
   scanf("%d",&choice);
   switch(choice)
   {
    case 1:
	printf("Enter data to push into stack:\n");
	scanf("%d",&data);
	//push elt to stack
	push(data);
	break;
    case 2:
	data=pop();
	//if stack is not empty
	if(data!=INT_MIN)
	  printf("Data=>%d\n",data);
	break;
    case 3:
	printf("Stack size:%d\n",size);
	break;
    case 4:
	printf("Exiting from app\n");
	exit(0);
	break;
    default:
	printf("Invalid choice,please try again\n");
  }
  printf("\n\n");
  getch();
 }
}
void push(int element)
{
 //check stack overflow
 struct stack *newNode;
 if(size>=CAPACITY)
 {
  printf("Stack overflow,can't add more element to stack\n");
  return;
 }
 //create a new node and push to stack
 newNode=(struct stack *)malloc(sizeof(struct stack));
 //Assign data to new node in stack
 newNode->data=element;
 //next elt after new node should be current top elt
 newNode->next=top;
 //make sure new node is always at top
 top=newNode;
 //increase elt count in stack
 size++;
 printf("Data pushed to stack\n");
}
/* fn to pop elt from top of stack*/
int pop()
{
 int data=0;
 struct stack * topNode;
 //check stack underflow
 if(size<=0||!top)
 {
  printf("Stack is empty\n");
  //Throw empty stack/exception
  //since c doesn't have concept of exception
  //hence rtn min integer value as error value
  //later in code check if rtn value is INT_MIN,then
  //stack is empty
  return INT_MIN;
 }
 //copy refernce of stack top to some temp variable
 //since we need to dlt current stack top and make
 //stack top its next elt
 topNode=top;
 //copy data from stack's top elt
 data=top->data;
 //move top to its next elt
 top=top->next;
 //dlt the previous top most stack elt from memory
 free(topNode);
 //decrement stack size
 size--;
 return data;
}