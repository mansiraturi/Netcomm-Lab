#include<stdio.h> 
int main() 
{
printf("19BCE0488 MANSI RATURI");
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
if (fr%window!=0) 
printf("\nAcknowledgement of above frames sent is received by sender\n");
}