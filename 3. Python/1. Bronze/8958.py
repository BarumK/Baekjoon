N = int(input())

for _ in range(N):
    arr = list(input())
    count = 0
    sum = 0
    for i in arr:
        if i == 'O':
            count += 1
            sum += count
        else:
            count = 0
    print(sum)