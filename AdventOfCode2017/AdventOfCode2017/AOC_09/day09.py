def readGarbage(stream, index):
    while True:
        index += 1
        char = stream[index]
        if (char == '!'):
            # Skip next char
            index += 1
        elif (char == '>'):
            # End of garbage
            return index

def getScoreOfGroups(stream):
    score = 0
    openGroups = 0
    i = 0
    while (i < len(stream)):
        char = stream[i]
        if (char == '{'):
            openGroups += 1
            score += openGroups
        elif (char == '}'):
            openGroups -= 1
        elif (char == '<'):
            i = readGarbage(stream, i)
        i += 1
    return score

def day09_01(input):
    return getScoreOfGroups(input)

def day09_02(input):
    return -1

if __name__ == "__main__":
    inputData = open('day09_input.txt').read()
    print 'Day 09 01 The solution is', day09_01(inputData),'.'
    print 'Day 09 02 The solution is', day09_02(inputData),'.'
