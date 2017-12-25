import re

class Program:
    name = ""
    size = -1
    programs = []

def createProgram(input):
    program = Program()
    data = input.split(' ')
    program.name = data[0]
    program.size = int(re.search(r'\d+', data[1]).group())
    if (len(data) > 2):
        index = 3
        while len(data) > index:
            program.programs.append(data[index].replace(',', ''))
            index += 1
    return program

def getProgramList(input):
    programs = input.splitlines()
    programlist = []
    for prgm in programs:
        programlist.append(createProgram(prgm))
    return programlist

def findParentProgram(name, list):
    for program in list:
        if (name in program.programs):
            return True;
    return False

def getBottomProgram(input):
    programs = getProgramList(input)
    # Check if program has a parent
    for program in programs:
        if (findParentProgram(program.name, programs) == False):
            return program.name
    return "Not Found!"

def day07_01(input):
    return getBottomProgram(input)

def day07_02(input):
    return -1

if __name__ == "__main__":
    inputData = open('day07_input.txt').read()
    print 'Day 07 01 The solution is', day07_01(inputData),'.'
    print 'Day 07 02 The solution is', day07_02(inputData),'.'
