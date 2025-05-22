
#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <unordered_set>


int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    
    int n, m;

    std::cin >> n;
    std::cin >> m;
    std::vector<int> result(n, 0);

    std::map<int, std::priority_queue<int, std::vector<int>, std::greater<int>>> info;

    for(int i = 0; i < n; i++) {
        int cnt;
        std::cin >> cnt;

        std::unordered_set<int> seen;

        for(int j = 0; j < cnt; j++) {
            int sushi;
            std::cin >> sushi;

            if (!seen.count(sushi)) {
                info[sushi].push(i);
                seen.insert(sushi);
            }
        }
    }

    for(int i = 0; i < m; i++) {
        int sushi;
        std::cin >> sushi;

        if (info.find(sushi) != info.end()) {
            if (info[sushi].empty()) continue; 
            int customer = info[sushi].top();
            result[customer]++;
            info[sushi].pop(); 
        }
    }
    for(auto& i : result) {
        std::cout << i << " ";
    }
}
