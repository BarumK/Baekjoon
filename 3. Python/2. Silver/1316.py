N = int(input())
count = 0

for _ in range(N):
    temp = input()
    TF = True

    a = [chr(i) for i in range(97, 123)]
    prev = None

    for i in temp:
        if (prev != None) and (prev != i) and not (i in a):
            TF = False
            break
        else:
            if i in a:
                a.remove(i)
            prev = i

    if TF:
        count += 1
    else:
        pass

print(count)