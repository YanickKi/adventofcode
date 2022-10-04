import numpy as np 

position_crab = np.genfromtxt('input.txt', dtype = int, delimiter = ',')

min_position_crab = min(position_crab)
max_position_crab = max(position_crab)

min_fuel = np.sum(position_crab)

for middle in range(min_position_crab, max_position_crab + 1):
    sum_fuel = 0
    for crab in range(len(position_crab)):
        sum_fuel += abs(middle - position_crab[crab])
    if sum_fuel < min_fuel:
        min_fuel = sum_fuel

print(min_fuel)