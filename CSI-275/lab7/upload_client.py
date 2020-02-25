"""Don't forget your docstring!"""

import argparse
import socket
import os
import constants


class UploadError(Exception):
    """Error when uploading."""

    pass


class UploadClient:
    # TODO document this class and implement the specified functions

    def __init__(self, host, p):
        pass
        """Initialize UploadClient class."""
        address = (host, int(p))
        self.tcp_sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        self.tcp_sock.settimeout(constants.MAX_TIMEOUT)
        try:
            self.tcp_sock.connect(address)
        except ():
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
        not_found = True
        wait_time = constants.INITIAL_TIMEOUT
        while not_found:
            try:
                self.tcp_sock.settimeout(wait_time)
                more = self.tcp_sock.recv(constants.MAX_BYTES)
                if not more:
                    raise EOFError('expected %d bytes but not found'
                                   % (delim))
                self.buffer += more
                print(self.buffer)
                for i in range(len(self.buffer)):
                    if self.buffer[i] == delim:
                        not_found = False
                        hold = self.buffer[:i]
                        self.buffer = self.buffer[i + 1:]
                        return hold
            except socket.timeout:
                if wait_time >= constants.MAX_TIMEOUT:
                    raise EOFError
                # exponential backoff of timeout
                wait_time *= 2
                if wait_time > constants.MAX_TIMEOUT:
                    wait_time = constants.MAX_TIMEOUT
            except:
                print("ERORRR")

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

        # TODO: Change tcp_sock here to match your __init__ function!
        self.tcp_sock.sendall(header.encode("ascii"))

        # TODO: Change tcp_sock here to match your __init__ function!
        # Send the file data
        self.tcp_sock.sendall(file_data)

        # Wait for a response
        return_msg = self.recv_until_delimiter(b"\n").decode("ascii")
        if return_msg == "ERROR":
            raise UploadError
        else:
            print("Upload successful")


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
