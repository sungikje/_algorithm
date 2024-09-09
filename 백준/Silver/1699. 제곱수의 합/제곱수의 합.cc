#include <iostream>
#include <vector>
#include <limits>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int n;
  cin >> n;
  vector<int> dp(n+1, numeric_limits<int>::max());


  dp[0] = 0;
  for(int i = 1; i <= n; i++) {
    for(int j = 1; j*j <= i; j++) {
      dp[i] = min(dp[i], dp[i - j*j] + 1);
    }
  }

  cout << dp[n];
}
/*
처음 로직
  1. 제곱수 하나인 경우 세팅
  2. n을 기준으로 n보다 작은 수들 투 포인터(dp[left], dp[right])로 연산하며 dp[n] 최신화
  => 시간 초과 발생

*/