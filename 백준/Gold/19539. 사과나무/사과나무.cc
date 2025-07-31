#include <iostream>
#include <vector>

int main () {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

    int n;
    int sum = 0;
    int min_cnt = 0;
    int max_cnt = 0;
    std::vector<int> vec;

    std::cin >> n;
    for(int i = 0; i < n; i++) {
        int t;
        std::cin >> t;
        sum += t;
        if (t == 1) min_cnt++;
        else if (t != 0) vec.push_back(t);
    }
    
    if (sum % 3 != 0) {
        std::cout << "NO";
        return 0;
    }

    max_cnt = sum / 3;
    int two_max_cnt = 0;
    for(auto& v : vec) two_max_cnt += v / 2;

    if (two_max_cnt < min_cnt) {
        std::cout << "NO";
        return 0;
    }

    for(int i = min_cnt; i <= two_max_cnt; i++) {
        if (1*i + 2*i == sum) {
            std::cout << "YES";
            return 0;
        }
    }
    std::cout << "NO";
}