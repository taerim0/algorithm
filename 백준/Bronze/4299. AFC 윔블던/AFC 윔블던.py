a, b = map(float, input().split())

temp = (a - b) / 2

if a < b or not temp.is_integer():
    print(-1)
elif not (temp + b).is_integer():
    print(-1)
elif temp + b < 0 or temp < 0:
    print(-1)
elif a == b:
    print(str(int(a)) + " 0")
else:
    print(str(int(temp + b)) + " " + str(int(temp)))