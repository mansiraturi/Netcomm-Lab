#include <stdio.h>
#include <string.h>
int main()
{
printf("\nMANSI RATURI 19BCE0488\n");
int router, source;
int i,j,k,w,v,min;
int flag[100];
printf("\n Enter the no of routers:");
scanf("%d",&router);
int cost_matrix[100][100], dist[100],last[100];
printf("\n Enter the cost matrix values:");
for(i=0;i<router;i++)
{
	for(j=0;j<router;j++)
{
printf("\n%d->%d:",i,j);
scanf("%d",&cost_matrix[i][j]);
if(cost_matrix[i][j]<0)
	cost_matrix[i][j]=1000; }
}
printf("\n Enter the source router:");
scanf("%d",&source);
for(v=0; v<router; v++)
{
flag[v]=0;
last[v]=source;
dist[v]=cost_matrix[source][v]; }
flag[source]=1;
for(i=0;i<router;i++) {
min=1000;
for(w=0;w<router;w++) {
if(!flag[w])
if(dist[w]<min) {
v=w;
min=dist[w];
}
}
flag[v]=1;
for(w=0;w<router;w++) {
if(!flag[w])
if(min+cost_matrix[v][w]<dist[w]){
	dist[w]=min+cost_matrix[v][w];
    last[w]=v;
}
}
}
for(i=0;i<router;i++)
{
printf("\n%d==>%d:Path taken:%d",source,i,i);
w=i; 
while(w!=source) {
printf("\n<--%d",last[w]);w=last[w];
}
printf("\n Shortest path cost:%d",dist[i]);
}
printf("\n");
}

#include<stdlib.h>
#define nul 1000
#define nodes 10
int no;
struct node
{
int a[nodes][4];
}router[nodes];
void init(int r)
{
int i;
for(i=1;i<=no;i++)
{
router[r].a[i][1]=i;
router[r].a[i][2]=999;
router[r].a[i][3]=nul;
}
router[r].a[r][2]=0;
router[r].a[r][3]=r;
}
void inp(int r)
{int i;
printf("\nEnter dist from the node %d to other nodes",r);
printf("\nPls enter 999 if there is no direct route\n",r);
for(i=1;i<=no;i++)
{
if(i!=r)
{
printf("\nEnter dist to the node %d:",i);
scanf("%d",&router[r].a[i][2]);
router[r].a[i][3]=i;
}
}
}
void display(int r)
{
int i,j;
printf("\n\nThe routing table for node %d is as follows:",r);
for(i=1;i<=no;i++)
{
if(router[r].a[i][2]>=999)
printf("\n\t\t\t %d \t no link \t no hop",router[r].a[i][1]);
else
printf("\n\t\t\t %d \t %d \t\t 
d",router[r].a[i][1],router[r].a[i][2],router[r].a[i][3]);
}
}
void dv_algo(int r)
{
int i,j,z;
for(i=1;i<=no;i++)
{
if(router[r].a[i][2]!=999 && router[r].a[i][2]!=0)
{for(j=1;j<=no;j++)
{
z=router[r].a[i][2]+router[i].a[j][2];
if(router[r].a[j][2]>z)
{
router[r].a[j][2]=z;
router[r].a[j][3]=i;
}
}
}
}
}
int main()
{
int i,j,x,y;
char choice;
printf("Enter the no. of nodes required:");
scanf("%d",&no);
for(i=1;i<=no;i++)
{
init(i);
inp(i);
}
printf("\nThe configuration of the nodes after initialization is as follows:");
for(i=1;i<=no;i++)
display(i);
for(i=1;i<=no;i++)
dv_algo(i);
printf("\nThe configuration of the nodes after computation of paths is as follows:");
for(i=1;i<=no;i++)
display(i);while(1)
{
printf("\n\nWanna continue (y/n):");
scanf("%c",&choice);
if(choice=='n')
break;
printf("\nEnter the nodes btn which shortest path is to be found:\n");
scanf("%d %d",&x,&y);
printf("\nThe length of the shortest path is %d",router[x].a[y][2]);
}
}