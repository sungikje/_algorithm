#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

    int n, k;
    int min = 1000000;
    int max = -1000000;
    std::vector<int> vec; 
    std::priority_queue<int, std::vector<int>, std::less<int>> pq;

    std::cin >> n;
    std::cin >> k;

    for(int i = 0 ; i < n; i++) {
        int t;
        std::cin >> t;
        vec.push_back(t);
        if (t > max) max = t;
        if (t < min) min = t;
    }

    std::sort(vec.begin(), vec.end());

    for(int i = 0; i < vec.size()-1; i++) {
        pq.push(vec[i+1] - vec[i]);
    }

    int len = 0;
    for(int i = 0; i < k-1; i++) {
        if (pq.empty()) break;
        pq.pop();
    }
    while(!pq.empty()) {
        len += pq.top();
        pq.pop();
    }

    std::cout << len;;
}