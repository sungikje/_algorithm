#include <iostream>
#include <vector>

int main () {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    
    int n;
    std::cin >> n;
    std::vector<char> vec;
    std::vector<char> color;
    std::vector<int> color_cnt;
    char prev = 's';
    char t;
    int cnt = 0;
    for(int i = 0; i < n; i++){
        std::cin >> t;

        if (prev == 's' || prev == t) {
            cnt++;
        } else {
            color.push_back(prev);
            color_cnt.push_back(cnt);
            cnt = 1;
        }
        prev = t;
    }
    color.push_back(prev);
    color_cnt.push_back(cnt);

    int first_color = color[0];
    int last_color = color[color.size()-1];
    int res = 0;
    if (first_color == last_color) {
        int bigger_standard = 0;
        int beside_bigger = 0;
        int bigger_idx = color_cnt[0] > color_cnt[color_cnt.size()-1] ? 0 : color_cnt.size()-1;
        for(int i = 0; i < color_cnt.size(); i++) {
            if (color[i] == first_color && i != bigger_idx) {
                bigger_standard += color_cnt[i];
            }
        }

        for(int i = 0; i < color_cnt.size(); i++) {
            if (color[i] != first_color) {
                beside_bigger += color_cnt[i];
            }
        }

        res = bigger_standard > beside_bigger ? beside_bigger : bigger_standard;
    } else {
        int first_start = 0;
        int last_start = 0;
        for(int i = 1; i < color_cnt.size(); i++) {
            if (color[i] == first_color) {
                first_start += color_cnt[i];
            }
        }

        for(int i = color_cnt.size()-2; i >= 0; i--) {
            if (color[i] == last_color) {
                last_start += color_cnt[i];
            }
        }
        res = first_start > last_start ? last_start : first_start;
    }
    std::cout << res;
}