Nlist = list(map(int, input().split()))
over = 0
for i in Nlist:
    if i == 9:
        over = 1
if (over):
    print("F")
else:
    print("S")