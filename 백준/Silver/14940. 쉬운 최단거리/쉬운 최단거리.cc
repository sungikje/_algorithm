#include <iostream>
#include <queue>
#include <vector>

int main () {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

    int n, m, start_x, start_y;
    std::cin >> n >> m;
    std::vector<std::vector<int>> grid(n, std::vector<int>(m, 0));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            std::cin >> grid[i][j];
            if (grid[i][j] == 2) {
                start_x = i;
                start_y = j;
            }
        }
    }

    std::vector<std::vector<int>> dire = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
    std::queue<std::vector<int>> q;
    std::vector<std::vector<bool>> visited(n, std::vector<bool>(m, false));
    std::vector<std::vector<int>> res(n, std::vector<int>(m, 0));
    q.push({start_x, start_y});
    visited[start_x][start_y] = true;
    while(!q.empty()) {
        std::vector<int> info = q.front();
        q.pop();
        for(auto& d: dire) {
            int curr_x = info[0], curr_y = info[1];
            int new_x = curr_x + d[0], new_y = curr_y + d[1];

            if (!(0 <= new_x && new_x < n && 0 <= new_y && new_y < m)) {
                continue;
            }
            if (visited[new_x][new_y]) {
                continue;
            }
            if (grid[new_x][new_y] != 1) {
                continue;
            }
            q.push({new_x, new_y});
            visited[new_x][new_y] = true;
            res[new_x][new_y] = res[curr_x][curr_y] + 1;
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if (!visited[i][j] && grid[i][j] != 0) res[i][j] = -1;
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if (j == m-1) std::cout << res[i][j];
            else std::cout << res[i][j] << " ";
        }
        std::cout << std::endl;
    }
}