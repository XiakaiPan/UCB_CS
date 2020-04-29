class Student:
    students = 0 # this is a class attribute
    def __init__(self, name, ta):
        self.name = name # this is an instance attribute
        self.understanding = 0
        Student.students += 1
        print("There are now", Student.students, "Students")
        ta.add_student(self)

    def visit_office_hours(self, staff):
        staff.assist(self)
        print("Thanks, " + staff.name)

class Professor:
    def __init__(self, name):
        self.name = name
        self.students = {}

    def add_student(self, student):
        self.students[student.name] = student

    def assist(self, student):
        student.understanding += 1


class Email:
    """Every email object has 3 instance attributes: the message, the sender name, and the recipient name."""
    def __init__(self, msg, sender_name, recipient_name):
        self.msg = message
        self.sender_name = sender_name
        self.recipient = recipient_name

class Server:
    """Each Server has an instance attribute clients, which is a dictionary that associates client names with client objects"""
    def __init__(self):
        self.clients = {}

    def send(self, emial):
        """Take an email and put it in the inbox of the client it is addressed to"""
        client = self.clients[email.recipient_name]
        client.receive(email)

    def register_client(self, client, client_name):
        """Takes a client object and adds them to the clients instance attribute.
        """
        self.clients[client.name] = client


class Client:
    """Every Client has instance attributes name (which is used for addressing emails to the client), server (which is used to send emails out to other clients), and inbox (a list of all emails the clients has recieved).
    """
    def __init__(self, server, name):
        self.inbox = []
        self.server = server
        self.name = name

        self.server.register_client(self, self.name)

    def compose(self, msg, recipient_name):
        """Send an email with the given message msg to the given recipient client."""
        email = Email(msg, self.name, recipient_name)
        self.server.send(email)

    def receive(self, email):
        """Take an email and add it to the inbox of this client"""
        self.inbox.append(email)


class Dog():
    def __init__(self, name, owner):
        self.is_value = True
        self.name = name
        self.owner = owner

    def eat(self, thing):
        print(self.name + " ate a " + str(thing) + "!")

    def talk(self):
        print(self.name + " says woof!")

class Cat():
    def __init__(self, name, owner, lives = 9):
        self.is_alive = True
        self.name = name 
        self.owner = owner
        self.lives = lives

    def eat(self, thing):
        print(slef.name + " ate a " + str(thing) +"!")

    def talk(self):
        print(self.name + " says meow!")


class Pet():
    def __init__(self, name, owner):
        self.is_alive = True
        self.name = name
        self.owner = owner

    def eat(self, thing):
        print(self.name + " ate a " + str(thing) + "!")

    def talk(self):
        print(self.name)

class Dog(Pet):
    def talk(self):
        print(self.name + ' says woof!')

class Cat(Pet):
    def __init__(self, name, owner, lives = 9):
        '''
        self.name = name
        self.owner = owner
        '''
        Pet.__init__(self, name, owner)
        self.lives = lives
    
    def talk(self):
        """ Print out a cat's greeting.

        >>> cat('Thomas', 'Tammy').talk()
        Thomas says meow!
        """
        print(self.name + " says meow!")

    def lose_life(self):
        """Decrements a cat's life by 1. When lives reaches zero, 'is_alive' becomes False. If this is called after lives has reached zero, print that the cat has no more lives to lose.
        """
        if self.lives <= 0:
            print("The cat has no more lives to lose")
        else:
            self.lives -= 1
            if self.lives == 0:
                self.is_alive = False


class NoisyCat(Cat):
    """ A Cat that repeats thing twice."""
    #def __init__(self, name, owner, lives = 9):
    def talk(self):
        """Talk twice as much as a regular cat.

        >>> NoisyCat('Magic', 'James').talk()
        Magic says meow!
        Magic says meow!
        """
        '''
        for i in range(2):
            print(self.name + " says meow!")
        '''
        Cat.talk(self)
        Cat.talk(self)

class A:
    def f(self):
        return 2
    def g(self, obj, x):
        if x == 0:
            return A.f(obj)
        return obj.f() + self.g(self, x - 1)

class B(A):
    def f(self):
        return 4


class Link:
    empty = ()
    def __init__(self, first, rest=empty):
        assert rest is Link.empty or isinstance(rest, Link)
        self.first = first
        self.rest = rest

    def __repr__(self):
        if self.rest:
            rest_str = ', ' + repr(self.rest)
        else:
            rest_str = ''
        return 'Link({0}{1})'.format(repr(self.first), rest_str)


    def __str__(self):
        string = '<'
        while self.rest is not Link.empty:
            string += str(self.first)
            self = self.rest
        return string + str(self.first) + '>'

def sum_nums(lnk):
    """
    >>> a = Link(1, Link(6, Link(7)))
    >>> sum_nums(a)
    14
    """
    '''
    res = 0
    if lnk is Link.empty:
        return 0
    elif lnk.rest:
        res += sum_nums(lnk.rest)
    res += lnk.first
    return res
    '''
    if lnk == Link.empty:
        return 0
    return lnk.first + sum_nums(lnk.rest)

def multiply(lst_of_lnks):
    product = 1
    for lnk in lst_of_lnks:
        if lnk is Link.empty:
            return Link.empty
        product *= lnk.first
    lst_of_lnks_rests = [lnk.rest for lnk in lst_of_lnks]
    return Link(product, multiply(lst_of_lnks_rests))


import operator 
from functools import reduce
def prod(factors):
    return reduce(operator.mul, factors, 1)

head = Link.empty
tail = head
while Link.empty not in lst_of_lnks:
    all_prod = prod([l.first for l in lst_of_lnks])
    if head is Link.empty:
        head = Link(all_prod)
        tail = head
    else:
        tail.rest = Link(all_prod)
        tail = tail.rest
    lst_of_lnks = [l.rest for l in lst_of_lnks]
return head


def filter_link(link, f):
    """
    >>> link = Link(1, Link(2, Link(3)))
    >>> g = filter_link(link lambda x:x % 2 == 0)
    >>> next(g)
    2
    >>> next(g)
    StopIteration
    >>> list(filter_link(link, lambda x: x % 2 != 0))
    [1, 3]
    """
    while link is not Link.empty:
        if f(link.first):
            yield link.first
        link = link.rest

def filter_no_iter(link, f):
    """
    >>> link = Link(1, Link(2, Link(3)))
    >>> list(filter_no_iter(link, lambda x: x % 2 != 0))
    [1, 3]
    """
    if link is Link.empty:
        return 
    elif f(link.first):
        yield link.first
    yield from filter_no_iter(link.rest, f)


def feed(snax, x, y):
    """
    >>> feed([1, 1, 1], 2, 2) # The two robots both refill once at the beginning
    2
    >>> feed([1, 2, 2], 2, 2) # Only one robot refills to feed middle student
    3
    >>> feed([1, 1, 1, 2, 2], 2, 2)
    4
    >>> feed([3, 2, 1, 3, 2, 1, 1, 2, 3], 3, 3)
    6
    """
    def helper(lst, p, q):
        if p < 0 or q < 0:
            return float("inf")
        elif not lst:
            return 0
        elif len(lst) == 1:
            return not (p >= lst[0] or q >= lst[0])
        else:
            a = helper(lst[1:-1], p - lst[0], q - lst[-1]) # No one refills
            b = 2 + helper(lst[1:-1], x - lst[0], y - lst[-1]) # Both refill
            c = 1 + helper(lst[1:-1], x - lst[0], q - lst[-1]) # Only robot A refills
            d = 1 = helper(lst[1:-1], p - lst[0], y - lst[-1]) # Only robot B refills
            return min(a, b, c, d)
        return helper(snax, 0, 0)
