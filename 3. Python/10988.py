N = input()
TF = 1
for i in range(int(len(N) / 2)):
    if N[i] != N[-1 * (i + 1)]:
        TF = 0
        break
    else:
        pass
print(TF)