import sys

# Variables
line = []

# Take Inputs
for _ in range(3): line.append(sys.stdin.readline().strip())

# Find Number
for i in range(3):
    if (line[i].isdigit()):
        number = int(line[i]) + (3 - i)
    
# Print Result
if (number % 3 == 0):
    if (number % 5 == 0): print("FizzBuzz")
    else: print("Fizz")
else:
    if (number % 5 == 0): print("Buzz")
    else: print(number)