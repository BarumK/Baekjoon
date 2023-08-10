import math

def PrimeNum(N):
    if N == 1: return False
    else:
        for i in range(2, int(math.sqrt(N)) + 1):
            if N % i == 0: return False
    return True

M, N = map(int, input().split())
for i in range(M, N + 1):
    if PrimeNum(i):
        print(i)