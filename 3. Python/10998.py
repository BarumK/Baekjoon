a = input()
temp = []
for i in a:
    if i.isdigit():
        temp.append(int(i))

print(temp[0] * temp[1])