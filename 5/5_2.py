import numpy as np 

with open('input.txt', 'rb') as f:
    clean_lines = (line.replace(b' -> ',b',') for line in f)
    unfiltered_data = np.genfromtxt(clean_lines, dtype=int, delimiter=',')

data = []

for row in range(len(unfiltered_data)):
    if unfiltered_data[row][0] == unfiltered_data[row][2] or unfiltered_data[row][1] == unfiltered_data[row][3] or abs(unfiltered_data[row][3] - unfiltered_data[row][1]) == abs(unfiltered_data[row][3] - unfiltered_data[row][1]):
       data.append(unfiltered_data[row])

sign = [[1] * 2 for i in range(len(data))]

#determine wether x1>x2 or y1>y2, the sign is important for the range function later on
for row in range(len(sign)):
    if unfiltered_data[row][0] > unfiltered_data[row][2]:
        sign[row][0] = -1
    if unfiltered_data[row][1] > unfiltered_data[row][3]:
        sign[row][1] = -1

max_x = max([max([data[x][0] for x in range(len(data))]), max([data[x][2] for x in range(len(data))])])
max_y = max([max([data[x][1] for x in range(len(data))]), max([data[x][3] for x in range(len(data))])])

#this time the y-coordinates are determined by the first list index
board = [['.'] * (max_x +1) for i in range(max_y + 1)]

for row in range(len(data)):
    if data[row][0] == data[row][2]:
        way = [list(range(data[row][1], data[row][3] + sign[row][1], sign[row][1])),[data[row][0]] * (abs(unfiltered_data[row][3] - unfiltered_data[row][1])+1)]
    elif data[row][1] == data[row][3]: 
        way = [[data[row][1]] * (abs(unfiltered_data[row][2] - unfiltered_data[row][0])+1), list(range(data[row][0], data[row][2] + sign[row][0], sign[row][0]))]
    else:
        way = [list(range(data[row][1], data[row][3] + sign[row][1], sign[row][1])),list(range(data[row][0], data[row][2] + sign[row][0], sign[row][0]))]
    for coloumn in range(len(way[0])):
        if board[way[0][coloumn]][way[1][coloumn]] == '.':
            board[way[0][coloumn]][way[1][coloumn]] = 1
        else:
            board[way[0][coloumn]][way[1][coloumn]] += 1

count = 0 

for x in range(max_x + 1):
    for y in range(max_y + 1):
        if(board[y][x]) != '.':
            if(board[y][x] > 1):
                count += 1

print(count)