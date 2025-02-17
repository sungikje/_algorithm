#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

struct Node {
  int x;
  int y;
  int v;
  int t;
};

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);

  int n, k, s, x, y;
  std::cin >> n >> k;
  std::vector<std::vector<int>> _map(n, std::vector<int>(k, 0));
  std::vector<Node> vec;
  std::queue<Node> q;
  int dire[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      std::cin >> _map[i][j];
      if (_map[i][j] != 0) vec.push_back({i, j, _map[i][j], 0});
    }
  }
  std::sort(vec.begin(), vec.end(), [](const Node &a, const Node &b) {
    return a.v < b.v;
  });
  std::cin >> s >> x >> y;

  for(auto& i : vec) q.push(i);

  while(!q.empty()) {
    struct Node node = q.front();
    q.pop();
    if (node.t == s) break;
    for(int i = 0; i < 4; i++){
      int new_x = node.x + dire[i][0];
      int new_y = node.y + dire[i][1];
      if (0 <= new_x && new_x < _map.size() && 0 <= new_y && new_y < _map[0].size()){
        if (_map[new_x][new_y] == 0) {
          _map[new_x][new_y] = _map[node.x][node.y];
          q.push({new_x, new_y, _map[node.x][node.y], node.t + 1});
        }
      }
    }
  }
  std::cout << _map[x-1][y-1];
}