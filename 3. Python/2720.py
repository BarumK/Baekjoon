N = int(input())

for _ in range(N):
    T = int(input())
    coin = [[25, 0], [10, 0], [5, 0], [1, 0]]
    for i in range(4):
        while(coin[i][0] <= T):
            coin[i][1] += 1
            T -= coin[i][0]
    for i in range(4):
        print(coin[i][1], end=' ')