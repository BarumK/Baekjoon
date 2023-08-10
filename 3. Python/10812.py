N, M = map(int, input().split())
baguni = [(i + 1) for i in range(N)]
for _ in range(M):
    i, j, k = map(int, input().split())
    i = i - 1; k = k - 1
    baguni = baguni[:i] + baguni[k:j] + baguni[i:k] + baguni[j:]
for i in range(N):
    print(baguni[i], end = ' ')