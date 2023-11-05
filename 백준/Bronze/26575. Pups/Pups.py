T = int(input())
for i in range(T):
    a, b, c = map(float, input().split())
    ans = a * b * c
    print('$%.2f' % ans)