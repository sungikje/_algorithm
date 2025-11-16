#include <iostream>
#include <vector>
#include <stack>

std::vector<std::vector<int>> dire = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
int people = 0;
void dfs (std::vector<std::vector<char>>& graph, std::vector<std::vector<bool>>& visited, int x, int y) {
    visited[x][y] = true;
    if (graph[x][y] == 'P') people++;
    
    for(int i = 0; i < dire.size(); i++) {
        int new_x = x+dire[i][0], new_y = y+dire[i][1];
        if (!(0 <= new_x && new_x < graph.size() && 0 <= new_y && new_y < graph[0].size())) {
            continue;
        }
        if (graph[new_x][new_y] == 'X') {
            continue;
        }
        if (visited[new_x][new_y]) {
            continue;
        }
        dfs(graph, visited, new_x, new_y);
    }
}

int main() {
    int n, m, st_x, st_y;
    std::cin >> n >> m;
    std::vector<std::vector<char>> graph(n, std::vector<char>(m));
    std::vector<std::vector<bool>> visited(n, std::vector<bool>(m, false));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            std::cin >> graph[i][j];
            if (graph[i][j] == 'I') st_x = i, st_y = j;
        }
    }
    
    dfs(graph, visited, st_x, st_y);

    if (people == 0) std::cout << "TT";
    else std::cout << people;
}