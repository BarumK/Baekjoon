def jongMalSu(n):
    temp = list(str(n))
    for i in range(len(temp) - 2):
        if temp[i] == '6' and temp[i + 1] == '6' and temp[i + 2] == '6':
            return True
    return False

N = int(input())
count = 0
num = 1

while True:
    if jongMalSu(num):
        count += 1
    if count == N:
        print(num)
        break
    num += 1