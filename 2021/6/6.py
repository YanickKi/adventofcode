import numpy as np 

fish = np.genfromtxt('input.txt', dtype = int, delimiter = ',')


for day in range(80):
    if 0 in fish:
        giving_birth_index = [index for index in range(len(fish)) if fish[index] == 0]
        fish[giving_birth_index] = 7
        fish = np.append(fish, [9] * len(giving_birth_index))
    for single_fish in range(len(fish)):
        fish[single_fish] -= 1
    day += 1

print(len(fish))    