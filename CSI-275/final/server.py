import socket
import _thread
import json

PORT = 54321
HOST = "0.0.0.0"

users = {}

def handle_start(data_arr, connection):
    name = data_arr[1].replace(" ", "_")
    users[name] = connection
    print(name, "connected")

def handle_exit(data_arr):
    users[data_arr[1]].close()
    del users[data_arr[1]]
    print(data_arr[1], "left")


def handle_broadcast(data_arr):
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
    """Sends a private """
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
    """Handle connections to new clients"""
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
    sock = socket.socket()
    sock.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
    sock.bind((HOST, PORT))
    sock.listen(50)
    while True:
        try:
            client, addr = sock.accept()
            _thread.start_new_thread(handle, (client, addr))
        except:
            sock.close()
            print("Shuting Down")
            break
