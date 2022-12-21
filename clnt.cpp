#include <iostream>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>

int main() {
  // Create a TCP client socket
  int client_socket = socket(AF_INET, SOCK_STREAM, 0);

  // Set up the server address and port
  sockaddr_in server_address;
  server_address.sin_family = AF_INET;
  server_address.sin_addr.s_addr = inet_addr("127.0.0.1");
  server_address.sin_port = htons(12345);

  // Connect the socket to the server
  connect(client_socket, reinterpret_cast<sockaddr*>(&server_address), sizeof(server_address));

  // Send a message to the server
  std::string message = "Hello, server!";
  send(client_socket, message.c_str(), message.length(), 0);

  // Close the client socket
  close(client_socket);

  return 0;
}