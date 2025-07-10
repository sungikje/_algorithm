#include <iostream>
#include <vector>
#include <queue>

int main() {
    std::cin.tie(0);
    std::cout.tie(0);
    std::ios::sync_with_stdio(false);

    int n;
    std::cin >> n;
    std::priority_queue<int, std::vector<int>, std::greater<int>> tmp_pq;
    std::priority_queue<int, std::vector<int>, std::less<int>> max_pq;

    for(int i = 0; i < n; i++) {
        int t;
        std::cin >> t;
        tmp_pq.push(t);
    }

    for(int i = 0; i < (n+1)/2; i++) {
        max_pq.push(tmp_pq.top());
        tmp_pq.pop();
    }

    int cnt = 0;
    while(max_pq.size() > 0) {
        int v = max_pq.top();
        max_pq.pop();
        while(v != 1) {
            v /= 2;
            cnt++;
        }
    }

    std::cout << cnt + 1;
}