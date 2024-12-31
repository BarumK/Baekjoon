# a: input, b: times of each dice eyes
a = list(map(int, input().split()))
b = [-1, 0, 0, 0, 0, 0, 0]

for i in range(len(a)):
    b[a[i]] += 1

# initialization of values
times = -1
dice_eye = -1

# find maximum
for i in range(1, 7):
    if times <= b[i]:
        times = b[i]
        dice_eye = i

# print phase
if times == 3:
    print(10000 + dice_eye * 1000)
elif times == 2:
    print(1000 + dice_eye * 100)
else:
    print(dice_eye * 100)