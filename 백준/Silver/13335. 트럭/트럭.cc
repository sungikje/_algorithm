#include <iostream>
#include <vector>
#include <queue>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int n, w, l;
    std::cin >> n >> w >>l;
    std::vector<int> vec(n);
    for(int i = 0; i < n; i++) {
        std::cin >> vec[i];
    }

    std::queue<int> q;
    for(int i = 0; i < w; i++) q.push(0);
    
    // 21:43
    int idx = 0;
    int t = 0;
    while (idx < vec.size()) {
        l += q.front();
        q.pop();
        if (l >= vec[idx]) {
            q.push(vec[idx]);
            l -= vec[idx];
            idx++;
        } else {
            q.push(0);
        }
        t += 1;
    }
    std::cout << t + q.size() << std::endl;
}