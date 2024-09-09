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

/*
본질적으로 구하고자 하는 것은 배열 요소에서 증가하는 부분 집합 중 가장 길이가 긴 부분 집합의 길이를 확인하는 것이 목적

종착지를 첫번째 요소부터 마지막 요소까지 점진적으로 증가시키면서 종착지 이 전 요소들 중 종착지보다 작은 경우, 즉 종착지에 도달할 수 있는
요소들을 dp 배열의 길이로 탐색하며 로직 진행

위에 과정은 입력 배열의 각 요소들을 종착점으로 하는 가장 긴 부분 배열을 찾는 과정인거고 dp에 부분 배열의 길이 값이 담기고 dp 배열의 최댓값을 탐색하며 
결과를 추린다
*/