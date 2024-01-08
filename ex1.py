# Implementation 1
def three_max_int(list):

    if (len(list) >= 3):

        three_max = [list[0], 0, 0]

        for i in range (1, len(list)):
            if (list[i] > three_max[0]):
                three_max[2] = three_max[1]
                three_max[1] = three_max[0]
                three_max[0] = list[i]
            elif (list[i] > three_max[1]):
                three_max[2] = three_max[1]
                three_max[1] = list[i]
            elif (list[i] > three_max[2]):
                three_max[2] = list[i]
        
        return three_max
    
    else:
        print("Erreur : la liste est trop petite...")
        return None

# Implementation 2
def n_min_int(list, n):

    if (n <= len(list)):

        buffer = list
        n_min = [1000000] * n
        n_min[0] = list[0]
        min_index = 0

        for i in range(n):
            for j in range(1, len(buffer)):
                if (buffer[j] < n_min[i]):
                    n_min[i] = buffer[j]
                    min_index = j
            buffer[min_index] = 1000000
            
        return n_min
    
    else:
        print("Erreur : n est plus grand que la taille de la liste...")
        return None
    
# Implementation 3
def is_prime_number(number):
    pass