#include <iostream>
#include <queue>
#include <vector>

int bfs(std::vector<std::vector<char>>& grid, int x, int y) {
    std::vector<std::vector<int>> dire = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    std::vector<std::vector<bool>> visited(grid.size(), std::vector<bool>(grid[0].size(), false));
    std::queue<std::vector<int>> q;
    q.push({x, y, 0});
    visited[x][y] = true;
    int dist = 0;
    while(!q.empty()) {
        std::vector<int> front = q.front();
        int curr_x = front[0], curr_y = front[1];
        dist = front[2];
        q.pop();

        for(int i = 0; i < dire.size(); i++) {
            int new_x = curr_x + dire[i][0], new_y = curr_y + dire[i][1];
            if (!(0 <= new_x && new_x < grid.size() && 0 <= new_y && new_y < grid[0].size())) {
                continue;
            }

            if (visited[new_x][new_y]) {
                continue;
            }

            if (grid[new_x][new_y] == 'W') {
                continue;
            }

            q.push({new_x, new_y, dist+1});
            visited[new_x][new_y] = true;
        }
    }
    return dist;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

    int x, y;
    std::cin >> x >> y;
    std::vector<std::vector<char>> grid(x, std::vector<char>(y, '\0'));
    for(int i = 0; i < x; i++) {
        for(int j = 0; j < y; j++) {
            std::cin >> grid[i][j];
        }
    }
    
    int min = 0;
    for(int i = 0; i < x; i++) {
        for(int j = 0; j < y; j++) {
            if (grid[i][j] == 'L') {
                int dist = bfs(grid, i, j);
                if (min < dist) {
                    min = dist;
                }
            }
        }
    }
    std::cout << min;
}