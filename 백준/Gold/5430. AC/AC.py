import sys

T = int(sys.stdin.readline())

for _ in range(T):
    p = sys.stdin.readline().strip()
    n = int(sys.stdin.readline())
    if n == 0:
        __ = sys.stdin.readline()
        if 'D' in p:
            print('error')
        else:
            print('[]')
        continue
    nl = list(map(int, sys.stdin.readline().strip('[]\n').split(',')))

    flag = 0

    for order in p:
        if order == 'R':
            flag = flag ^ 1
        else:
            if (len(nl) == 0):
                flag = -1
                break

            if flag:
                nl.pop(-1)
            else:
                nl.pop(0)

    if len(nl) == 0:
        if flag == -1:
            print('error')
        else:
            print('[]')
        continue

    print('[', end="")
    if flag:
        for i in range(len(nl) - 1, 0, -1):
            print(nl[i], end=",")
        print(nl[0], end="]\n")
    else:
        for i in range(0, len(nl) - 1):
            print(nl[i], end=",")
        print(nl[-1], end="]\n")