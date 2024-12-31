N, K = map(int, input().split())
num = 0
for i in range(1, N + 1):
    if N % i == 0:
        num += 1
        if num == K:
            print(i)
            break
if num < K:
    print(0)