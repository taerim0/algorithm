import sys

N = int(sys.stdin.readline())

for i in range(N):
    s = sys.stdin.readline()
    print(str(i + 1) + ". " + s, end="")