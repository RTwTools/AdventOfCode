#  Returns false if duplicate is found
def checkForDuplicates(list):
    checkedWords = set()
    for word in list:
        if word in checkedWords:
            return False
        checkedWords.add(word)
    return True

def getNumberOfValidPassphrases(input):
    passList = input.split('\n')
    count = 0

    #check passphrases
    for passPhrase in passList:
        passList = passPhrase.split(' ')
        if (checkForDuplicates(passList)):
            count += 1
    return count

def day04_01(input):
    return getNumberOfValidPassphrases(input)

def day04_02(input):
    return -1

if __name__ == "__main__":
    inputData = open('day04_input.txt').read()
    print 'Day 04 01 The solution is', day04_01(inputData),'.'
    print 'Day 04 02 The solution is', day04_02(inputData),'.'