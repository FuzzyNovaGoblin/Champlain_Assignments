"""Client test code for Lab 10.

Author: Jason Reeves
Class: CSI-275
Assignment: Lab/HW 10 -- Multi-threaded 8-Ball Server
"""

import socket
import threading

# Number of questions each thread should send
SMALL_QUESTION_COUNT = 25
LARGE_QUESTION_COUNT = 10000

# Server host/port information
HOST = "localhost"
SERVER_PORT = 7000

# Maximum amount of data to read in one function call
MAX_BYTES = 1024


def recv_until_delimiter(delim_sock, byte_delim, storage):
    """Receive data until a specified delimiter is found."""
    # Initialize an empty buffer
    data = b""

    # For ease of use later: Decode the delimiter and
    # initialize a buffer index
    delim_char = byte_delim.decode("ascii")
    index = 0

    # See if the message is already there
    for c in storage.decode("ascii"):
        if c != delim_char:
            # Add the character to the returned data
            data += c.encode("ascii")
            index += 1
        else:
            data += c.encode("ascii")  # Add the delimiter now

            # Everything after the found delimiter goes into storage
            temp = storage[index + 1:]
            storage = temp

            # Return the message + delimiter and the storage buffer
            return data, storage

    # If we get here, no delimiter yet
    delim_found = False
    while not delim_found:
        # Grab data from the server
        more = delim_sock.recv(MAX_BYTES)
        if not more:
            return b"", ""

        # Go through the received data for the delimiter
        test = more.decode("ascii")
        index = 0
        for c in test:
            if c != delim_char:
                # No delimiter yet - add this to the data to return
                data += c.encode("ascii")
                index += 1
            else:  # Delimiter found!
                data += c.encode("ascii")  # Add the delimiter now

                # Everything after the delimiter goes into storage
                temp = test[index + 1:]
                storage = temp.encode("ascii")

                # Return the message + delimiter and the storage buffer
                return data, storage


def question_handler(handler_sock, num_qs, preamble):
    """Send questions to the server, and print the responses.

    handler_sock = The socket used to send/receive data.
    num_qs = The number of questions this function will send.
    preamble = The thread identifier.
    """
    # Initialize a storage variable
    short_storage = b""

    # Ask a smaller number of questions
    questions = "Can I ask a question?" * num_qs

    # Send the whole thing to the client
    handler_sock.sendall(questions.encode("ascii"))

    # Tell the client you're done
    handler_sock.shutdown(socket.SHUT_WR)

    # Print what you get back
    num_answers = 0
    while True:
        (answer, remaining) = recv_until_delimiter(handler_sock,
                                                   b".", short_storage)
        if not answer:
            break
        else:
            num_answers += 1
            short_storage = remaining

    # Did we get all the answers we expected?
    if num_answers == num_qs:
        print(f"PASS: Thread '{preamble}' received all requested answers.")
    else:
        print(f"FAIL: Thread '{preamble}' received {num_answers} answers,"
              f"but expected {num_qs}.")

    # Close the socket completely
    handler_sock.close()


if __name__ == '__main__':
    # Create three sockets
    first_socket = socket.socket()
    second_socket = socket.socket()
    third_socket = socket.socket()

    # Connect the sockets
    first_socket.connect((HOST, SERVER_PORT))
    second_socket.connect((HOST, SERVER_PORT))
    third_socket.connect((HOST, SERVER_PORT))

    # Set up the thread arguments
    long_args = (first_socket, SMALL_QUESTION_COUNT, "THREAD 1")
    short_args = (second_socket, LARGE_QUESTION_COUNT, "THREAD 2")
    third_args = (third_socket, SMALL_QUESTION_COUNT, "THREAD 3")

    # Create the threads and give them their arguments
    long_thread = threading.Thread(target=question_handler,
                                   args=long_args)
    short_thread = threading.Thread(target=question_handler,
                                    args=short_args)
    third_thread = threading.Thread(target=question_handler,
                                    args=third_args)

    # Start the threads
    long_thread.start()
    short_thread.start()
    third_thread.start()

    # Make the main program wait for all of the threads
    # to finish before continuing
    long_thread.join()
    short_thread.join()
    third_thread.join()
