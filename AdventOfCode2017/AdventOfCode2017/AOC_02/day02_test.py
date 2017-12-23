import unittest
import day02

class testDay02_01(unittest.TestCase):
    cases = (
        ("5\t1\t9\t5\n7\t5\t3\n2\t4\t6\t8", 18),
        )

    def testDay02_01_examples(self):
        for(input, expectedOutput) in self.cases:
            output = day02.day02_01(input)
            self.assertEqual(output, expectedOutput,
            "Expected {input} to return {expectedOutput}, but got {output}".\
                        format(**locals()))
          
class testDay02_02(unittest.TestCase):
    cases = (
        ("5\t9\t2\t8\n9\t4\t7\t3\n3\t8\t6\t5", 9),
        )

    def testDay02_02_examples(self):
        for(input, expectedOutput) in self.cases:
            output = day02.day02_02(input)
            self.assertEqual(output, expectedOutput,
            "Expected {input} to return {expectedOutput}, but got {output}".\
                        format(**locals()))

if __name__ == "__main__":
    unittest.main()