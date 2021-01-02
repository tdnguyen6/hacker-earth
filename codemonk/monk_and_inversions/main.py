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
    return(list(s[:len(s) - 1]))


def imi():
    return(map(int, i().split()))


def imil():
    return(list(imi()))


def o(w='', end='\n'):
    sys.stdout.write(str(w) + end)
#########################################################


for _ in range(ii()):
    N = ii()
    A = []
    c = 0
    for _ in range(N):
        A.append(imil())

    for u in range(N):
        for v in range(N):
            for m in range(u, N):
                for n in range(v, N):
                    if A[u][v] > A[m][n]:
                        c += 1
    o(c)

