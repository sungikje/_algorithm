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

/*
기본적으로 고려했던 점은 2,000,000,000 이란 l~r 간격을 모두 계산할 수 없겠다라는 생각

10의 Log를 이용해 입력 받은 수들을 10의 거듭 제곱 승으로 구분
특정 요소의 값이 8이며 증가, 감소하면서 각 각 r, l과 비교해 문제에서 요구하는 관계를 만족하지 못한다면 8을 그대로 유지하며 카운트 증가
    이 때 처음에 단순히 같은 자릿수들끼리만 크기를 비교하며 진행했지만 값을 증가, 감소 시켜도 l, r의 원래 수의 관계를 벗어나는 경우가 없다는 것도 유의
*/