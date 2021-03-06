'''
def count_stair_ways(n):
    if n == 0:
        return 0
    elif n == 1:
        return 1
    else:
        return count_stair_ways(n-1)+count_stair_ways(n-2)
'''
def count_k(n, k):
    '''
    >>> count_k(3, 3)
    4
    >>> count_k(4, 4)
    8
    >>> count_k(10, 3)
    274
    >>> count_k(300, 1)
    1
    '''
    '''
    if n == 0:
        return 0
    elif n == 1:
        return 1
    else:
       
       # return count_k(n-1, k)+count_k(n-2, k)+count_k(n-3, k)
    #sum(count_k(n-i-1, k) for i in range(k))'''
    if n == 0:
        return 1
    elif n < 0:
        return 0
    else:
        total = 0
        i = 1
        while i <= k:
            total += count_k(n-i, k)
            i += 1
        return total


def max_product(s):
    '''
    return max(s[i]*(s[j] for j in list[0:len(s)-2:2] if j<len(s)) for i in range(len(s)-2))
    '''
    if s == []:
        return 1
    elif len(s) == 1:
        return s[0]
    else:
        return max(max_product(s[1:]),s[0]*max_product(s[2:]))

def check_hole_number(n):
    if len(str(n)) == 3:
        return n//100 > n%100//10 and n%10 > n%100//10
    return check_hole_number(n//10%(10**(len(str(n))-2)))

def check_mountain_number(n):
    '''
    def helper(n):
        if (str(n)[i]<str(n)[i+1] for i in range(len(str(n))-1)) or (str(n)[i]>str(n)[i+1] for i in range(len(str(n)))):
            return True
        else:
            return False
    return helper(str(n)[0:str(n).index(max(str(n)[i] for i in range(len(str(n)))))]) and helper(str(n)[str(n).index(max(str(n)[i] for i in range(len(str(n))))):])'''
    def helper(x, is_increasing):
        if x // 10 == 0:
            return True
        if is_increasing and (x%10)<((x//10)%10):
            return helper(x // 10, is_increasing)
        return (x%10) > ((x // 10) % 10) and helper(x // 10, False)
    return helper(n, True)
