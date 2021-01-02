############## ---- Fast IO Functions ---- ##############
import io
import os
import sys
i = io.BytesIO(os.read(0, os.fstat(0).st_size)).readline


def ii():
    return(int(i()))


def iS():
    return i().decode().strip()


def icl():
    s = iS()
    return(list(s[:len(s)]))


def imi():
    return(map(int, i().split()))


def imil():
    return(list(imi()))


def o(w='', end='\n'):
    sys.stdout.write(str(w) + end)
#########################################################

for _ in range(ii()):
    N, K = imi()
    A = icl()
    max = ''.join(A)
    maxPos = [0]
    for _i in range(1, N):
        A = A[1:] + A[:1]
        v = ''.join(A)
        if v > max:
            max = v
            maxPos = [_i]
        elif v == max:
            maxPos.append(_i)
    
    c = 0
    ans = maxPos[c]
    for _i in range(K - 1):
        next_c = (c + 1) % len(maxPos)
        dis = abs(maxPos[next_c] - maxPos[c])
        if dis > 0:
            ans += dis
        else:
            ans += N
        c = next_c
    o(ans)

