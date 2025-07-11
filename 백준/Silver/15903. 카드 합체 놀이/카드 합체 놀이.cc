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

/*
int로 표현 가능한 최대값은 2,147,483,647
문제에서 최대 1,000,000을 최대 1000개, 최대 1500번 연산을 진행하기 때문에 int로는 커버가 불가능하다. 
*/