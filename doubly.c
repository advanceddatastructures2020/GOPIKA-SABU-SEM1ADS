#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node
{
 struct node *prev;
 struct node *next;
 int data;
};
struct node *head;
void insertion_beginning();
void insertion_last();
void insertion_specified();
void display();
void main()
{
 int choice=0;
 clrscr();
 while(choice!=9)
 {
  printf("\n**************MENU***************\n");
  printf("\n choose one option from the following list \n");
  printf("=================================================\n");
  printf("\n1.Insert in beginning\n 2.Insert at last\n 3.Insert at specified position\n 4.Display\n 5.Exit\n");
  printf("Enter your choice:");
  scanf("\n%d",&choice);
  switch(choice)
  {
   case 1:
	 insertion_beginning();
	 break;
   case 2:
	 insertion_last();
	 break;
   case 3:
	 insertion_specified();
	 break;
   case 4:
	 display();
	 break;
   case 5:
	 exit(0);
	 break;
   default:
	 printf("Enter the valid choice!");
  }
 }
 getch();
}
void insertion_beginning()
{
 struct node *ptr;
 int item;
 ptr=(struct node *)malloc(sizeof(struct node));
 if(ptr==NULL)
 {
  printf("\nOVERFLOW");
 }
 else
 {
  printf("\n Enter item value:");
  scanf("%d",&item);
  if(head==NULL)
  {
   ptr->next=NULL;
   ptr->prev=NULL;
   ptr->data=item;
   head=ptr;
  }
  else
  {
   ptr->data=item;
   ptr->prev=NULL;
   ptr->next=head;
   head->prev=ptr;
   head=ptr;
  }
  printf("\nNode inserted\n");
 }
}
void insertion_last()
{
 struct node *ptr,*temp;
 int item;
 ptr=(struct node *)malloc(sizeof(struct node));
 if(ptr==NULL)
 {
  printf("\n OVERFLOW\n");
 }
 else
 {
  printf("\n Enter value:");
  scanf("%d",&item);
  ptr->data=item;
  if(head==NULL)
  {
   ptr->next=NULL;
   ptr->prev=NULL;
   head=ptr;
  }
  else
  {
   temp=head;
   while(temp->next!=NULL)
   {
    temp=temp->next;
   }
   temp->next=ptr;
   ptr->prev=temp;
   ptr->next=NULL;
  }
 }
 printf("\n Node inserted\n");
}
void insertion_specified()
{
 struct node *ptr,*temp;
 int item,loc,i;
 ptr=(struct node *)malloc(sizeof(struct node));
 if(ptr==NULL)
 {
  printf("\n OVERFLOW");
 }
 else
 {
  temp=head;
  printf("Enter the location:");
  scanf("%d",&loc);
  for(i=0;i<loc;i++)
  {
   temp=temp->next;
   if(temp==NULL)
   {
    printf("\n There are less than %d elements",loc);
    return;
   }
  }
  printf("Enter value:");
  scanf("%d",item);
  ptr->data=item;
  ptr->next=temp->next;
  ptr->prev=temp;
  temp->next=ptr;
  temp->next->prev=ptr;
  printf("\n Node inserted\n");
 }
}
void deletion_beginning()
{
 struct node *ptr;
 if(head==NULL)
 {
  printf("\n UNDERFLOW");
 }
 else if(head->next==NULL)
 {
  head=NULL;
  free(head);
  printf("\n Node deleted\n");
 }
 else
 {
  ptr=head;
  head=head->next;
  head->prev=NULL;
  free(ptr);
  printf("\n Node deleted\n");
 }
}
void deletion_last()
{
 struct node *ptr;
 if(head==NULL)
 {
  printf("\n UNDERFLOW");
 }
 else if(head->next==NULL)
 {
  head=NULL;
  free(head);
  printf("\n Node deleted\n");
 }
 else
 {
  ptr=head;
  if(ptr->next!=NULL)
  {
   ptr=ptr->next;
  }
  ptr->prev->next=NULL;
  free(ptr);
  printf("\n Node deleted\n");
 }
}
void deletion_specified()
{
 struct node *ptr,*temp;
 int val;
 printf("\n Enter the data after which the node is to be deleted:");
 scanf("%d",val);
 ptr=head;
 while(ptr->data!=val)
 ptr=ptr->next;
 if(ptr->next==NULL)
 {
  printf("\n can't delete\n");
 }
 else if(ptr->next->next==NULL)
 {
  ptr->next=NULL;
 }
 else
 {
  temp=ptr->next;
  ptr->next=temp->next;
  temp->next->prev=ptr;
  free(temp);
  printf("\n node deleted\n");
 }
}
void display()
{
 struct node *ptr;
 printf("\n printing values:\n");
 ptr=head;
 while(ptr!=NULL)
 {
  printf("%d\n",ptr->data);
  ptr=ptr->next;
 }
}