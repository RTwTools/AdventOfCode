def redistributeMemory(memoryBanks):
    # Get highest value
    index = memoryBanks.index(max(memoryBanks))
    # Empty memory bank and redistribute
    blocks = memoryBanks[index]
    memoryBanks[index] = 0;
    for x in range(blocks):
        # Check if index is within array
        index += 1
        if (index >= len(memoryBanks)):
            index = 0

        memoryBanks[index] += 1

def findInfiniteLoop(input, partB):
    memoryBanks = [int(x) for x in input.split('\t')]
    steps = 0
    knownStates = []
    while (memoryBanks not in knownStates):
        
        knownStates.append(list(memoryBanks))
        redistributeMemory(memoryBanks)
        steps += 1

    if (partB):
        return steps - knownStates.index(memoryBanks)
    else:
        return steps

def day06_01(input):
    return findInfiniteLoop(input, False)

def day06_02(input):
    return findInfiniteLoop(input, True)

if __name__ == "__main__":
    inputData = open('day06_input.txt').read()
    print 'Day 06 01 The solution is', day06_01(inputData),'.'
    print 'Day 06 02 The solution is', day06_02(inputData),'.'