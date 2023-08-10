matrix = []
maxVal = -1
N = 0; M = 0
for i in range(9):
    matrix.append(list(map(int, input().split())))
    for j in range(9):
        if matrix[i][j] > maxVal:
            maxVal = matrix[i][j]
            N = i; M = j
print(maxVal)
print((N + 1), (M + 1))