N, M = map(int, input().split())
nums = list(map(int, input().split()))
result = 0

for i in range(N - 2):
    for j in range(i + 1, N - 1):
        for k in range(j + 1, N):
            if (nums[i] + nums[j] + nums[k] > result) and (nums[i] + nums[j] + nums[k] <= M):
                result = nums[i] + nums[j] + nums[k]

print(result)