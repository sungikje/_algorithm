#include <iostream>
#include <vector>
#include <set>



void run_cleaner(std::vector<std::vector<int>>& _map, std::vector<std::vector<int>> dire, std::set<std::pair<int, int>>& dust, int x, int y) {
  int idx = 0;
  int prev_x = x, prev_y = y, wall = x;
  while(true) {
    int new_x = prev_x + dire[idx][0];
    int new_y = prev_y + dire[idx][1];
    if (0 <= new_x && new_x < _map.size() && 0 <= new_y && new_y < _map[0].size()) {
      if (_map[new_x][new_y] == -1) {
        _map[prev_x][prev_y] = 0;
        break;
      }
      
      if (new_x == wall && new_y == _map[0].size() - 1) {
        idx++;
        idx %= 4;
      }

      if (_map[new_x][new_y] != 0){
        if (!(prev_x == x && prev_y == y)) {
          _map[prev_x][prev_y] = _map[new_x][new_y];
          dust.insert({prev_x, prev_y});
        }
        _map[new_x][new_y] = 0;
        dust.erase({new_x, new_y});
      } 
      prev_x = new_x;
      prev_y = new_y;
    } else {
      idx++;
      idx %= 4;
    }
  }
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);

  int r, c ,t;
  std::cin >> r >> c >> t;

  std::vector<std::vector<int>> _map(r, std::vector<int>(c, 0));
  std::vector<std::pair<int, int>> cleaner;
  std::set<std::pair<int, int>> dust;
  std::vector<std::vector<int>> dire_clockwise = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
  std::vector<std::vector<int>> dire_counter_clockwise = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

  for(int i = 0; i < r; i++) {
    for(int j = 0; j < c; j++) {
      std::cin >> _map[i][j];
      if (_map[i][j] != 0) {
        dust.insert({i, j}); 
        if (_map[i][j] == -1) {
          cleaner.push_back({i, j});
        }
      }
    }
  }

  int i = 0;
  int wall = 0;
  while(true) {
    std::vector<std::vector<int>> empty_map(r, std::vector<int>(c, 0));
    std::set<std::pair<int, int>> empty_set;
    std::set<std::pair<int, int>> del_set;

    for (const auto& [x, y] : dust) {
      if (_map[x][y] >= 5) {
        int cnt = 0;
        int value = _map[x][y] / 5;
        for (int j = 0; j < dire_clockwise.size(); j++) {
          int new_x = x + dire_clockwise[j][0]; 
          int new_y = y + dire_clockwise[j][1];
          if (0 <= new_x && new_x < _map.size() && 0 <= new_y && new_y < _map[0].size()) {
            if (_map[new_x][new_y] != -1) {
              empty_map[new_x][new_y] += value;
              empty_set.insert({new_x, new_y});
              cnt++;
            }
          } 
        }
        _map[x][y] -= value * cnt;
        if (_map[x][y] == 0) del_set.insert({x, y});
      }
    }

    for(const auto& [x, y] : del_set) {
      dust.erase({x, y});
    }

    for(const auto& [x, y] : empty_set) {
      _map[x][y] += empty_map[x][y];
      dust.insert({x, y});
    }

    run_cleaner(_map, dire_clockwise, dust, cleaner[0].first, cleaner[0].second);
    run_cleaner(_map, dire_counter_clockwise, dust, cleaner[1].first, cleaner[1].second);
    i += 1;
    if (i == t) break;
  }
  
  int result = 0;
  for(auto& i : _map) {
    for(auto& j : i) {
      if (j != -1) result += j;
    }
  }
  std::cout << result;
}