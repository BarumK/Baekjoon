a = input().split(' ')
for i in range(len(a)):
    a[i] = int(a[i])

if a[0] > a[1]:
    print('>')
elif a[0] < a[1]:
    print('<')
else:
    print('==')