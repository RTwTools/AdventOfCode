def getDiffHighLow(numbers):
    high = numbers[0]
    low = numbers[0]
    for i in numbers:
        if (i < low):
            low = i
        elif (i > high):
            high = i
    return high - low

def getEvenlyDivisible(numbers):
    for i in numbers:
        for j in numbers:
            # Skip the number itself
            if (i == j):
                continue

            # Check if evenly divisable
            if (i % j == 0):
                return i / j;
    return -1

def day02_01(input):
    sum = 0
    lines = input.split('\n')
    for line in lines:
        numbers = [int(x) for x in line.split('\t')]
        sum += getDiffHighLow(numbers)
    return sum

def day02_02(input):
    sum = 0
    lines = input.split('\n')
    for line in lines:
        numbers = [int(x) for x in line.split('\t')]
        result = getEvenlyDivisible(numbers)
        if (result != -1):
            sum += result
    return sum

if __name__ == "__main__":
    inputData = open('day02_input.txt').read()
    print 'Day 02 01 The solution is', day02_01(inputData),'.'
    print 'Day 02 02 The solution is', day02_02(inputData),'.'