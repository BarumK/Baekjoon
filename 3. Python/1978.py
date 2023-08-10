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

N = int(input()); num = 0
nums = list(map(int, input().split()))
for i in range(N):
    if Sosu(nums[i]):
        num += 1
print(num)