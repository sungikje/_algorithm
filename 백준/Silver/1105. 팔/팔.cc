#include <iostream>
#include <sstream>
#include <array>
#include <cmath>

int cal_ten_pow(int pow) {
    int res = 1;
    for(int i = 0; i < pow-1; i++) {
        res *= 10;
    }
    return res;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

    int l, r;
    int cnt = 0;
    std::array<int, 11> l_arr{0};
    std::array<int, 11> r_arr{0};
    std::cin >> l >> r;
    
    int l_len = static_cast<int>(std::floor(std::log10(l))) + 1;
    int r_len = static_cast<int>(std::floor(std::log10(r))) + 1;
    int mem_r = r;
    int mem_l = l;

    for(int i = 0; i < l_len; i++) {
        int ten_pow = cal_ten_pow(l_len-i);
        l_arr[i] = l / ten_pow;
        l %= ten_pow;              
    }

    for(int i = 0; i < r_len; i++) {
        int ten_pow = cal_ten_pow(r_len-i);
        r_arr[i] = r / ten_pow;
        r %= ten_pow;              
    }

    int l_cnt = 0;
    for(int i = 0; i < l_len; i++) {
        if (l_arr[i] == 8) {
            int ten_pow = cal_ten_pow(l_len-i);
            if (mem_l + ten_pow > mem_r) l_cnt++;
        }
    }

    int r_cnt = 0;
    for(int i = 0; i < r_len; i++) {
        if (r_arr[i] == 8) {
            int ten_pow = cal_ten_pow(r_len-i);
            if (mem_r - ten_pow < mem_l) r_cnt++;
        }
    }
    l_cnt > r_cnt ? std::cout << r_cnt : std::cout << l_cnt;
}