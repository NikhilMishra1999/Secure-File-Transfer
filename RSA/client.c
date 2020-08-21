#include <arpa/inet.h> 
#include <netinet/in.h> 
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <sys/socket.h> 
#include <sys/types.h> 
#include <unistd.h> 
  
#define IP_PROTOCOL 0 
#define IP_ADDRESS "127.0.0.1" // localhost 
#define PORT_NO 8098
#define NET_BUF_SIZE 32 
#define cipherKey 'S' 
#define sendrecvflag 0 
  
// function to clear buffer 
void clearBuf(char* b) 
{ 
    int i; 
    for (i = 0; i < NET_BUF_SIZE; i++) 
        b[i] = '\0'; 
} 
  
// driver code 
int main() 
{ 
    int counter=0;
    int sockfd, nBytes; 
    struct sockaddr_in addr_con; 
    int addrlen = sizeof(addr_con); 
    addr_con.sin_family = AF_INET; 
    addr_con.sin_port = htons(PORT_NO); 
    addr_con.sin_addr.s_addr = inet_addr(IP_ADDRESS); 
    char net_buf[NET_BUF_SIZE]; 
    FILE* fp; 
  
    // socket() 
    sockfd = socket(AF_INET, SOCK_DGRAM, 
                    IP_PROTOCOL); 
    printf("\nClient is using Hostname as %s and PORT NO. as %d\n\n",IP_ADDRESS,PORT_NO);
  
    while (counter == 0) { 
        printf("\nPlease enter the name of the file to be sent:\n"); 
        scanf("%s", net_buf); 
        sendto(sockfd, net_buf, NET_BUF_SIZE, 
               sendrecvflag, (struct sockaddr*)&addr_con, 
               addrlen); 
        counter++;
        printf("\n-------------------------------\n"); 
    } 
    return 0; 
} 
