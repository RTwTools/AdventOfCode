def cryptoKnot(input):
    lenghts = [int(x) for x in input.split(',')]
    numberList = []
    for i in range(256):
        numberList.append(i)
    curPos = 0
    skipSize = 0

    for length in lenghts:
        # Reverse the order
        index = curPos
        selection = []
        for i in range(length):
            selection.append(numberList[index])
            index = (index + 1) % len(numberList)

        index = curPos
        for j in selection[::-1]:
            numberList[index] = j
            index = (index + 1) % len(numberList)
        
        # Change current Position
        curPos = (curPos + length + skipSize) % len(numberList)
        # Increase skip size
        skipSize += 1

    return numberList[0] * numberList[1]

def cryptoKnot2(input):
    lenghts = [ord(x) for x in input]
    numberList = []
    for i in range(256):
        numberList.append(i)
    curPos = 0
    skipSize = 0

    # part B
    lenghts.append(17)
    lenghts.append(31)
    lenghts.append(73)
    lenghts.append(47)
    lenghts.append(23)

    for _ in range(64):
        for length in lenghts:
            # Reverse the order
            index = curPos
            selection = []
            for i in range(length):
                selection.append(numberList[index])
                index = (index + 1) % len(numberList)

            index = curPos
            for j in selection[::-1]:
                numberList[index] = j
                index = (index + 1) % len(numberList)
        
            # Change current Position
            curPos = (curPos + length + skipSize) % len(numberList)
            # Increase skip size
            skipSize += 1

    hash = []
    for x in range(16):
        h = 0
        for y in range(16):
            h ^=numberList[x*16+y]

        hash.append(h)

    return ''.join('{:02x}'.format(x) for x in hash)

    #return numberList[0] * numberList[1]

def day10_01(input):
    return cryptoKnot(input)

def day10_02(input):
    return cryptoKnot2(input)

if __name__ == "__main__":
    inputData = open('day10_input.txt').read()
    print 'Day 10 01 The solution is', day10_01(inputData),'.'
    print 'Day 10 02 The solution is', day10_02(inputData),'.'