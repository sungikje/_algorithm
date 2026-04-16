#include <iostream>
#include <vector>
#include <queue>

void stdout_grid(std::vector<std::vector<char>>& grid) {
    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[0].size(); j++) {
            std::cout << grid[i][j];
        }
        std::cout << std::endl;
    }
}

void checking_bomb(std::vector<std::vector<char>>& grid, std::vector<std::vector<int>>& time_table, std::queue<std::vector<int>>& q, int time) {
    std::vector<std::vector<int>> dire = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    std::queue<std::vector<int>> tmp_q;
    std::vector<int> top;
    while (q.size() > 0) {
        top = q.front();
        if (top[2] + 3 != time) break;
        q.pop();

        int x = top[0], y = top[1];
        if (grid[x][y] != 'O') continue;
        if (time_table[x][y] != top[2]) continue;
        tmp_q.push(top);
    }
    
    while (tmp_q.size() > 0) {
        top = tmp_q.front();
        tmp_q.pop();
        int x = top[0], y = top[1];
        grid[x][y] = '.';
        for (auto& d : dire) {
            int new_x = x + d[0], new_y = y + d[1];
            if (0 <= new_x && new_x < grid.size() && 0 <= new_y && new_y < grid[0].size()) {
                grid[new_x][new_y] = '.';
            }
        }
    }
}

void setting_bomb(std::vector<std::vector<char>>& grid, std::vector<std::vector<int>>& time_table, std::queue<std::vector<int>>& q, int time) {
    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[0].size(); j++) {
            if (grid[i][j] == '.') {
                grid[i][j] = 'O';
                q.push({i, j, time});
                time_table[i][j] = time;
            }
        }
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int r, c, n;
    std::queue<std::vector<int>> q;
    std::cin >> r >> c >> n;
    std::vector<std::vector<char>> grid(r, std::vector<char>(c, 0));
    std::vector<std::vector<int>> time_table(r, std::vector<int>(c, 0));
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            std::cin >> grid[i][j];
            if (grid[i][j] == 'O') {
                q.push({i, j, 0});
            }
        }
    }

    if (n > 1) {
        int t = 2;
        while (t <= n) {
            if (t % 2 == 0) setting_bomb(grid, time_table, q, t);
            checking_bomb(grid, time_table, q, t);
            t+=1;
        }
    }
    stdout_grid(grid);
}