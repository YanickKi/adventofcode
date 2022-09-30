import numpy as np 

def sum_list(data):
    sum = 0
    for x in data:
        sum += x
    return sum

with open('input.txt', 'r') as data:
    lines = data.readlines()
    dir_value = {'forward': [], 'up': [], 'down': []}
    for x in lines:
        dir_value[x.split()[0]].append(int(x.split()[1]))

depth = sum_list(dir_value['down']) - sum_list(dir_value['up'])
horizontal = sum_list(dir_value['forward'])

print(f'The final depth is {depth}, the final horizontal position is {horizontal} and the product of both is {depth * horizontal}.')