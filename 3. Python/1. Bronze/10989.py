import sys

# Variables
N = int(sys.stdin.readline())
res = {}

# Take Inputs
for i in range(N):
    temp = int(sys.stdin.readline())
    if temp in res: res[temp] += 1
    else: res[temp] = 1
    
# Print Result
for item in sorted(res.items()):
    for j in range(item[1]): print(item[0])