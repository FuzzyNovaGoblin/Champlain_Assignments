"""Grant Hedley's code for Lab7.

Author: Grant Hedley
Class: CSI-275-1
Assignment: Lab 7
Due Date: 3/2/20

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

import argparse
import socket
import os
import constants


class UploadError(Exception):
    """Error when uploading."""

    pass


class UploadClient:
    """Upload Client class.

    this class is used to send and recive files or data, to and from
    a given server
    """

    def __init__(self, host, p):
        """Initialize UploadClient class."""
        address = (host, int(p))
        self.tcp_sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        self.tcp_sock.settimeout(constants.MAX_TIMEOUT)
        try:
            self.tcp_sock.connect(address)
        except Exception:
            raise ConnectionError()

        self.buffer = b''

    def close(self):
        """Close socket."""
        self.tcp_sock.close()

    def recv_all(self, length):
        """Recive data of given length."""
        data = b''
        while len(data) < length:
            more = self.tcp_sock.recv(length - len(data))
            if not more:
                raise EOFError('expected %d bytes but only received'
                               ' %d bytes before the socket closed'
                               % (length, len(data)))
            data += more
        return data

    def recv_until_delimiter(self, delim):
        """Recive data until delimiter.

        calls recives as many bytes as posible from server and adds it to a
        buffer, checkes if the delimiter is in the buffer. if not this is
        repeated until delimiter is found, otherwise it returns the message
        before the delimiter.
        """
        not_found = True
        wait_time = constants.INITIAL_TIMEOUT
        while not_found:
            for i in range(len(self.buffer)):
                if self.buffer[i] == delim[0]:
                    not_found = False
                    hold = self.buffer[:i]
                    self.buffer = self.buffer[i + 1:]
                    return hold
            try:
                self.tcp_sock.settimeout(wait_time)
                more = self.tcp_sock.recv(constants.MAX_BYTES)
                if not more:
                    raise EOFError
                self.buffer += more

            except socket.timeout:
                if wait_time >= constants.MAX_TIMEOUT:
                    return "ERROR"
                # exponential backoff of timeout
                wait_time *= 2
                if wait_time > constants.MAX_TIMEOUT:
                    wait_time = constants.MAX_TIMEOUT

    def upload_file(self, file_path):
        """Upload a file to the class's server.

        The function handles Q4 of the original assignment.
        """
        # Open the file
        file = open(file_path, "rb")

        # Read the whole thing into memory
        file_data = file.read()

        # Prep the first line to send
        header = "UPLOAD " + os.path.basename(file_path) + " " \
                 + str(len(file_data)) + "\n"
        print(f"Sending {header}")

        self.tcp_sock.sendall(header.encode("ascii"))

        # Send the file data
        self.tcp_sock.sendall(file_data)

        # Wait for a response
        return_msg = self.recv_until_delimiter(b"\n").decode("ascii")
        if return_msg == "ERROR":
            raise UploadError
        else:
            print("Upload successful")

    def list_files(self):
        """List files sent to server.

        sends comand to server to get a list of files that have been sent to
        it. Then recives the response with the recv_until_delimiter method
        all responses are added to a list of tuples, with the first element
        the name of the file and the second an int representing the size of
        the file. The method returns the list of tupples.
        """
        self.tcp_sock.sendall("LIST\n".encode("ASCII"))
        data = self.recv_until_delimiter(b'\n')
        all = []
        while len(data) > 0:
            if data == "ERROR":
                raise UploadError
            print(data)
            data = data.decode("ascii")
            all.append((str(data).split(' ')[0], int(str(data).split(' ')[1])))
            data = self.recv_until_delimiter(b'\n')
        return all


def main():
    """Run some basic tests on the required functionality.

    for more extensive tests run the autograder!
    """
    parser = argparse.ArgumentParser(description="TCP File Uploader")
    parser.add_argument("host", help="interface the server listens at;"
                        " host the client sends to")
    parser.add_argument("-p", metavar="PORT", type=int,
                        default=constants.UPLOAD_PORT,
                        help=f"TCP port (default {constants.UPLOAD_PORT})")
    args = parser.parse_args()
    try:
        upload_client = UploadClient(args.host, args.p)
    except (ConnectionError, TimeoutError):
        raise ConnectionError()
    upload_client.upload_file("upload_client.py")
    print(upload_client.list_files())
    upload_client.close()


if __name__ == "__main__":
    main()
