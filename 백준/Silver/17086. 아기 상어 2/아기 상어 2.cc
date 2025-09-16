#include <iostream>
#include <vector>
#include <limits>
#include <queue>

int bfs(std::vector<std::vector<int>>& map, int x, int y) {
    int max_x = map.size();
    int max_y = map[0].size();

    std::vector<std::vector<bool>> visited(max_x, std::vector<bool>(max_y, false));
    std::vector<std::vector<int>> dire = {
        {-1, 0}, {-1, -1}, {0, -1}, {1, -1}, {1, 0}, {1, 1}, {0, 1}, {-1, 1}
    };

    std::queue<std::vector<int>> q;
    q.push({x, y, 0});
    int distance = 0;
    while(!q.empty()) {
        std::vector<int> tmp = q.front();
        q.pop();
        int x = tmp[0], y = tmp[1], cnt = tmp[2];

        if (map[x][y] == 1) {
            distance = cnt;
            break;
        }

        for(int i = 0; i < dire.size(); i++) {
            int new_x = x+dire[i][0];
            int new_y = y+dire[i][1];
            if (!(0 <= new_x && new_x < max_x && 0 <= new_y && new_y < max_y)) {
                continue;
            }

            if (visited[new_x][new_y]) {
                continue;
            }

            visited[new_x][new_y] = true;
            q.push({new_x, new_y, cnt+1});
        }
    }
    return distance;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<int>> map(n, std::vector<int>(m, 0));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            std::cin >> map[i][j];
        }
    }
    
    int res = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if (map[i][j] != 1) {
                int distance = bfs(map, i, j);
                if (res < distance) {
                    res = distance;
                }
            }
        }
    }
    std::cout << res;
}