import numpy as np 

with open('input.txt', 'rb') as f:
    clean_lines = (line.replace(b' -> ',b',') for line in f)
    unfiltered_data = np.genfromtxt(clean_lines, dtype=int, delimiter=',')

data = []

for row in range(len(unfiltered_data)):
    if unfiltered_data[row][0] == unfiltered_data[row][2] or unfiltered_data[row][1] == unfiltered_data[row][3]:
       data.append(unfiltered_data[row])

for row in range(len(data)):
    if(data[row][0] > data[row][2]):
        temp = data[row][0]
        data[row][0] = data[row][2]
        data[row][2] = temp
    if(data[row][1] > data[row][3]):
        temp = data[row][1]
        data[row][1] = data[row][3]
        data[row][3] = temp    

max_x = max([data[x][2] for x in range(len(data))])
max_y = max([data[x][3] for x in range(len(data))])

board = [['.'] * (max_x +1) for i in range(max_y + 1)]

for row in range(len(data)):
    if data[row][0] != data[row][2]:
        way = list(range(data[row][0], data[row][2]+1))
        for x in way:
            if board[data[row][1]][x] == '.':
                board[data[row][1]][x] = 1
            else:
                board[data[row][1]][x] += 1
    if data[row][1] != data[row][3]:
        way = list(range(data[row][1], data[row][3]+1))
        for y in way:
            if board[y][data[row][0]] == '.':
                board[y][data[row][0]] = 1
            else:
                board[y][data[row][0]] += 1

count = 0 

for x in range(max_x + 1):
    for y in range(max_y + 1):
        if(board[y][x]) != '.':
            if(board[y][x] > 1):
                count += 1

print(count)