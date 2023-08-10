arr1= []
arr2 = []

for i in range(10):
    a = int(input()) % 42
    arr1.append(a)

for i in arr1:
    if not i in arr2:
        arr2.append(i)

print(len(arr2))