while True:
    # Take Input
    input_str = input()
    
    # Loop Break Condition
    if (input_str == "0 0 0"): break
    
    # Str -> Int
    value = list(map(int, input_str.split()))
    
    # Square Values
    for i in range(3): value[i] *= value[i]
    
    # Judgement
    if (value[0] == value[1] + value[2]): print("right")
    elif (value[1] == value[0] + value[2]): print("right")
    elif (value[2] == value[0] + value[1]): print("right")
    else: print("wrong")