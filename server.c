#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <winsock2.h>

#define PORT 8080
#define BUFFER_SIZE 1024

int main()
{
  WSADATA wsaData;
  int server_fd, new_socket;
  struct sockaddr_in address;
  int addrlen = sizeof(address);
  char buffer[BUFFER_SIZE] = {0};
  const char *response =
      "HTTP/1.1 200 OK\r\n"
      "Content-Type: text/html\r\n"
      "Content-Length: 48\r\n"
      "\r\n"
      "<html><body><h1>Hello, World!</h1></body></html>";

  // Initialize Winsock
  if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
  {
    fprintf(stderr, "WSAStartup failed.\n");
    exit(EXIT_FAILURE);
  }

  // Creating socket file descriptor
  if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == INVALID_SOCKET)
  {
    perror("socket failed");
    WSACleanup();
    exit(EXIT_FAILURE);
  }

  // Attaching socket to the port
  address.sin_family = AF_INET;
  address.sin_addr.s_addr = INADDR_ANY;
  address.sin_port = htons(PORT);

  if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) == SOCKET_ERROR)
  {
    perror("bind failed");
    closesocket(server_fd);
    WSACleanup();
    exit(EXIT_FAILURE);
  }

  if (listen(server_fd, 3) == SOCKET_ERROR)
  {
    perror("listen");
    closesocket(server_fd);
    WSACleanup();
    exit(EXIT_FAILURE);
  }

  printf("Server is listening on port %d\n", PORT);

  while (1)
  {
    if ((new_socket = accept(server_fd, (struct sockaddr *)&address, &addrlen)) == INVALID_SOCKET)
    {
      perror("accept");
      closesocket(server_fd);
      WSACleanup();
      exit(EXIT_FAILURE);
    }

    recv(new_socket, buffer, BUFFER_SIZE, 0);
    printf("Received request:\n%s\n", buffer);
    send(new_socket, response, strlen(response), 0);
    printf("Response sent\n");

    closesocket(new_socket);
  }

  closesocket(server_fd);
  WSACleanup();
  return 0;
}
