#include <iostream>
#include <cmath>

void multiple_and_attach(long a, long b, long* res, long cnt) {
    if (a == b) {
        if (*res == -1) {
            *res = cnt;
        } else {
            if (cnt < *res) {
                *res = cnt;
            } 
        }
    } else if (a > b) {
        return;
    }

    multiple_and_attach(a * 10 + 1, b, res, cnt+1);
    multiple_and_attach(a*2, b, res, cnt+1);
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

    long a, b;
    std::cin >> a >> b;

    long res = -1;
    multiple_and_attach(a, b, &res, 1);
    std::cout << res;
}