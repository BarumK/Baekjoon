num = list(map(int, input().split(' ')))
reverse_num = []

for i in num:
    reverse_num.append(int(''.join(list(reversed(list(str(i)))))))

print(max(reverse_num))