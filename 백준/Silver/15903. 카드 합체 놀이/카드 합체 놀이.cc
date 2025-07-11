#include <iostream>
#include <queue>
#include <vector>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

    int n, m;
    std::priority_queue<long long, std::vector<long long>, std::greater<long long>> pq;
    
    std::cin >> n;
    std::cin >> m;

    for(int i = 0; i < n; i++) {
        int t;
        std::cin >> t;
        pq.push(t);
    }

    for(int i = 0; i < m; i++) {
        long long x = pq.top();
        pq.pop();
        long long y = pq.top();
        pq.pop();
        pq.push(x + y);
        pq.push(x + y);
    }

    long long res = 0;
    while(pq.size() != 0) {
        res += pq.top();
        pq.pop();
    }
    std::cout << res;
}