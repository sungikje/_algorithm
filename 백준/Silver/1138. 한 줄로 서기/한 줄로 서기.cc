#include <iostream>
#include <vector>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int n;
    std::cin >> n;
    std::vector<int> info(n, 0);
    std::vector<int> res(n, 0);
    for(int i = 0; i < n; i++) {
        std::cin >> info[i];
    }

    for(int i = 0; i < n; i++) {
        int over_itself = info[i];
        int zero_cnt = 0;

        for(int j = 0; j < n; j++) {
            if (res[j] == 0) {
                zero_cnt++;
                if (zero_cnt == over_itself+1) {
                    res[j] = i+1;
                    break;
                }
            }
        }
    }

    for(auto& i : res) {
        std::cout << i << " ";
    }
}