#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define DELIM "." 
/* return 1 if string contain only digits, else return 0 */
int check_digit(char str[])
{
    for(int i=0; i< strlen(str); i++){
        if (str[i] == '0' || str[i] == '1')
           ;
        else
           printf("Invalid");
       return 0;
    }
}
int check_ip(char *ip_str)
{
    int i, num, dots = 0;
    char *ptr;
 
    if (ip_str == NULL)
        return 0;
 
    ptr = strtok(ip_str, DELIM);
 
    if (ptr == NULL)
        return 0;
 
    while (ptr) {
 
        /* after parsing string, it must contain only digits */
        if (!check_digit(ptr))
            return 0;
 
        num = atoi(ptr);
         /* check for valid IP */
        if ((num >= 0 && num <= 255) || (num >= 0 && num <= 11111111)){
            /* parse remaining string */
            ptr = strtok(NULL, DELIM);
            if (ptr != NULL)
                ++dots;
        } else
            return 0;
    }
 
    /* valid IP string must contain 3 dots */
    if (dots != 3)
        return 0;
    return 1;
}
char decClass(char str[])
{
    // storing first octet in addr[] variable
    char addr[4];
    int i = 0;
    while (str[i] != '.')
    {
        addr[i] = str[i];
        i++;
    }
    i--;
    int ip = 0, j = 1;
    while (i >= 0)
    {
        ip = ip + (str[i] - '0') * j;
        j = j * 10;
        i--;
    }
  
    // Class A
    if (ip >=1 && ip <= 126)
        return 'A';
  
    // Class B
    else if (ip >= 128 && ip <= 191)
        return 'B';
  
    // Class C
    else if (ip >= 192 && ip <= 223)
        return 'C';
  
    // Class D
    else if (ip >= 224 && ip <= 239)
        return 'D';
  
    // Class E
    else
        return 'E';
}
void block(char str[], char ipClass){
	int blockAddr;
	char network[12], host[12];
    for (int k = 0; k < 12; k++)
        network[k] = host[k] = '\0';
if (ipClass == 'A')
{
	blockAddr=255*256*256;
    int i = 0, j = 0;
        while (str[j] != '.')
            network[i++] = str[j++];
        i = 0;
        j++;
        while (str[j] != '\0')
            host[i++] = str[j++];
        printf("First IP address is %s.0.0.1\n", host);
        printf("last IP address is %s.255.255.255\n", host);
        printf("No. of addresses in the block are: %d\n", blockAddr);
    }
else if (ipClass == 'B')
    {
        blockAddr=255*256;
int i = 0, j = 0, dotCount = 0;
          while (dotCount < 2)
        {
            network[i++] = str[j++];
            if (str[j] == '.')
                dotCount++;
        }
        i = 0;
        j++;  
        while (str[j] != '\0')
            host[i++] = str[j++];  
        printf("First IP address is %s.0.1\n", host);
        printf("last IP address is %s.255.255\n", host);
        printf("No. of addresses in the block are 256*255=%d\n", blockAddr);
    }
  else if (ipClass == 'C')
    {
        int i = 0, j = 0, dotCount = 0;
          while (dotCount < 3)
        {
            network[i++] = str[j++];
            if (str[j] == '.')
                dotCount++;
        }
        i = 0;
        j++;
          while (str[j] != '\0')
            host[i++] = str[j++];
   
        printf("No. of addresses in the block are 255\n");
        printf("First IP address is %s.1\n", host);
                printf("last IP address is %s.255\n", host);
    }
   else
        printf("In this Class, IP address is not divided into Network and Host ID\n");
}

void HostNet(char str[], char ipClass)
{
   char network[12], host[12];
    for (int k = 0; k < 12; k++)
        network[k] = host[k] = '\0';
    if (ipClass == 'A')
    {
        int i = 0, j = 0;
        while (str[j] != '.')
            network[i++] = str[j++];
        i = 0;
        j++;
        while (str[j] != '\0')
            host[i++] = str[j++];
		printf("Network ID is %s\n", network);
        printf("Host ID is %s\n", host);       
    }
    else if (ipClass == 'B')
    {
        int i = 0, j = 0, dotCount = 0;
        while (dotCount < 2)
        {
            network[i++] = str[j++];
            if (str[j] == '.')
                dotCount++;
        }
        i = 0;
        j++;
  
        while (str[j] != '\0')
            host[i++] = str[j++];
  
        printf("Network ID is %s\n", network);
        printf("Host ID is %s\n", host);
    }
    else if (ipClass == 'C')
    {
        int i = 0, j = 0, dotCount = 0;
        while (dotCount < 3)
        {
            network[i++] = str[j++];
            if (str[j] == '.')
                dotCount++;
        }
  
        i = 0;
        j++;
  
        while (str[j] != '\0')
            host[i++] = str[j++];
  
        printf("Network ID is %s\n", network);
        printf("Host ID is %s\n", host);
    }
  
    else
        printf("In this Class, IP address is not divided into Network and Host ID\n");
}
int main()
{
    char str[50]; 
 printf("Enter the IP address: "); 
 scanf("%s", str); 
 char ipClass = decClass(str); 
  printf("Choose the following option: \n");
 int choice; 
 printf("\n1. Find class, network id and host id of the address\n"); 
 printf("2. Check if given IP address is valid\n"); 
 printf("3. Find first, last address and no. of addresses in the block\n"); 
 printf("4. Exit\n"); 
 printf("Enter your choice: "); 
 scanf("%d", &choice); 
 switch (choice) {  
 case 1: 
   printf("Given IP address belongs to Class %c\n", ipClass);
    HostNet(str, ipClass);
 break; 
 case 2: 
 check_digit(str);
check_ip(str)? printf("Valid\n"): printf("Not valid\n"); 
 break; 
 case 3: 
  block(str, ipClass);
 break; 
 case 4:
 exit(0);
 break;
 default: 
 printf("Enter valid choice"); 
 }  
    return 0;
}
