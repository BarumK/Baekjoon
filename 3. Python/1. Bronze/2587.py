result = []
for i in range(5):
    temp = int(input())
    result.append(temp)
result.sort()
print(int(sum(result) / 5))
print(result[2])