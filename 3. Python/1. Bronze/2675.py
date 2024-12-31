N = int(input())
for _ in range(N):
    a = list(input().split(' '))
    for i in a[1]:
        print(i * int(a[0]), end = '')
    print()