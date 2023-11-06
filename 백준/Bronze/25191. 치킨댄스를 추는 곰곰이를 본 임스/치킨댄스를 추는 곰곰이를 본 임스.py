c = int(input())
a, b = map(int, input().split())

cnt = a // 2 + b

if cnt >= c:
    print(c)
else:
    print(cnt)