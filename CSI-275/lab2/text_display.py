"""Text display for Pacman.

Champlain College CSI-235, Spring 2018
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

import time

DRAW_EVERY = 1
SLEEP_TIME = 0  # This can be overwritten by __init__
DISPLAY_MOVES = False
QUIET = False  # Supresses output


class NullGraphics:
    """Class that just allows pausing and printing to the console."""

    def initialize(self, state, is_blue=False):
        """Do nothing."""
        pass

    def update(self, state):
        """Do nothing."""
        pass

    def check_null_display(self):
        """Return True in this case."""
        return True

    def pause(self):
        """Sleep for the specified amount of time."""
        time.sleep(SLEEP_TIME)

    def draw(self, state):
        """Print the state."""
        print(state)

    def update_distributions(self, dist):
        """Do nothing."""
        pass

    def finish(self):
        """Do nothing."""
        pass
