import math


def check_conditions(x, y, _map):
  if (not(0 <= x < len(_map) and 0 <= y < len(_map[0]))):
    return False
  
  if (_map[x][y] == -1):
    return False

  return True

dire = [[-1, 0], [1, 0], [0, -1], [0, 1]]

xy_size = list(map(int, input().split()))
_map = [[0] * xy_size[1] for _ in range(xy_size[0])]

t = int(input())
obstacle_loc = list()

for i in range(0, t):
  t_list = list(map(int, input().split()))
  obstacle_loc.append(t_list)

for i in obstacle_loc:  
  _map[i[0]][i[1]] = -1

robot_loc = list(map(int, input().split()))
dire_seq = list(map(int, input().split()))


i = 0
while True:
  move_x = robot_loc[0] + dire[dire_seq[i] - 1][0]
  move_y = robot_loc[1] + dire[dire_seq[i] - 1][1]

  if(check_conditions(move_x, move_y, _map)):
    _map[robot_loc[0]][robot_loc[1]] = -1
    robot_loc[0] = move_x
    robot_loc[1] = move_y

    possible = 0
    for j in range(0, len(dire_seq)):
      temp_x = robot_loc[0] + dire[dire_seq[j] - 1][0]
      temp_y = robot_loc[1] + dire[dire_seq[j] - 1][1]
      if check_conditions(temp_x, temp_y, _map):
        possible += 1
        break

    if possible == 0:
      break

  else:
    i += 1
    if i == len(dire_seq): 
      i = 0

print(robot_loc[0], robot_loc[1])
