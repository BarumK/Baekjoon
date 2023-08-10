N = int(input())
result = "int"
while (N > 0):
    N -= 4
    result = "long " + result
print(result)