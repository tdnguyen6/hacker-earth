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


# M = 10 ** 32


# def powxy(x, y):
#     if y == 0:
#         return 1
#     if y % 2 == 1:
#         return (x*powxy(x, y-1)) % M
#     t = powxy(x, y/2)
#     return (t*t) % M


c = 1000000009
t = '13'
K = 10
l_t = len(t)
R = [0] * (l_t + 1)
r = len(R)

# O (S * T * K)

for _ in range(ii()):
    n = ii()
    for j in range(1, l_t + 1):  # 1 -> l_t
        R[j] = K ** j
    R[-1] = R[-1] - 1

    for _ in range(l_t + 1, n + 1): # l_t + 1 to n
        tmp = (R[r - 1] * K) - R[r - l_t]
        for u in range(l_t):  # 0 -> l_t - 1
            R[u] = R[u + 1]
        R[-1] = tmp % c

    o(int(R[-1]))
