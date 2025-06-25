def factorial(n):
    result = 1
    for i in range(n, 1, -1): result *= i
    return result

# Variables
N, K = map(int, input().split())

# Print Result
print(int(factorial(N) / (factorial(N - K) * factorial(K))))