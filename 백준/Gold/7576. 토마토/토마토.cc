#include <iostream>
#include <queue>
#include <vector>

int main () {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

    int m, n;
    std::cin >> m >> n;
    bool check_zero = false;
    std::vector<std::vector<int>> grid(n, std::vector<int>(m, 0));
    std::queue<std::vector<int>> q;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            std::cin >> grid[i][j];
            if (grid[i][j] == 0) check_zero = true;
            if (grid[i][j] == 1) q.push({i, j, 0});
        }
    }

    if (!check_zero) {
        std::cout << 0;
        return 0;
    } 

    if (q.empty()) {
        std::cout << -1;
        return 0;
    }

    std::vector<std::vector<int>> dire = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
    std::vector<std::vector<bool>> visited(n, std::vector<bool>(m, false));
    int cnt = 0;
    while(!q.empty()) {
        std::vector<int> front = q.front();
        q.pop();
        int curr_x = front[0], curr_y = front[1];
        cnt = front[2];
        for(int i = 0; i < dire.size(); i++) {
            int new_x = curr_x + dire[i][0];
            int new_y = curr_y + dire[i][1];

            if (!(0 <= new_x && new_x < n && 0 <= new_y && new_y < m)) {
                continue;
            }

            if (grid[new_x][new_y] == -1) {
                continue;
            }

            if (visited[new_x][new_y]) {
                continue;
            }
            q.push({new_x, new_y, cnt+1});
            visited[new_x][new_y] = true;
            if (grid[new_x][new_y] == 0) grid[new_x][new_y] = 1;
        }
    }

    check_zero = false;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if (grid[i][j] == 0) {
                check_zero = true;
                break;
            }
        }
        if (check_zero) break;
    }

    if (check_zero) std::cout << -1;
    else std::cout << cnt;
}