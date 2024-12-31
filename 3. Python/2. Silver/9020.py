import math

def PrimeNum(N):
    if N == 1: return False
    else:
        for i in range(2, int(math.sqrt(N)) + 1):
            if N % i == 0: return False
    return True

T = int(input())
for _ in range(T):
    N = int(input())
    for i in range(int(N / 2), 0, -1): 
        # 중간지점부터 시작해서 0으로 내려가는 방식
        # 이렇게 할 경우 앞의 i가 항상 작을 수 밖에 없으며
        # 가장 먼저 나오는 값이 격차가 최소
        if PrimeNum(i) and PrimeNum(N - i):
            print(i, N - i)
            break