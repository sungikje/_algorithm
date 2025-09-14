#include <iostream>
#include <vector>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

    int n;
    std::cin >> n;
    
    std::vector<int> max_move_cnt(n+1, 0);
    for(int i = 1; i <= n; i++) {
        std::cin >> max_move_cnt[i];
    }
    
    std::vector<int> cnt(n+1, 1001);
    cnt[1] = 0;
    int res = 1001;

    if (n == 1) {
        res = 0;
    } else {
        for(int i = 1; i <= n; i++) {
            if (max_move_cnt[i] < 1) continue;
            for(int j = 1; j <= max_move_cnt[i]; j++) {
                if (i+j >= n) {
                    if (cnt[i]+1 < res) res = cnt[i]+1;
                    break;
                } else {
                    if (cnt[i] + 1 < cnt[i + j]) {
                        cnt[i+j] = cnt[i]+1;
                    }
                }
            }
        }
    }
    
    if (res == 1001) {
        std::cout << -1;
    } else {
        std::cout << res;
    }
}