N = int(input())
result = []
for i in range(N):
    temp = int(input())
    result.append(temp)
result.sort()
for i in range(N):
    print(result[i], end=' ')