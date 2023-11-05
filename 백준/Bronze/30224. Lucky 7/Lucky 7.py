number_str = input()
number_int = int(number_str)

if '7' in number_str and number_int % 7 == 0:
    print(3)
elif '7' in number_str:
    print(2)
elif number_int % 7 == 0:
    print(1)
else:
    print(0)