def cutList8x8(nonCuttedList, column, row): # 8 * 8 리스트로 가공
    result = nonCuttedList[column:column + 8]
    for i in range(8):
        result[i] = result[i][row:row + 8]
    return result
    
def findNums(cuttedList): # 바꿔야 하는 칸의 개수
    num = 0
    for i in range(8):
        for j in range(8):
            if i == 0 and j == 0: pass
            elif (i % 2 == 0) and (j % 2 == 0):
                if cuttedList[i][j] != cuttedList[0][0]: num += 1
            elif (i % 2 == 0) and (j % 2 != 0):
                if cuttedList[i][j] == cuttedList[0][0]: num += 1
            elif (i % 2 != 0) and (j % 2 == 0):
                if cuttedList[i][j] == cuttedList[0][0]: num += 1
            else:
                if cuttedList[i][j] != cuttedList[0][0]: num += 1
    if (64 - num) < num: # 맨 처음 칸이랑 비교한거라 맨 첫 칸을 바꾸는게
        num = 64 - num # 개수가 더 적다면 값을 리버스해줌
    return num

N, M = map(int, input().split())

rawList = []
for i in range(N):
    rawList.append(list(input()))

minimum = 32 # 최솟값은 항상 최악의 수보다 작거나 같음

for i in range(N - 7): # column
    for j in range(M - 7): # row
        temp1 = cutList8x8(rawList, i, j)
        temp2 = findNums(temp1)
        if temp2 < minimum:
            minimum = temp2

print(minimum)