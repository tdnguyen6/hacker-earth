from sys import maxsize, stdin
from math import ceil


def get_list(): return list(map(int, stdin.readline().strip().split()))
def get_ints(): return list(map(int, stdin.readline().strip().split()))


def customBinSearch(list, val):
    low = 0
    high = len(list) - 1
    mid = (high + low) // 2
    while low < high:
        if list[mid] > val:
            high = mid
        else:
            low = mid + 1
        mid = (high + low) // 2
    if list[mid] > val:
        return list[mid - 1 if mid - 1 >= 0 else 0], list[mid]
    else:
        return list[mid], list[mid + 1 if mid + 1 < len(list) else len(list) - 1]


if __name__ == "__main__":
    N, Q = get_ints()

    mapIndexes = {}
    arr = get_list()
    def addN(x): return x + N
    def subN(x): return x - N
    for i in range(N):
        e = arr[i]
        if e not in mapIndexes:
            mapIndexes[e] = []
        if i not in mapIndexes[e]:
            mapIndexes[e].append(i)

    for _ in range(Q):
        min_dist = maxsize
        x, y = get_ints()
        extendedIndexes = list(
            map(subN, mapIndexes[y])) + mapIndexes[y] + list(map(addN, mapIndexes[y]))
        for i in range(len(mapIndexes[x])):
            start = mapIndexes[x][i]
            left, right = customBinSearch(extendedIndexes, start)
            distance1 = ceil((abs(left - start) - 1) / 2)
            distance2 = ceil((abs(right - start) - 1) / 2)
            min_dist = min(min_dist, distance1, distance2)

        print(min_dist)
