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

DP 자체는 문제에서 요하는 값을 기반으로 점화식을 세우는 것이 포인트
현재 문제는 체력-기쁨의 관계를 기반으로 체력과 기쁨 중 체력이 0~100으로 구간이 정해져 있는 경우이다
인사는 인 당 1회 제한이기에 중복될 수 없기 때문에 DP(체력)를 역순으로, 즉 큰 수부터 작은 수로 진행한다
  _체력 20인 경우, DP[60] = DP[40] + 체력 20의 해당하는 기쁨_
만약 순서대로 진행한 경우 
  _체력 20인 경우, DP[40] = DP[20] + 기쁨_체력20, DP[60] = DP[40] + 기쁨_체력20으로 DP[60]에서 기쁨_체력20이 두번 중복되는 문제 발생_
*/