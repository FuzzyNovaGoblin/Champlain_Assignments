"""Student code for Lab/HW1.

    Run python autograder.py

Champlain College CSI-235, Spring 2019
The following code was written by Joshua Auerbach (jauerbach@champlain.edu)
"""

from util import raise_not_defined


class InvalidEntryError(Exception):
    """Exception raised for invalid entries in the hosts file."""

    pass


def is_valid_ip_address(ip_address):
    """Return whether the given ip_address is a valid IPv4 address or not.

    Args:
        ip_address (str): ip_address to test

    Returns:
        bool: True if ip_address is valid IPv4 address, False otherwise.

    """
    ip_address = str(ip_address)
    pCount = 0 #number of decimal point in ip_address
    for i in range(len(ip_address)):
        print(ip_address[i])
        if (ip_address[i] == '.'):
            pCount += 1
        elif (ord(ip_address[i]) < 48 or ord(ip_address[i]) > 57):
            return False
    return pCount == 3

def is_valid_hostname(hostname):
    """Return whether the given hostname is valid or not.

    Host names may contain only alphanumeric characters, minus signs ("-"),
    and periods (".").  They must begin with an alphabetic character and end
    with an alphanumeric character.

    Args:
        hostname (str): hostname to test

    Returns:
        bool: True if hostname is valid, False otherwise.

    """
    if (not hostname[0].alphabetic() or not hostname[-1].alphabetic()):
        return False
    for i in range(len(hostname)):
        oVal = ord(hostname[i])
        if (oVal < 45):
            return False
        elif (oVal <= 46):
            continue
        elif (oVal == 47):
            return False
        elif (oVal <= 57):
            continue
        elif (oVal <= 64):
            return False
        elif (oVal <= 90):
            continue
        elif (oVal <= 96):
            return False
        elif (oVal <= 122):
            continue
        else:
            return False
    return True





class Hosts:
    """The Hosts class handles translating hostnames to ip addresses."""

    pass  # remove this line when you implement this class
    #   *** YOUR CODE HERE ***
