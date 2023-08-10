a = input()
b = a.split(' ')

temp = []
for i in b:
    temp.append(int(i))

print(temp[0] + temp[1])
print(temp[0] - temp[1])
print(temp[0] * temp[1])
print(temp[0] // temp[1])
print(temp[0] % temp[1])