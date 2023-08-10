N, M = map(int, input().split())
bag = [(i + 1) for i in range(N)]

for _ in range(M):
    i, j = map(int, input().split())
    i = i - 1
    j = j - 1
    temp = []
    for k in range(j, i - 1, -1):
        temp.append(bag[k])
    bag = bag[:i] + temp + bag[j + 1:]

for num in range(N):
    print(bag[num], end=' ')