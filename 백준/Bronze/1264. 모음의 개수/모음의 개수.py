while (1):
    s = input()
    if s == '#':
        break
    s = s.lower()
    sum = 0
    sum += s.count('o')
    sum += s.count('u')
    sum += s.count('i')
    sum += s.count('e')
    sum += s.count('a')
    print(sum)