"""Test client code for Lab 5.

Author: Jason Reeves
Class: CSI-275-01/02
Assignment: Lab/HW 5 -- Sorting Server
Due Date: February 17, 2020, 11:59 PM

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
# import sys

# Set these values to match the hostname and port of your server
HOST = "localhost"
PORT = 20000

# Create a TCP/IP socket
sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

# Connect the socket to the port where the server is listening
server_address = (HOST, PORT)
print(f'connecting to {server_address}')
sock.connect(server_address)

# Test 1: Valid data
test_string = "LIST 5 404 3 2 1"
success_string = "SORTED 1 2 3 5 404"
sock.sendall(test_string.encode("ascii"))
response_string = sock.recv(4096)

# Report test success/failure
if response_string.decode("ascii") == success_string:
    print("TEST #1: PASS")
else:
    print(f"TEST #1: FAIL (expected {success_string}, "
          + f"received {response_string})")


# Test 2: Valid data with floats
test_string = "LIST -6 3.5 1.7 5000 "
success_string = "SORTED -6 1.7 3.5 5000"
sock.sendall(test_string.encode("ascii"))
response_string = sock.recv(4096)

# Report test success/failure
if response_string.decode("ascii") == success_string:
    print("TEST #2: PASS")
else:
    print(f"TEST #2: FAIL (expected {success_string}, "
          + f"received {response_string})")

# Test 3: Invalid data
test_string = "LIST 5 4 e 2 1"
success_string = "ERROR"
sock.sendall(test_string.encode("ascii"))
response_string = sock.recv(4096)

# Report test success/failure
if response_string.decode("ascii") == success_string:
    print("TEST #3: PASS")
else:
    print(f"TEST #3: FAIL (expected {success_string}, "
          + f"received {response_string})")

# Test 4: Invalid prefix
test_string = "5 4 3 2 1"
success_string = "ERROR"
sock.sendall(test_string.encode("ascii"))
response_string = sock.recv(4096)

# Report test success/failure
if response_string.decode("ascii") == success_string:
    print("TEST #4: PASS")
else:
    print(f"TEST #4: FAIL (expected {success_string}, "
          + f"received {response_string})")

# Test 5: Only prefix sent
test_string = "LIST"
success_string = "ERROR"
sock.sendall(test_string.encode("ascii"))
response_string = sock.recv(4096)

# Report test success/failure
if response_string.decode("ascii") == success_string:
    print("TEST #5: PASS")
else:
    print(f"TEST #5: FAIL (expected {success_string}, "
          + f"received {response_string})")

# Test 6: Ascending prefix sent
test_string = "LIST 10 2 4 8 6|a"
success_string = "SORTED 2 4 6 8 10"
sock.sendall(test_string.encode("ascii"))
response_string = sock.recv(4096)

# Report test success/failure
if response_string.decode("ascii") == success_string:
    print("TEST #6: PASS")
else:
    print(f"TEST #6: FAIL (expected {success_string}, "
          + f"received {response_string})")

# Test 7: Descending prefix sent
test_string = "LIST 10 2 4 8 6|d"
success_string = "SORTED 10 8 6 4 2"
sock.sendall(test_string.encode("ascii"))
response_string = sock.recv(4096)

# Report test success/failure
if response_string.decode("ascii") == success_string:
    print("TEST #7: PASS")
else:
    print(f"TEST #7: FAIL (expected {success_string}, "
          + f"received {response_string})")

# Test 8: Alphabetic prefix sent
test_string = "LIST 1 2 3 10 20 100|s"
success_string = "SORTED 1 10 100 2 20 3"
sock.sendall(test_string.encode("ascii"))
response_string = sock.recv(4096)

# Report test success/failure
if response_string.decode("ascii") == success_string:
    print("TEST #8: PASS")
else:
    print(f"TEST #8: FAIL (expected {success_string}, "
          + f"received {response_string})")

# Test 9: Bad prefix sent
test_string = "LIST 1 2 3 10 20 100|z"
success_string = "ERROR"
sock.sendall(test_string.encode("ascii"))
response_string = sock.recv(4096)

# Report test success/failure
if response_string.decode("ascii") == success_string:
    print("TEST #9: PASS")
else:
    print(f"TEST #9: FAIL (expected {success_string}, "
          + f"received {response_string})")

sock.close()
