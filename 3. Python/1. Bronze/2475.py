val = list(map(int, input().split()))
for i in range(len(val)):
    val[i] *= val[i]
print(sum(val) % 10)