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
  => 시간 초과 발생, 투 포인터로 모든 조합을 따졌기 때문

개선 로직
  문제에서 요구하는 조건에서 가장 효율과 밀접한 포인트가 제곱근이다, 이전 로직처럼 모든 경우를 탐색하는 것이 아닌
  제곱근을 기준으로 제곱근과의 관계를 통해 dp를 최소값으로 갱신해 나간다
  ex)
    만약 12의 제곱수들의 합을 찾는다고 하면 12보다 작은 제곱근 수들은 1, 2, 3이 존재
    제곱근 수로부터의 출발을 고려해 
      제곱수 1 : dp[11] + 1, 여기서 1은 1*1의 경우로 dp[11] + dp[1]을 의미
      제곱수 2 : dp[8] + 1, 여기서 1은 2*2의 경우로 dp[8] + dp[4]를 의미
      제곱수 3 : dp[3] + 1, 여기서 1은 3*3의 경우로 dp[3] + dp[9]를 의미
*/