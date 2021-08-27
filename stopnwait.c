#include <stdio.h> 
#include<stdlib.h>
int main()
{
//Filling data
printf("19BCE0488 MANSI RATURI");
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
