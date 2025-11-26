#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

int dfs(std::vector<std::vector<int>>& graph, std::vector<std::vector<bool>>& visited, int x, int y) {
    std::vector<std::vector<int>> dire = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    std::stack<std::vector<int>> stack;
    int cnt = 0;
    stack.push({x, y});
    while(!stack.empty()) {
        std::vector<int> node = stack.top();
        stack.pop();
        if (!visited[node[0]][node[1]]) {
            visited[node[0]][node[1]] = true;
            cnt++;
        }

        for(int i = 0; i < dire.size(); i++) {
            int new_x = node[0]+dire[i][0], new_y = node[1]+dire[i][1];
            if (!(0 <= new_x && new_x < visited.size() && 0 <= new_y && new_y < visited[0].size())) {
                continue;
            }
            if (visited[new_x][new_y]) {
                continue;
            }
            if (graph[new_x][new_y] == 1) {
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

    int m, n, k;
    std::cin >> m >> n >> k;
    std::vector<std::vector<int>> graph(m, std::vector<int>(n, 0));
    for(int i = 0; i < k; i++) {
        int l_x, l_y, r_x, r_y;
        std::cin >> l_y >> l_x >> r_y >> r_x;
        l_x = m-l_x;
        r_x = m-r_x;
        
        for(int j = r_x; j < l_x; j++) {
            for(int z = l_y; z < r_y; z++) {
                graph[j][z] = 1;
            }
        }
    }
    
    std::vector<std::vector<bool>> visited(m, std::vector<bool>(n, false));
    std::vector<int> res;
    for(int i = 0; i < graph.size(); i++) {
        for(int j = 0; j < graph[0].size(); j++) {
            if (!visited[i][j] && graph[i][j] == 0) {
                res.push_back(dfs(graph, visited, i, j));
            }
        }
    }

    std::sort(res.begin(), res.end());
    std::cout << res.size() << std::endl;
    for(auto& i: res) {
        std::cout << i << " ";
    }

}

/*

*/