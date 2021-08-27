#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>
#include <errno.h>
#include <arpa/inet.h> 

int main(int argc, char *argv[])
{
    int scktfd = 0, n = 0;
    char rcvbfr[1024];
    struct scktaddr_in svraddr; 

    if(argc != 2)
    {
        printf("\n Usage: %s <ip of server> \n",argv[0]);
        return 1;
    } 

    memset(rcvbfr, '0',sizeof(rcvbfr));
    if((scktfd = socket(AF_INET, SCKT_STREAM, 0)) < 0)
    {
        printf("\n Error : Could not create socket \n");
        return 1;
    } 

    memset(&svraddr, '0', sizeof(svraddr)); 

    svraddr.sin_family = AF_INET;
    svraddr.sin_port = htons(5000); 

    if(inet_pton(AF_INET, argv[1], &svraddr.sin_addr)<=0)
    {
        printf("\n inet_pton error occured\n");
        return 1;
    } 

    if( connect(scktfd, (struct scktaddr *)&svraddr, sizeof(svraddr)) < 0)
    {
       printf("\n Error! Connect Failed \n");
       return 1;
    } 

    while ( (n = read(scktfd, rcvbfr, sizeof(rcvbfr)-1)) > 0)
    {
        rcvbfr[n] = 0;
        if(fputs(rcvbfr, stdout) == EOF)
        {
            printf("\n Error! Fputs error\n");
        }
    } 

    if(n < 0)
    {
        printf("\n Read error \n");
    } 

    return 0;
}