## read from a file

sum = 0
with open('inputa.txt') as f:
    for line in f:
        
        number = 1
        for index in range(len(line)):
            if line[index].isdigit():
                number = int(line[index]) * 10
                break
        # traverse reverse
        for index in range(len(line) - 1, -1, -1):
            if line[index].isdigit():
                number = number + int(line[index])
                break
            
        sum += number

print(sum)