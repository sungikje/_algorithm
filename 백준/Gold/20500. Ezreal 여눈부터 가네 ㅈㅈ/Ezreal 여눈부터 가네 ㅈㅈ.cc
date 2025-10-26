#include <iostream>
#include <vector>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

    int n;
    std::cin >> n;
    std::vector<std::vector<long long>> dp(n+1, std::vector<long long>(3,0));

    dp[0][0] = 1;
    for(int i = 0; i < n; i++) {
        for(int r = 0; r < 3; r++) {
            dp[i+1][(r+1)%3] = (dp[i+1][(r+1)%3] + dp[i][r]) % 1000000007;
            dp[i+1][(r+5)%3] = (dp[i+1][(r+5)%3] + dp[i][r]) % 1000000007;
        }
    }
    std::cout << dp[n-1][1];
}