N, M = map(int, input().split())
mat1 = []; mat2 = []
for i in range(N * 2):
    if i < N:
        mat1.append(list(map(int, input().split())))
    else:
        mat2.append(list(map(int, input().split())))
for i in range(N):
    for j in range(M):
        mat1[i][j] += mat2[i][j]
        print(mat1[i][j], end=' ')
    print()