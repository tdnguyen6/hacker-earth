M = 1000000009

i = int(input())


def powxy(x, y):
    if y == 0:
        return 1
    if y % 2 == 1:
        return (x*powxy(x, y-1)) % M
    t = powxy(x, y/2)
    return (t*t) % M

print(powxy(10, i))