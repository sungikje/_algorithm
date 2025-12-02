#include <iostream>
#include <vector>
#include <stack>

std::vector<std::vector<int>> dire = {
    {-1, -1}, {-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}
};

void dfs(std::vector<std::vector<int>>& graph, std::vector<std::vector<bool>>& visited, std::vector<std::vector<int>>& nodes, int x, int y) {
    std::stack<std::vector<int>> stack;
    stack.push({x, y});
    int value = graph[x][y];
    while(!stack.empty()) {
        std::vector<int> node = stack.top();
        stack.pop();
        if (visited[node[0]][node[1]]) {
            continue;
        }
        visited[node[0]][node[1]] = true;
        nodes.push_back({node[0], node[1]});

        for(int i = 0; i < dire.size(); i++) {
            int new_x = node[0]+dire[i][0], new_y = node[1]+dire[i][1];
            if (!(0 <= new_x && new_x < graph.size() && 0 <= new_y && new_y < graph[0].size())) {
                continue;
            }
            if (visited[new_x][new_y]) {
                continue;
            }
            if (graph[new_x][new_y] != value) {
                continue;
            }
            stack.push({new_x, new_y});
        }
    }
}

bool isPeak(std::vector<std::vector<int>>& graph, std::vector<std::vector<int>>& nodes, int value) {
    for(auto& node: nodes) {
        for(int i = 0; i < dire.size(); i++) {
            int new_x = node[0]+dire[i][0], new_y = node[1]+dire[i][1];
            if (!(0 <= new_x && new_x < graph.size() && 0 <= new_y && new_y < graph[0].size())) {
                continue;
            }
            if (graph[new_x][new_y] > value) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int x, y;
    std::cin >> x >> y;
    std::vector<std::vector<int>> graph(x, std::vector<int>(y, 0));
    std::vector<std::vector<bool>> visited(x, std::vector<bool>(y, false));
    for(int i = 0 ; i < x; i++) {
        for(int j = 0; j < y; j++) {
            std::cin >> graph[i][j];
        }
    }
    
    int res = 0;
    for(int i = 0 ; i < x; i++) {
        for(int j = 0; j < y; j++) {
            if (!visited[i][j]) {
                std::vector<std::vector<int>> nodes;
                dfs(graph, visited, nodes, i, j);
                if (isPeak(graph, nodes, graph[i][j])) res++;
            }
        }
    }
    std::cout << res;
}