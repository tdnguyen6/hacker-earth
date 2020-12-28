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


M = 10 ** 32


def powxy(x, y):
    if y == 0:
        return 1
    if y % 2 == 1:
        return (x*powxy(x, y-1)) % M
    t = powxy(x, y/2)
    return (t*t) % M


for _ in range(ii()):
    n = ii()
    if not n:
        o(0)
    else:
        n_13 = str(n - 1)
        l = min(n, 9)
        n_13_cl = list(map(int, n_13[-l:].zfill(l)))
        n_13_cl = list(map(lambda x: 9 - x, n_13_cl))
        n_13_cl[-1] = n_13_cl[-1] + 1
        o("".join(map(str, n_13_cl)))
