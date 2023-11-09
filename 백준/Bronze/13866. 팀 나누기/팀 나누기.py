a, b, c, d = map(int, input().split())
ans = min(abs((a + d) - (b + c)), abs((b + d) - (a + c)), abs((c + d) - (a + b)))
print(ans)