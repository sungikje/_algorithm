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

/*
처음 문제 접했을 때 10^14이므로 시간 복잡도를 유의해야겠다고 생각해 소수를 구하는 과정에서 A, B를 그대로 사용할 수 없다고 고려했었다.
하지만 문제를 잘 보면 소수의 N제곱을 따지므로 O(N) 형태의 시간 복잡도는 나오지 않는다.
    소수를 N제곱씩 증가하는 반복문의 경우 log 형태를 취하기 때문에 소수 2는 log2, 3은 log3으로 시간 복잡도가 대폭 줄어드는 것을 알 수 있다.
이를 배경으로 2부터 제곱한 수가 B보다 크지 않은 소수를 모두 구한 후 각 소수들을 제곱하며 A~B 구간에 들어가는 소수를 찾았다.
*/