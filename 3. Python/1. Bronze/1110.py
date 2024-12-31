def new_num(N):
    if N < 10:
        return 10 * N + N
    else:
        return (N % 10) * 10 + (N // 10 + N % 10) % 10

N = int(input())
count = 0
temp = N
while True:
    temp = new_num(temp)
    count += 1
    if temp == N:
        print(count)
        break