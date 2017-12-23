import sys
sys.path.insert(0, 'AOC_01')
sys.path.insert(0, 'AOC_02')

import day01
import day02

inputData = open('AOC_01/day01_input.txt').read()
print 'Day 01 01 The solution to the captcha is ', day01.day01_01(inputData),'.'
print 'Day 01 02 The solution to the captcha is ', day01.day01_02(inputData),'.'
print '---'

inputData = open('AOC_02/day02_input.txt').read()
print 'Day 02 01 The checksum for the spreadsheet is ', day02.day02_01(inputData),'.'
print 'Day 02 02 The sum of each row is ', day02.day02_02(inputData),'.'
print '---'