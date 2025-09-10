#include <iostream>
#include <cmath>
#include <vector>
#include <iomanip>

long double calculate(int num) {
    int n = 18;
    int k = num;
    int n_k = 18-num;

    double child = 1.0;
    for(int i = 18; i > n_k; i--) {
        child *= i;
    }

    double parent = 1.0;
    for(int i = k; i > 0; i--) {
        parent *= i;
    }

    return child/parent;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

    int a, b;
    std::cin >> a >> b;

    std::vector<bool> is_prime(19, true);
    is_prime[0] = is_prime[1] = false;
    for(int i = 2; i < is_prime.size(); i++) {
        for(int j = i*i; j < is_prime.size(); j+=i) {
            if(is_prime[j]) {
                is_prime[j] = false;
            }
        }
    }

    std::vector<long double> comb(19, 0.0);
    for(int i = 0; i < is_prime.size(); i++) {
        if (is_prime[i]) {
            comb[i] = calculate(i);
        }
    }

    long double p_a = 0.0;
    long double p_b = 0.0;
    for(int i = 0; i < is_prime.size(); i++) {
        if (is_prime[i]) {
            long double cast_a = static_cast<long double>(a);
            long double cast_b = static_cast<long double>(b);
            p_a += comb[i] * std::pow(cast_a/100, i) * std::pow((1-cast_a/100), 18-i);
            p_b += comb[i] * std::pow(cast_b/100, i) * std::pow((1-cast_b/100), 18-i); 
        }
    }
    long double res = p_a + p_b - (p_a * p_b);
    if (res == 0.0) {
        std::cout << std::fixed << std::setprecision(1) << 0.0;
    } else {
        std::cout << std::setprecision(16) << p_a + p_b - (p_a * p_b);
    }
}

/*
문제는 이항분포 + 포함-배재 원리를 기반으로 해결

유의
    double: 8byte, 15~17자리
    long double: 10 or 16byte, 19 or 33~36자리
    std::cout은 기본적으로 소수점 6자리까지만 출력하기에 그냥 사용하는 경우 문제에서 요하는 10^-6 오차를 만족하지 않는다.
    0.0은 std::cout으로 출력하면 0으로 출력되며 별도로 자릿수를 fix해서 해결했다.
*/