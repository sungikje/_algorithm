#include <iostream>
#include <utility>
#include <vector>
#include <queue>
#include <algorithm>

int main () {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

    std::vector<std::pair<int, int>> vec;
    int n;
    std::cin >> n;
    for(int i = 0; i < n; i++) {
        int s, e;
        std::cin >> s >> e;
        vec.push_back(std::make_pair(s, e));
    }

    std::sort(vec.begin(), vec.end(), [](const auto& a, const auto& b) {
        if (a.first == b.first) {
            return a.second < b.second;
        } else {
            return a.first < b.first;
        }
    });

    std::priority_queue<int, std::vector<int>, std::greater<int>> rooms;
    for(int i = 0; i < vec.size(); i++) {
        if (rooms.empty()) {
            rooms.push(vec[i].second);
        } else {
            if (rooms.top() <= vec[i].first) {
                rooms.pop();
            }
            rooms.push(vec[i].second);
        }     
    }
    std::cout << rooms.size();
}