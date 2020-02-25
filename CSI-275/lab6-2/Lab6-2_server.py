"""Grant Hedley's code for Lab6-2.

Author: Grant Hedley
Class: CSI-275-1
Assignment: Lab 6-2
Due Date: 2/17/20

Certification of Authenticity:
I certify that this is entirely my own work, except where I have given
fully-documented references to the work of others. I understand the definition
and consequences of plagiarism and acknowledge that the assessor of this
assignment may, for the purpose of assessing this assignment:
- Reproduce this assignment and provide a copy to another member of academic
- staff; and/or Communicate a copy of this assignment to a plagiarism checking
- service (which may then retain a copy of this assignment on its database for
- the purpose of future plagiarism checking)
"""


import socket


HOST = "localhost"
PORT = 45000


def recvall(sock, length):
    """Recive data of given length."""
    data = b''
    while len(data) < length:
        more = sock.recv(length - len(data))
        if not more:
            raise EOFError('expected %d bytes but only received'
                           ' %d bytes before the socket closed'
                           % (length, len(data)))
        data += more
    return data


class LengthServer:
    """Create a server that return the length of received strings."""

    def __init__(self, host, port):
        """Init server object.

        create tcp socket and bind to listen on given ip and port
        """
        self.address = (host, port)
        self.sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        self.sock.bind(self.address)
        self.sock.listen(20)

    def calc_length(self):
        """Calculate the length of incoming message

        recive the first 4 bytes from the client these are the length of the
        incoming message
        the bytes are converted to int and returned
        """
        self.data_len = self.connection.recv(4)
        self.data_len = int.from_bytes(self.data_len, byteorder='big')

    def run_server(self):
        """Run the Server.

        listen for connection
        when connected get the length of the incomming data
        call recvall with the length recived
        if the length of data recived is not right send Length Error back
        otherwise send back the amount of data recived
        """

        self.sock.listen(1)
        while True:
            print('waiting for connection')
            self.connection, address = self.sock.accept()
            print('connected to', self.connection.getsockname())
            self.calc_length()

            try:
                data = recvall(self.connection, self.data_len)
                data = "I received " + str(len(data)) + " bytes."
            except (EOFError):
                data = "Length Error"

            print('sending data')

            data = len(data).to_bytes(4, 'big')+data.encode('ascii')
            self.connection.sendall(data)
            self.connection.close()


if __name__ == "__main__":
    server = LengthServer(HOST, PORT)
    server.run_server()
