#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

int main(void)
{
	int socket_desc;
	struct sockaddr_in server_addr;
	char server_message[100];



	// Create socket:
	socket_desc = socket(AF_INET, SOCK_STREAM, 0);

	if (socket_desc < 0)
	{
		printf("Unable to create socket\n");
		return -1;
	}

	printf("Socket created successfully\n");

	// Set port and IP the same as server-side:
	server_addr.sin_family = AF_INET;
	server_addr.sin_port = htons(2000);
	server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

	// Send connection request to server:
	if (connect(socket_desc, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0)
	{
		printf("Unable to connect\n");
		return -1;
	}
	printf("Connected with server successfully\n");


    char str[56][56] = {"34ee", "tRtBgB", "MfQBa", "aHgCD", "12AR4Z5", "fOghWjK", "KtY3Hd", "IfDdD3", "QfdSad44C", "D452X42R", "JM12Ofd", "W546FhR", "X334SJ", "YB34Ldd", "3ggDtr4BE", "FgfSAs", "RdfC334B", "Y12N3E", "C43DY", "434G44GXg", "X5P43K", "L5O4R", "E5L77Lg", "N234MP", "AdasfP4Q", "erF3WK", "H34OP", "K34MC", "55OgQH", "55N6WN7", "K452UE5", "WHSgfs", "23QMG", "BB5U4", "QCL324", "J13J44Ig", "VrtS45W", "34MD5K","Q3434TfrB", "X34IX", "M43V4T", "R4231RB", "L45JP", "555T6NS", "NFW4", "121234ZQF", "J5M5A", "FAadD", "R34RW", "SOF"};


	// Send the message to server:
	int ind = 0;
	while (ind < 47)
	{
		for (int i = ind + 0; i < ind + 5; i++)
		{
			if (send(socket_desc, str[i], strlen(str[i]), 0) < 0)
			{
				printf("Unable to send message\n");

				return -1;
			}
			sleep(1);
			int converted_number = htonl(i);

			
			send(socket_desc, &converted_number, sizeof(converted_number), 0);
			sleep(1);
		}
		int max;
		int return_status = recv(socket_desc, &max, sizeof(max), 0);
		if (return_status > 0)
		{
			fprintf(stdout, "Received int is = %d\n", ntohl(max));
		}
		else
		{
			printf("error");
		}
		ind = ntohl(max);
		// Close the socket:
	}
	close(socket_desc);

	return 0;
}
