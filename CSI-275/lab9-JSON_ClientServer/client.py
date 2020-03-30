"""Client code for Lab 9.

Author: Grant Hedley
Author: Duane Dunston (original author)
Author: Jason Reeves (modified code for CSI-275)
Class: CSI-275-01/02
Assignment: Lab/HW 9 - JSON Client/Server

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

import json
import socket
import zlib

def build_list():
    """Collect input from the user and return it as a list.
    Only numeric input will be included; strings are rejected.
    """
    #Create a list to store our numbers
    unsorted_list = []
    # Create a variable for input
    user_input = ""

    while user_input.lower() != "1" and user_input.lower() != "2" and user_input.lower() != "3":
        user_input = input("How would you like to sort values?\n1) Ascending\n2) Descending\n3) Aphabetically\n")

    unsorted_list.append("a" if user_input == "1" else "d" if user_input == "2" else "s")

    while user_input != "done":
        # Prompt the user for input
        user_input = input("Please enter a number, or 'done' to stop.")
        # Validate our input, and add it to out list
        # if it's a number
        try:
            # Were we given an integer?
            unsorted_list.append(int(user_input))
        except ValueError:
            try:
                # Were we given a floating-point number?
                unsorted_list.append(float(user_input))
            except ValueError:
                # Non-numeric input - if it's not "done",
                # reject it and move on
                if (user_input != "done"):
                    print("ERROR: Non-numeric input provided.")
                continue
    # Once we get here, we're done - return the list
    return unsorted_list


def sort_list(unsorted_list):
    """Has server sort list.

    sends unsorted list to server
    waits for a response
    decodes and prints the response
    """
    print(unsorted_list)
    data = json.dumps(unsorted_list).encode("utf-8")

    print("pre compress size:", len(data))
    data = zlib.compress(data)
    print("post compress size:", len(data))


    sock = socket.socket()
    sock.connect(('127.0.0.1', 7778))
    sock.sendall(data)
    data = sock.recv(4096)
    decoded_data = json.loads(data.decode('utf-8'))
    print(decoded_data)


def main():
    """Call the build_list and sort_list functions, and print the result."""
    number_list = build_list()

    sort_list(number_list)


if __name__ == "__main__":
    main()
