#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

    auto compare = [](std::pair<int, int>& a, std::pair<int, int>& b){
        if (a.second == b.second) {
            return a.first > b.first;
        }
        return a.second < b.second;
    };

    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, decltype(compare)> pq(compare);
    
    int n;
    std::cin >> n;
    for(int i = 0; i < n; i++) {
        int d, t;
        std::cin >> d >> t;
        pq.push(std::make_pair(d, t));
    }

    int t = pq.top().second - pq.top().first;
    pq.pop();
    while(!pq.empty()) {
        if (t <= pq.top().second) {
            t -= pq.top().first;
        } else {
            t = pq.top().second - pq.top().first;
        }
        pq.pop();
    }
    std::cout << t;
}