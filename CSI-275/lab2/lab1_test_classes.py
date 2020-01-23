"""Test classes for Lab 1.

Champlain College CSI-235, Spring 2019
The following code was adapted by Joshua Auerbach (jauerbach@champlain.edu)
from the UC Berkeley Pacman Projects (see license and attribution below).

----------------------
Licensing Information:  You are free to use or extend these projects for
educational purposes provided that (1) you do not distribute or publish
solutions, (2) you retain this notice, and (3) you provide clear
attribution to UC Berkeley, including a link to http://ai.berkeley.edu.

Attribution Information: The Pacman AI projects were developed at UC Berkeley.
The core projects and autograders were primarily created by John DeNero
(denero@cs.berkeley.edu) and Dan Klein (klein@cs.berkeley.edu).
Student side autograding was added by Brad Miller, Nick Hay, and
Pieter Abbeel (pabbeel@cs.berkeley.edu).
"""

import test_classes


class BlankSolutionTest(test_classes.TestCase):
    """A test case that intentionally leaves the solution file blank."""

    def write_solution(self, module_dict, file_path):
        """Write solution for the test.

        Overrides test_classes.TestCase.write_solution
        """
        handle = open(file_path, 'w')
        handle.write('# This is the solution file for %s.\n' % self.path)
        handle.write('# This file is left blank intentionally.\n')
        handle.close()
        return True


class ValidTest(BlankSolutionTest):
    """A test case that tests whether values are properly validated."""

    def __init__(self, question, test_dict):
        """Extend test_classes.TestCase.__init__."""
        super().__init__(question, test_dict)
        self.test_cases = test_dict["test_cases"]
        self.module_name = test_dict["module_name"]
        self.function_name = test_dict["function_name"]

    def execute(self, grades, module_dict, solution_dict):
        """Run student code.

        Overrides test_classes.TestCase.execute

        If an error message is returned, print error and return false.
        If a good solution is returned, print the solution and return true.
        Otherwise, print both the correct and student's solution and return
        false.
        """
        module = module_dict[self.module_name]
        function = module.__dict__[self.function_name]
        passing_all = True
        for test, solution in self.test_cases.items():
            grades.add_message("Testing {}...".format(repr(test)))

            result = function(test)

            if not isinstance(result, bool):
                grades.add_message('FAIL: {}'.format(self.path))
                grades.add_message('\tReturn type of {} must be '
                                   'bool, but it is {}'.format(
                                    self.function_name, type(result)))
                passing_all = False

            if result == solution:
                grades.add_message('PASS: {}'.format(self.path))
                grades.add_message('\t{} properly classified'.format(
                                    repr(test)))

            else:
                grades.add_message('FAIL: {}'.format(self.path))
                grades.add_message('\t{} improperly classified'.format(
                                    repr(test)))
                grades.add_message('\tstudent result: {}'.format(repr(result)))
                grades.add_message('\tcorrect result: {}'.format(
                                    repr(solution)))
                passing_all = False
        return passing_all


class ValidIPTest(ValidTest):
    """A test case that tests whether IP addresses are properly validated."""

    def __init__(self, question, test_dict):
        """Extend ValidTest.__init__."""
        test_dict["test_cases"] = {'127.0.0.1': True,
                                   '56.65.100.101': True,
                                   100: False,
                                   '100': False,
                                   '127a.0.0.1': False,
                                   '126.256.3.1': False,
                                   None: False,
                                   '': False}
        test_dict["module_name"] = "hosts"
        test_dict["function_name"] = "is_valid_ip_address"
        super().__init__(question, test_dict)


class ValidHostnameTest(ValidTest):
    """A test case that tests whether host names are properly validated."""

    def __init__(self, question, test_dict):
        """Extend ValidTest.__init__."""
        test_dict["test_cases"] = {'google.com': True,
                                   'www.google.com': True,
                                   'www3.example.com': True,
                                   'test.org7': True,
                                   'test-me.com': True,
                                   'localhost': True,
                                   '7labs.com': False,
                                   'test@wrong.com': False,
                                   'bad$%stuff.com': False,
                                   'a': True,
                                   '': False}
        test_dict["module_name"] = "hosts"
        test_dict["function_name"] = "is_valid_hostname"
        super().__init__(question, test_dict)


class ParseHostFileTest(BlankSolutionTest):
    """A test case that tests whether host files are properly validated."""

    def __init__(self, question, test_dict):
        """Extend test_classes.TestCase.__init__."""
        self.valid_files = ["test_files/hosts_valid1",
                            "test_files/hosts_valid2"]
        self.invalid_files = ["test_files/hosts_invalid1",
                              "test_files/hosts_invalid2",
                              "test_files/hosts_invalid3"]
        super().__init__(question, test_dict)

    def execute(self, grades, module_dict, solution_dict):
        """Run student code.

        Overrides test_classes.TestCase.execute

        If an error message is returned, print error and return false.
        If a good solution is returned, print the solution and return true.
        Otherwise, print both the correct and student's solution and return
        false.
        """
        hosts = module_dict["hosts"]
        passing_all = True
        for filename in self.valid_files:
            try:
                hosts.Hosts(filename)
            except hosts.InvalidEntryError:
                grades.add_message('FAIL: {}'.format(self.path))
                grades.add_message('\tInvalidEntryError raised for valid ' +
                                   'hosts file {}'.format(filename))
                passing_all = False
            else:
                grades.add_message('PASS: {}'.format(self.path))
                grades.add_message(('\tValid hosts file {} parsed without ' +
                                   'InvalidEntryError').format(filename))

        for filename in self.invalid_files:
            try:
                hosts.Hosts(filename)
            except hosts.InvalidEntryError:
                grades.add_message('PASS: {}'.format(self.path))
                grades.add_message('\tInvalidEntryError raised for invalid ' +
                                   'hosts file {}'.format(filename))
            else:
                grades.add_message('FAIL: {}'.format(self.path))
                grades.add_message('\tNo InvalidEntryError raised for ' +
                                   'invalid hosts file {}'.format(filename))
                passing_all = False
        return passing_all


class ContainsEntryTest(BlankSolutionTest):
    """A test case that tests if hosts.Hosts.contains_entry works properly."""

    def __init__(self, question, test_dict):
        """Extend test_classes.TestCase.__init__."""
        self.hosts_files = ["test_files/hosts_valid1",
                            "test_files/hosts_valid2"]
        self.test_cases = [{'localhost': '127.0.0.1',
                            'thishost.mydomain.org': '127.0.1.1',
                            'thishost': '127.0.1.1',
                            'foo.mydomain.org': '192.168.1.10',
                            'foo': '192.168.1.10',
                            'bar.mydomain.org': '192.168.1.13',
                            'bar': '192.168.1.13',
                            'master.debian.org': '146.82.138.7',
                            'master': '146.82.138.7',
                            'master.alias2.org': '146.82.138.7',
                            'master.alias3.org': '146.82.138.7',
                            'www.opensource.org': '209.237.226.90'},
                           {'wicked.awesome.com': '192.168.1.10',
                            'wicked': '192.168.1.10',
                            'www.opensource.org': '123.2.4.45'}]
        self.negative_cases = ['google.com', 'master.debian.org']
        super().__init__(question, test_dict)

    def execute(self, grades, module_dict, solution_dict):
        """Run student code.

        Overrides test_classes.TestCase.execute

        If an error message is returned, print error and return false.
        If a good solution is returned, print the solution and return true.
        Otherwise, print both the correct and student's solution and return
        false.
        """
        hosts = module_dict["hosts"]
        passing_all = True

        for hosts_file, test_cases, negative_case in zip(self.hosts_files,
                                                         self.test_cases,
                                                         self.negative_cases):
            my_hosts = hosts.Hosts(hosts_file)

            for key, _ in test_cases.items():
                if my_hosts.contains_entry(key):
                    grades.add_message('PASS: {}'.format(self.path))
                    grades.add_message('\thosts contains an entry for ' +
                                       '{}'.format(key))
                else:
                    grades.add_message('FAIL: {}'.format(self.path))
                    grades.add_message('\thosts should contain an entry for ' +
                                       '{}, but does not'.format(key))
                    passing_all = False

            if not my_hosts.contains_entry(negative_case):
                grades.add_message('PASS: {}'.format(self.path))
                grades.add_message('\thosts does not contain an entry for ' +
                                   '{}'.format(negative_case))
            else:
                grades.add_message('FAIL: {}'.format(self.path))
                grades.add_message('\thosts should not contain an entry for ' +
                                   '{}'.format(negative_case))
                grades.add_message('\tHint: make sure you are using member '
                                   'variables and not class variables!')
                passing_all = False

        return passing_all


class RetrieveIPTest(ContainsEntryTest):
    """A test case that tests if hosts.Hosts.get_ip works properly."""

    def execute(self, grades, module_dict, solution_dict):
        """Run student code.

        Overrides ContainsEntryTest.execute

        If an error message is returned, print error and return false.
        If a good solution is returned, print the solution and return true.
        Otherwise, print both the correct and student's solution and return
        false.
        """
        hosts = module_dict["hosts"]
        passing_all = True

        for hosts_file, test_cases, negative_case in zip(self.hosts_files,
                                                         self.test_cases,
                                                         self.negative_cases):
            my_hosts = hosts.Hosts(hosts_file)

            for key, value in test_cases.items():
                result = my_hosts.get_ip(key)
                if result == value:
                    grades.add_message('PASS: {}'.format(self.path))
                    grades.add_message('\thosts properly maps ' +
                                       '{} to {}'.format(key, value))
                else:
                    grades.add_message('FAIL: {}'.format(self.path))
                    grades.add_message(('\thosts maps {} to {}, but should be '
                                        'mapped to {}').format(
                                            key, result, value))
                    passing_all = False

            result = my_hosts.get_ip(negative_case)
            if result is None:
                grades.add_message('PASS: {}'.format(self.path))
                grades.add_message('\thosts.get_ip properly returns None for '
                                   '{}'.format(negative_case))
            else:
                grades.add_message('FAIL: {}'.format(self.path))
                grades.add_message(('\thosts maps {} to {}, but should be ' +
                                    'mapped to {}').format(key, result, None))
                passing_all = False
        return passing_all
