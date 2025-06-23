while True:
    # Take Input
    line = input()
    
    # Loop Break Condition
    if (int(line) == 0): break
    
    # Print Result
    if (line == line[::-1]): print("yes")
    else: print("no")