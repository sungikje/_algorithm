#include <iostream>
#include <vector>
#include <queue>

int main() {
    std::cin.tie(0);
    std::cout.tie(0);
    std::ios::sync_with_stdio(false);   // 유의, scanf로 입력을 받으려면 해당 코드는 사용하면 안된다. 예기치 못한 문제 발생할 수 있음

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


/*
문제에서 요하는 부분은 log2의 대한 count였지만 문제 푸는 과정 중에 priority queue를 이용해 중앙값을 관리하는 메커니즘 알 수 있었다.

*/