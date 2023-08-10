dic = {'A+':4.5, 'A0':4, 'B+':3.5, 'B0':3, 'C+':2.5, 'C0':2, 'D+':1.5, 'D0':1, 'F':0}
bunja = 0
bunmo = 0

for _ in range(20):
    line = list(input().split(' '))
    if line[2] == 'P': pass
    else:
        bunja += dic[line[2]] * int(float(line[1]))
        bunmo += int(float(line[1]))

result = bunja / bunmo
print(f"{result:.6f}")