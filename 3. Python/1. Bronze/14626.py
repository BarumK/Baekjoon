import sys

# Variables
ISBN = sys.stdin.readline().strip()
res = 0

# Calculate
for i in range(13):
    if (i % 2 == 0): mul = 1
    else: mul = 3
    
    if (ISBN[i] == '*'): saved_mul = mul
    else: res += mul * int(ISBN[i])

# Print Result
for x in range(10):
    if (res + saved_mul * x) % 10 == 0:
        print(x)
        break