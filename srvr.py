import socket

# Create a TCP server socket
server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

# Bind the socket to a local address and port
server_socket.bind(('localhost', 12345))

# Set the socket to listen for incoming connections
server_socket.listen()

# Accept an incoming connection
client_socket, client_address = server_socket.accept()


while True:
# Receive a message from the client
    message = client_socket.recv(1024)

# Decode the message
    message = message.decode()

# Print the message
    print(message)

# Close the client socket
client_socket.close()

# Close the server socket
server_socket.close()