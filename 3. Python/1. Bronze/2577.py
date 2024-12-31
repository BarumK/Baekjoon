a = int(input()); b = int(input()); c = int(input())
res = list(str(a * b * c))

count = 0
for i in range(10):
    for j in res:
        if i == int(j):
            count += 1
    print(count)
    count = 0