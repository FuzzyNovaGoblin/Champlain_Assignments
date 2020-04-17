import socket
import json
import subprocess
import _thread
import threading
import curses
from curses.textpad import Textbox, rectangle

PORT = 54321
HOST = "fuzytech.com"
# HOST = "192.168.7.39"

username = ""
recv_sock = socket.socket()
send_sock = socket.socket()
padheight = 1
msgs = []
exit = False

msg_pad= None
input_win = None

def refresh():
    msg_pad.resize(curses.LINES-2, curses.COLS)
    while len(msgs) > curses.LINES - 3:
        del msgs[0]
    msg_pad.refresh(0, 0, curses.LINES - 5 - len(msgs), 0, curses.LINES -4 , curses.COLS - 1)
    # else:
    #     msg_pad.refresh(len(msgs)-curses.LINES-4, 0, 0, 0, curses.LINES - 4, curses.COLS - 1)

    for i in range(len(msgs)):
        msg_pad.move(i,0)
        msg_pad.addstr(msgs[i]+"\n")

    # input_win.redrawwin()

def init_connection():
    recv_sock.connect((HOST, PORT))
    data = ["START", username]
    json_data = json.dumps(data).encode("utf-8")
    recv_sock.sendall(len(json_data).to_bytes(4, 'big') + json_data)
    send_sock.connect((HOST,PORT))


def await_msg():
    while True:
        size = int.from_bytes(recv_sock.recv(4), 'big')
        data = json.loads(recv_sock.recv(size).decode("utf-8"))
        msgs.append(data)
        refresh()
        refresh()

def send_msg(arr):
    json_data = json.dumps(arr).encode("utf-8")
    send_sock.sendall(len(json_data).to_bytes(4, 'big') + json_data)


def server():
    try:
        init_connection()
        await_msg()
        # _thread.start_new_thread(await_msg, tuple())
    except Exception as e:
        print(e)
        print("Shuting Down")
        recv_sock.close()
        send_sock.close()


def send(msg):
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
    global msg_pad
    global input_win
    msg_pad  = curses.newpad(curses.LINES-2, curses.COLS) # (curses.LINES-2, curses.COLS)
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

    curses.endwin





if __name__ == "__main__":

    username = str(input("Enter a display name: "))
    username = username.replace(" ", "_")
    print(username)


    _thread.start_new_thread(server, ())
    curses.wrapper(main)

    curses.endwin