import numpy as np

def increase_count(depths):
    count = 0
    for x in range(0, len(depths)-1):
        if depths[x] < depths[x+1]:
            count += 1
    return count

def sum_of_three(depths):
    sum_of_three = []
    for x in range(0, len(depths)-2):
        sum_of_three.append(depths[x] + depths[x+1] + depths[x+2])
    return sum_of_three

depths = np.genfromtxt('input.txt', unpack = True)
print(f'{increase_count(depths)} depths are bigger than the previous ones.')
print(f'{increase_count(sum_of_three(depths))} sliding windows of three are bigger than the previous ones.')