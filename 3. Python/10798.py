matrix = []
result = ""
maxLength = -1
for i in range(5):
    matrix.append(input())
    if len(matrix[i]) > maxLength: maxLength = len(matrix[i])
for i in range(maxLength):
    for j in range(5):
        if i < len(matrix[j]):
            result += matrix[j][i]
print(result)