N = int(input())
arr = list(map(int, input().split()))

max_val = max(arr)
sum = 0
for i in range(N):
    arr[i] = (arr[i] / max_val) * 100
    sum += arr[i]

print(sum / N)