N, M = map(int, input().split())
bag = [0 for _ in range(N)]

for _ in range(M):
    i, j, k = map(int, input().split())
    for l in range(i - 1, j):
        bag[l] = k

for num in range(N):
    print(bag[num], end=' ')