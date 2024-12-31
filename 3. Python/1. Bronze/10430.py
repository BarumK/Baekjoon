a = input()
b = a.split(' ')

temp = []
for i in b:
    temp.append(int(i))

A = temp[0]
B = temp[1]
C = temp[2]

print((A + B) % C)
print(((A % C) + (B % C)) % C)
print((A * B) % C)
print(((A % C) * (B % C)) % C)