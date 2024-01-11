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

    def test_is_prime_number(self):
        self.assertEqual(ex1.is_prime_number(1), False)
        self.assertEqual(ex1.is_prime_number(2), True)
        self.assertEqual(ex1.is_prime_number(3), True)
        self.assertEqual(ex1.is_prime_number(4), False)

    def test_is_arithmetic(self):
        list1 = [1, 3, 5, 7, 9]     # arithmetic: Un+1 = Un + 2 with U0 = 1
        list2 = [2, 6, 18, 54]      # geometric: Un+1 = Un x 3 with U0 = 2
        list3 = [3, 7, 15, 31, 63]  # both: Un+1 = Un x 2 + 1 with U0 = 3
        self.assertEqual(ex1.is_arithmetic(list1), True)
        self.assertEqual(ex1.is_arithmetic(list2), False)
        self.assertEqual(ex1.is_arithmetic(list3), False)


if __name__ == "__main__":
    unittest.main()