#include<stdio.h>
int main()
{
int a,b,c=0,opt;
do
{
	    printf("\n  CALCULATOR");
		printf("\n  ----------\n");
	    printf("\n1)Add two number");  
        printf("\n2)Substract two number");  
        printf("\n3)Multiply two number");
        printf("\n4)Devide two number");
        printf("\n5)Quit !\n");
        printf("\nEnter your choice : ");
        scanf("%d",&opt); 
	switch(opt)
	{
		case 1:printf("\nEnter two numbers for addition: ");
		scanf("%d%d",&a,&b);
		c=a+b;
		printf("\nAnswer is %d",c);
		break;
		case 2:printf("\nEnter two numbers for subtraction: ");
		scanf("%d%d",&a,&b);
		c=a-b;
		printf("\nAnswer is %d",c);
		break;
		case 3:printf("\nEnter two numbers for Multipliction: ");
		scanf("%d%d",&a,&b);
		c=a*b;
		printf("\nAnswer is %d",c);
		break;
		case 4:printf("\nEnter two numbers for Divition: ");
		scanf("%d%d",&a,&b);
		c=a/b;
		printf("\nAnswer is %d",c);
		break;
		case 5:break;
		default:
		printf("\ninvalid option");
		break;
	}
}while(opt!=5); 
return 0;
}
