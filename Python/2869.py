A, B, V = map(int, input().split())
C = A - B

# 1 ~ 3
day = ((V - A) // C) + 1
temp = A + ((V - A) % C)

# 4
while True:
    temp -= A
    if temp <= 0:
        break
    temp += B
    day += 1

print(day)