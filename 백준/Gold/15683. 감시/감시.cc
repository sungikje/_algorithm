
#include <iostream>
#include <vector>


// 상 하 좌 우
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
std::vector<std::vector<std::vector<int>>> cctv_dire = {
  {},
  {{0}, {1}, {2}, {3}},
  {{2, 3}, {0, 1}},
  {{0, 3}, {2, 0}, {1, 2}, {1, 3}},
  {{0, 2, 3}, {0, 1, 3}, {1, 2, 3}, {0, 1, 2}},
  {{0, 1, 2, 3}}
};

std::vector<std::vector<int>> cctv;
int min_count = 1e9;

void spred(int idx, int dire, std::vector<std::vector<int>>& vec) {
  int x = cctv[idx][0];
  int y = cctv[idx][1];
  int c = vec[x][y];

  for(int j = 0; j < cctv_dire[c][dire].size(); j++) { // 바라보고 있는 총 방향 수
    // std::cout << "dx index : " << cctv_dire[c][i][j] << std::endl;
    int nx = x + dx[cctv_dire[c][dire][j]];
    int ny = y + dy[cctv_dire[c][dire][j]];
    // std::cout << "nx : " << nx << "   ny : " << ny << std::endl;
    while(0 <= nx && nx < vec.size() && 0 <= ny && ny < vec[0].size() && vec[nx][ny] != 6) {
      if (vec[nx][ny] == 0) {
          vec[nx][ny] = 7;
      }
      nx = nx + dx[cctv_dire[c][dire][j]];
      ny = ny + dy[cctv_dire[c][dire][j]];
      // std::cout << "nx : " << nx << "   ny : " << ny << std::endl;
    }
  }

}

void dfs(int idx, std::vector<std::vector<int>>& vec) {
  if (idx == cctv.size()) {
    int count = 0;
    for(int i = 0; i < vec.size(); i++) {
      for(int j = 0; j < vec[0].size(); j++) {
        if (vec[i][j] == 0) {
          count++;
        }
      }
    }
    if (count < min_count) {
      min_count = count;
    }
    return;
  }

  int type = vec[cctv[idx][0]][cctv[idx][1]];
  for(int i = 0; i < cctv_dire[type].size(); i++) {
    std::vector<std::vector<int>> copy_vec = vec;
    spred(idx, i, copy_vec);
    dfs(idx + 1, copy_vec);
  }
}

int main () {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);

  int n, m;
  std::cin >> n >> m;
  std::vector<std::vector<int>> vec(n, std::vector<int>(m, 0));
  
  std::vector<std::vector<std::vector<int>>> _map(n, std::vector<std::vector<int>>(m, std::vector<int>(2, -1)));
  std::vector<std::vector<int>> res_m(n, std::vector<int>(m, -1));

  for(int i = 0; i < n; i++){
    for(int j = 0 ; j < m; j++) {
      std::cin >> vec[i][j];
      if (vec[i][j] != 0 && vec[i][j] != 6) {
        cctv.push_back({i, j});
      }
    }
  }

  dfs(0, vec);

  // std::cout << "\n";

  // for(auto& i : _map) {
  //   for(auto& j : i) {
  //     for(auto& k : j) {
  //       std::cout << k << " ";
  //     }
  //     std::cout << "    ";
  //   }
  //   std::cout << std::endl;
  // }

  // std::cout << "\n";

  // std::cout << std::endl;
  // bool 2차원 배열은 auto로 reference 못함
  std::cout << min_count;
  // 벽 제외, 바라보고 있는 방향 -1에서 다른 값으로 바꾸고 전체 계산
}