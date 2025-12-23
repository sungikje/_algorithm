#include <iostream>
#include <queue>
#include <algorithm>

void bfs(std::vector<std::vector<int>>& graph, std::vector<int>& res, int start) {
    std::vector<bool> visited(graph.size(), false);
    std::queue<int> q;
    int depth = 1;
    q.push(start);
    res[start] = depth;
    visited[start] = true;

    while(!q.empty()) {
        int node = q.front();
        q.pop();

        bool pushed = false;
        for(int i = 0 ; i < graph[node].size(); i++) {
            if (!visited[graph[node][i]]) {
                pushed = true;
                q.push(graph[node][i]);
                visited[graph[node][i]] = true;
                res[graph[node][i]] = depth + 1;
                depth++;
            }
        }
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int n, m, s;
    std::cin >> n >> m >> s;
    std::vector<std::vector<int>> graph(n+1);
    std::vector<int> res(n+1);

    for(int i = 0; i < m; i++) {
        int n1, n2;
        std::cin >> n1 >> n2;
        graph[n1].push_back(n2);
        graph[n2].push_back(n1);
    }

    for(int i = 0; i < graph.size(); i++) {
        std::sort(graph[i].begin(), graph[i].end());
    }

    bfs(graph, res, s);
    for(int i = 1; i < res.size(); i++) {
        std::cout << res[i] << "\n";
    }
}