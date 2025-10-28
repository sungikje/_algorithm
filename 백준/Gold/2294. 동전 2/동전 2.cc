#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

    int n, k;
    std::cin >> n >> k;
    std::vector<int> coins(n, 0);
    std::vector<int> dp(k+1, 100000);
    for(int i = 0; i < n; i++) {
        std::cin >> coins[i];
        dp[coins[i]] = 1;
    }
    
    std::sort(coins.begin(), coins.end());

    for(int i = 0; i < n; i++) {
        for(int j = coins[i]; j <= k; j++) {
            dp[j] = std::min(dp[j], dp[j-coins[i]]+1);
        }
    }
    if (dp[k] >= 100000) std::cout << -1;
    else std::cout << dp[k];
}