with open('input.txt', 'r') as data:
    data_bin = data.read().split()

most_common  = '' 
least_common = '' 

for x in range(0, len(data_bin[0])):
    countones = 0 
    for y in range(0, len(data_bin)):
        if data_bin[y][x] == '1':
            countones += 1
    if countones > len(data_bin) // 2:
        most_common += '1'
        least_common +='0'
    else:
        most_common += '0'
        least_common += '1'

print(f'Product of both rates in int: {int(most_common, 2)*int(least_common,2)}')