import sys


N = int(sys.stdin.readline())
for i in range(1, 2 * N):
    if i <= N:
        star = ' ' * (N - i) + '*' * i + '*' * (i - 1)
    else:
        star = ' ' * (N - ((2 * N) - i)) + '*' * ((2 * N) - i) + '*' * (((2 * N) - i) - 1)
    print(star)