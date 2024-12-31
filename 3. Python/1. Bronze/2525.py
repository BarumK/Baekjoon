hour, minute = map(int, input().split())
time = int(input())

minute += time
while True:
    if minute >= 60:
        minute -= 60
        hour += 1
    if hour >= 24:
        hour -= 24
    if minute < 60 and hour < 24:
        break
    
print(hour, minute)