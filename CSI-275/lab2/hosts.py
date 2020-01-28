"""Grant Hedley's code for Lab2.

Author: Grant Hedley
Class: CSI-275-1
Assignment: Lab2
Due Date: 01/27/20

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
"""Student code for Lab/HW1.

    Run python autograder.py

Champlain College CSI-235, Spring 2019
The following code was written by Joshua Auerbach (jauerbach@champlain.edu)
"""


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
    ip_address = str(ip_address)  # make sure ip_address is a string

    if len(ip_address) == 0:  # make sure string is not empty
        return False

    p_count = 0  # number of periods in ip_address
    for i in range(len(ip_address)):
        if (ip_address[i] == '.'):  # count periods
            p_count += 1
        elif (ord(ip_address[i]) < 48
                or ord(ip_address[i]) > 57):  # only contains numbers
            return False
    ip_address = ip_address.split('.')

    # check that each section is no more than 1 byte
    for section in ip_address:
        if int(section) > 255:
            return False
    return p_count == 3


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
    if (hostname == ''):
        return False

    if (not hostname[0].isalpha() or not hostname[-1].isalnum()):
        return False
    for i in range(len(hostname)):
        o_val = ord(hostname[i])
        if (o_val < 45):
            return False
        elif (o_val <= 46):
            continue
        elif (o_val == 47):
            return False
        elif (o_val <= 57):
            continue
        elif (o_val <= 64):
            return False
        elif (o_val <= 90):
            continue
        elif (o_val <= 96):
            return False
        elif (o_val <= 122):
            continue
        else:
            return False
    return True


class Hosts:
    """The Hosts class handles translating hostnames to ip addresses."""

    def __init__(self, file_name):
        """Initialize the Hosts class.

        if file is valid add all ips to array and
        all host names and aliases to array
        """
        self.ips = []
        self.hostnames = []

        file = open(file_name, "r")
        ips_to_add = []
        hostnames_to_add = []
        for line in file.readlines():  # iterate over each line in the file
            ip = ""
            hostnames = []
            buff = line.split()
            while buff.__contains__(''):  # removes empty parts of the line
                buff.remove('')
            # ignores comments and empty lines
            if len(buff) == 0 or buff[0][0] == '#':
                continue
            if len(buff) < 2:  # checks for both a ip and host name

                raise(InvalidEntryError)
            if not is_valid_ip_address(buff[0]):  # verifies ip
                raise(InvalidEntryError)
            if not is_valid_hostname(buff[1]):  # verifies host name
                raise (InvalidEntryError)
            ip = buff[0]  # ip will be cept track of
            hostnames.append(buff[1])  # host name will be kept track of
            if len(buff) > 2:  # checks if there are aliases
                for alias in buff[2:]:
                    if alias[0] == "#":  # ignores comments
                        break
                    if not is_valid_hostname(alias):  # validates aliases
                        raise (InvalidEntryError)
                    hostnames.append(alias)  # alias will be added
            ips_to_add.append(ip)
            hostnames_to_add.append(hostnames)
        self.ips += ips_to_add
        self.hostnames += hostnames_to_add

    def contains_entry(self, hostname):
        """Check to see if host name is stored.

        Args:
            hostname (str): hostname to test

        Returns:
            bool: True if hostname is in file, False otherwise.
        """
        for host in self.hostnames:  # look at each host name
            for name in host:  # look at evey alias of each host
                if name == hostname:
                    return True
        return False

    def get_ip(self, hostname):
        """Get the ip of a given hostname.

        Args:
            hostname (str): hostname to test

        Returns:
            str: ip of host name
        """
        for host_index in range(len(self.hostnames)):  # look at each host name
            # look at evey alias of each host
            for name in self.hostnames[host_index]:
                if name == hostname:
                    return self.ips[host_index]
        return None
