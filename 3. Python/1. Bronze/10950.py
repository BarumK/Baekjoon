a = int(input())
temp = []

for i in range(a):
    b = input().split(' ')
    for j in range(len(b)):
        b[j] = int(b[j])
    temp.append(b[0] + b[1])

for i in range(len(temp)):
    print(temp[i])