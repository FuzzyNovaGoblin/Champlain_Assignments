"""
Author: Grant Hedley
Class: CSI-275-1
Assignment: fianl
Due Date: 4/24/20

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
import _thread
import json
import sys

PORT = 54321
HOST = "127.0.0.1"

users = {}

def handle_start(data_arr, connection):
    """Hanldle a start signal.

    called when a start signal is recived
    asigns that connection to a new a name and they are stored
    """
    name = data_arr[1].replace(" ", "_")
    users[name] = connection
    print(name, "connected")

    json_data = json.dumps(name + " has joined the chat").encode("utf-8")
    data = len(json_data).to_bytes(4, 'big') + json_data
    for name, conn in users.items():
        try:
            conn.sendall(data)
        except Exception:
            del users[name]

def handle_exit(data_arr):
    """Handle exit signal.

    called when exit signal is recived
    disconects the client
    removes client from saved users
    """
    users[data_arr[1]].close()
    del users[data_arr[1]]
    print(data_arr[1], "left")
    json_data = json.dumps(data_arr[1] + " has left the chat").encode("utf-8")
    data = len(json_data).to_bytes(4, 'big') + json_data
    for name, conn in users.items():
        try:
            conn.sendall(data)
        except Exception:
            del users[name]


def handle_broadcast(data_arr):
    """Handle a brodcast signal.

    called when a user sends a brodcast message
    message is sent to every user that is saved
    """

    json_data = json.dumps(str(data_arr[1]) + ": " + str(data_arr[2]))
    print(json.loads(json_data))
    json_data = json_data.encode('utf-8')
    data = len(json_data).to_bytes(4, 'big') + json_data
    for name, conn in users.items():
        try:
            conn.sendall(data)
        except Exception:
            del users[name]
    print(data_arr[1], "yells", data_arr[2])


def handle_private(data_arr):
    """Handle a private signal.

    called when a user sends a private message
    message is sent to specified user if they exist
    """
    json_data = json.dumps(str(data_arr[1]) + ": " + str(data_arr[2]))
    json_data = json_data.encode('utf-8')
    data = len(json_data).to_bytes(4, 'big') + json_data
    try:
        users[data_arr[1]].sendall(data)
        users[data_arr[3]].sendall(data)
    except Exception:
        pass
    print(data_arr[1], "says", data_arr[2], "to", data_arr[3])


def handle(connection, addr):
    """Handle incoming messages.

    data is sent to method to handle the relevant signal
    """

    try:
        while True:
            size = int.from_bytes(connection.recv(4), 'big')
            data = json.loads(connection.recv(size).decode("utf-8"))
            print(data)
            if data[0] == "START":
                handle_start(data, connection)
            elif data[0] == "EXIT":
                handle_exit(data)
            elif data[0] == "BROADCAST":
                handle_broadcast(data)
            elif data[0] == "PRIVATE":
                handle_private(data)
            else:
                connection.close()
                break
    except Exception:
        connection.close()




if __name__ == "__main__":

    if len(sys.argv) > 1:
        HOST = sys.argv[1]
        if len(sys.argv) > 2:
            PORT = int(sys.argv[2])


    sock = socket.socket()
    sock.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
    sock.bind((HOST, PORT))
    sock.listen(50)
    print("listening at", (HOST, PORT))
    while True:
        try:
            client, addr = sock.accept()
            _thread.start_new_thread(handle, (client, addr))
        except:
            sock.close()
            print("Shuting Down")
            break
