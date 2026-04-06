#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int n;
    std::cin >> n;
    std::vector<std::vector<int>> info;
    for(int i = 0; i < n; i++) {
        int idx, value;
        std::cin >> idx >> value;
        info.push_back({idx, value});
    }

    struct {
        bool operator()(std::vector<int> a, std::vector<int> b) const { return a[0] < b[0]; }
    } custom;
    std::sort(info.begin(), info.end(), custom);

    int peek_left_idx = 0;
    
    int max_value = 0;
    for (auto& i : info) {
        if (i[1] > max_value) {
            peek_left_idx = i[0];
            max_value = i[1];
        }
    }

    int peek_right_idx = info[info.size()-1][0];
    for (int i = info.size()-1; i >= 0; i--) {
        if (info[i][1] == max_value) {
            peek_right_idx = info[i][0];
            break;
        }
    }

    int area = 0;
    int curr_idx = info[0][0];
    int curr_v = info[0][1];
    for(int i = 0; i < info.size() && info[i][0] <= peek_left_idx; i++) {
        if (curr_v < info[i][1]) { 
            area += (info[i][0] - curr_idx) * curr_v;
            curr_idx = info[i][0];
            curr_v = info[i][1];
        }
    }

    curr_idx = info[info.size()-1][0];
    curr_v = info[info.size()-1][1];
    for(int i = info.size()-1; i >= 0 && info[i][0] >= peek_right_idx; i--) {
        if (curr_v < info[i][1]) { 
            area += (curr_idx - info[i][0]) * curr_v;
            curr_idx = info[i][0];
            curr_v = info[i][1];
        }
    }

    area += (peek_right_idx - peek_left_idx + 1) * max_value;
    std::cout << area;
}