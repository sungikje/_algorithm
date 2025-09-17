#include <iostream>
#include <queue>
#include <vector>

void bfs(std::vector<std::vector<int>> maze, int dest_x, int dest_y) {
    int max_x = maze.size();
    int max_y = maze[0].size();

    std::vector<std::vector<bool>> visited(max_x, std::vector<bool>(max_y, false));
    std::vector<std::vector<int>> dire = {{0, -1}, {1, 0}, {0, 1}, {-1, 0}};
    std::queue<std::vector<int>> q;
    q.push({0, 0, 1});

    while(!q.empty()) {
        std::vector<int> front = q.front();
        int x = front[0], y = front[1], cnt = front[2];
        q.pop();
        if (x == dest_x && y == dest_y) {
            std::cout << cnt;
            return;
        }

        for(int i = 0; i < dire.size(); i++) {
            int new_x = x + dire[i][0], new_y = y + dire[i][1];
            if (!(0 <= new_x && new_x < max_x && 0 <= new_y && new_y < max_y)) continue;
            if (visited[new_x][new_y]) continue;
            if (maze[new_x][new_y] == 0) continue;

            visited[new_x][new_y] = true;
            q.push({new_x, new_y, cnt+1});
        }
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

    int n, m;
    std::cin >> n >> m;

    std::vector<std::vector<int>> maze(n, std::vector<int>(m, 0));
    for(int i = 0; i < n; i++) {
        std::string t;
        std::cin >> t;
        for(int j = 0; j < t.length(); j++) {
            t[j] == '1' ? maze[i][j] = 1 : maze[i][j] = 0;
        }
    }

    bfs(maze, n-1, m-1);
}