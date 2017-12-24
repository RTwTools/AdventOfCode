import unittest
import day03

class testDay03_01(unittest.TestCase):
    cases = (
        ("1", 0),
        ("12", 3),
        ("23", 2),
        ("1024", 31)
        )

    def testDay03_01_examples(self):
        for(input, expectedOutput) in self.cases:
            output = day03.day03_01(input)
            self.assertEqual(output, expectedOutput,
            "Expected {input} to return {expectedOutput}, but got {output}".\
                        format(**locals()))
          
'''class testDay03_02(unittest.TestCase):
    cases = (
        ("5\t9\t2\t8\n9\t4\t7\t3\n3\t8\t6\t5", 9),
        )

    def testDay03_02_examples(self):
        for(input, expectedOutput) in self.cases:
            output = day03.day03_02(input)
            self.assertEqual(output, expectedOutput,
            "Expected {input} to return {expectedOutput}, but got {output}".\
                        format(**locals()))
'''
if __name__ == "__main__":
    unittest.main()