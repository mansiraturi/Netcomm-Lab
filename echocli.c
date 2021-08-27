#include<arpa/inet.h>
	#include <stdio.h>
	#include <string.h>
	#include <sys/socket.h>
	#include <unistd.h>
	

	int main() {
		const char* server_name = "localhost";
		const int server_port = 8877;
	

		struct sockaddr_in server_address;
		memset(&server_address, 0, sizeof(server_address));
		server_address.sin_family = AF_INET;
	

		
		inet_pton(AF_INET, server_name, &server_address.sin_addr);
	

		
		server_address.sin_port = htons(server_port);
	

		
		int sock;
		if ((sock = socket(PF_INET, SOCK_DGRAM, 0)) < 0) {
			printf("could not create socket\n");
			return 1;
		}
	

		
		const char* data_to_send = "Hey! How are you?";
	

		
		int len =
		    sendto(sock, data_to_send, strlen(data_to_send), 0,
		           (struct sockaddr*)&server_address, sizeof(server_address));
	

		
		char buffer[100];
		recvfrom(sock, buffer, len, 0, NULL, NULL);
	

		buffer[len] = '\0';
		printf("received: '%s'\n", buffer);
	

		
		close(sock);
		return 0;
	}
