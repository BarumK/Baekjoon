X = []; Y = []
for i in range(3):
    x, y = map(int, input().split())
    X.append(x); Y.append(y)

if X[0] == X[1]:
    print(X[2], end = ' ')
elif X[0] == X[2]:
    print(X[1], end = ' ')
else:
    print(X[0], end = ' ')

if Y[0] == Y[1]:
    print(Y[2], end = ' ')
elif Y[0] == Y[2]:
    print(Y[1], end = ' ')
else:
    print(Y[0], end = ' ')