#include <iostream>
#include <vector>
#include <stack>

int dfs(std::vector<std::vector<int>>& graph, std::vector<std::vector<bool>>& visited, int x, int y) {
    std::vector<std::vector<int>> dire = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    std::stack<std::vector<int>> stack;
    int cnt = 0;
    stack.push({x, y});

    while(!stack.empty()) {
        std::vector<int> node = stack.top();
        stack.pop();

        int x = node[0], y = node[1];
        if (!visited[x][y]) {
            visited[x][y] = true;
            cnt++;
        }
        for(int i = 0; i < dire.size(); i++) {
            int new_x = node[0] + dire[i][0], new_y = node[1] + dire[i][1];
            if(!(0 <= new_x && new_x < graph.size() && 0 <= new_y && new_y < graph[0].size())) {
                continue;
            }
            if (visited[new_x][new_y]) {
                continue;
            }
            if (graph[new_x][new_y] != 1) {
                continue;
            }
            stack.push({new_x, new_y});
        }
    }
    return cnt;
}
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int x, y;
    std::cin >> x >> y;
    std::vector<std::vector<int>> graph(x, std::vector<int>(y, 0));
    std::vector<std::vector<bool>> visited(x, std::vector<bool>(y, 0));
    for(int i = 0; i < x; i++) {
        for(int j = 0; j < y; j++) {
            std::cin >> graph[i][j];
        }
    }

    int cnt = 0;
    int res = 0;
    for(int i = 0; i < x; i++) {
        for(int j = 0; j < y; j++) {
            if (!visited[i][j] && graph[i][j] == 1) {
                cnt++;
                int tmp = dfs(graph, visited, i, j);
                if (tmp > res) res = tmp;
            }
        }
    }
    std::cout << cnt << std::endl;
    std::cout << res;
}