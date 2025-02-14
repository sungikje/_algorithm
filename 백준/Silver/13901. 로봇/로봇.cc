#include <iostream>
#include <vector>


bool check_conditions(int x, int y, std::vector<std::vector<int>> *map) {

  if (!(0 <= x && x < (*map).size() && 0 <= y && y < (*map)[0].size())) return false;

  if ((*map)[x][y] == -1) return false;

  return true;
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);

  int x, y, obstacle_cnt, robot_x, robot_y;
  int dire[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
  std::vector<int> dire_seq;

  std::cin >> x >> y;
  std::vector<std::vector<int>> map(x, std::vector<int>(y, 0));

  std::cin >> obstacle_cnt;
  for(int i = 0; i < obstacle_cnt; i++) {
    int x, y;
    std::cin >> x >> y;
    map[x][y] = -1;
  }

  std::cin >> robot_x >> robot_y;

  for(int i = 0; i < 4; i++) {
    int t;
    std::cin >> t;
    dire_seq.push_back(t);
  }

  int i = 0;
  while(true) {
    // std::cout << "robot : " << robot_x << " " << robot_y << std::endl;
    
    int move_x, move_y;
    move_x = robot_x + dire[dire_seq[i]-1][0];
    move_y = robot_y + dire[dire_seq[i]-1][1];
    
    // std::cout << "move : " << move_x << " " << move_y << std::endl;

    if (check_conditions(move_x, move_y, &map)) {
      map[robot_x][robot_y] = -1;
      robot_x = move_x;
      robot_y = move_y;

      int possible = 0;
      for (int j = 0; j < dire_seq.size(); j++) {
        int temp_x, temp_y;
        temp_x = robot_x + dire[dire_seq[j]-1][0];
        temp_y = robot_y + dire[dire_seq[j]-1][1];
        if(check_conditions(temp_x, temp_y, &map)) {
          possible++;
          break;
        }
      }
      if (possible == 0) break;
    } else {
      i += 1;
      if (i == 4) i = 0;
    }

    

    
    
    // std::cout << "============================\n";
    // for(auto& i : map) {
    //   for(auto&j : i) {
    //     std::cout << j << " ";
    //   }
    //   std::cout << "\n";
    // }
    // std::cout << "============================\n";
  }

  std::cout << robot_x << " " << robot_y;

}