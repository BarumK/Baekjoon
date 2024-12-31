N = int(input())
i = 2
if N == 1: pass
else:
    while(N >= i):
        if (N % i) == 0:
            print(i)
            N /= i
        else:
            i += 1