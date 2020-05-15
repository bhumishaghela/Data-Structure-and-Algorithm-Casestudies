#include<stdio.h>
#include<stdlib.h>
#define newnode (struct treenode *) malloc(sizeof(struct treenode))
struct treenode
{
struct treenode *l;
int data;
struct treenode *r;
}*s=NULL,*t1=NULL,*t2=NULL;
struct treenode *append(struct treenode *f,int data)
{
s=newnode;
s->data=data;
s->l=NULL;
s->r=NULL;

if(f==NULL)
{
	f=s;
}
else
{
	t1=f;
	while(t1!=NULL)
	{	t2=t1;
		if(data<=t1->data)t1=t1->l;
		else t1=t1->r;
	}
	if(data<=t2->data)t2->l=s;
	else t2->r=s;
		

}
return f;
}
void inorder(struct treenode *t)
{
if(t!=NULL)
{
inorder(t->l);
printf("%d\n",t->data);

inorder(t->r);
}
}
struct treenode * merge(struct treenode *t1,struct treenode *t2)
{
	if(!t1) return t2; 
    	if (!t2) return t1; 
       t1->data=t1->data+ t2->data; 
       t1->l = merge(t1->l, t2->l); 
       t1->r = merge(t1->r, t2->r); 
       return t1; 

}


void main()
{
	int a[8],b[8];
	int i=0,n1,n2;
	struct treenode *tree1=NULL;
	printf("Enter Length of Tree 1");
	scanf("%d",&n1);
	printf("Enter Tree 1");
		for(i=0;i<n1;i++)
		{
			scanf("%d",&a[i]);
			tree1=append(tree1,a[i]);
		}
	printf("Tree 1\n");
	inorder(tree1);
	struct treenode *tree2=NULL;
	printf("Enter Length of Tree 2");
	scanf("%d",&n2);
	printf("Enter Tree 2");
		for(i=0;i<n2;i++)
		{
			scanf("%d",&b[i]);
			tree2=append(tree2,b[i]);
		}
	printf("Tree 2\n");
	inorder(tree2);
	struct treenode *tree3=NULL;
	tree3=merge(tree1,tree2);
	printf("Merged Tree is\n");
	inorder(tree3);
}
