def nut_finder(s):
    '''
    for si in s:
        print(list(si))
        for sii in list(si):
            print(sii)
            if sii == 'nut':
                return True
    return False
    '''
    def branch(t):
        if len(t) == 1 and t[0] == 'nut':
            return True
        elif len(t) == 1:
            return False
        else:
            for ti in t:
                branch(ti)
    return branch(s)
