#include <iostream>
#include <vector>

int main () {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

    int n;
    std::cin >> n;
    std::vector<int> dp(n+1);

    dp[1] = 3; 
    dp[2] = 7;
    for(int i = 3; i <= n; i++) {
        dp[i] = (2*dp[i-1] + dp[i-2]) % 9901;
    }
    std::cout << dp[n];
}