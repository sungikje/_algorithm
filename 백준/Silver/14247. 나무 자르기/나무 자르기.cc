#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int n;
    std::cin >> n;
    std::vector<long long> grown;
    
    long long total_trees = 0;
    for(int i = 0; i < n; i++) {
        int t;
        std::cin >> t;
        total_trees += t;
    }
    for(int i = 0; i < n; i++) {
        int t;
        std::cin >> t;
        grown.push_back(t);
    }

    std::sort(grown.begin(), grown.end());
    long long total_grown = 0;
    for(int i = 0; i < n; i++) {
        total_grown += grown[i] * i;
    }

    std::cout << total_trees + total_grown;
}