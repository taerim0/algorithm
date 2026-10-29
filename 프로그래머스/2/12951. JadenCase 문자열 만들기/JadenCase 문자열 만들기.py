def solution(s):
    answer = ''
    flag = True
    for c in s:
        if c == ' ':
            flag = True
        elif flag:
            if 'a' <= c <= 'z':
                c = c.upper()
            flag = False
        elif 'A' <= c <= 'Z':
            c = c.lower()
        answer += c  
    return answer