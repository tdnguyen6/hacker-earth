size = input()
lim = 300
freq = lim * [0]
arr = [int(e) for e in input().split(' ')]

for i in arr:
    freq[i] = freq[i] + 1

for i in range(lim):
    if freq[i] > 0:
        print(i, freq[i])
