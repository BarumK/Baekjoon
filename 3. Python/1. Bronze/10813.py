N, M = map(int, input().split())
bag = [(i + 1) for i in range(N)]

for _ in range(M):
    i, j = map(int, input().split())
    temp = bag[i - 1]
    bag[i - 1] = bag[j - 1]
    bag[j - 1] = temp

for num in range(N):
    print(bag[num], end=' ')