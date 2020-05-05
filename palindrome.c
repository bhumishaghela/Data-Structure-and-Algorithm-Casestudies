#include<stdio.h>
#define SIZE 10
#define BOTTOM  -1
//creating a structure of stack which has array of integers and top(indicates top of stack)
typedef struct stack
{
	int data[SIZE];
        int top;
}s1;
//initializing the stack to -1 which indicates the bottom of stack
void initstack(struct stack * s)
{
	s->top=BOTTOM;
}
//checking whether stack is empty if top of stack is -1 then returns 1 else 0
int isempty(struct stack *s)
{
	return s->top==BOTTOM?1:0;
	
}
//checking whether stack is full if stack top is equal to its predefined size-1(as stack starts from 0) returns 1 else 0
int isfull(struct stack *s)
{
	return s->top==SIZE-1?1:0;
}
//if stack is not full add element at top and increment top
void push(struct stack *s,int d)
{
	if(isfull(s)) printf("stack is full");
	else {
           s->data[++(s->top)]=d;}
}
//if stack is not empty return element at top and decrement top
int pop(struct stack *s)
{
	if(isempty(s)) printf("stack is empty");
	else return s->data[s->top--];
}

void main()
{
	int n,i,a[5],temp,r=0,s,t,count=0;
	s1 st;
	//initializing stack
	initstack(&st);
	
	printf("Enter number");
	scanf("%d",&n);
	t=n;
	i=10;
	while(n!=0)
	{	temp=n%i;//getting remainder
		n=n/i;//getting quotient and quotient is new n
		push(&st,temp);//pushing remainder in stack 
		a[r]=temp;// pushing remainder in array
		r++;

		

	}

// so now if n=123 array=321 stack=123 where 1 is stack top

for(i=0;i<r;i++)
{
	if(a[i]==pop(&st))//popping element of stack and checking with array element
	{
	count++;
	}
}
//counting whether the count is equal to length of array
if(count==r)
{
printf("%d is palindrome",t);
}
else
{
printf("%d is not palindrome",t);
}




}
