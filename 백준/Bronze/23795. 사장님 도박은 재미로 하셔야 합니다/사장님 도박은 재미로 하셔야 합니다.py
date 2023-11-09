lost = 0
while 1:
    a = int(input())
    if a < 0:
        break
    lost += a
print(lost)