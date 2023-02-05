def calc_aim_depth_horizontal(direction, value):
    aim = 0
    depth = 0
    horizontal = 0
    for x in range(0, len(direction)):
        if direction[x] == 'down':
            aim += value[x]
        elif direction[x] == 'up':
            aim -= value[x]
        elif direction[x] == 'forward':
            horizontal += value[x]
            depth += aim * value[x] 
    return [aim, depth, horizontal] 

with open('input.txt', 'r') as data:
    lines = data.readlines()
    direction = []
    value = []
    for x in lines:
        direction.append(x.split()[0])
        value.append(int(x.split()[1]))

aim_depth_horizontal = calc_aim_depth_horizontal(direction, value)
print(f'The final product of the horizontal position and the depth is {aim_depth_horizontal[1]*aim_depth_horizontal[2]}.')