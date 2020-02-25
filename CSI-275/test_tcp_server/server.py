import socket
HOST = "184.171.151.255"
PORT = 45000


class LengthServer:
    """Create a server that return the length of received strings."""

    def __init__(self, host, port):
        self.address = (host, port)
        self.sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        self.sock.bind(self.address)
        self.sock.listen(20)

    def calc_length(self):
        return len(self.data)

    def run_server(self):
        self.sock.listen(1)
        while True:
            print('waiting for connection')
            connection, address = self.sock.accept()
            print('connected to', connection)
            self.data = b''
            while True:
                print('waiting for data')
                buff = connection.recv(1)
                if buff == b'`':
                    print('data recived')
                    break
                self.data += buff
            self.data = self.data.decode("ASCII")
            return_data = str(self.calc_length()) + '`'
            return_data = return_data.encode("ASCII")
            print('sending data')
            connection.send(return_data)


if __name__ == "__main__":
    server = LengthServer(HOST, PORT)
    server.run_server()
