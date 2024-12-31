a = [chr(i) for i in range(97, 123)]
s = list(input())
result = [-1 for i in range(26)]

for i in range(26):
    try:
        result[i] = s.index(a[i])
    except:
        pass

for i in result:
    print(i, end = ' ')