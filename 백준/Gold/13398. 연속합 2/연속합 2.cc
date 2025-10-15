#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

    int n;
    std::cin >> n;
    std::vector<int> vec;
    for(int i = 0; i < n; i++) {
        int t;
        std::cin >> t;
        vec.push_back(t);
    }

    std::vector<int> dp(n, 0);
    std::vector<int> dp_skip(n, 0);
    dp[0] = vec[0];
    dp_skip[0] = vec[0];
    int res = vec[0];
    for(int i = 1; i < n; i++) {
        dp[i] = std::max(dp[i-1] + vec[i], vec[i]);
        dp_skip[i] = std::max(dp[i-1], dp_skip[i-1] + vec[i]);
        res = std::max({dp[i], dp_skip[i], res});
    }
    std::cout << res;
}
/*
dp: 
    - 일반적인 연속합 
    - 현재 요소를 이 전 연속합에 이어갈지 or 현재 요소로 연속합을 시작할지 고려
dp_skip: 
    - 일반적인 연속합(dp)에서 현재 요소를 건너 뜀 여부를 고려한다.
    - 현재 요소까지 1번 skip 했을 때 최대값을 기록한다.
    - 점화식을 토대로 설명하자면 dp[i-1]은 "현재 요소를 건너 뛰는 경우"이고 "dp_skip[i-1] + vec[i]"는 현재 요소를 건너 뛰지 못하는, 이미 이 전에 건너뛴 경우이다.
*/