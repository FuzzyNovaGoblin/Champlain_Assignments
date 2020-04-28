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
import json
import subprocess
import _thread
import threading
import curses
import sys
from curses.textpad import Textbox, rectangle

PORT = 54321
HOST = "127.0.0.1"

username = ""
recv_sock = socket.socket()
send_sock = socket.socket()
padheight = 1
msgs = []
exit = False

msg_pad= None
input_win = None

def refresh():
    """Upadetes the curses display."""
    msg_pad.resize(curses.LINES-2, curses.COLS)
    while len(msgs) > curses.LINES - 3:
        del msgs[0]
    msg_pad.refresh(0, 0, curses.LINES - 5 - len(msgs),
    0, curses.LINES -4 , curses.COLS - 1)

    for i in range(len(msgs)):
        msg_pad.move(i,0)
        msg_pad.addstr(msgs[i]+"\n")


# def init_connection():
#     print("initial")
#     recv_sock.connect((HOST, PORT))
#     data = ["START", username]
#     json_data = json.dumps(data).encode("utf-8")
#     recv_sock.sendall(len(json_data).to_bytes(4, 'big') + json_data)
#     send_sock.connect((HOST,PORT))


def await_msg():
    """Wait for message

    runs on its own thread and waits for messages from the server
    on message it adds the message to the list of messages
    and refreshes the page
    """

    while True:
        size = int.from_bytes(recv_sock.recv(4), 'big')
        data = json.loads(recv_sock.recv(size).decode("utf-8"))
        msgs.append(data)
        refresh()
        refresh()

def send_msg(arr):
    """Send a message to the server."""

    json_data = json.dumps(arr).encode("utf-8")
    send_sock.sendall(len(json_data).to_bytes(4, 'big') + json_data)


def server():
    """Establish connection to server."""

    try:
        recv_sock.connect((HOST, PORT))
        data = ["START", username]
        json_data = json.dumps(data).encode("utf-8")
        recv_sock.sendall(len(json_data).to_bytes(4, 'big') + json_data)
        send_sock.connect((HOST, PORT))
    except Exception as e:
        print("Shuting Down")
        recv_sock.close()
        send_sock.close()


def send(msg):
    """Handle input from user.

    Takes input from user and generates a messeg to send to the server
    """

    global exit
    if len(msg) > 0 and msg[0] == '@':
        to = msg.split()[0][1:]
        msg = " ".join(msg.split()[1:])
        send_msg(["PRIVATE", username, msg, to])
    elif msg == "!exit":
        send_msg(["EXIT", username])
        send_sock.close()
        recv_sock.close()
        exit = True
    else:
        send_msg(["BROADCAST", username, msg])


def main(stdsrc):
    """Main display of program."""

    global msg_pad
    global input_win
    msg_pad  = curses.newpad(curses.LINES-2, curses.COLS)
    input_win = curses.newwin(1, curses.COLS, curses.LINES - 1, 0)
    refresh()
    msg = ""
    box = curses.textpad.Textbox(input_win)

    try:
        while not exit:
            refresh()

            box.edit()
            msg = box.gather()
            send(msg[:-1])
            input_win.move(0, 0)
            input_win.addstr(" "*(curses.COLS-1))
            input_win.move(0, 0)
    except Exception:
        pass

    curses.endwin()





if __name__ == "__main__":

    if len(sys.argv) > 1:
        HOST = sys.argv[1]
        if len(sys.argv) > 2:
            PORT = int(sys.argv[2])

    username = str(input("Enter a display name: "))
    username = username.replace(" ", "_")

    server()
    _thread.start_new_thread(await_msg, ())
    curses.wrapper(main)

    curses.endwin()
