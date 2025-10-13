#include <iostream>
#include <vector>
#include <algorithm>

int main () {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

    int n , k;
    std::cin >> n >> k;
    std::vector<std::vector<int>> w_v;
    std::vector<long> dp(k+1, 0);
    for(int i = 0; i < n; i++) {
        int w, v;
        std::cin >> w >> v;
        w_v.push_back({w, v});
    }

    std::sort(w_v.begin(), w_v.end(), [](std::vector<int> a, std::vector<int> b) {
        if (a[0] == b[0]) {
            return a[1] < b[1];
        } 
        return a[0] < b[0];
    });

    for(int i = 0; i < w_v.size(); i++) {
        int vec_w = w_v[i][0];
        int vec_v = w_v[i][1];
        for(int w = k; w >= vec_w; w--) {
            dp[w] = std::max(dp[w], dp[w - vec_w] + vec_v);
        }
    }
    std::cout << dp[k];
}