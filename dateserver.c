#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <time.h> 
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int listenfd = 0, connfd = 0;
    struct sockaddr_in svraddr; 

    char sendbfr[1025];
    time_t ticks; 

    listenfd = socket(AF_INET, SOCK_STREAM, 0);
    memset(&svraddr, '0', sizeof(svraddr));
    memset(sendbfr, '0', sizeof(sendbfr)); 

    svraddr.sin_family = AF_INET;
    svraddr.sin_addr.s_addr = htonl(INADDR_ANY);
    svraddr.sin_port = htons(5000); 

    bind(listenfd, (struct sockaddr*)&svraddr, sizeof(svraddr)); 

    listen(listenfd, 10); 

    while(1)
    {
        connfd = accept(listenfd, (struct sockaddr*)NULL, NULL); 

        ticks = time(NULL);
        snprintf(sendbfr, sizeof(sendbfr), "%.24s\r\n", ctime(&ticks));
        write(connfd, sendbfr, strlen(sendbfr)); 

        close(connfd);
        sleep(1);
     }
}