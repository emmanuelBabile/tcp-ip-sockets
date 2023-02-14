#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 4444

int main(){

	int clientSocket, ret;
	struct sockaddr_in serverAddr;

	char message[30], warning1[80], warning2[90];
	int N, sum;

	clientSocket = socket(AF_INET, SOCK_STREAM, 0);
	if(clientSocket < 0){
		printf("[-]Error in connection.\n");
		exit(1);
	}
	printf("[+]Client Socket is created.\n");

	memset(&serverAddr, '\0', sizeof(serverAddr));
	serverAddr.sin_family = AF_INET;
	serverAddr.sin_port = htons(PORT);
	serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");

	ret = connect(clientSocket, (struct sockaddr*)&serverAddr, sizeof(serverAddr));
	if(ret < 0){
		printf("[-]Error in connection.\n");
		exit(1);
	}
	printf("[+]Connected to Server.\n\n");

	read(clientSocket, warning1, sizeof(warning1)-1);
	printf("%s", warning1);

	read(clientSocket, warning2, sizeof(warning2)-1);
	printf("%s", warning2);

	while(1){
		read(clientSocket, message, sizeof(message)-1);
		printf("%s", message);
		scanf("%d",&N);
		write(clientSocket, &N, sizeof(N));
		
		if(N<=0){
			close(clientSocket);
			printf("[-]Disconnected from server.\n");
			exit(1);
		}
		else{
			read(clientSocket, &sum, sizeof(sum));
			printf("The 1 -> N sum is : %d\n\n", sum);
		}
	
	}

	return 0;
}