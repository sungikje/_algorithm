#include <iostream>
#include <vector>

using namespace std;

void dfs(vector<vector<int>> arr, int x, int y, int p_value, vector<vector<int>>& dp, vector<vector<bool>> visited) {

  dp[x][y] = max(p_value + arr[x][y], dp[x][y]);
  visited[x][y] = true;

  // if (x == arr.size() && y == arr[0].size()) {
  //   return;
  // }

  vector<vector<int>> move = {{1, 0}, {0, 1}, {1, 1}};

  for(vector<int> i : move) {
    int n_x = x + i[0];
    int n_y = y + i[1];
    if (0 <= n_x && n_x < arr.size() && 0 <= n_y && n_y < arr[0].size()) {
      if (!visited[n_x][n_y]) {
        dfs(arr, n_x, n_y, dp[x][y], dp, visited);
      }
    }
  }
  visited[x][y] = false;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  vector<vector<int>> arr;
  int n, m;
  cin >> n >> m;

  for(int i = 0; i < n; i++){
    vector<int> vec;
    for(int j = 0; j < m; j++) {
      int t;
      cin >> t;
      vec.push_back(t);
    }
    arr.push_back(vec);
  }

  vector<vector<int>> dp(n, vector<int>(m, 0));
  vector<vector<bool>> visited(n, vector<bool>(m, false));

  dp[0][0] = arr[0][0];
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      if (i + 1 < n){ dp[i+1][j] = max(dp[i+1][j], dp[i][j] + arr[i+1][j]); }
      if (i + 1 < n && j + 1 < m){ dp[i+1][j+1] = max(dp[i+1][j+1], dp[i][j] + arr[i+1][j+1]); }
      if (j + 1 < m) { dp[i][j+1] = max(dp[i][j+1], dp[i][j] + arr[i][j+1]); } 
    }
  }

  // dfs(arr, 0, 0, 0, dp, visited);

  // cout << endl;
  // for(vector<int> i : dp) {
  //   for(int j : i) cout << j << " ";
  //   cout << endl;
  // }
  cout << dp[n-1][m-1];
}
/*
처음 DFS를 재귀로 DP를 2차원 배열에 저장했을 때 메모리 초과 발생

*/