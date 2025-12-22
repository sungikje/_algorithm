#include <iostream>
#include <vector>
#include <stack>

int dfs(std::vector<std::vector<int>>& graph, std::vector<std::vector<int>>& graph_reverse, int start) {
    std::stack<int> stack;
    std::vector<bool> visited(graph.size());
    int cnt = 0;

    stack.push(start);
    while(!stack.empty()) {
        int node = stack.top();
        stack.pop();

        if (visited[node]) continue;
        visited[node] = true;
        if (node != start) cnt++;
        for(int i = 0; i < graph[node].size(); i++) {
            if (!visited[graph[node][i]]) {
                stack.push(graph[node][i]);
            }
        }
    }

    stack.push(start);
    visited.assign(visited.size(), false);
    while(!stack.empty()) {
        int node = stack.top();
        stack.pop();

        if (visited[node]) continue;
        visited[node] = true;
        if (node != start) cnt++;
        for(int i = 0; i < graph_reverse[node].size(); i++) {
            if (!visited[graph_reverse[node][i]]) {
                stack.push(graph_reverse[node][i]);
            }
        }
    }

    return cnt+1;
}
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<int>> graph(n+1);
    std::vector<std::vector<int>> graph_reverse(n+1);
    for(int i = 0; i < m; i++) {
        int b, s;
        std::cin >> b >> s;
        graph[b].push_back(s);
        graph_reverse[s].push_back(b);
    }

    for(int i = 1; i <= n; i++) {
        int cnt = dfs(graph, graph_reverse, i);
        std::cout << n - cnt << "\n";
    }
}