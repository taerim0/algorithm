import sys

M = int(sys.stdin.readline())

cup = [1, 2, 3]

for _ in range(M):
    a, b = map(int, sys.stdin.readline().split())
    for i in range(3):
        if cup[i] == a:
            cupX = i
        if cup[i] == b:
            cupY = i
    cup[cupX], cup[cupY] = cup[cupY], cup[cupX]

print(cup[0])