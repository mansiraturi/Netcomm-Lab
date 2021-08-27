#include <stdio.h>
#include <math.h>
int data[50], code[32];
void hammingCode()
{
	int n,i,a = 0,b,j,k;
	printf("\nEnter the no. of databits: ");
	scanf("%d",&n);
	printf("\nEnter the data word:\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&data[i]);
	}
printf("\nYour data: ");
for (int i = 0; i < m; i++) 
  {
    if((data[i]==0) || (data[i]==1)){
        printf("%d", data[i]);}
    else{ 
printf("\nData invalid."); 
                return 0;
            }
        }
	i=0;
	while(n>(int)pow(2,i)-(i+1))
	{
		a++;
		i++;
	}
		
	b = a + n;

	j=k=0;
	for(i=0;i<b;i++)
	{
		
		if(i==((int)pow(2,k)-1))
		{
			code[i]=0;
			k++;
		}
		else
		{
			code[i]=data[j];
			j++;
		}
	}
	for(i=0;i<a;i++)
	{
		int posn = (int)pow(2,i);
		int value = ham_calc(posn,b);
		code[posn-1]=value;
	}
	printf("\nThe calculated Code Word is: ");
	for(i=0;i<b;i++)
		printf("%d",code[i]);
	printf("\n");
	printf("Please enter the received Code Word:\n");
	for(i=0;i<b;i++)
		scanf("%d",&code[i]);

	int errorposn = 0;
	for(i=0;i<a;i++)
	{
		int posn = (int)pow(2,i);
		int value = ham_calc(posn,b);
		if(value != 0)
			errorposn+=posn;
	}
	if(errorposn == 1)
		printf("The received Code Word is correct.\n");
	else
		printf("Error at bit position: %d\n",errorposn);
}
int ham_enc(int posn,int b)
{
	int count=0,i,j;
	i=posn-1;
	while(i<b)
	{
		for(j=i;j<i+posn;j++)
		{
			if(code[j] == 1)
				count++;
		}
		i=i+2*posn;
	}
	if(count%2 == 0)
		return 0;
	else
		return 1;
}