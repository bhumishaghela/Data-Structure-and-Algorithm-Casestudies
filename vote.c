#include<stdio.h>
#include <string.h>
#include<stdlib.h>
void main()
{
FILE *fp;
char c[3];
char *tok;
int i=0,candidate[100],f1,f2,f3,voter[100],v1,c1,l1,l2,l3,n1,n2,count=0;
printf("Enter number of voters");
scanf("%d",&n1);
printf("Enter number of candidates");
scanf("%d",&n2);
for(i=1;i<=n1;i++)
{
voter[i]=0;
}
for(i=1;i<=n2;i++)
{
candidate[i]=0;
}
fp=fopen("vote.txt","r");
if(fp==NULL)
{
printf("ERROR");
}
else
{
 while (EOF != fscanf(fp, "%[^\n]\n",c))
    {
         printf("%s\n", c);
	tok=strtok(c," ");
      	while( tok != NULL ) {
		count++;
	      if(count%2==0)c1=atoi(tok);
	      else v1=atoi(tok);
             tok = strtok(NULL, " ");
	     
  			    }
	if(voter[v1]==0)
	{
	voter[v1]=c1;
	
	candidate[c1]++;
	}
	else
	{
	printf("FRAUD  voter_id:%d\n",v1);
	}
	
	
	
    }

l3=l1=l2=candidate[1];
for(i=1;i<=n2;i++)
{

		if(candidate[i]>l1)
		{
		l1=candidate[i];
		f1=i;
		
		}
		
}

for(i=1;i<=n2;i++)
{

		if(candidate[i]>l2 && candidate[i] <=l1 &&i!=f1)
		{
		l2=candidate[i];
		f2=i;
	
		}
		
}
for(i=1;i<=n2;i++)
{

		if(candidate[i]>l3 && candidate[i] <=l2 && i!=f2 && i!=f1)
		{
		l3=candidate[i];
		f3=i;
	
		}
		
}
printf("FIRST\n");
printf("Candidate_id:%d Votes=%d\n",f1,l1);
printf("SECOND\n");
printf("Candidate_id:%d Votes=%d\n",f2,l2);
printf("THIRD\n");
printf("Candidate_id:%d Votes=%d\n",f3,l3);
fclose(fp);
}
}
