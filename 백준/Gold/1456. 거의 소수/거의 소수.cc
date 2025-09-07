#include <iostream>
#include <vector>
#include <cmath>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    
    long long a, b;
    std::cin >> a >> b;
    double tmp = sqrt(b);
    int sqrt_b = std::ceil(tmp);

    std::vector<bool> is_prime(sqrt_b, true);
    is_prime[0] = is_prime[1] = false;
    for(long i = 2; i < is_prime.size(); i++) {
        if (is_prime[i]) {
            for(long j = i*i; j < is_prime.size(); j+=i) {
                is_prime[j] = false;
            }
        }
    }

    long long res = 0;
    for(long i = 0; i < is_prime.size(); i++) {
        if (is_prime[i]) {
            long long j = 2;
            double result = std::pow(i, j);
            while(result <= b) {
                if (a <= result) {
                    res++;
                }
                j++;
                result = std::pow(i, j);
            }
        }
    }
    std::cout << res;
}