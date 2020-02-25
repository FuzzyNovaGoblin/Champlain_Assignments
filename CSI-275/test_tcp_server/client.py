import socket
import sys
HOST = "localhost"
PORT = 45000


if __name__ == "__main__":
    sock = socket.socket()
    server_address = (HOST, PORT)
    sock.connect(server_address)
    data = sys.argv[1]+"`"
    data = data.encode("ASCII")
    sock.sendall(data)
    data = b''
    while True:
        buff = sock.recv(1)
        if buff == b'`':
            break
        data += buff

    print(data.decode("ASCII"))
