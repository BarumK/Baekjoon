def sum(n): return n * (n + 1) // 2

n = int(input())
num = 1

while sum(num) < n:
    num += 1

if num % 2 == 0:
    print(num - (sum(num) - n), '/', 1 + (sum(num) - n), sep='')
else:
    print(1 + (sum(num) - n), '/', num - (sum(num) - n), sep='')