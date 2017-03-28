memo = {}

def isCharMatch(s, p):
    return p in ('.', s)

def isMatch(s, p):
    if (s, p) not in memo:
        memo[(s, p)] = isMatchInner(s, p)
    return memo[(s, p)]

def isMatchInner(s, p):
    if p == '':
        return s == ''
    elif len(p) == 1:
        return len(s) == 1 and isCharMatch(s, p)

    if p[-1] != '*':
        return s != '' and isCharMatch(s[-1], p[-1]) and isMatch(s[:-1], p[:-1])
    return (isMatch(s, p[:-2]) or
        (s != '' and isCharMatch(s[-1], p[-2]) and isMatch(s[:-1], p)))

class Solution(object):
    def isMatch(self, s, p):
        return isMatch(s, p)
