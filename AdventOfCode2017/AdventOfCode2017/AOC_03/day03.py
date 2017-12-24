# (ringNr * 2) + 1 = ringIdx
# ringIdx * ringIdx = Max ring value
def getMaxRingValue(ringNr):
    return pow((ringNr * 2) + 1, 2)

def getRingNr(number):
    ring = 0
    while True:
        # Check if number is in current ring
        maxRingValue = getMaxRingValue(ring)
        if (maxRingValue >= number):
            return ring
        ring += 1

def getDistToMiddle(ringNr, location):
    nrsInRing = ringNr * 8
    stepsToNextMiddle = nrsInRing / 4
    middle = getMaxRingValue(ringNr) - (stepsToNextMiddle / 2)
    dist = abs(location - middle)

    for i in range(3):
        # nextMiddle = middle - stepsToNextMiddle
        middle -= stepsToNextMiddle
        # check lowest distance from location to the middle
        curDist = abs(location - middle)
        if (dist > curDist):
            dist = abs(location - middle)
    
    return dist

def getDistToCenter(input):
    location = int(input)
    ringNr = getRingNr(location)
    distToMiddle = getDistToMiddle(ringNr, location)
    return ringNr + distToMiddle

def day03_01(input):
    return getDistToCenter(input)


def day03_02(input):
    return -1

if __name__ == "__main__":
    inputData = open('day03_input.txt').read()
    print 'Day 03 01 The solution is', day03_01(inputData),'.'
    print 'Day 03 02 The solution is', day03_02(inputData),'.'