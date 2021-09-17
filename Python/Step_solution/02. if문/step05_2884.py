a = input().split(' ')
for i in range(len(a)):
    a[i] = int(a[i])

a[1] -= 45

if a[1] < 0:
    a[0] -= 1
    a[1] += 60

if a[0] < 0:
    a[0] = 23

print(str(a[0]), str(a[1]))