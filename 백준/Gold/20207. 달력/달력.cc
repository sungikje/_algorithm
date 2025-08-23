#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

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

    std::sort(vec.begin(), vec.end(), [](std::pair<int, int>& a, std::pair<int, int>& b) {
        if (a.first == b.first) {
            return a.second < b.second;
        }
        return a.first < b.first;
    });

    std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
    int start;
    int max = 0;
    int res = 0;
    for(auto& p: vec) {
        if (pq.empty()) {
            start = p.first;
            pq.push(p.second);
            max = 1;
        } else {
            int end = 0;
            while(!pq.empty() && pq.top() < p.first) {
                end = end < pq.top()? pq.top() : end;
                pq.pop();
            }

            if (pq.empty()) {
                if (end + 1 != p.first) {
                    res += (end - start + 1) * max;
                    start = p.first;
                    max = 1;
                }
                pq.push(p.second);
            } else {
                pq.push(p.second);
                max = pq.size() > max ? pq.size() : max;
            }
        }
    }

    if (!pq.empty()) {
        while(pq.size() > 1) pq.pop();
        res += (pq.top() - start + 1) * max;
    }
    std::cout << res;
}