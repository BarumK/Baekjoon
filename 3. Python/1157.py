word = list(input())
alphabet = [chr(i) for i in range(65, 91)]
result = [0 for i in range(len(alphabet))]
max_index = []

for i in word:
    result[alphabet.index(i.upper())] += 1

for i in range(len(result)):
    if (max_index == []) or (result[max_index[0]] < result[i]): # max 값이 바뀌는 순간
        max_index = [i]
    elif result[max_index[0]] == result[i]: # max 값이 여러개가 되는 순간
        max_index.append(i)
    else:
        pass

if len(max_index) != 1:
    print('?')
else:
    print(alphabet[max_index[0]])