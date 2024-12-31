def d(n):
    sum = 0
    sum += n
    temp = n
    while temp > 0:
        sum += temp % 10
        temp = temp // 10
    return sum

num = [i for i in range(1, 10001)]

for i in range(1, 10001):
    if d(i) in num:
        num.remove(d(i))
        
for i in num:
    print(i)