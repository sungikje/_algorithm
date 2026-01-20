#include <iostream>
#include <algorithm>
#include <vector>

int find(int t, std::vector<int>& vec) {
    int left = 0, right = vec.size()-1;

    int mid = (left+right)/2;
    bool find = false;
    while(left <= right) {
        mid = (left+right)/2;
        if (vec[mid] == t) {
            find = true;
            break;
        } else if (vec[mid] > t) {
            right = mid - 1;
        } else if (vec[mid] < t) {
            left = mid + 1;
        }
    }

    left = left >= vec.size() ? left - 1 : left;
    int start = find == true? mid : left;
    int res = 0;
    for(int i = start; i >= 0; i--) {
        if (vec[i] < t) {
            res = i + 1;
            break;
        }
    }
    return res;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int t;
    std::cin >> t;

    while(t > 0) {
        int n, m;
        std::cin >> n >> m;
        std::vector<int> vec_n(n);
        std::vector<int> vec_m(m);
        for(int i = 0; i < n; i++) {
            std::cin >> vec_n[i];
        }
        for(int i = 0; i < m; i++) {
            std::cin >> vec_m[i];
        }
        std::sort(vec_n.begin(), vec_n.end());
        std::sort(vec_m.begin(), vec_m.end());

        int res = 0;
        for(auto& i: vec_n) {
            res += find(i, vec_m);
        }
        std::cout << res << std::endl;
        t -= 1;
    }
}