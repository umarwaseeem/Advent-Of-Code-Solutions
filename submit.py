import aocd

day = input("Enter the day: ")
year = input("Enter the year: ")

part = input("Enter the part: ")
answer = input("Enter Answer: ")

try:
    aocd.submit(int(answer), part= part, day=int(day), year=int(year))
except:
    print("Error")
    exit()

