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