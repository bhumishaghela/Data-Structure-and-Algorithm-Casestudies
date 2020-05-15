#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <ctype.h>
#define newnode (struct node*)malloc(sizeof(struct node))
struct node
{
char data;
struct node *next;
};
struct node * append(struct node *f,char data)//append node
{	struct node *s;
	if(f==NULL)
	{
		f=newnode;
		f->data=data;
		f->next=NULL;

	}
        else
	{
		s=f;
		while(s->next!=NULL) s=s->next;
		s->next=newnode;
		s=s->next;
		s->data=data;
		s->next=NULL;
		
	}
return f;
}


void display(struct node *f)//display link list
{
	while(f!=NULL)
	{
		printf("%c",f->data);
		f=f->next;
	}
}
int search(struct node *t,char data)//search element in linklist
{
int count=0;
	while(t!=NULL)
	{
	if(t->data==data)
	{
	count++;

	}
	t=t->next;
	}
return count;
}
struct node * insert(struct node *t,char d1,char d2)//insert element
{
int c=0,i=0;
struct node *t1;
struct node *t2;
struct node *s;
	s=newnode;
	s->data=d2;
	t1=t;
	while(t1!=NULL)
	{
		c++;
		if(t1->data==d1)break;
		t1=t1->next;
	}
	if(c==1)
	{
		s->next=t;
		t=s;
	}
	else
	{
	for(i=1,t2=t;i<c-1;i++)
	{
		t2=t2->next;
	}
	s->next=t2->next;
	t2->next=s;
	}
return t;
}
void main()
{
char string[100];
printf("Enter String");
scanf("%s",string);
int i=0,c1=0,c2=0,flag1=0,flag2=0,f1=0,f2=0;
char temp1,temp2;
struct node *h=NULL;
struct node *v1=NULL;
struct node *v2=NULL;
struct node *s=NULL;
struct node *t1=NULL;
struct node *s1=NULL;
struct node *s2=NULL;
for(i=0;i<strlen(string);i++)
{
	h=append(h,tolower(string[i]));//adding string to link list
}
display(h);
printf("\n");
s=h;
int a[strlen(string)];
for(i=0;i<strlen(string);i++)
{
a[i]=-1;
}
i=0;
while(s!=NULL)
{
c1=0;
c2=0;
flag1=0;
flag2=0;
f1=0;
f2=0;
s1=t1;

temp1=s->data;
flag1=search(t1,temp1);//element search from link list of letters whose frequency is greater than 0
f1=search(s2,temp1);//element search from link list of letters whose frequency 0
v1=s->next;
s=s->next;
if(s==NULL)
{
break;
}
v2=s->next;
temp2=s->data;
flag2=search(t1,temp2);
f2=search(s2,temp2);
	//taking two letters and counting frequencies	

	while(v1!=NULL)
	{
		if(v1->data==temp1 && flag1==0 )
		{
		c1++;
		
		

		}

		
	v1=v1->next;
	}
	while(v2!=NULL)
	{
		if(v2->data==temp2 && flag2==0)
		{
		c2++;
		
		

		}

		
	v2=v2->next;
	}
c1++;
c2++;
if(temp1==temp2&&(flag1==0||flag2==0))//both letters are equal and not present in link list
{
	char d1;
	int n=0;
	struct node *t;
	t=t1;
	while(t!=NULL)
	{
		if(t->next==NULL)
		{
			d1=t->data;
			break;
		}
		t=t->next;
	}
	t=t1;
	while(t!=NULL)//counting the frequency of last elements in link list
	{
		if(t->data==d1)
		{
			n++;
		}
		t=t->next;
	}
	if(n==0)//no data append
	{
		while(c1>0)
		{
		t1=append(t1,temp1);
		c1--;
		}
	}
	else if(n>=c1)//data in link list greater append
	{
		while(c1>0)
		{
		t1=append(t1,temp1);
		c1--;
		}
	}
	else if(n<c1)//data in link list smaller insert
	{
		t1=insert(t1,d1,temp1);
		while(c1>0)
		{
		t1=insert(t1,temp1,temp1);
		c1--;
		}
	}
}
else if(c1==1  && c2==1)//both have frequency 0
{
	printf("1");
	if(flag2==0 && f2==0)
	{
		s2=append(s2,temp2);
	}
	if(flag1==0 && f1==0)
	{
		s2=append(s2,temp1);
	}
}
else if(c1>=c2 && c1!=1 && c2!=1)//first letter frequency is greater than second letter frequency
{
	printf("2");
	char d1;
	int n=0;
	struct node *t;
	t=t1;
	while(t!=NULL)
	{
		if(t->next==NULL)
		{
		d1=t->data;
		break;
		}
	t=t->next;
	}
	t=t1;
	while(t!=NULL)
	{
		if(t->data==d1)
		{
		n++;
		}
	t=t->next;
	}
	if(n==0)
	{
		while(c1>0)
		{
			t1=append(t1,temp1);
			c1--;
		}
		while(c2>0)
		{
			t1=append(t1,temp2);
			c2--;
		}
	}
	else if(n>=c1)
	{
		while(c1>0)
		{
			t1=append(t1,temp1);
			c1--;
		}
		while(c2>0)
		{
			t1=append(t1,temp2);
			c2--;
		}
	}
	else if(n<c1)
	{
		if(n<c2)
		{
			t1=insert(t1,d1,temp2);
			c2--;
			while(c2>0)
			{
				t1=insert(t1,temp2,temp2);
				c2--;
			}
			t1=insert(t1,temp2,temp1);
			while(c1>0)
			{
				t1=insert(t1,temp1,temp1);
				c1--;
			}
		}
		else if(n>=c2)
		{
		t1=insert(t1,d1,temp1);
		c1--;
		while(c1>0)
		{
				t1=insert(t1,temp1,temp1);
				c1--;
		}
		while(c2>0)
		{
			t1=append(t1,temp2);
		c2--;
		}
		}
	}
}
else if(c1<c2 && c1!=1 && c2!=1)//first letter frequency is less than second letter frequency
{
printf("3");
char d1;
int n=0;
struct node *t;
t=t1;
	while(t!=NULL)
	{
	if(t->next==NULL)
	{
		d1=t->data;
		break;
	}
	t=t->next;
	}
t=t1;
	while(t!=NULL)
	{
	if(t->data==d1)
	{
	n++;
	}
	t=t->next;
	}
if(n==0)
{
	while(c2>0)
	{
	t1=append(t1,temp2);
	c2--;
	}
	while(c1>0)
	{
	t1=append(t1,temp1);
	c1--;
	}
}
else if(n<c2)
{
if(n<c1)
{
t1=insert(t1,d1,temp1);
		c1--;
		while(c1>0)
		{
			t1=insert(t1,temp1,temp1);
			c1--;
		}
		t1=insert(t1,temp1,temp2);
		while(c2>0)
		{
			t1=insert(t1,temp2,temp2);
			c2--;
		}
}
else if(n>=c1)
{
	t1=insert(t1,d1,temp2);
	c2--;
	while(c2>0)
	{
			t1=insert(t1,temp2,temp2);
			c2--;
	}
	while(c1>0)
	{
		t1=append(t1,temp1);
	c1--;
	}
}
}
else if(n>=c2)
{
while(c2>0)
{
t1=append(t1,temp2);
c2--;
}
while(c1>0)
{
t1=append(t1,temp1);
c1--;
}
}

}
else if(c1==1 &&c2>1 )//first letter is already in  link list
{
printf("4");
	if(flag1==0 && f1==0)
	{
	s2=append(s2,temp1);
	}
char d1;
	int n=0;
	struct node *t;
	t=t1;
		while(t!=NULL)
		{
		if(t->next==NULL)
		{
			d1=t->data;
			break;
		}
		t=t->next;
		}
	t=t1;
	while(t!=NULL)
	{
		if(t->data==d1)
		{
		n++;
		}
		t=t->next;
	}
 	if(n==0)
	{
		while(c2>0)
		{
			t1=append(t1,temp2);
			c2--;
		}
	}
	else if(n>=c2)
	{
		while(c2>0)
		{
			t1=append(t1,temp2);
			c2--;
		}
	}
	else if(n<c2)
	{
		t1=insert(t1,d1,temp2);
		c2--;
		while(c2>0)
		{
			t1=insert(t1,temp2,temp2);
			c2--;
		}
		
	}

	
}

else if(c2==1 && c1>1)//second letter is already in link list
{
printf("5");
	if(flag2==0 &&f2==0)
	{
	s2=append(s2,temp2);
	
	
	}
	char d1;
	int n=0;
	struct node *t;
	t=t1;
		while(t!=NULL)
		{
		if(t->next==NULL)
		{
			d1=t->data;
			break;
		}
		t=t->next;
		}
	t=t1;
		while(t!=NULL)
		{
		if(t->data==d1)
		{
		n++;
		}
		t=t->next;
		}
 	if(n==0)
	{
		while(c1>0)
		{
			t1=append(t1,temp1);
			c1--;
		}
	}
	else if(n>=c1)
	{
		while(c1>0)
		{
			t1=append(t1,temp1);
			c1--;
		}
	}
	else if(n<c1)
	{
	t1=insert(t1,d1,temp1);
	c1--;
		while(c1>0)
		{
			t1=insert(t1,temp1,temp1);
			c1--;
		}
	}
	
	
			
	
}
s=s->next;
}


display(t1);
printf("\n");

while																																(s2!=NULL)
{
t1=append(t1,s2->data);
s2=s2->next;
}
display(t1);

}

