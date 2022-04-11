#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>

int main(void)
{
	int socket_desc, client_sock, client_size;
	struct sockaddr_in server_addr, client_addr;
	char server_message[100], client_message[100][10];
	char ind_message[3];

	// Clean buffers:
	memset(server_message, '\0', sizeof(server_message));
	memset(client_message, '\0', sizeof(client_message));

	// Create socket:
	socket_desc = socket(AF_INET, SOCK_STREAM, 0);

	if (socket_desc < 0)
	{
		printf("Error while creating socket\n");
		return -1;
	}
	printf("Socket created successfully\n");

	// Set port and IP:
	server_addr.sin_family = AF_INET;
	server_addr.sin_port = htons(2000);
	server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

	// Bind to the set port and IP:
	if (bind(socket_desc, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0)
	{
		printf("Couldn't bind to the port\n");
		return -1;
	}
	printf("Done with binding\n");

	// Listen for clients:
	if (listen(socket_desc, 1) < 0)
	{
		printf("Error while listening\n");
		return -1;
	}
	printf("\nListening for incoming connections.....\n");

	// Accept an incoming connection:
	client_size = sizeof(client_addr);
	client_sock = accept(socket_desc, (struct sockaddr *)&client_addr, &client_size);

	if (client_sock < 0)
	{
		printf("Can't accept\n");
		return -1;
	}
	printf("Client connected at IP: %s and port: %i\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

	// Receive client's message:
	int max = -1;
	while (1)
	{
		for (int i = 0; i < 5; i++)
		{
			if (recv(client_sock, client_message[i], sizeof(client_message[i]), 0) < 0)
			{
				printf("Couldn't receive\n");
				return -1;
			}
			printf("Msg from client: %s\n", client_message[i]);

			int return_status = recv(client_sock, &max, sizeof(max), 0);
			if (return_status > 0)
			{
				printf("Received index \n");
			}
			else
			{
				printf("error");
			}
		}
		printf("max is %d\n", ntohl(max));
		int to_send = ntohl(max);
		// Respond to client:
		// strcpy(server_message, "This is the server's message.");

		int converted_number = htonl(to_send);

		// Write the number to the opened socket
		send(client_sock, &converted_number, sizeof(converted_number), 0);
	}
	// Closing the socket:
	close(client_sock);
	close(socket_desc);

	return 0;
}
