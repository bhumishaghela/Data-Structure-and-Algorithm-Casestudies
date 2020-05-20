#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
char *get_timestamp(FILE *fp)
{
unsigned long timestamp[100];
int entry_count[100],exit_count[100],total_count[100],flag=0,i=0,j=0,max_people=0,k=0,m=0,l=0;
char *type,*ptr;
timestamp[0]=(unsigned long)time(NULL); 
entry_count[0]=0;
exit_count[0]=0;
total_count[0]=0;
char *tok,*t1,*t2[10],*t3[10][10];
char c[100];
if(fp==NULL)
{
printf("ERROR");
}
else
{
 while (EOF != fscanf(fp, "%[^\n]\n",c))
    {
        j=0;
	
	tok=strtok(c,",");
      	while( tok != NULL ) {
		
		t2[j]=tok;
		
		j++;
         tok = strtok(NULL, ",");
	     
  	 }
    	
	for(k=0;k<j;k++)
	{
	m=0;

	
	t1=strtok(t2[k],":");
		while(t1!=NULL)
		{	t3[k][m]=t1;
			
			m++;
			t1=strtok(NULL,":");
		}
		
		for(l=0;l<m;l++)
		{
		   if(strstr(t3[k][l],"timestamp"))
			{
			i++;
			timestamp[i]=strtoul(t3[k][l+1],&ptr,10);
			
			}
		   else if(strstr(t3[k][l],"type"))
			{
			type=t3[k][l+1];
			if(strstr(type,"enter"))
			{
			entry_count[i]=atoi(t3[k-1][l+1]);
		
			total_count[i]=total_count[i-1]+entry_count[i];	
			
			}
			else if(strstr(type,"exit"))
			{
			
			exit_count[i]=atoi(t3[k-1][l+1]);
			
			total_count[i]=total_count[i-1]-exit_count[i];
			
			
			}
						

		                	
			}
	
		}
	}
	
	
    }
}
fclose(fp);
j=0;
max_people=total_count[j];
for(j=1;j<=i;j++)
{
if(total_count[j]>max_people)
{
max_people=total_count[j];
flag=j;
}
}
char data[50];
char *d1=data;
if(flag==j-1)
{
sprintf(data,"{start timestamp:%lu end timestamp:%lu}",timestamp[flag],timestamp[flag]);
printf("%s",d1);
 
}
else
{
sprintf(data,"{start timestamp:%lu end timestamp:%lu}",timestamp[flag],timestamp[flag+1]);
printf("%s",d1);
return d1;
}
}
void main()
{

FILE *fp;

fp=fopen("building.txt","r");
char *d2;
d2=get_timestamp(fp);
}
