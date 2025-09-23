#include <iostream>
#include <vector>
#include <queue>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

    int n, k;
    std::cin >> n >> k;

    std::vector<bool> visited(100001, false);
    std::queue<std::vector<int>> q;
    q.push({n, 0});
    visited[n] = true;
    while(!q.empty()) {
        std::vector<int> front = q.front();
        int loc = front[0], cnt = front[1];
        q.pop();
        if (loc == k) {
            std::cout << cnt;
            break;
        }

        int new_loc = loc * 2;
        if (new_loc <= 100000 && !visited[new_loc]) {
            q.push({new_loc, cnt});
            visited[new_loc] = true;
        }  

        new_loc = loc - 1;
        if (0 <= new_loc && !visited[new_loc]) {
            q.push({new_loc, cnt+1});
            visited[new_loc] = true;
        }

        new_loc = loc + 1;
        if (new_loc <= 100000 && !visited[new_loc]) {
            q.push({new_loc, cnt+1});
            visited[new_loc] = true;
        }
    }
}