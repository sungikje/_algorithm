#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  vector<int> vec;
  int n, ans = 0;
  cin >> n;
  for(int i = 0; i < n; i++) {
    int t;
    cin >> t;
    vec.push_back(t);
  }

  vector<int> dp(n, 1);
  for(int i = 1; i < n; i++) {
    for(int j = 0; j < i; j++) {
      if (vec[i] > vec[j]) {
        dp[i] = max(dp[i], dp[j]+1);
      }
    }
  }

  for(int i = 0; i < dp.size(); i++) {
    if (ans < dp[i]) ans = dp[i];
  }

  cout << ans;
}