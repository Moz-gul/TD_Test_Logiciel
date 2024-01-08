import ex1
import unittest

class TestExampleFunc(unittest.TestCase):

    def test_three_max_int(self):
        list1 = [5, 9, 2, 3, 6, 0, 7, 8, 1, 4]
        list2 = [36, 0, 4, 98, 14, 72, 28, 32, 9, 45]
        list3 = [0, 0, 0, 0, 1, 1, 1, 1, 1, 1]
        list4 = [2, 3]
        self.assertEqual(ex1.three_max_int(list1), [9, 8, 7])
        self.assertEqual(ex1.three_max_int(list2), [98, 72, 45])
        self.assertEqual(ex1.three_max_int(list3), [1, 1, 1])
        self.assertEqual(ex1.three_max_int(list4), None)

    def test_n_min_int(self):
        list1 = [5, 9, 2, 3, 6, 0, 7, 8, 1, 4]
        list2 = [36, 0, 4, 98, 14, 72, 28, 32, 9, 45]
        list3 = [0, 0, 0, 0, 1, 1, 1, 1, 1, 1]
        list4 = [2, 3]
        self.assertEqual(ex1.n_min_int(list1, 3), [0, 1, 2])
        self.assertEqual(ex1.n_min_int(list2, 5), [0, 4, 9, 14, 28])
        self.assertEqual(ex1.n_min_int(list3, 1), [0])
        self.assertEqual(ex1.n_min_int(list4, 3), None)

if __name__ == "__main__":
    unittest.main()