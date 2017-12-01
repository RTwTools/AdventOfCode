import unittest
import day01

class testDay01_01(unittest.TestCase):
    cases = (
        ("1122", 3),
        ("1111", 4),
        ("1234", 0),
        ("91212129", 9),
        )

    def testDay01_01_examples(self):
        for(input, expectedOutput) in self.cases:
            output = day01.day01_01(input)
            self.assertEqual(output, expectedOutput,
            "Expected {input} to return {expectedOutput}, but got {output}".\
                        format(**locals()))
          
class testDay01_02(unittest.TestCase):
    cases = (
        ("1212", 6),
        ("1221", 0),
        ("123425", 4),
        ("123123", 12),
        ("12131415", 4),
        )

    def testDay01_02_examples(self):
        for(input, expectedOutput) in self.cases:
            output = day01.day01_02(input)
            self.assertEqual(output, expectedOutput,
            "Expected {input} to return {expectedOutput}, but got {output}".\
                        format(**locals()))

if __name__ == "__main__":
    unittest.main()