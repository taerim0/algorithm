s = input()
T = int(input())
cnt = 0
for i in range(T):
    ts = input()
    if ts == s:
        cnt += 1
print(cnt)