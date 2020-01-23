"""Base classes for tests.

Champlain College CSI-235, Spreing 2019
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


import inspect


def raise_not_implemented_error():
    """Raise NotImplementedError when method has not been defined."""
    raise NotImplementedError('Method not implemented: %s' %
                              inspect.stack()[1][3])


class Question:
    """Class which models a question in a project.

    Note that questions have a maximum number of points they are worth,
    and are composed of a series of test cases.
    """

    def __init__(self, question_dict, display):
        """Create Question instance given dictionary and display object."""
        self.max_points = int(question_dict['max_points'])
        self.test_cases = []
        self.display = display

    def add_test_case(self, test_case, thunk):
        """Add a test case.

        Note that 'thunk' must be a function which accepts a single argument,
        namely a 'grading' object
        """
        self.test_cases.append((test_case, thunk))

    def execute(self, grades):
        """Run the test and puts the result in grades.

        This will raise an error if not overridden.
        """
        raise_not_implemented_error()


class PassAllTestsQuestion(Question):
    """Question requiring all tests be passed in order to receive credit."""

    def execute(self, grades):
        """Run the test and put result in the grades object."""
        tests_failed = False
        grades.assign_zero_credit()
        for _, f in self.test_cases:
            if not f(grades):
                tests_failed = True
        if tests_failed:
            grades.fail("Tests failed.")
        else:
            grades.assign_full_credit()


class TestCase:
    """Template modeling a generic test case."""

    def __init__(self, question, test_dict):
        """Create test from question and test dictionary."""
        self.question = question
        self.test_dict = test_dict
        self.path = test_dict['path']
        self.messages = []

    def __str__(self):
        """Return string representation of test."""
        raise_not_implemented_error()

    def execute(self, grades, module_dict, solution_dict):
        """Run the test and return whether passes or not.

        Any additional information will be added to the grades object.
        """
        raise_not_implemented_error()

    def write_solution(self, module_dict, file_path):
        """Generate solutions using the correct code."""
        raise_not_implemented_error()

    # Tests should call the following messages for grading
    # to ensure a uniform format for test output.
    #
    # TODO: this is hairy, but we need to fix grading.py's interface
    # to get a nice hierarchical project - question - test structure,
    # then these should be moved into Question proper.
    def test_pass(self, grades):
        """Add appropriate passing messages to grades object."""
        grades.add_message('PASS: %s' % (self.path,))
        for line in self.messages:
            grades.add_message('    %s' % (line,))
        return True

    def test_fail(self, grades):
        """Add appropriate failing messages to grades object."""
        grades.add_message('FAIL: %s' % (self.path,))
        for line in self.messages:
            grades.add_message('    %s' % (line,))
        return False

    def add_message(self, message):
        r"""Add '\n' separated messages to this object."""
        self.messages.extend(message.split('\n'))


class EvalTest(TestCase):
    """Simple test case which evals an arbitrary piece of python code.

    The test is correct if the output of the code given the student's
    solution matches that of the instructor's.
    """

    def __init__(self, question, test_dict):
        """Create test from question and test dictionary."""
        super().__init__(question, test_dict)
        self.preamble = compile(test_dict.get('preamble', ""),
                                "%s.preamble" % self.path, 'exec')
        self.test = compile(test_dict['test'], "%s.test" % self.path,
                            'eval')
        self.success = test_dict['success']
        self.failure = test_dict['failure']

    def eval_code(self, module_dict):
        """Evaluate the code."""
        bindings = dict(module_dict)
        exec(self.preamble, bindings)
        return str(eval(self.test, bindings))

    def execute(self, grades, module_dict, solution_dict):
        """Run the test and return whether passes or not.

        Any additional information will be added to the grades object.
        """
        result = self.eval_code(module_dict)
        if result == solution_dict['result']:
            grades.add_message('PASS: %s' % self.path)
            grades.add_message('\t%s' % self.success)
            return True
        else:
            grades.add_message('FAIL: %s' % self.path)
            grades.add_message('\t%s' % self.failure)
            grades.add_message('\tstudent result: "%s"' % result)
            grades.add_message('\tcorrect result: "%s"' %
                               solution_dict['result'])

        return False

    def write_solution(self, module_dict, file_path):
        """Generate solutions using the correct code."""
        handle = open(file_path, 'w')
        handle.write('# This is the solution file for %s.\n' % self.path)
        handle.write('# The result of evaluating the test must equal ')
        handle.write('the below when cast to a string.\n')

        handle.write('result: "%s"\n' % self.eval_code(module_dict))
        handle.close()
        return True
