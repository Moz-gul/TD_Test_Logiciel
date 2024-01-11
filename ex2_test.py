import ex2 
import unittest

class TestExampleFunc(unittest.TestCase):

    def test_fifo_class(self):
        fifo = ex2.Fifo()
        self.assertEqual(fifo.get(), [])
        fifo.add(1)
        fifo.add(2)
        fifo.add(3)
        self.assertEqual(fifo.get(), [1, 2, 3])
        fifo.remove()
        self.assertEqual(fifo.get(), [2, 3])


if __name__ == "__main__":
    unittest.main()