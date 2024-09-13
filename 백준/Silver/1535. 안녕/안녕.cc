#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int n;
  cin >> n;
  vector<int> vec_l(n), vec_j(n);
  vector<int> dp(101, 0);

  for(int j = 0; j < n; j++) {
    cin >> vec_l[j];
  }

  for(int j = 0; j < n; j++) {
    cin >> vec_j[j];
  }

  // dp_l[0] = vec_l[0];
  // dp_j[0] = vec_j[0];

  for(int i = 0; i < n; i++) {
    for(int h = 100; h > vec_l[i]; h--) {
      dp[h] = max(dp[h], dp[h-vec_l[i]] + vec_j[i]);
    }
  }

  int ans = 0;
  for(int i : dp) {
    if (ans < i) ans = i;
  }
  cout << ans;
}
/*
초기에 dp 이용해 순차적으로 최신화하면서 진행했을 때 모든 조합을 고려하지 못하는 문제 존재
*/