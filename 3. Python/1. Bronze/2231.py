n = int(input())
TF = False

for i in range(1, n + 1):
    nums = [i]
    temp = i
    while(temp >= 1):
        nums.append(temp % 10)
        temp = int(temp / 10)
    if sum(nums) == n:
        print(i)
        TF = True
        break
    
if not TF:
    print(0)