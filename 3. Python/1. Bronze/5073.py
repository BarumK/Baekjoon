while True:
    length = list(map(int, input().split()))
    
    if max(length) == min(length) == 0:
        break
    
    length.sort()
    
    if length[2] >= sum(length[0:2]):
        print("Invalid")
    else:
        if length[0] == length[2]:
            print("Equilateral")
        elif (length[0] == length[1]) or (length[1] == length[2]) or (length[0] == length[2]):
            print("Isosceles")
        else:
            print("Scalene")