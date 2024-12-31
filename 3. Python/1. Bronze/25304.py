# variables setting
x = int(input())
n = int(input())
total = 0

# sum
for _ in range(n):
    temp = list(map(int, input().split()))
    total += temp[0] * temp[1]

# print
if x == total:
    print("Yes")
else:
    print("No")