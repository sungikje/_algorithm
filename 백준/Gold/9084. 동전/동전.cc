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

/*
처음 로직은 BFS를 노드 방문하지 않는 형태로 진행 
: 모든 조합을 구성할 것을 목적으로 방문 여부를 관리하지 않았는데 노드들의 중복으로 거의 무한루프

DP 이용
DP[0]은 아무것도 선택하지 않은 경우를 뜻하며 1로 시작
이 때 개념적으로 현재 DP 테이블 요소를 만들 수 있는 코인, 즉 "현재 DP 테이블 요소 - 코인" 위치에 있는 DP 테이블 요소로부터 값을 더 해줘야 한다.
- 여기서 포인트는 단순히 "동전의 갯수"가 아니라 목표 값을 만들 수 있는 "동전들의 조합의 갯수"가 포인트
    - 코인이 5로 1개라면, 5(5*1), 10(5*2) 모두 경우의 수는 1이다.
*/