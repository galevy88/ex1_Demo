#include <iostream>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>

int main() {
  // Create a TCP server socket
  int server_socket = socket(AF_INET, SOCK_STREAM, 0);

  // Set up the server address and port
  sockaddr_in server_address;
  server_address.sin_family = AF_INET;
  server_address.sin_addr.s_addr = INADDR_ANY;
  server_address.sin_port = htons(12345);

  // Bind the socket to the server address and port
  bind(server_socket, reinterpret_cast<sockaddr*>(&server_address), sizeof(server_address));

  // Set the socket to listen for incoming connections
  listen(server_socket, 5);

  // Accept an incoming connection
  sockaddr_in client_address;
  socklen_t client_address_length = sizeof(client_address);
  int client_socket = accept(server_socket, reinterpret_cast<sockaddr*>(&client_address), &client_address_length);

  // Receive a message from the client
  char message[1024];
  int message_length = recv(client_socket, message, sizeof(message), 0);

  // Print the message
  std::cout << "Received message: " << std::string(message, message_length) << std::endl;

  // Close the client socket
  close(client_socket);

  // Close the server socket
  close(server_socket);

  return 0;
}