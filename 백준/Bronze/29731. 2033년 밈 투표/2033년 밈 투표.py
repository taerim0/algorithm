promise = ["Never gonna give you up", "Never gonna let you down", "Never gonna run around and desert you", "Never gonna make you cry", "Never gonna say goodbye", "Never gonna tell a lie and hurt you", "Never gonna stop"]
isYes = False
N = int(input())
for i in range(N):
    S = input()
    if S not in promise:
        isYes = True

if isYes:
    print("Yes")
else:
    print("No")