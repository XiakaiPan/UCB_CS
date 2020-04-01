def a_then_b(a, b):
	for x in a:
		yield x
	for x in b:
		yield x

def a_then_b_(a, b):
	yield a
	yield b

def countdown(k):
	if k > 0:
		yield k
		yield from countdown(k-1)
