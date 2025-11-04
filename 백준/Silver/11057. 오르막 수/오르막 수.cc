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

/*
dp[x][y]: x는 자릿수, y는 첫번째 요소가 y일 때 경우의 수
    x == 2, y == 0인 경우 01, 02, 03 ... 이렇게 몇개가 올 수 있냐는 의미

점화식을 보면 알 수 있듯이 dp[i][j] = dp[i][j-1] - dp[i-1][j-1]
    위의 점화식은 항샹 양수를 보장하지 않는다. 누적합이 커지는 속도가 다르기 때문

음수 보정 유의
    모듈러 연산은 음수를 그대로 남긴다.
    만약 모듈러 연산을 제대로(0이상 mod 보다 작은 값을 결과로) 사용하려면 mod를 더해주는 음수 보정이 필요하다.
*/