def hansu(N):
    temp = list(map(int, list(str(N))))
    TF = True
    for i in range(len(temp) - 2):
        if (temp[i] - temp[i + 1]) != (temp[i + 1] - temp[i + 2]):
            TF = False
            break
    return TF

count = 0
N = int(input())

for i in range(1, N + 1):
    if hansu(i):
        count += 1

print(count)