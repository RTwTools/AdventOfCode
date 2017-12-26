import operator

ops = {"==" : operator.eq,
       "!=" : operator.ne,
       "<" : operator.lt,
       "<=": operator.le,
       ">=" : operator.ge,
       ">" : operator.gt,
       "inc" : operator.add,
       "dec" : operator.sub
       }

class Register:
    name = ""
    value = 0

    def __init__(self, name, value):
        self.name = name
        self.value = value

registers = []

def getRegisterValue(regName):
    for register in registers:
        if (regName == register.name):
            return register.value
    return 0;

def updateRegisterValue(regName, value):
    # Find register and update value
    for register in registers:
        if (regName == register.name):
            register.value += value
            return

    # Register doesn't exist
    registers.append(Register(regName, value));

def executeInstruction(instruction):
    # Name and Value
    regName = instruction[0]
    value = ops[instruction[1]](0, int(instruction[2]))
    
    # Check Condition
    compRegValue = getRegisterValue(instruction[4])
    compValue = int(instruction[6])

    if (ops[instruction[5]](compRegValue, compValue)):
        updateRegisterValue(regName, value)

def executeInstructions(input):
    instructionsList = input.splitlines()
    for instructionLine in instructionsList:
        instruction = instructionLine.split(' ')
        executeInstruction(instruction)

def getHighestValue():
    val = 0
    for reg in registers:
        if (reg.value > val):
            val = reg.value
    return val

def day08_01(input):
    executeInstructions(input)
    return getHighestValue()

def day08_02(input):
    return -1

if __name__ == "__main__":
    inputData = open('day08_input.txt').read()
    print 'Day 08 01 The solution is', day08_01(inputData),'.'
    print 'Day 08 02 The solution is', day08_02(inputData),'.'
