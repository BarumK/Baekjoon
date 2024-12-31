x_coordinate = []; y_coordinate = []
for _ in range(int(input())):
    x, y = map(int, input().split())
    x_coordinate.append(x); y_coordinate.append(y)
print((max(x_coordinate) - min(x_coordinate)) * (max(y_coordinate) - min(y_coordinate)))