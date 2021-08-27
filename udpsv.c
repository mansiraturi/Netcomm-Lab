#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <string.h>
#include <sys/types.h>
  
#define PORT     8080
#define MAXLINE 1024
  
int main() {
    int scktfd;
    char buffer[MAXLINE];
    char *hello = "Hello! How are you doing?";
    struct sockaddr_in svraddr, cliaddr;
      
    
    
    svraddr.sin_family    = AF_INET; 
    svraddr.sin_addr.s_addr = INADDR_ANY;
    svraddr.sin_port = htons(PORT);
      
    memset(&svraddr, 0, sizeof(svraddr));
    memset(&cliaddr, 0, sizeof(cliaddr));
    if ( (scktfd = socket(AF_INET, SCKT_DGRAM, 0)) < 0 ) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }
      
    
      
    
    if ( bind(scktfd, (const struct sockaddr *)&svraddr, 
            sizeof(svraddr)) < 0 )
    {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }
      
    int len, n;
  
    len = sizeof(cliaddr);  
  
    n = recvfrom(scktfd, (char *)buffer, MAXLINE, 
                MSG_WAITALL, ( struct sockaddr *) &cliaddr,
                &len);
    buffer[n] = '\0';
    printf("Client : %s\n", buffer);
    sendto(scktfd, (const char *)hello, strlen(hello), 
        MSG_CONFIRM, (const struct sockaddr *) &cliaddr,
            len);
    printf("Message sent.\n"); 
      
    return 0;
}