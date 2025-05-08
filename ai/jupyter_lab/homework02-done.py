from collections import deque
import heapq
import math
import random
import sys

class Problem:
    def __init__(self, initial=None, goal=None, **kwds):
        self.__dict__.update(initial=initial, goal=goal, **kwds)

    
    def actions(self, state):
        raise NotImplementedError

    
    def result(self, state, action):
        raise NotImplementedError

    
    def is_goal(self, state):
        return state == self.goal

    
    def action_cost(self, s, a, s1):
        return 1

class Node:
    def __init__(self, state, parent=None, action=None, path_cost=0):
        self.__dict__.update(state=state, parent=parent, action=action, path_cost=path_cost)

    
    def __lt__(self, other):
        return self.path_cost < other.path_cost

    
    def __len__(self):
        return 0 if self.parent is None else (1 + len(self.parent))

class PriorityQueue:
    def __init__(self, items=(), key=lambda x : x):
        self.key = key
        self.items = []
        for item in items:
            self.add(item)

    
    def add(self, item):
        pair = (self.key(item), item)
        heapq.heappush(self.items, pair)

    
    def pop(self):
        return heapq.heappop(self.items)[1]

    
    def is_empty(self):
        return len(self.items) == 0

# we are going to treat a `deque` as a `queue`
queue = deque
reached = deque
failure = Node('failure', path_cost=math.inf)
cutoff  = Node('cutoff',  path_cost=math.inf)

def is_cycle(node, k=100):
    def find_cycle(ancestor, k):
        return (ancestor is not None and
                k > 0 and
                (ancestor.state == node.state or
                 find_cycle(ancestor.parent, k - 1)))
    return find_cycle(node.parent, k)


def expand(problem, node):
    s = node.state
    for act in problem.actions(s):
        s1 = problem.result(s, act)
        cost = node.path_cost + problem.action_cost(s, act, s1)
        yield Node(s1, node, act, cost)


def breadth_first_search(problem):
    node = Node(problem.initial)
    if problem.is_goal(node.state):
        return node
    queue.append(node)
    reached.append(node)

    while queue:
        m = queue.pop(0)
        for child in expand(problem, m):
            s = child.state
            if problem.is_goal(s):
                return child
            if s not in reached:
                reached.append(s)
                queue.append(child)
    return failure


def get_path_cost(node):
    """
    A simple function that just extracts the path cost from a given node.
    Used as the evaluation function, f(n), for implementing UCS.
    """
    return node.path_cost


def uniform_cost_search(problem):
    node = Node(problem.initial)
    frontier = PriorityQueue([node], key = get_path_cost)
    reached = { problem.initial: node }

    while frontier:
        node = frontier.pop()
        if problem.is_goal(node.state):
            return node
        for child in expand(problem, node):
            s = child.state
            if s not in reached or get_path_cost(child) < get_path_cost(reached[s]):
                reached[s] = child
                frontier.append(child)
    return failure


def depth_first_search(problem):
    node = Node(problem.initial)
    frontier = list((node))

    while len(frontier) >= 1:
        node = frontier.pop()
        if problem.is_goal(node.state):
            return node
        if not is_cycle(node):
            for child in expand(problem, node):
                frontier.append(child)

    return failure


def iterative_deepening_search(problem):
    for depth in range(sys.maxsize):
        result = depth_limited_search(problem, depth)

        if result != cutoff:
            return result


def depth_limited_search(problem, limit):
    node = Node(problem.initial)
    frontier = list((node))

    result = failure
    while len(frontier) >= 1:
        node = frontier.pop()
        if problem.is_goal(node.state):
            return node
        if len(node) > limit:
            result = cutoff
        elif not is_cycle(node):
            for child in expand(problem, node):
                frontier.append(child)
    
    return result


class TowersOfHanoi(Problem):
    def __init__(self, initial=(), goal=(), num_discs=2, **kwds):
        Problem.__init__(self, initial=(tuple([i for i in range(1,num_discs+1)]),(),()), goal=((),(),tuple([i for i in range(1,num_discs+1)])), num_discs=num_discs, **kwds)


    def result(self, state, action):
        new_state = ()
        source_tuple = state[action[0]].pop()
        destination_tuple = state[action[1]].append(action[2])
        
        if action[0] == 0 and action[1] == 1:
            new_state = tuple((source_tuple, destination_tuple, state[2]))
        elif action[0] == 0 and action[1] == 2:
            new_state = tuple((source_tuple, state[1], destination_tuple))
        elif action[0] == 1 and action[1] == 0:
            new_state = tuple((destination_tuple, source_tuple, state[2]))
        elif action[0] == 1 and action[1] == 2:
            new_state = tuple((state[0], source_tuple, destination_tuple))
        elif action[0] == 2 and action[1] == 0:
            new_state = tuple((destination_tuple, state[1], source_tuple))
        elif action[0] == 2 and action[1] == 1:
            new_state = tuple((state[0], destination_tuple, source_tuple))
        
        return new_state


    def actions(self, state):
        new_state = []
        disc_num = state[0].pop()
        return [state[0], state[1].append(disc_num), state[2]]