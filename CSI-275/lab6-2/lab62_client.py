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
import sys
import random

# Set these values to match the hostname and port of your server
HOST = "localhost"
PORT = 45000

def recvall(sock, length):
    data = b''
    while len(data) < length:
        more = sock.recv(length - len(data))
        if not more:
            raise EOFError('was expecting %d bytes but only received'
                           ' %d bytes before the socket closed'
                           % (length, len(data)))
        data += more
    return data

# Create a TCP/IP socket
sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

# Connect the socket to the port where the server is listening
server_address = (HOST, PORT)
print(f'connecting to {server_address}')
sock.connect(server_address)

# Test 1: Simple string
test_string = "This is a test."
string_to_send = len(test_string).to_bytes(4, 'big') + test_string.encode("ascii")
sock.sendall(string_to_send)
length = int.from_bytes(sock.recv(4), 'big')
response = recvall(sock, length).decode("ascii")

if (length != len(response)):
    print(f"TEST #1: FAIL (expected {len(test_string)} bytes of data, "
          f"but received {length}")
elif (response != "I received 15 bytes."):
    print(f"TEST #1: FAIL (expected 'This is a test.', got {response}")
else:
    print("TEST #1: PASS")

sock.close()
sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
sock.connect(server_address)

# Test 2: Large string
rand_num = random.randint(10000, 15000)
test_string = "This is a test." * rand_num
print(f"Sending {rand_num} copies...")
string_to_send = len(test_string).to_bytes(4, 'big') + test_string.encode("ascii")
sock.sendall(string_to_send)
length = int.from_bytes(sock.recv(4), 'big')
response = recvall(sock, length).decode("ascii")

if (length != len(response)):
    print(f"TEST #2: FAIL (expected {len(test_string)} bytes of data, "
          f"but received {length}")
elif (response != f"I received {len(test_string)} bytes."):
    print(f"TEST #1: FAIL (expected 'I received {len(test_string)} bytes.', got {response}")
else:
    print("TEST #1: PASS")

sock.close()
sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
sock.connect(server_address)

# Test 3: Bad length field (too large)
rand_num = random.randint(20, 50)
print(f"Sending {rand_num} copies...")
test_string = "This is a test." * rand_num
bad_length = 80000
string_to_send = bad_length.to_bytes(4, 'big') + test_string.encode("ascii")
sock.sendall(string_to_send)
# Tell the server we're done sending data
sock.shutdown(socket.SHUT_WR)
length = int.from_bytes(sock.recv(4), 'big')
response = recvall(sock, length).decode("ascii")

if length != len("Length Error"):
    print(f"TEST #2: FAIL (expected {len('Length Error')} bytes of data, "
          f"but received {length}")
elif response != "Length Error":
    print(f"TEST #2: FAIL (expected 'Length Error', but did "
          f"not get it")
else:
    print("TEST #2: PASS")

sock.close()
sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
sock.connect(server_address)