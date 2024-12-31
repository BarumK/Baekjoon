N = int(input())
while True:
    numbers = []
    for i in range(1, N):
        if N % i == 0:
            numbers.append(i)
    
    if N == sum(numbers):
        print(N, "=", end=' ')
        for i in range(len(numbers)):
            if i == (len(numbers) - 1):
                print(numbers[i])
            else:
                print(numbers[i], end=' + ')
    else:
        print(N, "is NOT perfect.")
    
    N = int(input())
    if N == -1: break