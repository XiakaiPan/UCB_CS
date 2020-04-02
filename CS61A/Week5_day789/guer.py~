# 1.9 change
def c(n):
    '''
    if n < 10:
        print(n)
        return
    c(n//10)
    print(n)'''
    '''
    if n >= 10:
        print(n)
        c(n//10)
    print(n)
    '''
    if n >= 10:
        c(n//10)
    print(n)
    if n >= 10:
        c(n//10)
# fail!
# 1.10
def paths(m, n):
    if m == 1 or n == 1:
        return 1
    else:
        return paths(m, n-1) + paths(m-1, n)

# 1.11 
def merge(s1, s2):
    '''
    s = []
    if len(s1) == 0 :
        return s2
    elif len(s2) == 0:
        return s1
    elif len(s1) == 0 and len(s2) == 0:
        return 
    elif s1[0] > s2[0]:
	    s.append(s2[0])
	    del(s2[0])
    else:
	    s.append(s1[0])
	    del(s1[0])
    s.append(merge(s1, s2)[0])
    return s
    '''
    if len(s1) == 0:
        return s2
    elif len(s2) == 0:
        return s1
    elif s1[0] < s2[0]:
        return [s1[0]] + merge(s1[1:], s2)
    else:
        return [s2[0]] + merge(s1, s2[1:])

def move(n, f, buf, t):
    if n == 1:
        print('Move', 'from', f, 'to', t)
    else:
        move(n-1, f, t, buf)
        move(1, f, buf, t)
        move(n-1, buf, f, t)

def mario_number(level):
	def ways(n):
		if n == len(level)-1:
			return 1
		if n >= len(level) or level[n] == 'P':
			return 0
		return ways(n+1) + ways(n+2)
	return ways(0)
