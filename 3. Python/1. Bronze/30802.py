# Variables
num = int(input())
var = list(map(int, input().split()))
T, P = map(int, input().split())
result = 0

# Calculate T-Shirt
for i in range(6):
    if (var[i] % T == 0): result += (var[i] // T)
    else: result += (var[i] // T) + 1

# Print Result
print(result)
print(num // P, num % P)