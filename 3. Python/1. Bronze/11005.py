N, B = map(int, input().split())
matching = {"0":0, "1":1, "2": 2, "3":3, "4":4, "5":5, "6":6, "7":7, "8":8, "9":9,
    "A":10, "B":11, "C":12, "D":13, "E":14, "F":15, "G":16, "H":17, "I":18, "J":19, 
    "K":20, "L":21, "M":22, "N":23, "O":24, "P":25, "Q":26, "R":27, "S":28, "T":29,
    "U":30, "V":31, "W":32, "X":33, "Y":34, "Z":35}
reverse = dict(map(reversed, matching.items())) # key & value change

temp = 0 # 결과로 리턴되는 temp의 값은 필요한 최소 비트 수
while True:
    if (B ** temp) > N:
        break
    temp += 1

def find_max_value(B, N, i):
    res = 0
    while True:
        if (B ** i) * res > N:
            break
        else:
            res += 1
    res -= 1
    return res

result = ""
for i in range(temp - 1, -1, -1):
    a = find_max_value(B, N, i)
    result =  result + reverse[a]
    N -= (B ** i) * a
    
print(result)