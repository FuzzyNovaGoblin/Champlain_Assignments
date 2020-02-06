"""Student code for Lab/HW 2.

Champlain College CSI-235, Spring 2019
The following code was written by Joshua Auerbach (jauerbach@champlain.edu)
"""

import socket
import constants


class TimeOutError(Exception):
    """Exception raised for exceeding max timeout"""

    pass


class UDPClient:
    def __init__(self, host, port, req_ids = False):
        self.sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
        self.host = host
        self.port = port

    def send_message_by_character(self, msg):
        """sends string to server one characture at a time


        """
        chars = []
        for c in range(len(msg)):
            chars.append(str(c).encode("ASCII"))
        index = int(0)
        wait_time = constants.INITIAL_TIMEOUT
        response_msg = b''
        while index < len(msg):
            try:
                self.sock.settimeout(wait_time)
                self.sock.sendto(chars[index], (self.host, self.port))
                reponse, address = self.sock.recvfrom(1)
                response_msg += reponse
                index += 1
            except socket.timeout:  # if conection timesout
                if wait_time >= constants.MAX_TIMEOUT:
                    raise(TimeOutError)
                wait_time *=  constants.INITIAL_TIMEOUT
        return response_msg.decode("ASCII")



def main():
    """Run some basic tests on the required functionality.

    for more extensive tests run the autograder!
    """
    client = UDPClient(constants.HOST, constants.ECHO_PORT)
    print(client.send_message_by_character("hello world"))

    client = UDPClient(constants.HOST, constants.REQUEST_ID_PORT, True)
    print(client.send_message_by_character("hello world"))


if __name__ == "__main__":
    main()
