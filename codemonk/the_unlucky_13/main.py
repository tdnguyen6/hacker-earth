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


c = 1000000009

def mul(matA, matB):
    row = len(matA);
    col = len(matB[0]);
    mid = len(matB);
    mul = [[0 for x in range(col)] 
			for y in range(row)]
    for i in range(row):
        for j in range(col):
            for k in range(mid):
                mul[i][j] += (matA[i][k] * matB[k][j]) % c

    return mul


def matpowp(mat, p):
    r = len(mat)
    res = [[0 for x in range(r)] 
			for y in range(r)]
    for i in range(r):
        res[i][i] = 1
    while p > 0:
        if p % 2 == 1:
            res = mul(res, mat)
        mat = mul(mat, mat)
        p //= 2

    return res


T = '13'
t = len(T)
k = 10
matC = [[99], [10], [1]]
matB = [
    [0, 99, -10],
    [1, 0, 0],
    [0, 1, 0]
]

for _ in range(ii()):
    n = ii() % c
    if n < 2*t - 1:
        o(matC[t - n][0])
    else:
        # Construct matrix
        # o(matB)
        matBpow = matpowp(matB[:], n - 2)
        # o(matBpow)
        matA = mul(matBpow, matC[:])
        o(matA[0][0] % c)

# This solution is O(l_t^3logn) ~ O(logn)
