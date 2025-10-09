#include <iostream>
#include <vector>
#include <queue>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

    int test_case;
    std::cin >> test_case;

    for(int i = 0; i < test_case; i++) {
        int coin_cnt, target_amount;
        std::cin >> coin_cnt;

        std::vector<int> coins(coin_cnt, 0);
        for(int j = 0; j < coin_cnt; j++) {
            std::cin >> coins[j];
        }
        
        std::cin >> target_amount;
        std::vector<int> dp(target_amount+1, 0);

        dp[0] = 1;
        for(auto& j: coins) {
            for(int k = j; k <= target_amount; k++) {
                dp[k] += dp[k - j];
            }
        }
        std::cout << dp[target_amount] << std::endl;
    }
}