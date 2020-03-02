#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
struct detail
{
	char bookname[20],author[20];
	int version,year,price;
}k[100];
int c(const void *p,const void * q)
{
	int l=((struct detail *)p)->price;
	int r=((struct detail *)q)->price;
	return (l-r);
}
int co(const void *p,const void * q)
{
	int g=((struct detail *)p)->year;
	int h=((struct detail *)q)->year;
	return (g-h);
}
int com(const void *p,const void * q)
{
	return strcmp(((struct detail *)p)->author,((struct detail *)q)->author);
}
int main()
{
	int m=0,stop,no,i,y,p=0,p1=0,exit;
	char n[20];
	// m is the number of details entered
	while(1)
	{
	printf("Enter the book name,author name,version,year published,Enter price\n");
	scanf("%s%s%d%d%d",&k[m].bookname,&k[m].author,&k[m].version,&k[m].year,&k[m].price);
	m++;
    printf("To stop entering details press 1 and to continue press 2\n");
    scanf("%d",&stop);
    if(stop==1)
    {
    	break;
    }
	}
	printf("No of details entered is: %d \n",m);
    printf("Functions available are \n1.Find author and details\n2.Find year and details\n3.Sort in increasing order of price\n4.Sorting according to author name & year\n");
    while(1)
    {
    	printf("\nPress the corresponding number for the desired function\n");
    	scanf("%d",&no);
    	switch(no)
    	{
    		case 1:
    			printf("enter the author name \n");
	            scanf("%s",n);
	            for(i=0;i<m;i++)
  	            {     
	            if(strcmp(n,k[i].author) == 0)
	            {
		        printf("book name :%s\nauthor :%s\nVesion :%d\nYear :%d\nPrice :%d\n",k[i].bookname,k[i].author,k[i].version,k[i].year,k[i].price);
	            p++;
		        }
                } 
                if(p==0)
                {
    	        printf("Desired author unavailable \n");
                }
                break;
			case 2:
             	printf("enter the publication year \n");
                scanf("%d",&y);
                for(i=0;i<m;i++)
	            {
    	        if(y==k[i].year)
    	        {
    		    printf("book name :%s\nauthor :%s\nVesion :%d\nYear :%d\nPrice :%d\n",k[i].bookname,k[i].author,k[i].version,k[i].year,k[i].price);
    	        p1++;
		        }
                }
                if(p1==0)
                {
    	        printf("Desired year unavailable \n");
                }
                break;
             case 3:
             	qsort((void *)k,m-1,sizeof(k[m-1]),c);
                printf("Books listed in increasing order of price :\n");
                for(i=0;i<m;i++)
                {
    	        printf("book name :%s\nauthor :%s\nVesion :%d\nYear :%d\nPrice :%d\n",k[i].bookname,k[i].author,k[i].version,k[i].year,k[i].price);
                }
                break;
             case 4:
             	qsort((void *)k,m-1,sizeof(k[m-1]),co);
             	printf("Books listed in increasing order of year :\n");
             	for(i=0;i<m;i++)
                {
    	        printf("book name :%s\nauthor :%s\nVesion :%d\nYear :%d\nPrice :%d\n",k[i].bookname,k[i].author,k[i].version,k[i].year,k[i].price);
                }
                qsort((void *)k,m-1,sizeof(k[m-1]),com);
                printf("Books listed in alphabetical order :\n");
                for(i=0;i<m;i++)
                {
    	        printf("book name :%s\nauthor :%s\nVesion :%d\nYear :%d\nPrice :%d\n",k[i].bookname,k[i].author,k[i].version,k[i].year,k[i].price);
                }
                break;
        }
    	printf("To exit press 5\n");
    	scanf("%d",&exit);
    	if(exit==5)
    	{
    		break;
    	}
    }
	getch();
}





