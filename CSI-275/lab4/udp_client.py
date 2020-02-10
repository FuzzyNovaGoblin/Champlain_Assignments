"""Grnat Hedley's code for Lab4.

Author: Grant Hedley
Class: CSI-275-1
Assignment: Lab 4
Due Date: 2/10/20

Certification of Authenticity:
I certify that this is entirely my own work, except where I have given
fully-documented references to the work of others. I understand the definition
and consequences of plagiarism and acknowledge that the assessor of this
assignment may, for the purpose of assessing this assignment:
- Reproduce this assignment and provide a copy to another member of academic
- staff; and/or Communicate a copy of this assignment to a plagiarism checking
- service (which may then retain a copy of this assignment on its database for
- the purpose of future plagiarism checking)

Student code for Lab/HW 2.

Champlain College CSI-235, Spring 2019
The following code was written by Joshua Auerbach (jauerbach@champlain.edu)
"""


import socket
import constants
import random


class TimeOutError(Exception):
    """Exception raised for exceeding max timeout."""

    pass


class UDPClient:
    """Send data using udp.

    holds the port and ip the data needs to be sent to as well as wether or not
    an id needs to be added to the data before it is sent, the ids are
    generated and applied as needed in the send_message_by_character method.
    """

    def __init__(self, host, port, req_ids=False):
        """Initialize the UDPClient class.

        cteates socket for udp, saves ip and port, saves wether or not ids are
        to be used (defaults to False)
        """
        self.sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
        self.host = host
        self.port = port
        self.req_ids = req_ids

    def send_message_by_character(self, msg):
        """Send string to server one character at a time.

        The message is broken up into an array and if req_ids is enabled an id
        is generated before sending the character.
        """
        chars = []
        for c in msg:
            chars.append(str(c))

        index = int(0)
        wait_time = constants.INITIAL_TIMEOUT
        response_msg = ''
        id = random.randrange(constants.MAX_ID)
        while index < len(msg):
            try:
                self.sock.settimeout(wait_time)

                # sends and recives data using ids
                if self.req_ids:
                    self.sock.sendto(
                        (str(id) + "|" + chars[index]).encode("ASCII"),
                        (self.host, self.port))
                    response, address = self.sock.recvfrom(constants.MAX_BYTES)
                # sends and recives data without ids
                else:
                    self.sock.sendto(chars[index].encode(
                        "ASCII"), (self.host, self.port))
                    response, address = self.sock.recvfrom(1)

                # recives response from server
                response = response.decode("ASCII")

                # if using ids the id is checked, if the id is the same it is
                # added to the data otherwise it sends the data again and
                # waits for the right id
                if self.req_ids:
                    if id == int(response.split('|')[0]):
                        response_msg += response.split('|')[1]
                    else:
                        continue
                # if not using ids then the response is appended to the data
                else:
                    response_msg += response
                index += 1
                wait_time = constants.INITIAL_TIMEOUT
                id = random.randrange(constants.MAX_ID)
            except socket.timeout:  # if conection times out
                if wait_time >= constants.MAX_TIMEOUT:
                    raise (TimeOutError)
                # exponential backoff of timeout
                wait_time *= 2
                if wait_time > constants.MAX_TIMEOUT:
                    wait_time = constants.MAX_TIMEOUT
        return response_msg


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
