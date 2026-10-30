def solution(array, commands):
    answer = []
    for cmd in commands:
        target = array[cmd[0]-1:cmd[1]]
        target.sort()
        answer.append(target[cmd[2]-1])
    return answer