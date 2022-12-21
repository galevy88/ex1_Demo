import socket

# Create a TCP client socket
client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

# Connect the socket to the server
client_socket.connect(('localhost', 12345))

# Send a message to the server
while True:
    message = input("Tell your  message: ")
    
    client_socket.sendall(message.encode())

# Close the client socket
client_socket.close()
