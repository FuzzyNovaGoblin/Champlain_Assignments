"""
Author: Grant Hedley
Class: CSI-275-1
Assignment: Lab1
Due Date: January 20 11:59PM

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


def build_list():
    """Asks user for numbers and returns a list

    The user is prompted to enter a number repetedly until an empty
    string is returned. Every line that can be cast to an int or float
    is added to a list.
    """
    done = False
    nums = []

    while not done:
        buff = input("Enter a number or just press Enter to stop\n")
        if buff == "":
            done = True
        else:
            try:
                nums.append(int(buff))  # try to cast to int
            except:
                try:
                    nums.append(float(buff))  # try to cast to int
                except:
                    print("That is not a number")

    return nums


def sort_list(arr):
    """sorts a list

    calls the built in list sort method on the argument
    """
    if len(arr) == 0:  # if the array is empty end function
        return arr

    # turn the array into a string
    arr_str = "LIST"
    for s in arr:
        arr_str += " " + str(s)

    # encode the string to be sent to the server
    byte_str = arr_str.encode("ascii")

    sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)  # create socket
    sock.connect(("192.168.3.122", 7778))  # connect to server
    sock.sendall(byte_str)  # send our array to server

    return_str = sock.recv(4096)  # get data from server
    return_str = return_str.decode("ascii")  # decode the data from the server
    sock.close()  # close the socket

    str_arr = return_str.split(" ")  # convert data to array
    arr = str_arr[1:]  # remove key word from data

    for i in range(len(arr)):
        try:
            arr[i] = int(arr[i])
        except:
            try:
                arr[i] = float(arr[i])
            except:
                print("That is not a number")

    return arr


def main():
    arr = sort_list(build_list())
    print(arr)


if __name__ == "__main__":
    main()
