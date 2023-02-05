def count_bits(data_bin, position):
    countones = 0 
    for y in range(0, len(data_bin)):
        if data_bin[y][position] == '1':
            countones += 1
    if len(data_bin)//2 == countones:
        most_common = '1'
        least_common = '0'
    elif countones > len(data_bin) // 2:   
        most_common = '1'
        least_common ='0'
    else:
        most_common = '0'
        least_common = '1'
    return most_common, least_common

def filters(data, bit, position):
    filtered_data = []
    for row in range(0,len(data)):
        if bit == data[row][position]:
            filtered_data.append(data[row])
    return filtered_data

with open('input.txt', 'r') as data:
    data_bin = data.read().split()

data_bin_most_common = data_bin.copy()
data_bin_least_common = data_bin.copy()

for position in range(0, len(data_bin_most_common[0])):
    most_common, least_common = count_bits(data_bin_most_common, position)
    data_bin_most_common = filters(data_bin_most_common, most_common, position).copy()
    if len(data_bin_most_common) == 1:
        break 
    
for position in range(0, len(data_bin_least_common[0])):
    most_common, least_common = count_bits(data_bin_least_common, position)
    data_bin_least_common = filters(data_bin_least_common, least_common, position).copy()
    if len(data_bin_least_common) == 1:
        break 

print(f'Product of both rates as integer is: {int(data_bin_most_common[0],2)*int(data_bin_least_common[0],2)}')