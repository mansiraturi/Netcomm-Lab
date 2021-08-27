#include<stdio.h>
int main()
{
	printf("19BCE0488 MANSI RATURI");
	int wsize, ack,i;
	int a=0; 
	printf("\nEnter window size\n");
	scanf("%d",&wsize);
	do
	{
		for( i = 0; i < wsize; i++)
			{
				printf("Frame %d has been transmitted.\n",a);
				a++;
				if(a == wsize)
					break;
			}
			printf("\nPlease enter the last Acknowledgement received.\n");
			scanf("%d",&ack);
			
			if(ack == wsize)
				break;
			else
				a = ack;
	}
	while(true);
return 0;
}

