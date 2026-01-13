#include <iostream>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie();

    long long x, y;
    std:: cin >> x >> y;
    long long z = (y*100)/x;
    if (z >= 99) {
        std::cout << -1;
        return 0;
    }

    long long left = 1, right = 1000000000;
    int ans = -1;
    while(left <= right) {
        long long k = (left+right)/2;
        long long new_z = ((y+k)*100) / (x+k);
        if (new_z > z) {
            right = k-1;
            ans = k;
        } else {
            left = k+1;
        }
    }
    std::cout << ans;
}