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
    pass