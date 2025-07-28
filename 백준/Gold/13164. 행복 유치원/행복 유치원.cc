#include <iostream>
#include <vector>
#include <queue>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

    int n, k;
    std::vector<long long> vec;
    std::priority_queue<long long, std::vector<long long>, std::less<long long>> pq;
    std::cin >> n >> k;
    for(int i = 0; i < n; i++) {
        int t;
        std::cin >> t;
        vec.push_back(t);
    }

    for(int i = 0; i < n-1; i++) {
        pq.push(vec[i+1] - vec[i]);
    }

    long long res = 0;
    for(int i = 0; i < k-1; i++) pq.pop();
    while(!pq.empty()) {
        res += pq.top();
        pq.pop();
    }
    std::cout << res;
}

/*
k-1회 만큼 요소들을 구분하려고 하는 의도로 
    처음에 for(int i = 0; i < k-1; i++) pq.pop(); 코드를 while(pq.size() > k-1) 이런식으로 짬
    이는 k-1회 만큼 연산하는 것이 아니라 (n-1)-(k-1) 연산으로 잘못 짠 코드 
*/