a, b, c = map(int, input().split())
ans1 = a * 3 + b * 20 + c * 120
a, b, c = map(int, input().split())
ans2 = a * 3 + b * 20 + c * 120
if ans1 > ans2:
    print('Max')
elif ans1 < ans2:
    print('Mel')
else:
    print('Draw')