#include<stdio.h>
#include<string.h>
#include<arpa/inet.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<unistd.h>
#include<netdb.h>
#define MAXLINE 1024
int main(int argc,char **argv)
{
socklen_t len;
int scktfd, n;
char msg[1024];
struct sockaddr_in srvaddr,cliaddr;
scktfd=socket(AF_INET,SOCK_DGRAM,0);
bzero(&srvaddr,sizeof(srvaddr));
srvaddr.sin_family=AF_INET;
srvaddr.sin_addr.s_addr=INADDR_ANY;
srvaddr.sin_port=htons(5035);
printf("\n\n Binded");
bind(scktfd,(struct sockaddr*)&srvaddr,sizeof(srvaddr));
printf("\n\n Listening...");
for(;;)
{
      printf("\n ");
     len=sizeof(cliaddr);
     n=recvfrom(scktfd,msg,MAXLINE,0,(struct sockaddr*)&cliaddr,&len);
     printf("\n Client's Message : %s\n",msg);
     if(n<6)
        perror("send error");
     sendto(scktfd,msg,n,0,(struct sockaddr*)&cliaddr,len);
}
return 0;
}