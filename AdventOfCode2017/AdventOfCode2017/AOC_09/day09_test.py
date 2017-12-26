import unittest
import day0x

class testDay0x_01(unittest.TestCase):
    cases = (
        ("1", -1),
        )

    def testDay0x_01_examples(self):
        for(input, expectedOutput) in self.cases:
            output = day0x.day0x_01(input)
            self.assertEqual(output, expectedOutput,
            "Expected {input} to return {expectedOutput}, but got {output}".\
                        format(**locals()))
          
class testDay0x_02(unittest.TestCase):
    cases = (
        ("1", -1),
        )

    def testDay0x_02_examples(self):
        for(input, expectedOutput) in self.cases:
            output = day0x.day0x_02(input)
            self.assertEqual(output, expectedOutput,
            "Expected {input} to return {expectedOutput}, but got {output}".\
                        format(**locals()))

if __name__ == "__main__":
    unittest.main()