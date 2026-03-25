#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <limits>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int n;
    std::cin >> n;
    std::vector<int> potions(n, 0);

    for(int i = 0; i < n; i++) {
        std::cin >> potions[i];
    }

    std::vector<std::vector<int>> discount_table(n, std::vector<int>(n, 0));
    for(int i = 0 ; i < n; i++) {
        int p; std::cin >> p;
        for(int j = 0; j < p; j++) {
            int a, b; std::cin >> a >> b;
            discount_table[i][a-1] = b;
        }
    }

    std::vector<int> order(n);
    std::iota(order.begin(), order.end(), 0);   // numeric
    int coin = std::numeric_limits<int>::max(); // limits

    do {
        std::vector<int> potions_cp = potions;
        int tmp = 0;
        for(auto& i : order) {
            tmp += std::max(1, potions_cp[i]);
            for(int j = 0; j < n; j++) {
                potions_cp[j] = std::max(1, potions_cp[j] - discount_table[i][j]);
            }
        }
        coin = std::min(coin, tmp);
    } while (std::next_permutation(order.begin(), order.end()));
   std::cout << coin;
}