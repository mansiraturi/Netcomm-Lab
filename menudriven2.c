#include<stdio.h> 
#include<string.h> 
int StopWait()
{
//Filling data
int size, w;
printf("Enter data size: "); 
scanf("%d",&size);
printf("\nEnter window size: ");
scanf("%d",&w);
int i,no=0,data[size],rec[size], posn=0; 
for (i=0;i<size;i++) 
{
data[i]=no;
no++; 
}
//Frames
int trans[w];
//Displaying data printf("\nData is: "); for (i=0;i<size;i++)
{
printf("%d,", data[i]);
}
while (posn<size)
{
//Sending
send(data, posn, trans, w, size); 
//Received
posn=receive(trans, rec, posn, w, size); 
}
return 0; 
} 
//Stop and Wait 
int send(int data[], int posn, int trans[], int w, int size) 
{
//W=5
int i; 
for (i=posn;i<posn+w;i++) 
{
trans[i-posn]=data[i];
} 
printf("\n"); 
printf("\nData being transmitted is: "); 
for(i=0;i<w;i++) 
{
if(trans[i]<size)
{ 
printf("%d,", trans[i]); 
}
}
} 
int receive(int trans[],int rec[],int posn, int w,int size) 
{
int i, ackframe;
for(i=posn;i<posn+w;i++) 
{ 
rec[i]=trans[i-posn]; 
} 
printf("\n"); 
//Display received 
printf("\nReceived data is: "); 
for (i=0;i<posn+w;i++) { 
if (rec[i]>size) 
{ 
exit(1); 
} 
printf("%d,", rec[i]); 
} 
printf("\nWhich frame do you want acknowledged between %d and %d: ", posn, posn+w-1); 
scanf("%d", &ackframe); 
if (ackframe>posn+w-1 || ackframe<posn)
{
printf("\n\nFRAME EXCEEDS LIMIT. LAST FRAME SENT IS BEING ACKNOWLEDGED\n");
ackframe=posn+w-1;
}
printf("\nAcknowledgement Received for posnition: %d", ackframe); 
return ackframe+1;
}
int receive2(int trans[],int rec[],int posn, int w,int size)
{
int i; 
for (i=posn;i<posn+w;i++) 
{
rec[i]=trans[i-posn];
} 
printf("\n");
//Display received 
printf("\nReceived data is: ");
for (i=0;i<posn+w;i++)
{
if (rec[i]>size)
{
exit(1);
}
printf("%d,", rec[i]);}
printf("\nAcknowledgement Received for posnition: %d", posn+w-3); 
return posn+w-2; 
}
int Selective()
{
	int window,fr;
int frame[100]; 
printf("\nEnter no. of frames to transmit: "); 
scanf("%d",&fr);
printf("\nEnter %d frames: ",fr);
for(int i=1;i<=fr;i++) 
scanf("%d",&frame[i]);
printf("Enter window size: "); 
scanf("%d",&window);  
printf("\nThe frames are sent in the following sequence:\n\n"); 
printf("After sending %d frames at each stage sender waits for acknowledgement sent by the receiver\n\n",window); 
for(int i=1;i<=fr;i++) 
{
if(i%window==0) 
{ 
printf("%d\n",frame[i]); 
printf("Acknowledgement of above frames sent is received by sender\n\n"); 
} 
else 
printf("%d ",frame[i]); 
}
if (fr%window!=0) {
printf("\nAcknowledgement of above frames sent is received by sender\n");
}
}
int GoBack()
{
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
int main() { 
printf("19BCE0488 MANSI RATURI");
 int choice; 
 printf("\n1. Stop and Wait\n"); 
 printf("2. Selective Repeat\n"); 
 printf("3. Go Back N\n"); 
 printf("4. Exit\n"); 
 printf("Enter your choice: "); 
 scanf("%d", &choice); 
 switch (choice) {  
 case 1: 
 StopWait(); 
 break; 
 case 2: 
 Selective(); 
 break; 
 case 3: 
 GoBack(); 
 break; 
 case 4: 
 exit(0); 
 break; 
 default: 
 printf("Enter valid choice"); 
 }  
 return 0; 
}