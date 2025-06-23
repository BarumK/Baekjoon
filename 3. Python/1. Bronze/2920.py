val = list(map(int, input().split()))
if (sorted(val) == val): print("ascending")
elif (sorted(val) == val[::-1]): print("descending")
else: print("mixed")