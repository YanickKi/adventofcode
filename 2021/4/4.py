import numpy as np

with open('input.txt', 'r') as input_txt:
    input_unsorted = input_txt.read().split('\n')

#save the numbers in a seperate list and delete them from the board numbers
numbers = np.array(input_unsorted[0].split(','))
del input_unsorted[0]

count = 0

#sort out empty strings 
for search_index in range(len(input_unsorted)):
    if len(input_unsorted[search_index - count]) == 0:
        del input_unsorted[search_index - count]
        count += 1

input_split_string = []

#split the rows and the strings in the rows
for row in range(len(input_unsorted)):
        input_split_string.append(input_unsorted[row].split())

input_split = []

#convert all numbers from type string to int
for row in range(len(input_split_string)):
    for coloumn in range(0, len(input_split_string[row])):
        input_split.append(int(input_split_string[row][coloumn]))

temp_int = np.array(input_split)

boards = np.zeros((len(temp_int)//25, 5, 5))
marked = np.zeros((len(temp_int)//25, 5, 5))

#save the integers in an 3D numpy array to have actual boards and check for complete rows or coloumns
for k in range(len(temp_int)//25):
    for i in range(5):
        for j in range(5):
            boards[k,i,j] = temp_int[k*25+i*5+j]

board_index = -1

for number in numbers:
    for k in range(len(boards)):
        for i in range(5):
            for j in range(5):
                if boards[k,i,j] == int(number):
                    marked[k,i,j] = 1
        for i in range(5):
            if all(marked[k, :, i]) == 1:
                board_index  = k
                break
            if all(marked[k, i, :]) == 1:
                board_index = k
                break
        if board_index != -1:
            winning_number = number 
            break  
    if board_index != -1:
        break  

sum = 0
for i in range(5):
      for j in range(5):
        if marked[board_index, i, j] == 0:
            sum += boards[board_index, i, j]

result = int(winning_number) * sum

print(f'The result is {result}')