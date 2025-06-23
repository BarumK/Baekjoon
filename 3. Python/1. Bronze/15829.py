# Variables
rank = 31
modulo = 1234567891
result = 0

# Take Input
N = int(input())
arr = input()

# Character-Integer Matching + Rank Multiplication
for i in range(N):
    result += (ord(arr[i]) - 96) * (rank ** i)
    
# Modulo Operation
result %= modulo

# Print Result
print(result)