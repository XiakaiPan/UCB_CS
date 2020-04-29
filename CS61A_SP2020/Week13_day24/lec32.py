def bigs(t):
    def f(a, x):
        if a.label > x:
            return 1 + sum(f(b, a.label) for b in a.branches)
        else:
            return sum(f(b, x) for b in a.branches)
    return f(t, t.label-1)

def bigs(t):
    n = 0
    def f(a, x):
        nonlocal n
        if a.label > x:
            n += 1
        for b in a.branches:
            f(b, max(a.label, x))
    f(t, t.label-1)
    return n

def bigs(t):
    def f(a, x):
        if a.label > x:
            return 1 + sum([f(b, a,label) for b in a.branches])
        else:
            return sum([f(b, x) for b in a.branches])
    return f(t, a.label-1)

