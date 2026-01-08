#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int n, m;
    std::cin >> n;
    std::cin >> m;
    std::vector<int> light_pos;
    for(int i = 0; i < m; i++) {
        int t;
        std::cin >> t;
        light_pos.push_back(t);
    }
    std::sort(light_pos.begin(), light_pos.end());

    int res = 0;
    if (m == 1) {
        res = light_pos[0] > n - light_pos[0] ? light_pos[0] : n - light_pos[0];
    } else {
        res = light_pos[0] > n - light_pos[light_pos.size()-1]? light_pos[0] : n - light_pos[light_pos.size()-1];
        for(int i = 0; i < m-1; i++) {
            int value = (light_pos[i+1]-light_pos[i])%2 == 0 ? (light_pos[i+1]-light_pos[i])/2 : (light_pos[i+1]-light_pos[i])/2 +1;
            if (res < value) {
                res = value;
            }
        }
    } 
    std::cout << res;
}