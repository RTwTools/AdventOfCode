def day01_01(captcha):
    sum = 0
    for i, digit in enumerate(captcha):
        compDigit = captcha[0]
        if i +1 < len(captcha):
            compDigit = captcha[i+1]

        if digit == compDigit:
            sum += int(digit)
    return sum

def day01_02(captcha):
    sum = 0
    diff = len(captcha)/2
    for i, digit in enumerate(captcha):
        compIndex = i + diff
        if compIndex >= len(captcha):
            compIndex -= len(captcha)
        if digit == captcha[compIndex]:
            sum += int(digit)
    return sum

if __name__ == "__main__":
    inputData = open('day01_input.txt').read()
    print 'Day 01 01 The solution to the captcha is ', day01_01(inputData),'.'
    print 'Day 01 02 The solution to the captcha is ', day01_02(inputData),'.'