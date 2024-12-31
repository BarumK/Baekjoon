def sosu(n):
    if num[n] != -1: return num[n]
    else:
        if n == 1: 
            num[n] = 0
            return False
        for i in range(2, int(n ** 0.5) + 1):
            if n % i == 0:
                num[n] = 0
                return False
        num[n] = 1
        return True


global num
num = [0 if (i % 2 == 0) else -1 for i in range(123457 * 2)]
num[2] = True

N = int(input())
while True:
    if N == 0: break
    result = 0
    for i in range(N + 1, 2 * N + 1):
        if sosu(i) == 1: result += 1
    print(result)
    N = int(input())