a, b = map(int, input().split())
d = int((int(b / 2)) * a)
c = 0
if b % 2 == 1:
    c = int(a / 2)
print(d + c)