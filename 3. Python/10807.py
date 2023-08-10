n = int(input()); nums = list(map(int, input().split())); v = int(input())
times = 0
for i in range(n):
    if nums[i] == v: times += 1
print(times)