#include <iostream>
#include <vector>

std::string res = "NO";
std::vector<std::vector<int>> dire = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
void dfs(std::vector<std::vector<int>>& graph, std::vector<std::vector<bool>>& visited, int x, int y) {
    visited[x][y] = true;
    if (x == graph.size()-1) {
        res = "YES";
    }

    for(int i = 0; i < dire.size(); i++) {
        int new_x = x+dire[i][0], new_y = y+dire[i][1];
        if (!(0 <= new_x && new_x < graph.size() && 0 <= new_y && new_y < graph[0].size())) {
            continue;
        }
        if (graph[new_x][new_y] == 1) {
            continue;
        }
        if (visited[new_x][new_y]) {
            continue;
        }
        dfs(graph, visited, new_x, new_y);
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int m, n;
    std::cin >> m >> n;
    std::vector<std::vector<int>> graph(m, std::vector<int>(n));

    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            char t;
            std::cin >> t;
            graph[i][j] = t - '0'; 
        }
    }
    
    std::vector<std::vector<bool>> visited(m, std::vector<bool>(n, false));
    for(int i = 0; i < n; i++) {
        if (!visited[0][i] && graph[0][i] == 0) {
            dfs(graph, visited, 0, i);
        }
    }

    std::cout << res;
}