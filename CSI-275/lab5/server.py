"""Grnat Hedley's code for Lab5.

Author: Grant Hedley
Class: CSI-275-1
Assignment: Lab 5
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
PORT = 20000


class ERROR(Exception):
    """Throw if "ERROR" needs to be returned to client."""
    pass


def arr_to_str(arr):
    """Turns an array into a str"""
    str = ""
    for i in range(len(arr)):
        if i != 0:
            str += " "
        str += arr[i]
    return str


def to_lower_case_compare(str1, str2, opp="a"):
    """Compares elements of an array.

    if 's' operator is used converts paramaters to strings and
    compares alphabeticaly, if 'a' or 'd' values are sorted assendingly or
    decendingly, trys cast values to ints or floats before comparing
    if some values are numbers and some are strings raises ERROR
    """
    try:
        str1 = int(str1)
    except (ValueError):
        try:
            str1 = float(str1)
        except (ValueError):
            str1 = str1.lower()
    try:
        str2 = int(str2)
    except (ValueError):
        try:
            str2 = float(str2)
        except (ValueError):
            str2 = str2.lower()
    if opp == "s":
        str1 = str(str1)
        str2 = str(str2)
    elif (type(str1) is str or
            type(str2) is str)and not type(str1) is type(str2):
        raise ERROR

    if opp == "d":
        return str1 < str2
    return str1 > str2


def sort_list(arr, operator):
    """Sorts a list.

    bubble sort algorithem that uses to_lower_case_compare to
    compare the values
    """
    swaped = True  # = len(arr) - 1
    while swaped:  # > 0:
        swaped = False
        for i in range(len(arr)-1):
            if to_lower_case_compare(arr[i], arr[i + 1], operator):
                swaped = True
                arr[i], arr[i + 1] = arr[i + 1], arr[i]
    return arr


def handle_data(data):
    """Handle data sent to server.

    checks that data starts with LIST key word and handles weather or not it
    uses the paramater at the end of the data
    if the data is valid it is sorted and "SORTED" is put infrount of it before
    it is returned
    otherwise "ERROR" is returned
    """
    data = data.split(" ")
    operator = "a"
    if data[0] != "LIST":
        return "ERROR"
    data = data[1:]
    if len(data) == 0:
        return "ERROR"
    elif "|" in data[-1]:
        operator = data[-1][-1]
        data[-1] = data[-1][:-2]
        if not set({operator}).issubset(set({'a', 'd', 's'})):
            return "ERROR"

    while data.__contains__(''):  # removes empty parts of the line
        data.remove('')
    try:
        sort_list(data, operator)
    except (ERROR):
        return "ERROR"
    data.insert(0, "SORTED")
    data = arr_to_str(data)
    return data


class SortServer:
    """Server to sort arrays."""

    def __init__(self, host, port):
        """Initialize the SortServer class

        host and port are saved and a tcp socket is created
        """

        self.address = (host, port)
        self.sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        self.sock.bind(self.address)
        self.sock.listen(20)

    def run_server(self):
        """Start server.

        starts a server on its given port and ip address and handles data as
        it is sent to the server
        """
        while True:
            print("listening at", self.address)
            cli_sock, address = self.sock.accept()
            print("Connected to", address)
            while True:
                data = cli_sock.recv(4096)
                data = data.decode("ASCII")
                if len(data) == 0:
                    cli_sock.close()
                    break
                print('recived:', data)
                data = handle_data(data)
                print('return:', data)
                cli_sock.sendall(data.encode("ascii"))


if __name__ == "__main__":
    server = SortServer(HOST, PORT)
    server.run_server()
