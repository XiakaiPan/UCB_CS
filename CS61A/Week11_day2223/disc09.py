class VendingMachine:
    k = 0
    def __init__(self, k, v):
        self.soda = JunkDrink(self)
        self.k = k
        if v:
            print(isinstance(self.soda.machine, VendingMachine))

class JunkDrink:
    def __init__(self, machine):
        self.machine = machine

a = VendingMachine(1 ,False)
b = VendingMachine.__init__(a, 2, False)
VendingMachine.__init__(VendingMachine, 10, False)
