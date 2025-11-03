#include <iostream>
#include <vector>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

    int n;
    std::cin >> n;
    std::vector<std::vector<long long>> dp(1002, std::vector<long long>(10, 0));

    if (n == 1) {
        std::cout << 10;
    } else {
        for(int i = 0; i < 10; i++) {
            dp[1][i] = 1;
        }

        for(int i = 2; i <= n+1; i++) {
            long long sum = 0;
            for(int j = 0; j < 10; j++) {
                sum += dp[i-1][j];
            }
            dp[i][0] = sum % 10007;

            for(int j = 1; j < 10; j++) {
                dp[i][j] = (dp[i][j-1] - dp[i-1][j-1] + 10007) % 10007;
            }
        }
        std::cout << dp[n+1][0];
    }
}