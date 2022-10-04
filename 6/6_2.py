import numpy as np 

init = np.genfromtxt('input.txt', dtype = int, delimiter = ',')

count_days = [0] * 9
for fish in range(len(init)):
    count_days[init[fish]] +=1

for day in range(256):
    new_born = count_days[0]
    count_days[0] = 0
    for fish_age in range(0, len(count_days) - 1):
        if fish_age == 5:
            count_days[fish_age] = count_days[fish_age + 1]
        elif fish_age == 6:
            count_days[fish_age] = count_days[fish_age + 1] + new_born
        elif fish_age == 7:
            count_days[fish_age] = count_days[fish_age + 1]
            count_days[fish_age + 1] = new_born    
        else:
            count_days[fish_age] += count_days[fish_age + 1]
            count_days[fish_age + 1] = 0
    day += 1

sum_fish = 0

for day in count_days:
    sum_fish += day

print(sum_fish)