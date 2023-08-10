def GyeCha(n):
    return 3 * n * n - 3 * n + 1

N = int(input())
result = 1
while N > GyeCha(result):
    result += 1
print(result)