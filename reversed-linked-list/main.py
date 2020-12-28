from collections import deque
############## ---- Fast IO Functions ---- ##############
import io
import os
import sys
i = io.BytesIO(os.read(0, os.fstat(0).st_size)).readline


def ii():
    return(int(i()))


def iS():
    return i().decode()


def icl():
    s = iS()
    return(list(s[:len(s) - 1]))


def imi():
    return(map(int, i().split()))


def imil():
    return(list(imi()))


def o(w='', end='\n'):
    sys.stdout.write(str(w) + end)
#########################################################


def solve(*args):
    N, A = args
    B = A[:]
    tmp = deque()
    start = -1
    for i in range(N):
        if B[i] % 2 == 0:
            if start == -1:
                start = i
            tmp.appendleft(B[i])
            if len(tmp) > 1 and i == N - 1:
                A = A[:start] + list(tmp)
        else:
            if len(tmp) > 0 and start >= 0:
                if len(tmp) > 1:
                    A = A[:start] + list(tmp) + A[i:]
                
                tmp.clear()
                start = -1

    return " ".join(map(str, A))


n_test = ii()
for _ in range(n_test):
    N = ii()
    A = imil()
    o(solve(N, A))
