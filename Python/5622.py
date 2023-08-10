T = [["ABC", 3], ["DEF", 4], ["GHI", 5], ["JKL", 6], ["MNO", 7], ["PQRS", 8], ["TUV", 9], ["WXYZ", 10]]
word = input()
result = 0

for i in word:
    for j in T:
        if i in j[0]:
            result += j[1]
            break

print(result)