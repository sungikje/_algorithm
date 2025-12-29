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

/*
재배열 부등식을 기반으로 greedy의 수학적 정당성을 확인할 수 있다.
    N 턴 <-> 성장률, 2가지 배열을 기반으로 재배열 부등식
pq를 사용하는 경우 복잡도가 굉장히 올라가며 더 성장할 수 있는 나무를 미리 베어버리게 될 수도 있다.
*/