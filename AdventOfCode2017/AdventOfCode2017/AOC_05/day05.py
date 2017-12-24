def runInstructions(input):
    instructions = [int(x) for x in input.splitlines()]
    steps = 0
    index = 0

    # Read and execute instructions
    while (index < len(instructions)):
        curIndex = index
        index += instructions[index]
        instructions[curIndex] += 1
        steps += 1

    return steps

def day05_01(input):
    return runInstructions(input)

def day05_02(input):
    return -1

if __name__ == "__main__":
    inputData = open('day05_input.txt').read()
    print 'Day 05 01 The solution is', day05_01(inputData),'.'
    print 'Day 05 02 The solution is', day05_02(inputData),'.'