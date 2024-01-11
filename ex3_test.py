import ex3 
import numpy as np
import unittest

class TestExampleFunc(unittest.TestCase):

    def test_initial_rms_norm(self):
        data = np.array([1.0+0.5j, 0.25+0.02j, 0.25-0.8j, 0.75+1j, 1.25-0.1j])  # Example
        norm_data = [0.9852910151785045+0.49264550758925224j, 0.24632275379462612+0.01970582030357009j, 
                    0.24632275379462612-0.7882328121428036j, 0.7389682613838784+0.9852910151785045j, 
                    1.2316137689731306-0.09852910151785045j] # Expected result
        result = ex3.initial_rms_norm(data)
        self.assertEqual(ex3.rms(result), 1.0)      # The data should be normalized
        self.assertNotEqual(result, norm_data)      # But not the right way

    def test_new_rms_norm(self):
        data = np.array([1.0+0.5j, 0.25+0.02j, 0.25-0.8j, 0.75+1j, 1.25-0.1j])  # Example
        norm_data = [0.9852910151785045+0.49264550758925224j, 0.24632275379462612+0.01970582030357009j, 
                    0.24632275379462612-0.7882328121428036j, 0.7389682613838784+0.9852910151785045j, 
                    1.2316137689731306-0.09852910151785045j] # Expected result
        result = ex3.new_rms_norm(data)
        self.assertEqual(ex3.rms(result), 1.0)      # The data should be normalized
        self.assertEqual(result, norm_data)         # The right way
        

if __name__ == "__main__":
    unittest.main()