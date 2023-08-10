def Sosu(N):
    TF = True
    if N <= 1: TF = False
    elif N == 2 or N == 3: pass
    else: # 4 이상
        for i in range(2, N):
            if (N % i) == 0:
                TF = False; break
        else: pass
    return TF

M = int(input())
N = int(input())
S = 0; min = float("inf")
for i in range(M, N + 1):
    if Sosu(i):
        S += i
        if i <= min: min = i
if min == float("inf"): print(-1)
else: print(S, min, sep='\n')